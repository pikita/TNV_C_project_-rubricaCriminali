

#include "userInput.h"
#include "../utilities/utilities.h"
#include "../sort_libraries_define/sort_libraries_define.h"


/**
 * procedura di inserimento di un record, richiama a sua volte le subroutine di inserimento da parte dell'utente
 * nelle quali verranno eseguiti i controlli.
 * ho deciso di realizzare una subroutine per ogni inserimento da utente, poiché (in termini di user experience)
 * consentirebbe allo sviluppatore di realizzare delle subroutine per consentire la modifica di un singolo valore
 * di una specifica struttura. E ad un eventuale utilizzatore di evitare di reinserire  tutti i dati di un soggetto
 * anziché un singolo valore
 * @param rSoggetto
 */
void inserisciRecord(RecordSoggetto *rSoggetto){

    inserisciNome((char *)&rSoggetto->nome);
    inserisciCognome((char *)&rSoggetto->cognome);
    rSoggetto->altezza = inserisciAltezza();
    rSoggetto->peso = (float) inserisciPeso();
    inserisciColoreOcchi((char *) &rSoggetto->coloreOcchi);
    inserisciColoreCapelli((char *) &rSoggetto->coloreCapelli);
    rSoggetto->tipoCapelli = tipoCapelli();
    rSoggetto->barba = barba();
    inserisciChiaveImprontaDigitale((char *) &rSoggetto->improntaDigitale);
    residenza((char *) &rSoggetto->residenza);
    rSoggetto->ultimaPosizione = ultimaPosizioneSoggetto();
    rSoggetto->statoSoggetto = statoSoggetto();
    printf("\n");

}
/**
 * procedura di acquisizione e controllo di input da parte dell'utente in due passaggi,
 * prima acquisisce la stringa consentendo la scannerizzazione degli spazi per poi determinare che i caratteri siano
 * solo alphabetici o spazi.
 *
 * nome e cognome sono uguali.
 * per coloreOcchi e coloreCapelli cambia il charset d'ingresso
 * @param n riceve in ingresso un puntatore alla stringa
 */
void inserisciNome(char *n){
    //char *nome = n;
    _Bool flag = 0;
    int i;
    do {
        printf(" Nome: ");
        inserisciStringa(n, DIM_NOME, 1);

        for (i = 0; n[i] != '\0'; i++){
            if(isalpha(n[i]) || n[i] == ' ')
            {
                flag = 1;
            }
            else{
                flag = 0;
                printf("inserimento non valido\n");
                break;
            }
        }
    } while (flag == 0);
}
void inserisciCognome(char *c){
    char *cognome = c;
    _Bool flag = 0;
    int i;
    do {
        printf("Cognome: ");
        inserisciStringa(cognome, DIM_COGNOME, 1);
        for (i = 0; cognome[i] != '\0'; i++){
            if(isalpha(cognome[i]) || cognome[i] == ' ')
            {
                flag = 1;
            }
            else{
                flag = 0;
                printf(" inserimento non valido\n");
                break;
            }
        }
    } while (flag == 0);
}
void inserisciColoreOcchi(char *s){
    char *coloreOcchi = s;
    _Bool flag = 0;
    int i;
    do {
        printf("Colore occhi: ");
        inserisciStringa(coloreOcchi, DIM_OCCHI, 1);

        for (i = 0; coloreOcchi[i] != '\0'; i++){
            if(isdigit(coloreOcchi[i]) || (coloreOcchi[i] >= 'a' && coloreOcchi[i] <= 'f') || (coloreOcchi[i] >= 'A' && coloreOcchi[i] <= 'F'))
            {
                flag = 1;
            }
            else{
                flag = 0;
                printf("inserimento non valido\n");
                break;
            }
        }
    } while (flag == 0);
}
void inserisciColoreCapelli(char *s){
    char *coloreCapelli = s;
    _Bool flag = 0;
    int i;
    do {
        printf("Colore capelli: ");
        inserisciStringa(coloreCapelli, DIM_CAPELLI, 1);
        //svuotabuffer();
        for (i = 0; coloreCapelli[i] != '\0'; i++){
            if(isdigit(coloreCapelli[i]) || (coloreCapelli[i] >= 'a' && coloreCapelli[i] <= 'f') || (coloreCapelli[i] >= 'A' && coloreCapelli[i] <= 'F'))
            {
                flag = 1;
            }
            else{
                flag = 0;
                printf("inserimento non valido\n");
                break;
            }
        }
    } while (flag == 0);
}
/**
 * procedura di acquisizione e controllo di un intero, verifica che sia un intero tramite la funzione scanf
 * altezza e peso funzionano allo stesos modo ma con differenti range di acquisizione
 * @return altezza, intero
 */
