#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* funzione che restituisce 1 oppure 0 se il parametro è un numero primo oppure no */
int isPrimo(int numero) {
      // pre: numero e' un intero positivo
      int nessunDivisore;            // vale 1 fintanto che non hai trovato nessun divisore di numero
                                     // vale 0 quando hai trovato divisore di numero
      int i;                                    //variabile contatore

      /* all'inizio non hai trovato nessun divisore di numero */
      nessunDivisore = 1;
      /* il primo possibile divisore di numero e' 2 */
      i=2;

      /* guarda tutti i numeri fino a numero -1; interrompi se trovi un divisore */
      while(i<=numero-1 && nessunDivisore)
            /* il numero corrente e' un divisore? */
            if(numero%i==0)
                  nessunDivisore = 0;
            else  // altrimenti passa al prossimo numero
                   i++;

      return nessunDivisore;
}

/* funzione che stampa ripetutamente numeri random, interi, compresi fra 1 e 100, fino a che non sono stati stampati
 * un numero di primi pari al parametro. La funzione termina stampando un messaggio che indica quanti numeri randomici
 * sono stati generati. */
 void generatore(int numPrimi) {
       int contatore;              // numeri interi generati
       int contatorePrimi;        // numeri primi generati
       int x;                    // un numero generatore

       /* inizializzazioni */
       contatore = 0;           // all'inizio non hai generato nessun numero
       contatorePrimi = 0;       // all'inizio non hai generato nessun numero primo

       /* genera ripetutamente numeri */
       while(contatorePrimi < numPrimi) {
               /* genera un nuovo numero */
               x = rand()%100+1;
               contatore++;

               if(isPrimo(x)) {
                     contatorePrimi++;
                     printf("E' stato generato un numero primo: %d!\n", x);
               }
               else
                    printf("E' stato generato un numero non primo: %d!\n", x);

        }

        printf("Hai generato %d numeri in totale, a fronte di %d numeri primi!", contatore, contatorePrimi);
 }

 int main() {
       int numero;              // il numero letto

       /* INPUT */
       printf("Introduci un numero intero: ");
       scanf("%d", &numero);

       /* per generazione numero casuale */
       srand(time(NULL));

       generatore(numero);
       system("PAUSE");
 }
