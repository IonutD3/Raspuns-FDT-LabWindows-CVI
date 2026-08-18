/**************************************************************************/
/* Fisier de includere generat de LabWindows/CVI pentru resursa UIR              */
/*                                                                        */
/* ATENTIE: Continutul acestui fisier este generat automat. Nu il modifica manual.  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panouri si controale: */

#define  PANEL                            1
#define  PANEL_OKBUTTON_2                 2       /* tip control: comanda, functie callback: stergere_grafice */
#define  PANEL_OKBUTTON                   3       /* tip control: comanda, functie callback: start_aplicatie */
#define  PANEL_QUITBUTTON                 4       /* tip control: comanda, functie callback: QuitCallback */
#define  PANEL_TEXTBOX                    5       /* tip control: caseta text, fara callback */
#define  PANEL_LED                        6       /* tip control: LED, fara callback */
#define  PANEL_BINARYSWITCH               7       /* tip control: comutator binar, fara callback */
#define  PANEL_BINARYSWITCH_2             8       /* tip control: comutator binar, fara callback */
#define  PANEL_GRAPH                      9       /* tip control: grafic, fara callback */
#define  PANEL_SEL_REF                    10      /* tip control: cursor, functie callback: selectie_semnal */
#define  PANEL_REFERINTA                  11      /* tip control: scala, fara callback */
#define  PANEL_T_SINUS                    12      /* tip control: numeric, functie callback: detectare_comutare_SIN */
#define  PANEL_A_SINUS                    13      /* tip control: numeric, functie callback: detectare_comutare_SIN */
#define  PANEL_M_PANTA                    14      /* tip control: numeric, functie callback: modificare_Panta */
#define  PANEL_TIMER                      15      /* tip control: timer, functie callback: esantionare */
#define  PANEL_DECORATION                 16      /* tip control: decoratie, fara callback */
#define  PANEL_DECORATION_3               17      /* tip control: decoratie, fara callback */
#define  PANEL_TEXTMSG_2                  18      /* tip control: mesaj text, fara callback */
#define  PANEL_TEXTMSG                    19      /* tip control: mesaj text, fara callback */
#define  PANEL_TE                         20      /* control type: numeric, callback function: setare_TE */


     /* Tablouri de controale: */

          /* Nu exista tablouri de controale in resursa. */


     /* Bare de meniu, meniuri si elemente de meniu: */

          /* Nu exista meniuri in resursa. */


     /* Prototipuri pentru functiile callback: */

int  CVICALLBACK detectare_comutare_SIN(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK esantionare(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK modificare_Panta(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK selectie_semnal(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK setare_TE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK start_aplicatie(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK stergere_grafice(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif