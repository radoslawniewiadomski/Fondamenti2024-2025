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
    cout<<endl<<"Lista "<<endl; // Mostriamo i dettagli di tutti i film


    for (int i = 0; i < n_film; ++i) {
        cout << "\nFilm " << i + 1 << ":" << endl;
        cout << "Titolo: " << films[i]->titolo << endl;
        cout << "Durata: " << films[i]->durata << " minuti" << endl;
        cout << "Anno: " << films[i]->anno << endl;
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
