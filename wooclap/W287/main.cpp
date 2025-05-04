#include <iostream>
using namespace std;

class Punto {
public:
    Punto();
    Punto(double x, double y = 0.0);
    void stampa();
private:
    double _x;
    double _y;
};

Punto::Punto() : _x(-1), _y(-1) {}

Punto::Punto(double x, double y) : _x(x), _y(y) {}

void Punto::stampa() {
    cout << "Punto: (" << _x << ", " << _y << ")" << endl;
}
int main() {
    Punto p1;
    Punto p3(5.0);

    p1.stampa();
    p3.stampa();

    return 0;
}

