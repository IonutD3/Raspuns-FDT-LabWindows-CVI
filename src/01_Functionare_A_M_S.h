// Gestioneaza functionarea aplicatiei in mod Automat sau Manual.
int functiune_Automat_Manual()
{
    GetCtrlVal(panelHandle, PANEL_BINARYSWITCH, &regim);

    if (regim)
    {
        // In modul Manual, utilizatorul poate controla direct LED-ul.
        SetCtrlAttribute(panelHandle, PANEL_BINARYSWITCH_2, ATTR_DIMMED, 0);
        GetCtrlVal(panelHandle, PANEL_BINARYSWITCH_2, &stare_led);
        SetCtrlVal(panelHandle, PANEL_LED, stare_led);
    }
    else
    {
        // In modul Automat, comutatorul manual este dezactivat.
        SetCtrlAttribute(panelHandle, PANEL_BINARYSWITCH_2, ATTR_DIMMED, 1);

        GetCtrlVal(panelHandle, PANEL_LED, &valoare_led);

        // LED-ul isi schimba automat starea la fiecare esantionare.
        if (valoare_led == 0)
            SetCtrlVal(panelHandle, PANEL_LED, 1);
        else
            SetCtrlVal(panelHandle, PANEL_LED, 0);
    }

    return 0;
}
