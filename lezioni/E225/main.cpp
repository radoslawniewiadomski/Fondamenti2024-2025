#include <iostream>
using namespace std;

// Funzioni specifiche per calcolare l'area delle figure
double areaQuadrato(double lato, double = 0, double = 0) {
    return lato * lato;
}

double areaRettangolo(double base, double altezza, double = 0) {
    return base * altezza;
}

double areaTrapezio(double base1, double base2, double altezza) {
    return ((base1 + base2) * altezza) / 2;
}

// Funzione generica che usa un puntatore a funzione
double calcolaArea(double (*funzioneArea)(double, double, double), double a, double b = 0, double c = 0) {
    return funzioneArea(a, b, c);
}

int main() {

    double lato = 4.0;
    double base = 5.0, altezza = 3.0;
    double base1 = 6.0, base2 = 4.0, h = 2.0;

    cout << "Area del quadrato: " << calcolaArea(areaQuadrato, lato ) << endl;
    cout << "Area del rettangolo: " << calcolaArea(areaRettangolo, base, altezza) << endl;
    cout << "Area del trapezio: " << calcolaArea(areaTrapezio, base1, base2, h) << endl;

    return 0;
}
