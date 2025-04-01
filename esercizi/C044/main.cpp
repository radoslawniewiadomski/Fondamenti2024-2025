#include <iostream>
using namespace std;


// Funzione template per lo scambio di valori utilizzando puntatori
template<typename T>
void swapValues(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
void printArray(T* arr, int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{

    const int dim = 5;

    // Definizione delle array intere e float
    float floatArr[dim] = { 1.5, 2.5, 3.5, 4.5, 5.5 };
    float intArr[dim] = { 1, 2, 3, 4, 5};

    for (int i=0; i<dim/2; i++)
        swapValues(&intArr[i], &intArr[dim-i-1]);

    for (int i=0; i<dim/2; i++)
        swapValues(&floatArr[i], &floatArr[dim-i-1]);

    printArray(intArr, dim);
    printArray(floatArr, dim);

    return 0;
}
