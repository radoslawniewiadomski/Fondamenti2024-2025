#include <iostream>
using namespace std;


template <typename W, typename S>
S f2 (W x) {
  int z = x/2;
  return z;
}


//soluzione del problema
int main() {

 double d1=3.9;

 //int d2 = f2(d1) ;
 int d2 = f2<int,double>(d1); //esplicitamente indico dei tipi

 cout<<d2;
 return 0;
}