int inserisciAltezza(){
    static int a;
    _Bool isValid = 0;
    do {
        printf("Altezza: ");
        if (scanf("%d", &a) == 1 && (a >= 0 && a <= 250)) {
            svuotabuffer();
            isValid = 1;
        }
        else {
            getchar();
            isValid = 0;
            printf("inserimento non valido\n");
        }
    } while (isValid == 0);
    return  a;
}
float inserisciPeso(){
    static float a;
    _Bool isValid = 0;
    do {

        printf("Peso: ");
        if (scanf("%f", &a) == 1 && (a >= 0 && a <= 200)){
            svuotabuffer();
            isValid = 1;
        }
        else {
            getchar();
            isValid = 0;
            printf("inserimento non valido\n");
        }
    } while (isValid == 0);
    return  a;
}

/**
 * procedura di acquisizione e controllo della chiave impronta digitale
 * una volta acquisita verifica che siano esattamente 16 caratteri+terminatore
 * dopodiche verifica che i caratteri siano solo alfanumerici
 * **** anche di questa vado abbastanza orgoglioso ****
 * @param s
 */
void inserisciChiaveImprontaDigitale(char *s){
    int i,a;
    bool flag = 0;
    char *chiave = s;

    do {
        printf(" Inserire Impronta Digitale\n [sedici inserimenti]: ");
        scanf("%s", chiave);
        svuotabuffer();
        for (i = 0; chiave[i] != '\0'; i++) {}
        if (i == 16) {
            for (a = 0; chiave[a] != '\0'; a++){
                if(isalnum(chiave[a]))
                    flag = 1;
                else{
                    flag = 0;
                    printf("\ninseirmento non valido");
                    break;
                }
            }
        } else{
            printf("\ninseirmento non valido");
        }
    } while (flag == 0);
}
/**
 *funzione che consente l'acquisizione ed il controllo di un intero e
 * restituisce una valore di tipo enum__(nome) controllando che rientri tra i valori dell'enumenrazione definita
 * TipoCapelli e StatoSoggetto funzionano allo stesso modo
 * @return
 */
TipoCapelli tipoCapelli(){
    static TipoCapelli a;
    _Bool isValid;
    do {
        isValid = 0;
        printf("Definire tipo capelli\n CORTI [0], MEDI [1], LUNGHI [2], ALTRO[3]: ");
        scanf("%d", &a);
        if (a >= 0 && a <= 3)
            isValid = 1;
        else
            printf("\nInserimento non corretto");

    }while(isValid == 0);
    return a;
}
StatoSoggetto statoSoggetto(){
    static StatoSoggetto a;


    _Bool isValid;
    do {
        isValid = 0;
        printf("Definire stato soggetto\n LIBERO [0], RICERCATO [1], IN ARRESTO [2], EVASO [3]: ");
        scanf("%d", &a);
        if (a >= 0 && a <= 3)
            isValid = 1;
        else
            printf("\nInserimento non corretto");

    }while(isValid == 0);

    return a;
}

/**
 * funzione booleana che restituisce 0 o 1 se il soggetto ha la barba o no.
 * @return
 */
//TODO: reimpostarla come booleano
int barba(){
    static int a;

    printf("Definire presenza di barba, \n [1] se ha la barba, [0] se non la ha:");
    scanf("%d", &a);
    svuotabuffer();
    if(a == 1)
        return 1;
    else
        return 0;
}
/**
 * procedura di acquisizione e controllo di una stringa
 * accetta valori alfanumerici e spazi
 * @param s
 */
void residenza(char *s){
    char *residenza = s;

    _Bool flag = 0;
    int i;
    do {
        printf("Indicare residenza Via/Viale + Nome + Numero Civico: ");
        inserisciStringa(residenza, DIM_RESIDENZA, 1);

        for (i = 0; residenza[i] != '\0'; i++){
            if(isalnum(residenza[i]) || residenza[i] == ' ')
            {
                flag = 1;
            }
            else{
                flag = 0;
                printf("inserimento non valido\n");
                break;
            }
        }
    } while (flag == 0);
}
/**
 * funzione di acquisizione di due valori double corrispondenti a latitudine e longitudine
 * @return struttura PosizioneGPS contenendo due valori double
 */
PosizioneGPS ultimaPosizioneSoggetto(){
    static PosizioneGPS p;

    printf("Inserire i dati GPS relativi l'ultima posizione del soggetto.\n"
           " Inserire latitudine: ");
    scanf("%lf", &p.latitudine);
    printf("Inserire longitudine: ");
    scanf("%lf", &p.longitudine);
    svuotabuffer();

    return p;
}

