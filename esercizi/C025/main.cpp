#include <iostream>
using namespace std;

    const int dim = 3;

// Funzione per calcolare la somma di due matrici
void somma_matrici(int (*A)[dim], int (*B)[dim], int (*C)[dim], int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            *(*(C + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
            }
    }
}

int main() {
    int A[dim][dim], B[dim][dim], C[dim][dim];

    // Inserimento dei valori per la matrice A
    cout << "Inserisci i valori per la matrice A (3x3):\n";
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // Inserimento dei valori per la matrice B
    cout << "Inserisci i valori per la matrice B (3x3):\n";
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    // Calcolare la somma delle matrici A e B, risultato in C
    somma_matrici(A, B, C, dim);

    // Stampa della matrice risultante C
    cout << "La matrice risultante C = A + B, è: " << endl;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << C[i][j] << "\t ";  // Accesso agli elementi tramite puntatore
        }
        cout << endl;
    }

    return 0;
}
