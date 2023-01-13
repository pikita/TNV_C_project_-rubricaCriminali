#include "sort_libraries_define/sort_libraries_define.h"
#include "utilities/utilities.h"
#include "randomGeneration/randomGeneration.h"

int main() {
    //init random seed
    srand(time(0));
    int i;
    static int counter = 0;
    RecordSoggetto lista_soggetti[DIM_LISTA_SOGGETTI];

    printf("Numero Soggetti %d\n", counter);
    generaDati(lista_soggetti,&counter);
    printf("Elenco Criminali:\n");
    stampaElencoCriminali(lista_soggetti, &counter);
    printf("Numero Soggetti %d\n", counter);

    ordinaDati(lista_soggetti);
    printf("Elenco Criminali Ordinati:\n");
    stampaElencoCriminali(lista_soggetti, &counter);

    eliminaCriminale(lista_soggetti,1,&counter);
    eliminaCriminale(lista_soggetti,10,&counter);
    eliminaCriminale(lista_soggetti,rand() % (counter+1-0)+0,&counter);
    stampaElencoCriminali(lista_soggetti,&counter);
    modificaCriminale(lista_soggetti, 1);
    printf("PRIMO ELEMENTO MODIFICATO\n");
    stampaElencoCriminali(lista_soggetti,&counter);
    printf("Numero Soggetti %d\n", counter);

//////////////////////////////////////////////////////////////////////////////////////////////////////
// scusa, avrei dovuto fare una procedure ma non ho avuto il tempo materiale

    //variabili d'appoggio per la stampa su file
    char tipoCapelli[DIM_STRINGA_FPRINTF], statoSoggetto[DIM_STRINGA_FPRINTF];
    int cap,stato;

    FILE *fileDati = NULL;
    //apertura file in modalità scrittura
    fileDati = fopen("../listaCriminali.txt", "w");
    //ciclo di stampa su file del vettore
    for ( i = 0; i < counter; ++i) {
        cap =  lista_soggetti[i].tipoCapelli;
        stato = lista_soggetti[i].statoSoggetto;

        switch (cap)         {
            case 0:
                strcpy(tipoCapelli, "Capelli corti.");
        break;
        case 1:
            strcpy(tipoCapelli,"Capelli di media lunghezza.");
        break;
        case 2:
            strcpy(tipoCapelli, "Capelli lunghi.");
        break;
        case 3:
            strcpy(tipoCapelli,"Capigliatura particolare.");
        break;
    }
        switch (stato)         {
            case 0:
                strcpy(statoSoggetto, "STATO: LIBERO\n");
                break;
            case 1:
                strcpy(statoSoggetto,"STATO: RICERCATO\n");
                break;
            case 2:
                strcpy(statoSoggetto, "STATO: IN ARRESTO\n");
                break;
            case 3:
                strcpy(statoSoggetto,"STATO: EVASO (lol :D)\n");
                break;
        }




    fprintf(fileDati, "Nome: %s\nCognome: %s\nAltezza: %d\nPeso: %.2f\n"
                          "Colore Occhi: %s\nColore Capelli: %s\nTratti: %s\nChiave Impronta Digitale: %s\n"
                          "Residenza: %s\nUltima posizione conosciuta.\nLatitudine: %lf\nLongitudine: %lf\n%s\n%s\n\n\n",
                lista_soggetti[i].nome,lista_soggetti[i].cognome, lista_soggetti[i].altezza, lista_soggetti[i].peso,
                lista_soggetti[i].coloreOcchi, lista_soggetti[i].coloreCapelli,
                lista_soggetti[i].barba == 0 ? "Non ha la barba" : "Ha la barba",
                lista_soggetti[i].improntaDigitale, lista_soggetti[i].residenza,lista_soggetti[i].ultimaPosizione.latitudine,
                lista_soggetti[i].ultimaPosizione.longitudine,tipoCapelli,statoSoggetto);
    }
    //chiusura file
    fclose(fileDati);

    return 0;
}


