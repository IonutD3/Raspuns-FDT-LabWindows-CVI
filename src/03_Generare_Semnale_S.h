// Genereaza semnalul de referinta: treapta, rampa sau sinus.
// La schimbarea tipului de semnal, valoarea curenta este folosita ca punct
// de plecare pentru a evita salturile inutile ale referintei.
double generare_semnal()
{
    double local_Refk;
    double local_m, local_n;

    local_Refk = 0;

    switch (sel_ref)
    {
        case 0:
            // Semnal treapta: valoarea este preluata direct din interfata.
            SetCtrlAttribute(panelHandle, PANEL_REFERINTA, ATTR_VISIBLE, 1);
            SetCtrlAttribute(panelHandle, PANEL_M_PANTA, ATTR_VISIBLE, 0);
            SetCtrlAttribute(panelHandle, PANEL_A_SINUS, ATTR_VISIBLE, 0);
            SetCtrlAttribute(panelHandle, PANEL_T_SINUS, ATTR_VISIBLE, 0);

            GetCtrlVal(panelHandle, PANEL_REFERINTA, &local_Refk);
            break;

        case 1:
            // Semnal rampa: valoarea este calculata folosind panta selectata.
            SetCtrlAttribute(panelHandle, PANEL_REFERINTA, ATTR_VISIBLE, 0);
            SetCtrlAttribute(panelHandle, PANEL_M_PANTA, ATTR_VISIBLE, 1);
            SetCtrlAttribute(panelHandle, PANEL_A_SINUS, ATTR_VISIBLE, 0);
            SetCtrlAttribute(panelHandle, PANEL_T_SINUS, ATTR_VISIBLE, 0);

            GetCtrlVal(panelHandle, PANEL_M_PANTA, &local_m);
            local_n = Refk0;
            local_Refk = local_m * timp_rampa_tk + local_n;
            timp_rampa_tk = timp_rampa_tk + Te;
            break;

        case 2:
            // Semnal sinusoidal: amplitudinea si perioada sunt citite din interfata.
            SetCtrlAttribute(panelHandle, PANEL_REFERINTA, ATTR_VISIBLE, 0);
            SetCtrlAttribute(panelHandle, PANEL_M_PANTA, ATTR_VISIBLE, 0);
            SetCtrlAttribute(panelHandle, PANEL_A_SINUS, ATTR_VISIBLE, 1);
            SetCtrlAttribute(panelHandle, PANEL_T_SINUS, ATTR_VISIBLE, 1);

            if (comutare_Sin == 0)
            {
                GetCtrlVal(panelHandle, PANEL_A_SINUS, &A_sin);
                GetCtrlVal(panelHandle, PANEL_T_SINUS, &T_sin);
            }
            else
            {
                // Comutarea intre doua semnale sinusoidale se face cand
                // semnalul trece prin valoarea de referinta initiala.
                if ((Refk_2 < Refk0) && (Refk_1 >= Refk0))
                {
                    comutare_Sin = 0;
                    timp_sinus_tk = 2 * Te;
                }

                if ((Refk_2 > Refk0) && (Refk_1 <= Refk0))
                {
                    comutare_Sin = 0;
                    timp_sinus_tk = 2 * Te + T_sin / 2;
                }
            }
            //formula de calcul pentru SIN
            local_Refk = A_sin * sin(((2 * Pi()) / T_sin) * timp_sinus_tk) + Refk0;
            timp_sinus_tk = timp_sinus_tk + Te;
            break;

        default:
            break;
    }

    return local_Refk;
}

// Proceseaza schimbarea tipului de semnal de referinta.
int CVICALLBACK selectie_semnal(int panel, int control, int event,
                                void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
        case EVENT_COMMIT:
            GetCtrlVal(panelHandle, PANEL_SEL_REF, &sel_ref);

            switch (sel_ref)
            {
                case 0:
                    //treapta
                    break;

                case 1:
                    // Rampa porneste din valoarea curenta a referintei.
                    timp_rampa_tk = 0;
                    Refk0 = Refk;
                    break;

                case 2:
                    // Sinusul porneste din valoarea curenta a referintei.
                    timp_sinus_tk = 0;
                    Refk0 = Refk;
                    break;

                default:
                    break;
            }
            break;
    }

    return 0;
}

// Reporneste rampa din valoarea curenta atunci cand panta este modificata.
int CVICALLBACK modificare_Panta(int panel, int control, int event,
                                 void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
        case EVENT_COMMIT:
            timp_rampa_tk = 0;
            Refk0 = Refk;
            break;
    }

    return 0;
}

// Activeaza detectarea punctului de trecere pentru schimbarea sinusului.
int CVICALLBACK detectare_comutare_SIN(int panel, int control, int event,
                                       void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
        case EVENT_COMMIT:
            comutare_Sin = 1;
            break;
    }

    return 0;
}
