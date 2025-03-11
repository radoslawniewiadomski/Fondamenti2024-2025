#include <iostream>
using namespace std;


//Si scriva la funzione C++ prodotto_scalare che riceva come parametri il puntatore px al primo elemento di un array di numeri reali, il puntatore py al primo elemento di un array di numeri reali e la dimensione comune n dei due array (un numero intero).
//Utilizzando l’aritmetica dei puntatori, la funzione dovrà scandire i due array e calcolarne il prodotto scalare, restituito come valore di ritorno (un numero reale).
//Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma chiederà all’utente di immettere da tastiera i valori per i due array, chiamerà la funzione prodotto_scalare e ne stamperà a video il valore di ritorno.


// Funzione per calcolare il prodotto scalare di due array
float prodotto_scalare(const float *px, const float *py, int n) {
    float risultato = 0.0;
    for (int i = 0; i < n; ++i) {
        risultato += (*(px + i)) * (*(py + i));
    }
    return risultato;
}




int main() {
    const int dimensione = 5; // Dimensione comune dei due array

    // Dichiarazione e allocazione di memoria per gli array
    float array_x[dimensione];
    float array_y[dimensione];

    // Input degli elementi del primo array
    cout << "Inserisci gli elementi del primo array:" << endl;
    for (int i = 0; i < dimensione; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> array_x[i];
    }

    // Input degli elementi del secondo array
    cout << "Inserisci gli elementi del secondo array:" << endl;
    for (int i = 0; i < dimensione; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> array_y[i];
    }

    // Calcola e stampa il prodotto scalare
    float risultato = prodotto_scalare(array_x, array_y, dimensione);
    cout << "Il prodotto scalare degli array è: " << risultato << endl;

    return 0;
}
