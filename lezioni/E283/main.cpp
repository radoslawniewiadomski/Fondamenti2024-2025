#include <iostream>
using namespace std;

//partendo da W281 utilizzo le liste di inizialisazione

class Punto {
public:
    Punto();
    Punto(double x, double y);
    Punto(const Punto& p);
    double _x;
    double _y;
};

Punto::Punto() : _x(1.0), _y(1.0) {}

Punto::Punto(double x, double y) : _x(x), _y(y) {}

Punto::Punto(const Punto& p) : _x(p._x), _y(p._y) {}

int main(){
    Punto* arr[5];
    for(int i = 0; i < 5; i++)
        arr[i] = new Punto(i, i);

   Punto punto2;
   cout<<punto2._x<<endl;

   Punto punto3 (punto2);
   cout<<punto3._x<<endl;
}
