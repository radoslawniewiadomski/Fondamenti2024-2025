#include <iostream>
using namespace std;


// Funzione per inserire un carattere in una posizione specifica
char* insert_char(char* arr, int& size, int pos, char c) {

    // Creiamo un nuovo array di dimensione maggiore
    char* newArr = new char[size + 1];

    // Copiamo gli elementi prima della posizione di inserimento
    for (int i = 0; i < pos; i++) {
        newArr[i] = arr[i];
    }

    // Inseriamo il nuovo carattere
    newArr[pos] = c;

    // Copiamo gli elementi successivi alla posizione di inserimento
    for (int i = pos; i < size; i++) {
        newArr[i + 1] = arr[i];
    }

    // Aumentiamo la dimensione dell'array
    size++;

    // Dealloca la memoria dell'array originale
    delete[] arr;

    // Restituiamo il nuovo array
    return newArr;
}

// Funzione per cancellare un carattere in una posizione specifica
char* delete_char(char* arr, int& size, int pos) {
    // Creiamo un nuovo array di dimensione minore
    char* newArr = new char[size - 1];

    // Copiamo gli elementi prima della posizione di cancellazione
    for (int i = 0; i < pos; i++) {
        newArr[i] = arr[i];
    }

    // Copiamo gli elementi successivi alla posizione di cancellazione
    for (int i = pos + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }

    // Diminuiamo la dimensione dell'array
    size--;

    // Dealloca la memoria dell'array originale
    delete[] arr;

    // Restituiamo il nuovo array
    return newArr;
}

int main() {
    int n;

    // Chiediamo all'utente quanti elementi desidera nell'array
    cout << "Quanti elementi vuoi inserire nell'array di caratteri? ";
    cin >> n;

    // Allocazione dinamica dell'array
    char* arr = new char[n];

    // Chiediamo all'utente di inserire i caratteri uno alla volta
    cout << "Inserisci " << n << " caratteri: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Carattere " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Stampa l'array iniziale
    cout << "L'array inserito è: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Chiediamo all'utente dove vuole inserire un nuovo carattere
    int pos;
    char newChar;
    cout << "Dopo quale posizione vuoi inserire un nuovo carattere (1 -" << n << ")? ";
    cin >> pos;
    cout << "Inserisci il nuovo carattere: ";
    cin >> newChar;

    // Inseriamo il nuovo carattere nell'array
    arr = insert_char(arr, n, pos, newChar);

    // Stampa l'array aggiornato dopo l'inserimento
    cout << "L'array dopo l'inserimento: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Chiediamo all'utente quale elemento vuole cancellare
    int delPos;
    cout << "Quale posizione vuoi cancellare (1 -" << n << ")? ";
    cin >> delPos;

    // Cancelliamo l'elemento scelto
    arr = delete_char(arr, n, delPos-1);

    // Stampa l'array aggiornato dopo la cancellazione
    cout << "L'array dopo la cancellazione: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deallocazione della memoria
    delete[] arr;

    return 0;
}
