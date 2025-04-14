#include <iostream>
#include <cstring>

using namespace std;

class Libro {
    char* _autore;
    char* _titolo;
    int _anno;

public:
    // Costruttori
    Libro();
    Libro(const char* autore, const char* titolo, int anno);
    // Distruttore
    ~Libro();
    // Metodi di accesso
    const char* getAutore() const;
    void setAutore(const char* autore);
    const char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getAnno() const;
    void setAnno(int anno);
};

class Libreria {
    int _id;
    Libro* _libri;
    int _numLibri;

public:
    // Costruttore
    Libreria(int id);
    // Distruttore
    ~Libreria();
    // Metodo per inserire un libro nella libreria
    void inserisciLibro(const Libro& libro);
    // Metodo per ottenere il numero di libri nella libreria
    int getNumLibri() const;
};

// Definizioni dei metodi della classe Libro
Libro::Libro() : _autore(nullptr), _titolo(nullptr), _anno(0) {}

Libro::Libro(const char* autore, const char* titolo, int anno) : _anno(anno) {
    _autore = new char[strlen(autore) + 1];
    strcpy(_autore, autore);
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
}

Libro::~Libro() {
    delete[] _autore;
    delete[] _titolo;
}

const char* Libro::getAutore() const {
    return _autore;
}

void Libro::setAutore(const char* autore) {
    delete[] _autore;
    _autore = new char[strlen(autore) + 1];
    strcpy(_autore, autore);
}

const char* Libro::getTitolo() const {
    return _titolo;
}

void Libro::setTitolo(const char* titolo) {
    delete[] _titolo;
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
}

int Libro::getAnno() const {
    return _anno;
}

void Libro::setAnno(int anno) {
    _anno = anno;
}

// Definizioni dei metodi della classe Libreria
Libreria::Libreria(int id) : _id(id), _libri(nullptr), _numLibri(0) {}

Libreria::~Libreria() {
    for (int i = 0; i < _numLibri; ++i) {
        delete[] _libri[i].getAutore();
        delete[] _libri[i].getTitolo();
    }
    delete[] _libri;
}

void Libreria::inserisciLibro(const Libro& libro) {
    Libro* temp = new Libro[_numLibri + 1];
    for (int i = 0; i < _numLibri; ++i) {
        temp[i] = _libri[i];
    }
    temp[_numLibri] = libro;
    delete[] _libri;
    _libri = temp;
    _numLibri++;
}

int Libreria::getNumLibri() const {
    return _numLibri;
}

int main() {
    int numLibri;

    cout << "Quanti libri contiene la libreria? ";
    cin >> numLibri;

    Libreria libreria(1); // Creiamo una libreria con ID 1

    for (int i = 0; i < numLibri; ++i) {
        char autore[100];
        char titolo[100];
        int anno;

        cout << "Inserisci autore del libro " << i + 1 << ": ";
        cin >> autore;

        cout << "Inserisci titolo del libro " << i + 1 << ": ";
        cin >> titolo;

        cout << "Inserisci anno di stampa del libro " << i + 1 << ": ";
        cin >> anno;

        Libro libro;
        libro.setAutore(autore);
        libro.setTitolo(titolo);
        libro.setAnno(anno);

        libreria.inserisciLibro(libro);
    }

    cout << "La libreria contiene " << libreria.getNumLibri() << " libri." << endl;

    return 0;
}

