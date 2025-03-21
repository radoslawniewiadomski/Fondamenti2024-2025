#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap1(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    srand(time(NULL));

    // Creazione dell'array con numeri univoci da 0 a 9 in ordine casuale
    int a[10];
    for (int i = 0; i < 10; ++i)  a[i] = i;

    // casuale degli elementi nell'array
    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % 10;
        swap1(a[i], a[randomIndex]);
    }

   for (int i = 0; i < 10; ++i) {
        cout<<a[i]<<", ";
    }

    cout << endl;

    int num1, num2;
    cout << "Inserisci due numeri compresi tra 0 e 9: ";
    cin >> num1 >> num2;

    // Ricerca delle posizioni dei numeri nell'array
    int* ptr1 = NULL;
    int* ptr2 = NULL;

    for (int i = 0; i < 10; ++i) {
        if (a[i] == num1) ptr1 = &a[i];

        if (a[i] == num2) ptr2 = &a[i];
    }

    int distance = abs(ptr2 - ptr1);

    cout << "La distanza tra " << num1 << " e " << num2 << " nell'array e: " << distance << endl;

    return 0;
}
