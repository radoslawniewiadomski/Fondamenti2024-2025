#include <iostream>
using namespace std;

class film
{
public:

    char _titolo [20];
    int _durata;
    int _anno;
    void stampaFilm();
};

void film::stampaFilm()
{
    cout << "Titolo: " << _titolo << endl;
    cout << "Durata: " << _durata << " minuti" << endl;
    cout<< "Anno: " << _anno << endl;
}

int main()
{
    film p;
    cout << "Inserisci il titolo (max 20 char): " ;
    cin >>  p._titolo;
    cout << "Inserisci durata: ";
    cin >> p._durata;
    cout << "Inserisci anno: ";
    cin >> p._anno;

    p.stampaFilm();
    return 0;
}



