#include <iostream>
using namespace std;

int main() {
    // Dichiarazione di tre variabili per le lettere
    char lettera1, lettera2, lettera3;

    // Richiesta dell'input da parte dell'utente
    cout << "Inserisci tre lettere: ";
    cin >> lettera1 >> lettera2 >> lettera3;

    // Dichiarazione dei puntatori a char per ciascuna lettera
    char* ptr1 = &lettera1;
    char* ptr2 = &lettera2;
    char* ptr3 = &lettera3;

    // Comparazione delle lettere usando i puntatori
    char* min = ptr1; // Partiamo assumendo che ptr1 punti alla lettera più piccola

    if (*ptr2 < *min) {
        min = ptr2;
    }
    if (*ptr3 < *min) {
        min = ptr3;
    }

    // Stampa della lettera che viene prima nell'ordine alfabetico
    cout << "La lettera che viene prima nell'ordine alfabetico è: " << *min << endl;

    return 0;
}
