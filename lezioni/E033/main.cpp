#include <iostream>
using namespace std;

struct film
{
    int id;
    char titolo[50];
    int durata;
    int anno;
};

int main()
{
    film *p;
    film film1;

    cout << "Inserisci il titolo (senza spazi): ";
    cin >> film1.titolo;
    cout << "Inserisci durata  (in minuti): ";
    cin >> film1.durata;
    cout << "Inserisci anno di produzione: ";
    cin >> film1.anno;


    p=&film1;

    cout << "Titolo: " << p->titolo << endl;
    cout << "Durata: " << p->durata << endl;
    cout << "Anno: " << p->anno << endl;
    return 0;
}
