#include <iostream>
using namespace std;
struct t
//ATTENZIONE IL CODICE E SBAGLIATO

{
    int x;
    float y;
    float z;
};


int main()
{
    int x = 10;
    t t1;
    int* px = &x; // puntatore a un intero

    t* pt1 = &t1; //puntatore a una struttura

    cout << "Indirizzo a cui punta px: " << px << endl;

    cout << "Indirizzo a cui punta pt1: " << pt1 << endl;

    cout<<*px<<endl;

    px = pt1; //ERRORE!!!

    return 0;
}
