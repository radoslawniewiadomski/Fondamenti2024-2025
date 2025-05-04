#include <iostream>
using namespace std;

class Punto{
    double _x;
    double _y;

public:
    Punto();
    Punto(double x, double y);
    Punto(const Punto &p);

    Punto& operator++();
    Punto operator++(int);
    Punto operator-();
    void stampaPunto();
};

Punto::Punto(const Punto &p){
    _x=p._x;
    _y=p._y;
}

Punto::Punto() {
    _x = -1;
    _y = -1;
}

Punto::Punto(double x, double y) {
    _x = x;
    _y = y;
}

void Punto::stampaPunto() {
    cout << "Coordinate: (" <<_x << ", " <<_y << ")"<< endl;
}

Punto& Punto::operator++(){
    _x += 1.0;
    _y += 1.0;
    return *this;
}

Punto Punto::operator++(int){
    Punto temp(*this);
    _x += 1.0;
    _y += 1.0;
    return temp;
}

Punto Punto::operator-(){
    return Punto(-_x, -_y);
}

int main(){


    Punto p(3.0, 2.0);
    cout <<" p = ";
    p.stampaPunto();

    Punto q =-p++;
    cout <<" q = ";
    q.stampaPunto();
    cout <<" p = ";
    p.stampaPunto();

    Punto z =-++p;
    cout <<" z = ";
    z.stampaPunto();
    //cout <<" p = ";
    //p.stampaPunto();


    int pi=3;
    int qi=-pi++;
    cout << "qi= " << qi <<endl;
    cout << "pi= " << pi <<endl;

    int zi=-++pi;
    cout << "zi= " << zi <<endl;
    cout << "pi= " << pi <<endl;


    return 0;
}
