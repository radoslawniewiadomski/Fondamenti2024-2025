#include <iostream>
using namespace std;

int main() {
   int* p [3];

   for (int i=0;i < 3; i++){
     int temp;
     cin >> temp;
     p[i] = &temp;
   }

   for (int i=0;i < 3; i++){
        cout << *p[i];
   }

   for (int i=0;i < 3; i++){
        cout << p[i]<<", ";
   }

}
