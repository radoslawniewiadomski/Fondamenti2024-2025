#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Studente
{
    char* nome;
    char* cognome;
    int voto;
    ifstream* file;

public:
    // Costruttore con file
    Studente(ifstream& file);
    // Distruttore
    ~Studente();
    // Metodo per stampare i dati dello studente
    void stampaDati() const;
};

// Implementazione del costruttore con file
Studente::Studente(ifstream& file) : file(&file)
{
    if (file.is_open())
    {
        char buffer[256];  // Buffer temporaneo per leggere da file

        // Lettura del nome
        file.getline(buffer, 256);
        nome = new char[strlen(buffer) + 1];
        strcpy(nome, buffer);

        // Lettura del cognome
        file.getline(buffer, 256);
        cognome = new char[strlen(buffer) + 1];
        strcpy(cognome, buffer);

        // Lettura del voto
        file >> voto;
        file.ignore(); // Ignora il newline residuo

        if (file.fail())
        {
            cerr << "Errore nella lettura del voto." << endl;
        }
    }
    else
    {
        cerr << "Impossibile aprire il file." << endl;
    }
}

// Distruttore
Studente::~Studente()
{
    cout << "Distruttore chiamato per lo studente " << nome << " " << cognome << endl;
    delete[] nome;
    delete[] cognome;
    file->close();
}

// Metodo per stampare i dati dello studente
void Studente::stampaDati() const
{
    cout << "Nome: " << nome << endl;
    cout << "Cognome: " << cognome << endl;
    cout << "Voto: " << voto << endl;
}

int main()
{
    ifstream inputFile("d:\\studenti.txt");

    if (!inputFile.is_open())
    {
        cerr << "Impossibile aprire il file." << endl;
        return 1;
    }

    Studente studente(inputFile);

    studente.stampaDati();

    return 0;
}

