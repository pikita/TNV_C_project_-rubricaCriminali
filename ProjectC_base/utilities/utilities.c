
#include "../sort_libraries_define/sort_libraries_define.h"
#include "utilities.h"
#include "../userInput/userInput.h"
/**
 * Procedura che riceve un puntatore al vettore e stampa ogni elemento del vettore.
 */
void stampaElencoCriminali(RecordSoggetto *rSoggetto,int *counter){
    int i;
    for (i = 0; i < *counter; i++) {
        stampaRecord(&rSoggetto[i]);
        printf("\n");
    }
}
/**
 * Procedura di stampa di un singolo Record Soggetto, puo essere richiamata dando in ingresso
 * l'indirizzo di memoria della struttura che si vuole stampare.
 * ex dal main: stampaRecord(lista_soggetti+1);
 * se si vuole stampare la seconda struttura del vettore
 */
void stampaRecord(RecordSoggetto *rSoggetto){
    printf("Nome: %s\n", rSoggetto->nome);
    printf("Cognome: %s\n", rSoggetto->cognome);
    printf("Altezza: %d\n", rSoggetto->altezza);
    printf("Peso: %.2f\n", rSoggetto->peso);
    printf("Colore occhi: %s\n", rSoggetto->coloreOcchi);
    printf("Colore Capelli: %s\n", rSoggetto->coloreCapelli);
    printf("Chiave Impronta Digitale: %s\n", rSoggetto->improntaDigitale);
    printf("Residenza: %s\n", rSoggetto->residenza);
    printf("Tratti: %s\n", rSoggetto->barba == 0 ? "Non ha la barba" : "Ha la barba");

    switch (rSoggetto->tipoCapelli) {
        case 0:
            printf("Capelli corti.\n");
            break;
        case 1:
            printf("Capelli di media lunghezza.\n");
            break;
        case 2:
            printf("Capelli lunghi.\n");
            break;
        case 3:
            printf("Capigliatura particolare.\n");
            break;
    }
    switch (rSoggetto->statoSoggetto) {
        case 0:
            printf("Stato: LIBERO\n");
            break;
        case 1:
            printf("Stato: RICERCATO\n");
            break;
        case 2:
            printf("Stato: IN ARRESTO\n");
            break;
        case 3:
            printf("Stato: EVASO (lol :D)\n");
            break;
    }

    printf("Ultima posizione conosciuta.\n"
           "Latitudine:  %lf\n"
           "Longitudine: %lf\n", rSoggetto->ultimaPosizione.latitudine, rSoggetto->ultimaPosizione.longitudine);

}


/**
 * Procedura di modifica di un elemento del vettore, riceve l'indirizzo di memoria del vettore e l'indice del
 * elemento da modificare.
 * Al suo interno ci sarà un decremento del contatore poiché poi richiamando un inserimento
 * verrà nuovamente incrementato.
 *
 * Info per lo sviluppatore ***** all'interno si puo decidere si usarla con inserimento manuale o casuale. *****
 */
void modificaCriminale(RecordSoggetto *recordSoggetto, int indice){

    //recordSoggetto[indice-1] = generaRecord();
    inserisciRecord(&recordSoggetto[indice-1]);

}


/**
 * procedura di eliminazione con modalità shifting, riceve in ingresso l'IDM (indirizzo di memoria) del vettore e
 * l'indice dell'elemento da eliminare.
 * la procedura sposterà l'elemento in fondo al vettore decrementando poi il contatore in modo che l'elemento "eliminato"
 * non verrà stampato.
 */
void eliminaCriminale(RecordSoggetto *recordSoggetto, int indice, int *counter){
    int i;
    for (i = indice-1; i < *counter; i++) {
        recordSoggetto[i] = recordSoggetto[i + 1];
    }
    (*counter)--;
}


/**
 * procedura che consente impostare l'acquisizione di una stringa accettando gli spazi o no, tramite l'uso di un
 * espressione regolare.
 * @param s     puntatore alla stringa
 * @param dim   quantita di caratteri massimi scannerizzati
 * @param accettaspazio booleano accetta spazio o no
 */
void inserisciStringa(char *s, int dim, _Bool accettaspazio){
    char filtroStringa[DIM_FILTRO_STRINGA+1];

    if(accettaspazio)
        sprintf(filtroStringa, "%%%d[^\n]s", dim);
    else
        sprintf(filtroStringa, "%%%ds", dim);
    scanf(filtroStringa,s);
    svuotabuffer();
}
/**
 * elimina i caratteri rimasti nel buffer dopo uno scanf
 */
void svuotabuffer(){
    char carattere;
    do {
        carattere = getchar();
    } while (carattere != '\n');
}





