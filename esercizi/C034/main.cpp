#include <iostream>
#include <cstring>
using namespace std;

// Definiamo una struttura per rappresentare una macchina
struct Macchina {
    char tipo[30];   // Tipo di macchina
    char marca[30];  // Marca della macchina
    char targa[7];   // Targa della macchina
    double anno;   // Anno della macchina
};


// Funzione per inserire i dati delle macchine
void inseriscidati(Macchina* inventario) {

        cout << "Marca: ";
        cin >> inventario->marca;
        cout << "Tipo: ";
        cin >> inventario->tipo;
        cout << "Targa: ";
        cin >> inventario->targa;
        cout << "Anno: ";
        cin >> inventario->anno;
        cout << endl;

}

// Funzione per stampare l'inventario delle macchine
void stampa(Macchina* inventario) {
        cout << "Marca: " << (inventario)->marca << endl;
        cout << "Tipo: " << (inventario)->tipo << endl;
        cout << "Targa: " << (inventario)->targa << endl;
        cout << "Anno: " << (inventario)->anno << endl;
        cout << "------------------------------\n";

}

int main() {

    const int n=3;

    // Allocazione dinamica dell'array di strutture per memorizzare le macchine
    Macchina *inventario [n];

    for (int i = 0; i < n; i++) {
        inventario[i] = new Macchina;
        cout << "Inserisci i dati per la macchina " << i + 1 << ":\n";
        inseriscidati(inventario[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << "Macchina " << i + 1 << ":\n";
        stampa(inventario[i]);
    }

    for (int i = 0; i < n; i++) {
        delete inventario[i];
    }

    return 0;
}
