#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_ID 0
#define MAX_ID 10

struct RecordSoggetto {
    int id;
    struct RecordSoggetto *next;
};

struct RecordSoggetto *GeneraRecord();
struct RecordSoggetto *GeneraDati(int size);
void StampaElencoCriminali(struct RecordSoggetto *listIndex);
void StampaRecord(struct RecordSoggetto *item);
void eliminaCriminale(struct RecordSoggetto **head, int indexToDelete);
int contaCriminali(struct RecordSoggetto *listIndex);
void ordinaDati(struct RecordSoggetto **listIndex);
void swapPtr(struct RecordSoggetto **x, struct RecordSoggetto **y);

int main() {

    //init random seed
    srand(time(0));

    int size = 10;

    //genero lista dati
    struct RecordSoggetto *head = GeneraDati(size);

    //stampo lista dati appena generata
    printf("\nlista di valori casuali;\n");
    StampaElencoCriminali(head);

    //ordinare
    ordinaDati(&head);
    printf("lista di valori ordinati;\n");
    StampaElencoCriminali(head);

    //elimino il primo elemento
    eliminaCriminale(&head, 0);
    printf("elemento (head) eliminato;\n");
    StampaElencoCriminali(head);

    //elimino l'ultimo elemento
    eliminaCriminale(&head, contaCriminali(head) - 1);
    printf("elemento in coda eliminato;\n");
    StampaElencoCriminali(head);

    //elimino un elemento a caso
    eliminaCriminale(&head, (rand() % (contaCriminali(head))));
    printf("elemento a caso eliminato;\n");
    StampaElencoCriminali(head);
}

struct RecordSoggetto *GeneraDati(int size){
    //creo un puntatore del tipo RecordSoggetto e lo inizializzo a NULL in cui creare la head
    struct RecordSoggetto *head = NULL;
    int i;
        //creo head
        head = GeneraRecord();
        struct RecordSoggetto *listIndex = head;
        //concateno la lista di 10 struct legate
        for (i = 1; i < size; i++) {
            /*dichiaro una nuova variabile puntatore di tipo RecordSoggetto
             a cui verra restituito un indirizzo di memoria, il valore id e il NULL come link
            alla prossima struct*/
            struct RecordSoggetto *newSubject = GeneraRecord();
            //newSubject diventa il nuovo indirizzo di memoria della struttura (NULL fino a prima) a cui punta lastIndex
            listIndex->next = newSubject;
            //swappo gli indirizzi di memoria per evitare che si sovrascrivano
            listIndex = newSubject;

    }
    //restituisco l'indirizzo di memoria della head
    return head;
}
/**
 * funzione che restituisce un puntatore all'indirizzo della struttura appena allocata,
 * inizializza l'id e setta a NULL il link
 */
struct RecordSoggetto *GeneraRecord(){
    struct RecordSoggetto* nuovoSoggetto = (struct RecordSoggetto*)malloc(sizeof(struct RecordSoggetto));
    nuovoSoggetto->id = (rand() % (MAX_ID+1-MIN_ID)) + MIN_ID;
    nuovoSoggetto->next = NULL;

    return nuovoSoggetto;
}

/**
 * doppio puntatore perché devo modificare la head sia dentro che fuori dalla funzione
 * sto passando dunque il riferimento (&) alla head
 * @param **head puntatore al puntatore alla head
 * @param indexToDelete
 */
void eliminaCriminale(struct RecordSoggetto **head, int indexToDelete) {
    //attribuisco al puntatore *listIndex l'ind di mem della head
    struct RecordSoggetto *listIndex = *head; //head qui viene dereferenziato una volta
    struct RecordSoggetto *prev = NULL;
    int i;

    //cerco l'elemento da eliminare
    for (i = 0; i < indexToDelete; i++) {
        if(listIndex != NULL){
            /*ciclo la lista conservando in listIndex  l'indirizzo della struct da eliminare
             * ed in prev l'indirizzo della struct precedente all'elemento da eliminare*/
            prev = listIndex;
            listIndex = listIndex->next;
        }else{
            break;
        }
    }

    if(listIndex != NULL){
        if(prev != NULL){
            //prev (elemento precedente a quello da eliminare) si collega all'indirizzo di memoria a cui puntava l'elemento eliminato
            prev->next = listIndex->next;
        }
        /* risetto la head, attribuisco al puntatore della head l'indirizzo di memoria
         * dell'elemento successivo (che diventera a sua volta la nuova head) */
        if(indexToDelete == 0){ //re set head
            *head = listIndex->next;
        }
        free(listIndex);
    }
}

/**
 *QUESTA E' PURA MAGIA
 *bubble sort degli indirizzi di memoria (dall'id piu piccolo al piu grande)
 * ***PER FABIO, GUARDA IMMAGINE ALLEGATA***
 * @param **head
 */
void ordinaDati(struct RecordSoggetto **head){

    struct RecordSoggetto *i = *head;
    struct RecordSoggetto *j = NULL;
    struct RecordSoggetto *prev_i = NULL;
    struct RecordSoggetto *prev_j = NULL;
    bool reSetHead = true;

    while (i != NULL) {             //primo giro
        prev_j = i;                 //prev_j = head
        j = i->next;                //j      = cio a cui punta la head

        while (j != NULL) {
            if (i->id > j->id) {
                if(i == prev_j){ //swap nel caso in cui i = pre_j
                    i->next = j->next;   //swap dei link
                    j->next = i;
                    swapPtr(&i, &j); // swap dei puntatori
                }else{
                    swapPtr(&i->next, &j->next); //swap nei casi in cui non si tocca la head
                    prev_j->next = i;
                    swapPtr(&i, &j);
                }
                if(prev_i != NULL){
                    prev_i->next = i;
                }
                if(reSetHead == true){
                    *head = i;
                }
            }

            prev_j = j;
            j = j->next;
        }

        prev_i = i;
        i = i->next;
        reSetHead = false;
    }
}
//swap dei puntatori
void swapPtr(struct RecordSoggetto **x, struct RecordSoggetto **y){
    struct RecordSoggetto *tmp = *x;
    *x = *y;
    *y = tmp;
}

void StampaElencoCriminali(struct RecordSoggetto *listIndex){
    while (listIndex != NULL) {
        StampaRecord(listIndex);
        listIndex = listIndex->next;
    }
    printf("\n");
}

void StampaRecord(struct RecordSoggetto *item){
    printf("%d ", item->id);
}
//conta le linked struct
int contaCriminali(struct RecordSoggetto *listIndex) {
    int count = 0;
    while (listIndex != NULL) {
        count++;
        listIndex = listIndex->next;
    }
    return count;
}