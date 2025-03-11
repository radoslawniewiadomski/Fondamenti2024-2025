#include <iostream>  // Inclusione della libreria iostream per l'input/output
using namespace std;

int maggiore(int a, int b)
{
    // Funzione che restituisce 1 se a è maggiore di b, altrimenti 0
    return a > b;
}

int minore(int a, int b)
{
    // Funzione che restituisce 1 se a è minore di b, altrimenti 0
    return a < b;
}

void scambia(int& a, int& b)
{
    // Funzione che scambia i valori tra due variabili
    int t = a;  // Temporaneamente memorizza il valore di a
    a = b;       // Assegna a a il valore di b
    b = t;       // Assegna a b il valore temporaneamente memorizzato in t
}

void bubble_sort(int v[], int n, int (*pf)(int, int))
{
    // Funzione che implementa l'algoritmo di ordinamento Bubble Sort
    // v[] è l'array da ordinare, n è la dimensione dell'array,
    // pf è il puntatore alla funzione di confronto (maggiore o minore)
    for (int i = n - 1; i >= 0; i--)  // Ciclo esterno per determinare il numero di passaggi
        for (int j = 0; j < i; j++)   // Ciclo interno per confrontare e scambiare gli elementi
            if (!(*pf)(v[j], v[j + 1]))  // Se il confronto restituisce false, scambia
                scambia(v[j], v[j + 1]);  // Scambia gli elementi di posizione
}

int main()
{
    const int dim = 10;  // Dimensione dell'array (10 numeri da ordinare)
    int w[dim];          // Dichiarazione di un array di interi di dimensione 'dim'
    cout << "Inserire " << dim << " numeri interi: " << endl;

    // Ciclo per inserire 10 numeri nell'array
    for (int i = 0; i < dim; i++)
    {
        cout << "Valore " << i + 1 << ": ";
        cin >> w[i];  // Legge un numero dall'input e lo memorizza nell'array
    }

    int scelta = 0;
    do
    {
        // Chiede all'utente come vuole ordinare i dati
        cout << "Come si vogliono ordinare i dati? " << endl;
        cout << "1 - In senso crescente" << endl;
        cout << "2 - In senso decrescente" << endl;
        cin >> scelta;  // Legge la scelta dell'utente

        // Switch per eseguire l'ordinamento in base alla scelta
        switch (scelta)
        {
        case 1:
            // Se l'utente sceglie 1, ordina in senso crescente
            bubble_sort(w, dim, minore);
            break;
        case 2:
            // Se l'utente sceglie 2, ordina in senso decrescente
            bubble_sort(w, dim, maggiore);
            break;
        default:
            // In caso di input non valido, richiede di scegliere 1 o 2
            cout << "Errore: scegliere 1 o 2" << endl;
        }
    }
    while (scelta != 1 && scelta != 2);  // Continua a chiedere se l'input non è 1 o 2

    // Stampa i dati ordinati
    cout << "Dati ordinati: " << endl << "{ ";
    for (int i = 0; i < dim - 1; i++)  // Ciclo per stampare tutti i numeri tranne l'ultimo
        cout << w[i] << ", ";
    cout << w[dim - 1] << " } " << endl;  // Stampa l'ultimo numero senza la virgola finale

    return 0;  // Fine del programma
}

