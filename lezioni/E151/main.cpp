#include "film.h"
#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;

#include "List.h"


// le fuzioni amiche

ostream& operator<<(ostream& os, const film& film)
{
    os << endl << " Titolo: " << film._titolo << ", Durata: " << film._durata << " minuti, Anno: " << film._anno << endl;
    return os;
}

/*
istream& operator>>(istream& is, film& film)
{
    char temp[100];
    is >> temp;
    film._titolo = new char[strlen(temp) + 1];
    strcpy(film._titolo, temp);
    is >> film._durata >> film._anno;
    return is;
}
*/

int main()
{
    List<film> l; // dichiarazione di oggetto lista

    // inserimento di nodi

    l.insertFront(film("Matrix",120,1999));
    l.insertFront(film("Pirates",125,2010));

    cout<<endl<<"Prima versione della lista - insert front"<<endl;
    l.print();
    cout<<endl;

    cout<<endl<<"Seconda versione della lista - insert back"<<endl;
    l.insertBack(film("Godfather",145,1975));
    l.print();
    cout<<endl;

    cout<<endl<<"Terza versione della lista - insert after Pirates"<<endl;
    l.insertAfter(l.find(film("Pirates",125,2010)), film("Jaws",105,1970));
    l.print();
    cout<<endl;

    cout<<endl<<"Quarta versione della lista - remove front"<<endl;
    l.removeFront();
    l.print();
    cout<<endl;

    cout<<endl<<"Quinta versione della lista - remove back"<<endl;
    l.removeBack();
    l.print();
    cout<<endl;

    return 0;	// distruzione della lista
}

