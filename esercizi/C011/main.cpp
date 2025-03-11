#include<iostream>
using namespace std;

//Dichiarare due stringhe di uguale dimensione.
//Acquisire in una stringa una sequenza di caratteri, quindi copiare, usando i puntatori, tutti i caratteri dalla stringa acquisita all'altra, accedendo in modo indiretto a ciascuna delle locazioni delle due stringhe.

int main()
{
    char st[20];
    char st2[20];

    char *p, *j;
    cout << "Inserisci una stringa di massimo 20 elementi: ";
    cin >> st;

    p = &st[0]; // Il puntatore 'p' punta al primo carattere della stringa originale
    j = &st2[0]; // Il puntatore 'j' punta al primo carattere della stringa copia

    // Ciclo per copiare i caratteri da 'st' a 'st2'
    do
    {
        *j = *p; // Copia del carattere
        p++; // Avanza al carattere successivo
        j++; // Avanza al carattere successivo nella stringa copia
    }
    while (*p != '\0'); // Continua fino al termine della stringa originale

    *j = '\0'; // Aggiunge il terminatore di stringa alla copia

    cout << st2 ;
}





