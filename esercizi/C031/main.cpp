#include <iostream>
using namespace std;

// Funzione append per concatenare due array dinamici
int* append(int* pa, int na, int* pb, int nb) {

    int* result = new int[na + nb];

    // Copia degli elementi di pa nell'array result
    for (int i = 0; i < na; i++) {
        //result[i] = pa[i];
           *(result+i) = *(pa+i);
    }

    // Copia degli elementi di pb nell'array result
    for (int i = 0; i < nb; i++) {
        result[na + i] = pb[i];
    }

    // Restituisce il puntatore all'array concatenato
    return result;
}

int main() {
    // Variabili per le dimensioni degli array
    int na, nb;

    // Chiedere all'utente le dimensioni degli array
    cout << "Inserisci la dimensione del primo array: ";
    cin >> na;
    int* pa = new int[na];

    // Chiedere all'utente di inserire i valori per il primo array
    cout << "Inserisci gli elementi del primo array: ";
    for (int i = 0; i < na; i++) {
        cin >> pa[i];
    }

    cout << "Inserisci la dimensione del secondo array: ";
    cin >> nb;
    int* pb = new int[nb];

    // Chiedere all'utente di inserire i valori per il secondo array
    cout << "Inserisci gli elementi del secondo array: ";
    for (int i = 0; i < nb; i++) {
        cin >> pb[i];
    }

    // Chiamata alla funzione append
    int* concatenato = append(pa, na, pb, nb);

    // Stampa dell'array concatenato
    cout << "Array concatenato: ";
    for (int i = 0; i < (na + nb); i++) {
        cout << concatenato[i] << " ";
    }
    cout << endl;


    // Deallocazione della memoria
    delete[] pa;
    delete[] pb;

    delete[] concatenato;

    return 0;
}
