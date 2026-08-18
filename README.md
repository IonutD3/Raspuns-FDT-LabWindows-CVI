# Răspuns FDT / Discrete Process Response

**C / NI LabWindows/CVI application for signal generation, discrete process simulation and graphical response visualization.**

---

## 🇷🇴 Română

### Despre proiect

**Răspuns FDT** este o aplicație desktop dezvoltată în **C folosind NI LabWindows/CVI**, destinată simulării și vizualizării răspunsului unui proces discret la diferite semnale de referință.

Aplicația permite generarea mai multor tipuri de semnale de intrare și afișează atât semnalul de referință, cât și răspunsul procesului pe un grafic.

### Funcționalități

- pornirea și oprirea aplicației;
- configurarea perioadei de eșantionare `Te`;
- funcționare în mod **Automat** sau **Manual**;
- generarea unui semnal de tip **treaptă**;
- generarea unui semnal de tip **rampă**;
- generarea unui semnal **sinusoidal**;
- configurarea pantei pentru rampă;
- configurarea amplitudinii și perioadei sinusoidale;
- afișarea simultană a referinței și a răspunsului procesului;
- ștergerea graficului și resetarea timpului de simulare.

### Principiul de funcționare

Aplicația utilizează un **timer LabWindows/CVI** pentru executarea ciclului de eșantionare.

La fiecare eveniment `EVENT_TIMER_TICK` sunt executate următoarele operații:

1. actualizarea modului Automat/Manual;
2. generarea semnalului de referință;
3. transmiterea referinței către modelul procesului;
4. calcularea răspunsului procesului discret;
5. afișarea referinței și a răspunsului pe grafic;
6. actualizarea valorilor pentru următorul ciclu.

### Generarea semnalelor

#### Treaptă

Valoarea semnalului este preluată din interfața grafică.

#### Rampă

Semnalul este calculat pe baza pantei introduse de utilizator:

```text
r(k) = m · t(k) + r₀
```

unde `m` este panta, `t(k)` timpul curent, iar `r₀` valoarea inițială.

#### Sinusoidal

Semnalul sinusoidal este generat pe baza amplitudinii și perioadei configurate:

```text
r(k) = A · sin((2π / T) · t(k)) + r₀
```

unde `A` este amplitudinea, `T` perioada, iar `r₀` valoarea inițială.

### Modelul procesului discret

Răspunsul procesului este calculat numeric la fiecare pas de eșantionare:

```text
y₀(k) = y₀(k-1) + C · [u(k) - y₀(k-1)]

y(k) = y(k-1) + C₁ · [y₀(k) - y(k-1)]
       + C₂ · [y₀(k) - y₀(k-1)]
```

Coeficienții modelului sunt determinați în funcție de perioada de eșantionare `Te` și de parametrii modelului.

### Structura proiectului

```text
Raspuns-FDT–LabWindows-CVI/
│
├── src/
│   ├── rasp_FDT.c
│   ├── rasp_FDT.h
│   ├── 00_Declaratii_Variabile_S.h
│   ├── 01_Functionare_A_M_S.h
│   ├── 02_Functii_Utilitare_S.h
│   └── 03_Generare_Semnale_S.h
│
├── ui/
│   └── rasp_FDT.uir
│
└── README.md
```

### Tehnologii

- **C**
- **NI LabWindows/CVI**
- CVI Runtime
- LabWindows/CVI User Interface Library
- programare bazată pe evenimente
- timer pentru eșantionare
- modelare și simulare discretă
- vizualizarea grafică a datelor

### Cerințe

- Windows;
- NI LabWindows/CVI;
- bibliotecile incluse în instalarea LabWindows/CVI.

Fișierul `rasp_FDT.uir` este o resursă specifică LabWindows/CVI și trebuie gestionat folosind mediul LabWindows/CVI.

### Instalare și rulare

1. Descarcă sau clonează repository-ul.
2. Deschide proiectul în NI LabWindows/CVI.
3. Include fișierele `.c` și `.h` și resursa `rasp_FDT.uir` în proiect.
4. Compilează aplicația.
5. Rulează aplicația și apasă butonul de pornire.
6. Selectează tipul de semnal și parametrii doriti din interfață.
7. Urmărește pe grafic semnalul de referință și răspunsul procesului.

---

## 🇬🇧 English

### About

**Răspuns FDT** is a desktop application developed in **C using NI LabWindows/CVI**, designed to simulate and visualize the response of a discrete process to different reference signals.

The application generates several input signal types and displays both the reference signal and the process response over time.

### Features

- application start and exit;
- configurable sampling period `Te`;
- **Automatic** and **Manual** operating modes;
- **step**, **ramp**, and **sine** signal generation;
- configurable ramp slope;
- configurable sine amplitude and period;
- simultaneous plotting of reference and process response;
- graph clearing and simulation time reset.

### How it works

The application uses a **LabWindows/CVI timer** to execute the sampling cycle.

During each `EVENT_TIMER_TICK` event, the application updates the operating mode, generates the reference signal, calculates the discrete process response, plots the results, and stores the values required for the next sampling cycle.

### Signal generation

#### Step

The signal value is read from the graphical interface.

#### Ramp

```text
r(k) = m · t(k) + r₀
```

where `m` is the slope, `t(k)` is the current time, and `r₀` is the initial value.

#### Sine

```text
r(k) = A · sin((2π / T) · t(k)) + r₀
```

where `A` is the amplitude, `T` is the period, and `r₀` is the initial value.

### Discrete process model

The process response is numerically calculated at every sampling step:

```text
y₀(k) = y₀(k-1) + C · [u(k) - y₀(k-1)]

y(k) = y(k-1) + C₁ · [y₀(k) - y(k-1)]
       + C₂ · [y₀(k) - y₀(k-1)]
```

The model coefficients depend on the sampling period `Te` and model parameters.

### Project structure

```text
Raspuns-FDT–LabWindows-CVI/
│
├── src/
│   ├── rasp_FDT.c
│   ├── rasp_FDT.h
│   ├── 00_Declaratii_Variabile_S.h
│   ├── 01_Functionare_A_M_S.h
│   ├── 02_Functii_Utilitare_S.h
│   └── 03_Generare_Semnale_S.h
│
├── ui/
│   └── rasp_FDT.uir
│
└── README.md
```

### Technologies

- **C**
- **NI LabWindows/CVI**
- CVI Runtime
- LabWindows/CVI User Interface Library
- event-driven programming
- timer-based sampling
- discrete modeling and simulation
- graphical data visualization

### Requirements

- Windows;
- NI LabWindows/CVI;
- libraries included with the LabWindows/CVI installation.

The `rasp_FDT.uir` file is a LabWindows/CVI-specific resource and should be managed using the LabWindows/CVI environment.

### Installation and running

1. Download or clone the repository.
2. Open the project in NI LabWindows/CVI.
3. Add the `.c` and `.h` files and the `rasp_FDT.uir` resource to the project.
4. Build the application.
5. Run the application and press the start button.
6. Select the signal type and desired parameters from the interface.
7. Monitor the reference signal and process response on the graph.

---

## 👤 Autor / Author

**IonutD**

