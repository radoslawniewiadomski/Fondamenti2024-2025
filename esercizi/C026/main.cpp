#include <iostream>
using namespace std;

struct film
{
    int id;
    char titolo[50];
    int durata;
    int anno;
};

// Funzione che confronta due film e restituisce un puntatore al film più recente
film* piu_recente(film* f1, film* f2)
{
    if (f1->anno > f2->anno)
    {
        return f1; // Restituisce il puntatore al film 1 se è più recente
    }
    else if (f2->anno > f1->anno)
    {
        return f2; // Restituisce il puntatore al film 2 se è più recente
    }
    else
    {
        return nullptr; // Se i due film hanno lo stesso anno, restituisce nullptr
    }
}

int main()
{
    film *p1, *p2;
    film film1, film2;

    // Inserimento dati per il primo film
    cout << "Inserisci il titolo del primo film: ";
    cin >> film1.titolo;
    cout << "Inserisci durata del primo film: ";
    cin >> film1.durata;
    cout << "Inserisci anno del primo film: ";
    cin >> film1.anno;

    // Inserimento dati per il secondo film
    cout << "Inserisci il titolo del secondo film: ";
    cin >> film2.titolo;
    cout << "Inserisci durata del secondo film: ";
    cin >> film2.durata;
    cout << "Inserisci anno del secondo film: ";
    cin >> film2.anno;

    // Assegnazione dei puntatori ai film
    p1 = &film1;
    p2 = &film2;

    // Chiamata alla funzione per trovare il film più recente
    film* film_recente = piu_recente(p1, p2);

    // Stampa del risultato
    if (film_recente)
    {
        cout << "Il film piu' recente è: " << film_recente->titolo << " (" << film_recente->anno << ")\n";
    }
    else
    {
        cout << "I due film hanno lo stesso anno di uscita.\n";
    }

    return 0;
}
