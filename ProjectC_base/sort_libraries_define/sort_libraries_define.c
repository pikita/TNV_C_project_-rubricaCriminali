
#include "sort_libraries_define.h"
#include "../utilities/utilities.h"






/**
 * questa procedura consente l'ordinamento, rispetto a nome e cognome, del vettore tramite un algoritmo bubble sort
 * 1)utilizzo sprintf per unire nome e cognome con uno spazio tra di loro
 * 2)utilizzo strcmp per comparare due stringhe (composte da "nome cognome") ridotte in minuscolo
 * per determinare quale delle due viene dopo.
 *
 * Funzionamento ciclo:
 * ogni ciclo for compara due stringhe mettendo (o lasciando) quella di valore piu alto come seconda.
 * ripete l'operazione per la dimensione del vettore - i per ogni ciclo, poiché ogni ciclo determinerà
 * l'elemento piu grande che non dovra quindi piu essere comparato.
 *
 * @param rSoggetto indirizzo di memoria del vettore
 */
void ordinaDati(RecordSoggetto *rSoggetto){

    RecordSoggetto tmp;
    int i, j;
    for(i = 0; i<DIM_LISTA_SOGGETTI-1; i++){

        for(j = 0; j<DIM_LISTA_SOGGETTI-1-i;j++){

            char str1[DIM_NOME+DIM_COGNOME+2];
            char str2[DIM_NOME+DIM_COGNOME+2];

            sprintf(str1, "%s %s", rSoggetto[j].nome, rSoggetto[j].cognome);
            sprintf(str2, "%s %s", rSoggetto[j+1].nome, rSoggetto[j+1].cognome);

            if(strcmp(strlwr(str1), strlwr(str2)) > 0){
                tmp = rSoggetto[j+1];
                rSoggetto[j+1] = rSoggetto[j];
                rSoggetto[j] = tmp;
            }
        }
    }
}

