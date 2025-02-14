#include <iostream>
using namespace std;

int main() {
    float num1, num2, num3;
    float *ptr1, *ptr2, *ptr3;

    // Input dei tre numeri reali
    cout << "Inserisci tre numeri reali: ";
    cin >> num1 >> num2 >> num3;

    // Assegnamento dei puntatori alle variabili num1, num2, num3
    ptr1 = &num1;
    ptr2 = &num2;
    ptr3 = &num3;

    // Inizializzazione del puntatore p_max con ptr1
    float *p_max = ptr1;

    // Trova il massimo tra i tre numeri utilizzando i puntatori
    if (*ptr2 > *p_max) {
        p_max = ptr2;
    }
    if (*ptr3 > *p_max) {
        p_max = ptr3;
    }

    // Stampa il massimo tra i tre numeri
    cout << "Il massimo tra i tre numeri è: " << *p_max << endl;

    return 0;
}
