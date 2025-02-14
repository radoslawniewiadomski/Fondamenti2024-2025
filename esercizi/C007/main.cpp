#include <iostream>
#include <string>
using namespace std;

struct Studente
{
    string nome;
    int voto;
};

int main()
{
    // Array di 5 studenti
    Studente studenti[5] =
    {
        {"Mario", 75},
        {"Luigi", 88},
        {"Anna", 92},
        {"Giulia", 80},
        {"Giovanni", 70}
    };

    // Riferimento al miglior voto
    Studente& migliore = studenti[0];  // Inizializziamo con il primo studente

    // Trova lo studente con il voto più alto
    for (int i = 1; i < 5; i++)
    {
        if (studenti[i].voto > migliore.voto)
        {
            migliore = studenti[i];
        }
    }

    // Incrementa il voto dello studente con il voto più alto
    migliore.voto++;

    // Stampa lo studente con il voto più alto dopo l'incremento
    cout << "Lo studente con il voto piu' alto (dopo incremento) è: "
         << migliore.nome << " con voto " << migliore.voto << endl;


    return 0;
}
