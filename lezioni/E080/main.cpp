#include <iostream>
#include <cstring>
using namespace std;
class Punto
{
    double _x;
    double _y;
    char  c [20];

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
    strcpy(c,"Uno");
}

void Punto::cambiaNome(char *x)
{
    strcpy(c,x);
}

void Punto::stampaNome()
{
    cout<<c;
}

int main()
{
    Punto punto1;
    punto1.cambiaNome("Due");
    Punto punto2;

    punto2.cambiaNome("Tre");
    punto2=punto1;

    punto1.cambiaNome("Quattro");
    punto2.stampaNome();
    return 0;
}
