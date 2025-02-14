#include <iostream>
using namespace std;

int main() {
    // Array di numeri interi
    int numeri[5] = {15, 42, 7, 63, 22};

    // Riferimento al numero massimo
    int& max = numeri[0];

    // Trova il numero più grande nell'array usando il riferimento
    for (int i = 1; i < 5; i++) {
        if (numeri[i] > max) {
            max = numeri[i];
        }
    }

    // Aggiungi 1 al numero più grande
    max++;

    // Stampa il numero più grande dopo l'incremento
    cout << "Il numero piu' grande (dopo incremento) è: " << max << endl;

    return 0;
}
