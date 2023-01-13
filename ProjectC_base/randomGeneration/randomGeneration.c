
#include "randomGeneration.h"
#include "../sort_libraries_define/sort_libraries_define.h"



/**
 * Procedura di generazione di strtture pari alla lunghezza del vettore
 */
void generaDati(RecordSoggetto *rSoggetto, int *counter){
    int i;
    for (i = 0; i < DIM_LISTA_SOGGETTI; i++) {
        rSoggetto[i] = generaRecord(counter);
        (*counter)++;
    }
}
/**
 * funzione che restituisce la struttura di un soggetto con valori casuali
 */
RecordSoggetto generaRecord(){

    RecordSoggetto rSoggetto;
    rSoggetto.altezza = (rand() % (MAX_ALTEZZA+1-MIN_ALTEZZA)) + MIN_ALTEZZA;
    generaNome(rSoggetto.nome);
    generaCognome(rSoggetto.cognome);
    rSoggetto.peso = MIN_PESO + (float) rand() / (float) RAND_MAX*(MAX_PESO - MIN_PESO);
    generaColore(rSoggetto.coloreCapelli);
    generaColore(rSoggetto.coloreOcchi);
    generaChiave(rSoggetto.improntaDigitale);
    generaResidenza(rSoggetto.residenza);
    rSoggetto.barba = rand() % (true + true - false) + false;
    rSoggetto.tipoCapelli = rand() % (MAX_RANGE_ENUM + 1 - MIN_RANGE_ENUM) + MIN_RANGE_ENUM;
    rSoggetto.statoSoggetto = rand() % (MAX_RANGE_ENUM + 1 - MIN_RANGE_ENUM) + MIN_RANGE_ENUM;
    rSoggetto.ultimaPosizione.latitudine = (double)rand()/RAND_MAX*3.0-1.0;
    rSoggetto.ultimaPosizione.longitudine = (double)rand()/RAND_MAX*3.0-1.0;


    return rSoggetto;
}
/**
 * procedura di generazione casuale di un nome/cognome acquisito da una lista di nomi
 */
void generaNome(char stringa[]){
    char nomi[N_NOMI][DIM_NOME+1] = { "Carlo", "Luca", "Fabio", "Massimiliano", "Alessandra", "Barbara"};
    strcpy(stringa, nomi[rand()%N_NOMI]);
}
void generaCognome(char stringa[]){
    char nomi[N_COGNOMI][DIM_COGNOME+1] = { "Cadeddu", "Sogos", "Serra", "Radu", "Ciki", "Mezekin"};
    strcpy(stringa, nomi[rand()%N_COGNOMI]);
}
/**
 * genera una stringa che corrisponde ad un colore in forma esadecimale
 */
void generaColore(char stringa[]){
    char colori[N_COLORI][DIM_CAPELLI+1] = {
            "AA345FF", "76GGH66", "AAFF33", "778899",
            "000000", "FF00FF"};
    strcpy(stringa, colori[rand()%N_COLORI]);
}
/**
 * Proicedura di generazione di una stringa da 16 caratteri + terminatore di stringa tramite l'utilizzo di un
 * charset.
 * Info per Fabio, ne vado abbastanza orgoglioso, uso anche un casting.
 */
void generaChiave(char str[]) {
    int size = DIM_CHIAVE_IMPRONTA+1, i;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (size) {
        --size;
        for ( i = 0; i < size; i++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[i] = charset[key];
        }
        str[size] = '\0';
    }
}
/**
 * genera casualmente 3 stringhe da un bacino definito per poi concatenarle
 */
void generaResidenza(char residenza[]){
    char tipo[3][20] = {"Via", "Viale", "Piazza"};
    char nome[3][20] = {"Michelangelo", "Donatello", "Gabriele"};
    char numero[3][20] = {"18A", "4B", "3F"};

    strcpy(residenza, tipo[rand()%3]);
    strcat(residenza, " ");
    strcat(residenza, nome[rand()%3]);
    strcat(residenza, " ");
    strcat(residenza, numero[rand()%3]);
}

