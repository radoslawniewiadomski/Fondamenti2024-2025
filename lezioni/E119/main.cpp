#include <iostream>
#include <cstring>
using namespace std;

class Impiegato {
private:
    char _nome[32];
    char _cognome[32];
public:
    Impiegato(const char* nome, const char* cognome);
    Impiegato();

    // Operatore ">" sovraccaricato per confrontare due impiegati in base al cognome
    bool operator>(const Impiegato& imp) const;

    void stampa() const;
};

Impiegato::Impiegato() {
    strcpy(_nome, "N/D");
    strcpy(_cognome, "N/D");

}

Impiegato::Impiegato(const char* nome, const char* cognome) {
    strcpy(_nome, nome);
    strcpy(_cognome, cognome);
}

bool Impiegato::operator>(const Impiegato& imp) const {
    if (strcmp(_cognome, imp._cognome) > 0) return true;
     return false;
}

void Impiegato::stampa() const {
    cout << "Nome: " << _nome << ", Cognome: " << _cognome << endl;
}


/////////////////////////////////////////////////////////

template<typename T>
void BubbleSort (T v[], int n) {
	int i, j;
	T tmp;
	for (i = n - 1; i > 0; i--)
		for (j = 0; j < i; j++)
      		if (v[j] > v[j+1]) {
				tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
	}
}


/////////////////////////////////////////////////////////


int main() {
    int a[5] = {3, 2, 6, 1, 4};
    Impiegato imp[3] = {{"Mario", "Rossi"}, {"Paola", "Bianchi"}, {"Riccardo", "Bianccardi"}};

    cout << "Prima di ordinare:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; ++i) {
        imp[i].stampa();
    }

    BubbleSort<int>(a, 5);

    BubbleSort<Impiegato>(imp, 3);

    cout << "\nDopo l'ordinamento:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; ++i) {
        imp[i].stampa();
    }

    return 0;
}
