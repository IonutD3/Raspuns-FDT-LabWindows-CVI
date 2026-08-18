// Declaratii pentru variabilele globale utilizate de aplicatie.
static int panelHandle;

// Starea modului Automat/Manual si starea LED-ului.
int regim;
int stare_led;
int valoare_led;

// Parametrii pentru generarea semnalelor de referinta.
float Refk, Refk_1, Refk_2, Refk0;
int sel_ref;
double timp_rampa_tk, timp_sinus_tk;
double T_sin, A_sin;
int comutare_Sin;

// Perioada de esantionare si parametrii modelului discret.
double Te, T1, T2, C1, C2;
double tk_1, tk;

// Variabile pentru semnalul de intrare si iesirea procesului.
float y_matlabk_1, y_matlabk;
float uk, uk_1;
double ynouk, ynouk_1, yk1, yk1_1;

// Parametrii modelului de ordinul intai.
double C, T;
