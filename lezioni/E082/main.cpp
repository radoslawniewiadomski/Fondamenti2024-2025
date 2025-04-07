#include <iostream>
#include <cstring>
using namespace std;
class Punto
{
    double _x;
    double _y;
    char * c;

public:
    Punto();
    Punto(double x, double y);
    void cambiaNome(char *x);
    void stampaNome ();
};

Punto::Punto()
{
    _x = 0.0;
    _y = 0.0;
    c = new char [20];
    strcpy(c,"Uno");
}

void Punto::cambiaNome(char *x)
{
    delete[] c;
    c = new char[strlen(x) + 1];
    strcpy(c, x);
}

void Punto::stampaNome() {
    cout<<c;
}

int main() {
    Punto punto1;
    punto1.cambiaNome("Due");
    Punto punto2;

    punto2.cambiaNome("Tre");
    punto2=punto1;

    punto1.cambiaNome("Quattro");
    punto2.stampaNome();
    return 0;
}
