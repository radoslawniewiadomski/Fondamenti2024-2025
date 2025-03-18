#include <iostream>
#include <cstring>
using namespace std;

// Definiamo una struttura per rappresentare una macchina
struct Macchina
{
    char tipo[30];   // Tipo di macchina
    char marca[30];  // Marca della macchina
    char targa[7];   // Targa della macchina
    double anno;     // Anno della macchina
};

// Funzione per inserire i dati delle macchine
void inseriscidati(Macchina* inventario)
{
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
void stampa(Macchina* inventario)
{
    cout << "Marca: " << (inventario)->marca << endl;
    cout << "Tipo: " << (inventario)->tipo << endl;
    cout << "Targa: " << (inventario)->targa << endl;
    cout << "Anno: " << (inventario)->anno << endl;
    cout << "------------------------------\n";
}

// Funzione per aggiungere una macchina all'inventario
void aggiungiMacchina(Macchina**& inventario, int& n)
{
    Macchina** nuovoInventario = new Macchina*[n + 1]; // Nuovo array con un elemento in più

    // Copia tutte le macchine esistenti nel nuovo array
    for (int i = 0; i < n; i++)
    {
        nuovoInventario[i] = inventario[i];  // Copia le macchine esistenti nel nuovo array
    }

    // Dealloca il vecchio array di puntatori
    delete[] inventario;

    inventario = nuovoInventario;  // Assegna il nuovo array

    // Inserisci la nuova macchina
    inventario[n] = new Macchina; // Alloca la memoria per una nuova macchina
    cout << "Inserisci i dati per la nuova macchina:\n";
    inseriscidati(inventario[n]);  // Inserisce i dati della nuova macchina
    n++;  // Incrementa la dimensione dell'inventario
}

// Funzione per cancellare una macchina dall'inventario in base alla targa
void cancellaMacchina(Macchina**& inventario, int& n, const char* targa)
{
    int index = -1;

    // Trova l'indice della macchina con la targa corrispondente
    for (int i = 0; i < n; i++)
    {
        if (strcmp(inventario[i]->targa, targa) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Macchina con targa " << targa << " non trovata.\n";
        return;
    }

    // Crea un nuovo array per l'inventario senza la macchina da rimuovere
    Macchina** nuovoInventario = new Macchina*[n - 1];
    for (int i = 0, j = 0; i < n; i++)
    {
        if (i != index)
        {
            nuovoInventario[j++] = inventario[i];  // Copia solo le macchine che non sono da rimuovere
        }
    }

    // Dealloca la memoria dell'array vecchio
    delete[] inventario;

    inventario = nuovoInventario;  // Assegna il nuovo array
    n--;  // Decrementa la dimensione dell'inventario
    cout << "Macchina con targa " << targa << " è stata rimossa dall'inventario.\n";
}

int main()
{
    int n;

    // Chiediamo all'utente il numero di macchine da inserire inizialmente
    cout << "Quante macchine vuoi inserire nell'inventario? ";
    cin >> n;

    // Allocazione dinamica dell'array di puntatori per memorizzare le macchine
    Macchina** inventario = new Macchina*[n];  // Array di puntatori a Macchina

    // Inserimento dei dati per ciascuna macchina
    for (int i = 0; i < n; i++)
    {
        inventario[i] = new Macchina;  // Allocazione dinamica per ciascuna macchina
        cout << "Inserisci i dati per la macchina " << i + 1 << ":\n";
        inseriscidati(inventario[i]);  // Passiamo il puntatore alla struttura
    }

    // Stampa dell'inventario delle macchine
    cout << "\nInventario iniziale:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Macchina " << i + 1 << ":\n";
        stampa(inventario[i]);  // Passiamo il puntatore alla struttura
    }

    // Ciclo per aggiungere o rimuovere macchine
    char scelta;
    do
    {
        cout << "Vuoi aggiungere una macchina (A), rimuoverne una (R)? (A/R) o uscire (E): ";
        cin >> scelta;

        if (scelta == 'A' || scelta == 'a')
        {
            aggiungiMacchina(inventario, n);  // Aggiungi una macchina
        }
        else if (scelta == 'R' || scelta == 'r')
        {
            char targa[7];
            cout << "Inserisci la targa della macchina da rimuovere: ";
            cin >> targa;
            cancellaMacchina(inventario, n, targa);  // Cancella una macchina
        }
        else if (scelta == 'E' || scelta == 'e')
        {
            cout << "Uscita dal programma.\n";
        }


    }
    while (scelta != 'E' && scelta != 'e');

    // Stampa l'inventario finale
    cout << "\nInventario finale:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Macchina " << i + 1 << ":\n";
        stampa(inventario[i]);
    }

    // Deallocazione della memoria
    for (int i = 0; i < n; i++)
    {
        delete inventario[i];  // Dealloca ogni singola macchina
    }
    delete[] inventario;  // Dealloca l'array di puntatori

    return 0;
}

