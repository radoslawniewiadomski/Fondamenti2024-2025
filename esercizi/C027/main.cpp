#include <iostream>
using namespace std;

struct film
{
    int id;
    char titolo[50];
    int durata;
    int anno;
};

// Funzione che confronta i film in un array di puntatori e restituisce il puntatore al film più recente
film* piu_recente(film* films[], int n)
{
    film* piu_recente_film = films[0];  // Assume che il primo film sia il più recente inizialmente

    for (int i = 1; i < n; i++)
    {
        if (films[i]->anno > piu_recente_film->anno)
        {
            piu_recente_film = films[i];  // Aggiorna il puntatore se un film più recente è trovato
        }
    }

    return piu_recente_film;  // Restituisce il puntatore al film più recente
}

int main()
{
    const int n = 3;  // Numero di film
    film film1, film2, film3;  // Tre strutture film
    film* films[n];  // Array di puntatori a film

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

    // Inserimento dati per il terzo film
    cout << "Inserisci il titolo del terzo film: ";
    cin >> film3.titolo;
    cout << "Inserisci durata del terzo film: ";
    cin >> film3.durata;
    cout << "Inserisci anno del terzo film: ";
    cin >> film3.anno;

    // Assegnazione dei puntatori all'array
    films[0] = &film1;
    films[1] = &film2;
    films[2] = &film3;

    // Chiamata alla funzione per trovare il film più recente
    film* film_recente = piu_recente(films, n);

    // Stampa del risultato
    cout << "Il film piu' recente è: " << film_recente->titolo << " (" << film_recente->anno << ")\n";

    return 0;
}
