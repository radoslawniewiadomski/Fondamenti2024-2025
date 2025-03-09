#include <iostream>
using namespace std;

// Funzione che calcola l'inverso di un numero intero
double inverso(int a) {
    return 1.0 / a;
}

// Funzione che calcola il quadrato di un numero intero
double quadrato(int a) {
    return double(a * a);
}

// Funzione che restituisce il valore assoluto di un numero intero
double assoluto(int a) {
    return abs(a);
}

// Funzione che calcola la somma dei valori ottenuti applicando la funzione f agli elementi dell'array a
double somma(int *a, double (*f)(int)) {
    double s = 0.0;
    for (int i = 0; i < 5; i++) // Itera su tutti gli elementi dell'array
        s += (*f)(*(a + i));  // Applica la funzione f all'elemento corrente e somma il risultato
    return s;
}

int main() {
    int a[] = {1, -2, 3, -4, 5};  // Array di interi
    double (*pf[3])(int) = {inverso, quadrato, assoluto};  // Array di puntatori a funzione

    // Itera sulle funzioni e calcola la somma per ogni funzione applicata agli elementi dell'array
    for (int i = 0; i < 3; i++)
        cout << somma(a, pf[i]) << endl;

    return 0;
}
