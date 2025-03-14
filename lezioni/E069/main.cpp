#include <iostream>
using namespace std;

int main()
{
    // Allocazione iniziale di memoria per un array di 3 interi
    int* array1 = new int[3];

    // Inizializzazione dei valori dell'array
    for (int i = 0; i < 3; ++i) array1[i] = i * 10;

    cout << "Valori del array prima di riallocazione:" << endl;
    for (int i = 0; i < 3; ++i) cout << array1[i] << " ";

    cout << endl;

    // Riallocazione di memoria per un array di 5 interi
    int* newArray = new int[5];

    // Copia dei valori dall'array originale al nuovo array
    for (int i = 0; i < 3; ++i) newArray[i] = array1[i];


    // Deallocazione della memoria dell'array originale
    delete[] array1;

    array1=newArray;

    // Aggiunta di valori aggiuntivi al nuovo array
    for (int i = 3; i < 5; ++i) array1[i] = i * 10;

    cout << "Valori del nuovo array dopo la riallocazione:" << endl;
    for (int i = 0; i < 5; ++i) cout << array1[i] << " ";
    cout << endl;

    // Deallocazione della memoria del nuovo array
    delete[] array1;

    return 0;
}
