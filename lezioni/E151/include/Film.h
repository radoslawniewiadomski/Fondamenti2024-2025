#include <iostream>
using namespace std;

#ifndef FILM_H
#define FILM_H

class film {
    char* _titolo;
    int _durata;
    int _anno;

public:
    // Costruttori
    film();
    film(char* titolo, int durata, int anno);
    // Costruttore di copia
    film(const film& otherFilm);
    // Distruttore
    ~film();

    // Selettori e modificatori
    char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);

    bool operator==(const film& film1) const;

    friend ostream& operator<<(ostream& os, const film& film);
    //friend istream& operator>>(istream& is, film& film);

    void stampaFilm();
};


#endif // FILM_H
