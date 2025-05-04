#include <iostream>
#include <cstring>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//classe Person

class Person
{
    char _nome[32];
    char _cognome[32];
public:
    Person(const char* nome, const char* cognome);
    Person();
    void stampa() const;


};

Person::Person()
{
    strcpy(_nome, "N/D");
    strcpy(_cognome, "N/D");
}

Person::Person(const char* nome, const char* cognome)
{
    strcpy(_nome, nome);
    strcpy(_cognome, cognome);
}

void Person::stampa() const
{
    cout << "Nome: " << _nome << ", Cognome: " << _cognome << endl;
}


////////////////////////////////////////////////////////////
//classe Film

class Film
{
    char* _titolo;
    int _durata;
    int _anno;

public:
    // Costruttori
    Film();
    Film(const char* titolo, int durata, int anno);
    // Costruttore di copia
    Film(const Film& otherFilm);
    // Distruttore
    ~Film();


    // Selettori e modificatori
    const char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);

    void stampa() const;
};

// Definizioni delle funzioni
Film::Film()
{
    _titolo = new char[4];
    strcpy(_titolo, "N/D");
    _durata = 0;
    _anno = 0;
}

Film::Film(const char* titolo, int durata, int anno)
{
    this->_titolo = new char[strlen(titolo) + 1];
    strcpy(this->_titolo, titolo);
    this->_durata = durata;
    this->_anno = anno;
}

Film::Film(const Film& otherFilm)
{
    _titolo = new char[strlen(otherFilm._titolo) + 1];
    strcpy(_titolo, otherFilm._titolo);
    _durata = otherFilm._durata;
    _anno = otherFilm._anno;
}

Film::~Film()
{
    delete[] _titolo;
}

const char* Film::getTitolo() const
{
    return _titolo;
}

void Film::setTitolo(const char* titolo)
{
    delete[] this->_titolo;
    this->_titolo = new char[strlen(titolo) + 1];
    strcpy(this->_titolo, titolo);
}

int Film::getDurata() const
{
    return _durata;
}

void Film::setDurata(int durata)
{
    this->_durata = durata;
}

int Film::getAnno() const
{
    return _anno;
}

void Film::setAnno(int anno)
{
    this->_anno = anno;
}

void Film::stampa() const
{
    cout << "Titolo: " << _titolo << endl;
    cout << "Durata: " << _durata << " minuti" << endl;
    cout << "Anno: " << _anno << endl;
}


////////////////////////////////////////////////////
//Il template di classe Coppia

template <typename T, typename U>
class Coppia {
    T primo;
    U secondo;

public:
    Coppia(T p, U s) : primo(p), secondo(s) {}
    void stampaCoppia();

    template <typename Z>
    void stampaOggetto(const Z& oggetto);
};

template <typename T, typename U>
 void Coppia<T, U>::stampaCoppia() {
    cout << "Primo elemento: ";
    stampaOggetto(primo);
    cout << "Secondo elemento: ";
    stampaOggetto(secondo);
}

//esempio di template di funzione "dentro" un template di classe

template <typename T, typename U>
template <typename Z>
 void Coppia<T, U>::stampaOggetto(const Z& oggetto) {
    oggetto.stampa();
}

int main()
{
    cout<<"La prima coppia:"<<endl;
    Coppia<Film, Person> coppia1(Film("Shrek",120,2000),Person("Mary", "Smith"));
    coppia1.stampaCoppia();


    cout<<"La seconda coppia:"<<endl;
    Coppia<Person, Film> coppia2(Person("John", "Smith"),Film("Jaws",120,1970));
    coppia2.stampaCoppia();

    return 0;
}
