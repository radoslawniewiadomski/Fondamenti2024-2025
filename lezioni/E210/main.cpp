#include <iostream>

using namespace std;

int main()
{
   int i, j;

   int* p;
   int* q;

   p = &i; 	// p = indirizzo di i

   *p = 3; 	// equivale a i = 3

   j = *p; 	// equivale a j = i

   q = p; 	// assegna a q l'indirizzo di i

   cout << i << ", "<<j<<endl;

   cout << *p << ", "<<*q;
}
