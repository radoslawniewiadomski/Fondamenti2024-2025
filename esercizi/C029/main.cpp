#include <iostream>
using namespace std;

struct film {
    int id;
    char titolo[50];
    int durata;
    int anno;
};

// Funzione per aggiornare la durata del film
void aggiorna_durata(film* films[], int n) {
    for (int i = 0; i < n; i++) {
        if (films[i]->durata > 120) {
            films[i]->durata = 120;  // Imposta la durata a 120 minuti se è maggiore
        }
    }
}

// Funzione per stampare le informazioni di tutti i film
void stampa_film(film* films[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Titolo: " << films[i]->titolo << endl;
        cout << "Durata: " << films[i]->durata << " minuti" << endl;
        cout << "Anno: " << films[i]->anno << endl;
        cout << "----------------------------------" << endl;
    }
}

int main() {
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

    // Array di puntatori alle funzioni
    void (*funzioni[3])(film*[], int) = {stampa_film, aggiorna_durata, stampa_film};

    // Esegui le funzioni per l'array di puntatori a film
    for (int i = 0; i < 3; i++) {
        cout << "Funzione: "<< i +1 <<endl;
        funzioni[i](films, n);  // Esegui la funzione corrente passando l'array di puntatori a film
    }
    return 0;
}
