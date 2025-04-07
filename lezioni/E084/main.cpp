#include <iostream>
using namespace std;

class Punto {
public:
    Punto();                     // Costruttore di default
    Punto(double x, double y);    // Costruttore con parametri
    const double _x;              // Membri const
    const double _y;
};

Punto::Punto() : _x(1.0), _y(1.0) {}  // Inizializzazione tramite lista di inizializzazione

Punto::Punto(double x, double y) : _x(x), _y(y) {}  // Inizializzazione tramite lista di inizializzazione


/*
QUESTO è un errore, non è possibile inizializzare atributi const nel corpo del costruttore
Punto::Punto()
{
    _x = 1.0;
    _y = 1.0;
}


Punto::Punto(double x, double y){
    _x = x;
    _y = y;
}
*/

int main() {
    Punto punto1;                // Oggetto con il costruttore di default
    Punto punto2(3, 4);          // Oggetto con il costruttore con parametri

    cout << "punto1: (" << punto1._x << ", " << punto1._y << ")\n";
    cout << "punto2: (" << punto2._x << ", " << punto2._y << ")\n";

    return 0;
}

