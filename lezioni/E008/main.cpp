#include <iostream>
using namespace std;
int main()
{
    int a = 100;
    cout << &a << endl; // vedo quale indirizzo di memoria viene utlizzato

    // Inserisco l'indirizzo, che ho stampato nell'esecuzione precedente, sperando che sia lo stesso
    //int* x = (int*)6422076;
    int* x = (int*)0x61fe44;

    cout << x << endl;

    //mi stampa l'indirizzo in hex
    cout << "Il valore : " << *x << endl;

    //pero se ci spostiamo di qualche bit nella memoria
    x = (int*)0x61fe46;

    cout << x << endl;

    //il valore è casuale, puo essere pericoloso di stampare un valore una cella di memoria a caso
    cout << "Il valore : " << *x << endl;

    return 0;
}
