#include <iostream>
#include <cstring>
using namespace std;

// Definiamo una struttura per rappresentare una macchina
struct Macchina {
    char tipo[30];   // Tipo di macchina
    char marca[30];  // Marca della macchina
    char targa[7];   // Targa della macchina
    double anno;     // Anno della macchina
};

// Funzione per inserire i dati delle macchine
void inseriscidati(Macchina* macchina) {
    cout << "Tipo: ";
    cin >> macchina->tipo;
    cout << "Marca: ";
    cin >> macchina->marca;
    cout << "Targa: ";
    cin >> macchina->targa;
    cout << "Anno: ";
    cin >> macchina->anno;
    cout << endl;
}

// Funzione per stampare l'inventario delle macchine
void stampa(Macchina* macchina) {
    cout << "Tipo: " << macchina->tipo << endl;
    cout << "Marca: " << macchina->marca << endl;
    cout << "Targa: " << macchina->targa << endl;
    cout << "Anno: " << macchina->anno << endl;
    cout << "------------------------------\n";
}

int main() {
    int n;

    // Chiediamo all'utente il numero di macchine da inserire
    cout << "Quante macchine vuoi inserire nell'inventario? ";
    cin >> n;

    // Allocazione dinamica dell'array di puntatori per memorizzare le macchine
    Macchina** inventario = new Macchina*[n];  // Array di puntatori a Macchina

    // Inserimento dei dati per ciascuna macchina
    for (int i = 0; i < n; i++) {
        inventario[i] = new Macchina;  // Allocazione dinamica per ciascuna macchina
        cout << "Inserisci i dati per la macchina " << i + 1 << ":\n";
        inseriscidati(inventario[i]);  // Passiamo il puntatore alla struttura
    }

    // Stampa dell'inventario delle macchine
    for (int i = 0; i < n; i++) {
        cout << "Macchina " << i + 1 << ":\n";
        stampa(inventario[i]);  // Passiamo il puntatore alla struttura
    }

    // Deallocazione della memoria
    for (int i = 0; i < n; i++) {
        delete inventario[i];  // Dealloca ogni singola macchina
    }
    delete[] inventario;  // Dealloca l'array di puntatori

    return 0;
}

