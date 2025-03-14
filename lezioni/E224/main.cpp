#include <iostream>
using namespace std;

struct film
{
    int id;
    char* titolo;
    int durata;
    int anno;
};

int main()
{
    int n_film;
    cout << "Quanti film vuoi inserire? ";
    cin >> n_film;

    // Creiamo un array di puntatori per il numero di film specificato dall'utente
    film** films = new film*[n_film];

    for (int i = 0; i < n_film; ++i)
    {
        films[i] = new film;  // Allochiamo memoria per ogni film

        int n;
        cout << "Quanto è lungo il titolo del film " << i + 1 << "? ";
        cin >> n;

        films[i]->titolo = new char[n];  // Allochiamo memoria per il titolo
        cout << "Inserisci il titolo del film " << i + 1 << ": ";
        cin >> films[i]->titolo;

        cout << "Inserisci durata (in minuti) del film " << i + 1 << ": ";
        cin >> films[i]->durata;

        cout << "Inserisci l'anno di produzione del film " << i + 1 << ": ";
        cin >> films[i]->anno;
    }

    // Mostriamo i dettagli di tutti i film
    cout << endl << "Lista dei film:" << endl; // Mostriamo i dettagli di tutti i film

    for (int i = 0; i < n_film; ++i) {
        cout << "\nFilm " << i + 1 << ":" << endl;
        cout << "Titolo: " << films[i]->titolo << endl;
        cout << "Durata: " << films[i]->durata << " minuti" << endl;
        cout << "Anno: " << films[i]->anno << endl;
    }

    // Chiedi all'utente se vuole modificare un titolo
    int scelta;
    cout << "\nVuoi cambiare il titolo di un film? (Scegli un numero da 1 a " << n_film << ", oppure 0 per uscire): ";
    cin >> scelta;

    if (scelta == 0) {
        cout << "Uscita dal programma..." << endl;
    }
    else if (scelta >= 1 && scelta <= n_film) {
        int nuovo_n;
        cout << "Inserisci la nuova lunghezza del titolo del film " << scelta << ": ";
        cin >> nuovo_n;

        // Dealloca la memoria del vecchio titolo
        delete[] films[scelta - 1]->titolo;

        // Alloca la memoria per il nuovo titolo
        films[scelta - 1]->titolo = new char[nuovo_n];
        cout << "Inserisci il nuovo titolo del film " << scelta << ": ";
        cin >> films[scelta - 1]->titolo;

        // Mostra la lista aggiornata dei film
        cout << endl << "Lista aggiornata dei film:" << endl;
        for (int i = 0; i < n_film; ++i) {
            cout << "\nFilm " << i + 1 << ":" << endl;
            cout << "Titolo: " << films[i]->titolo << endl;
            cout << "Durata: " << films[i]->durata << " minuti" << endl;
            cout << "Anno: " << films[i]->anno << endl;
        }
    }
    else {
        cout << "Scelta non valida!" << endl;
    }

    // Deallocazione della memoria
    for (int i = 0; i < n_film; ++i) {
        delete[] films[i]->titolo;
        delete films[i];
    }

    // Dealloca l'array di puntatori
    delete[] films;

    return 0;
}
