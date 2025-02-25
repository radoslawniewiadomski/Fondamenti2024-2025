#include <iostream>
#include <cstring>

using namespace std;


//Si scriva la funzione C++ cerca che riceva come parametri il puntatore al primo elemento di una stringa str1 e il puntatore al primo elemento di una seconda stringa str2.
//Utilizzando l’aritmetica dei puntatori, la funzione dovrà scandire la stringa str1 e restituire, come valore di ritorno, il puntatore alla prima occorrenza della sottostringa str2 in str1. Nel caso in cui la sottostringa str2 non occorra in str1, la funzione restituirà NULL.
//Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma chiederà all’utente di immettere da tastiera due stringhe, chiamerà la funzione cerca per verificare se la seconda stringa occorre all’interno della prima e stamperà a video, in caso di esito positivo, la stringa str1 a partire dal carattere puntato dal puntatore restituito dalla funzione cerca e fino al suo termine.
//In caso di esito negativo della verifica, il programma stamperà a video un opportuno messaggio.




// Funzione per cercare la sottostringa str2 in str1 usando aritmetica dei puntatori
char* cerca(char* str1, char* str2)
{
    char *p1, *p2, *p_start;

    // Scansiona str1
    for (p1 = str1; *p1 != '\0'; p1++)
    {
        p_start = p1; // Salva la posizione attuale
        p2 = str2;

        // Controlla se la sottostringa coincide
        while (*p1 == *p2 && *p2 != '\0')
        {
            p1++;
            p2++;
        }

        // Se siamo arrivati alla fine di str2, significa che l'abbiamo trovata in str1
        if (*p2 == '\0')
        {
            return p_start;
        }

        // Reset p1 alla posizione iniziale del ciclo for
        p1 = p_start;
    }

    return nullptr; // Sottostringa non trovata
}


int main()
{
    char str1[100], str2[100];

    cout << "Inserisci la stringa principale: ";
    cin >> str1;

    cout << "Inserisci la sottostringa da cercare: ";
    cin >> str2;


    char* risultato = cerca(str1, str2);

    // Verifica del risultato
    if (risultato != nullptr)
    {
        cout << "Sottostringa trovata: " << risultato << endl;
    }
    else
    {
        cout << "Sottostringa non trovata." << endl;
    }

    return 0;
}
