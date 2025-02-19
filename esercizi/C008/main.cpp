#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

// Definiamo il numero di squadre e il numero di partite per squadra
const int NUM_SQUADRE = 8;

// Funzione per calcolare i punti di una squadra
int calcolaPunti(int risultati[][NUM_SQUADRE], int squadraIndex)
{
    int punti = 0; // Inizializziamo i punti della squadra a 0
    for (int i = 0; i < NUM_SQUADRE; ++i)
    {
        // Ignoriamo il confronto con la stessa squadra
        if (i != squadraIndex)
        {
            // Se la squadra ha vinto (i punti segnati sono maggiori dei punti subiti), aggiungiamo 3 punti
            if (risultati[squadraIndex][i] > risultati[i][squadraIndex]) punti += 3;
            // Se la partita è terminata in pareggio, aggiungiamo 1 punto
            else if (risultati[squadraIndex][i] == risultati[i][squadraIndex]) punti += 1;
        }
    }
    return punti; // Restituiamo i punti ottenuti dalla squadra
}

int main()
{
 const char squadre[NUM_SQUADRE][10] = {
    "Squadra 1", "Squadra 2", "Squadra 3", "Squadra 4",
    "Squadra 5", "Squadra 6", "Squadra 7", "Squadra 8"
};
    // Matrice dei risultati delle partite (inizializzata a 0)
    int risultati[NUM_SQUADRE][NUM_SQUADRE] = {{0}};

    // Impostiamo il seme per la generazione di numeri casuali, utilizzando l'ora corrente
    srand(time(NULL));

    // Simuliamo i risultati delle partite tra le squadre
    for (int i = 0; i < NUM_SQUADRE; ++i)
    {
        for (int j = i + 1; j < NUM_SQUADRE; ++j)
        {
            // Generiamo un punteggio casuale da 0 a 4 per entrambe le squadre
            risultati[i][j] = rand() % 5; // Risultato per la partita i vs j
            risultati[j][i] = rand() % 5; // Risultato per la partita j vs i
            // Stampa dei risultati delle partite
            cout << squadre[i] << " vs " << squadre[j] << " : " << risultati[i][j] << " : " << risultati[j][i] << endl;
        }
    }


    // Array per memorizzare i punti, le reti fatte e le reti subite di ogni squadra
    int punti[NUM_SQUADRE] = {0};
    int retiFatte[NUM_SQUADRE] = {0};
    int retiSubite[NUM_SQUADRE] = {0};

    // Calcoliamo i punti e le reti per ogni squadra
    for (int i = 0; i < NUM_SQUADRE; ++i)
    {
        // Calcoliamo i punti per ogni squadra
        punti[i] = calcolaPunti(risultati, i);
        for (int j = 0; j < NUM_SQUADRE; ++j)
        {
            // Calcoliamo le reti fatte e subite da ciascuna squadra
            retiFatte[i] += risultati[i][j];
            retiSubite[i] += risultati[j][i];
        }
    }

    // Determiniamo la squadra vincente
    int squadraVincenteIndex = 0; // Indice della squadra vincente
    for (int i = 1; i < NUM_SQUADRE; ++i)
    {
        // Confrontiamo i punti delle squadre, se sono uguali consideriamo la differenza reti
        if (punti[i] > punti[squadraVincenteIndex] ||
                (punti[i] == punti[squadraVincenteIndex] && retiFatte[i] - retiSubite[i] > retiFatte[squadraVincenteIndex] - retiSubite[squadraVincenteIndex]))
        {
            squadraVincenteIndex = i; // Aggiorniamo l'indice della squadra vincente
        }
    }

    // Stampa dei risultati finali
    cout << "Risultati Finali:" << endl;
    cout << "Squadra\t\tPunti\tReti Fatte\tReti Subite" << endl;
    for (int i = 0; i < NUM_SQUADRE; ++i)
    {
        // Stampa delle informazioni per ogni squadra
        cout << squadre[i] << "\t\t" << punti[i] << "\t" << retiFatte[i] << "\t\t" << retiSubite[i] << endl;
    }

    // Stampa della squadra vincente
    cout << "La squadra vincente e: " << squadre[squadraVincenteIndex] << endl;

    return 0;
}
