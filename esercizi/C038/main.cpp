#include <iostream>
#include <cstring>
using namespace std;

// Funzione ricorsiva per verificare se la parola è palindroma
bool isPalindroma(const char* parola, int inizio, int fine) {
    // Caso base: se l'inizio supera la metà della parola, è palindroma
    if (inizio >= fine) {
        return true;
    }

    // Se i caratteri alle posizioni inizio e fine non sono uguali, non è palindroma
    if (parola[inizio] != parola[fine]) {
        return false;
    }

    // Chiamata ricorsiva per controllare i caratteri successivi
    return isPalindroma(parola, inizio + 1, fine - 1);
}

int main() {
    char parola[100];

    // Acquisizione della parola dall'utente
    cout << "Inserisci una parola: ";
    cin >> parola;

    int lunghezza = strlen(parola);

    // Verifica se la parola è palindroma
    if (isPalindroma(parola, 0, lunghezza - 1)) {
        cout << "La parola è palindroma." << endl;
    } else {
        cout << "La parola non è palindroma." << endl;
    }

    return 0;
}
