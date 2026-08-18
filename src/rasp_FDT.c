#include "toolbox.h"
#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include "rasp_FDT.h"

// Include modulele aplicatiei.
#include "00_Declaratii_Variabile_S.h"
#include "01_Functionare_A_M_S.h"
#include "02_Functii_Utilitare_S.h"
#include "03_Generare_Semnale_S.h"

double generare_semnal();

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                      LPSTR lpszCmdLine, int nCmdShow)
{
    if (InitCVIRTE(hInstance, 0, 0) == 0)
        return -1;

    if ((panelHandle = LoadPanel(0, "rasp_FDT.uir", PANEL)) < 0)
        return -1;

    DisplayPanel(panelHandle);
    RunUserInterface();
    DiscardPanel(panelHandle);

    return 0;
}

// Initializeaza parametrii aplicatiei si porneste timerul de esantionare.
int CVICALLBACK start_aplicatie(int panel, int control, int event,
                                void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
        case EVENT_COMMIT:
            InsertTextBoxLine(panelHandle, PANEL_TEXTBOX, -1,
                              "Aplicatia a fost pornita cu succes.");

            // Citeste perioada de esantionare configurata in interfata.
            GetCtrlVal(panelHandle, PANEL_TE, &Te);
            tk_1 = 0;
            tk = Te;

            // Initializeaza istoricul semnalului de referinta.
            Refk = 0;
            Refk_1 = 0;
            Refk_2 = 0;
            sel_ref = 0;

            // Pregateste comutarea fara salt intre semnale sinusoidale.
            comutare_Sin = 0;
            GetCtrlVal(panelHandle, PANEL_A_SINUS, &A_sin);
            GetCtrlVal(panelHandle, PANEL_T_SINUS, &T_sin);

            // Parametrii modelului discret al procesului.
            T = 0.2;
            C = Te / (Te + T);
            T1 = 32;
            T2 = 79;
            C1 = Te / (Te + T2);
            C2 = T1 / (Te + T2);

            // Dezactiveaza butonul Start dupa pornirea aplicatiei.
            SetCtrlAttribute(panelHandle, PANEL_OKBUTTON, ATTR_DIMMED, 1);

            // Configureaza si porneste timerul de esantionare.
            SetCtrlAttribute(panelHandle, PANEL_TIMER, ATTR_INTERVAL, Te);
            SetCtrlAttribute(panelHandle, PANEL_TIMER, ATTR_ENABLED, 1);
            break;
    }

    return 0;
}

// Executa un ciclu de esantionare la fiecare eveniment al timerului.
int CVICALLBACK esantionare(int panel, int control, int event,
                            void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
        case EVENT_TIMER_TICK:
            // Actualizeaza functionarea Automat/Manual.
            functiune_Automat_Manual();

            // Genereaza semnalul de referinta selectat.
            Refk = generare_semnal();

            // Semnalul de referinta reprezinta intrarea procesului.
            uk = Refk;

            // Discretizeaza modelul procesului folosind perioada Te.
            ynouk = ynouk_1 + C * (uk - ynouk_1);
            yk1 = yk1_1 + C1 * (ynouk - yk1_1) + C2 * (ynouk - ynouk_1);

            // Afiseaza referinta si raspunsul procesului pe acelasi grafic.
            PlotLine(panelHandle, PANEL_GRAPH, tk_1, Refk_1,
                     tk, Refk, VAL_GREEN);
            PlotLine(panelHandle, PANEL_GRAPH, tk_1, yk1_1,
                     tk, yk1, VAL_RED);

            // Pastreaza valorile curente pentru urmatorul ciclu.
            tk_1 = tk;
            tk = tk + Te;
            Refk_2 = Refk_1;
            Refk_1 = Refk;
            uk_1 = uk;
            ynouk_1 = ynouk;
            yk1_1 = yk1;
            y_matlabk_1 = y_matlabk;
            break;
    }

    return 0;
}

// Actualizeaza perioada timerului atunci cand Te este modificata din interfata.
int CVICALLBACK setare_TE(int panel, int control, int event,
                          void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
        case EVENT_COMMIT:
            GetCtrlVal(panelHandle, PANEL_TE, &Te);
            SetCtrlAttribute(panelHandle, PANEL_TIMER, ATTR_INTERVAL, Te);
            break;
    }

    return 0;
}
