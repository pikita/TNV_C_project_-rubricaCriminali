#ifndef UNTITLED2_SORT_LIBRARIES_DEFINE_H
#define UNTITLED2_SORT_LIBRARIES_DEFINE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define DIM_NOME 64
#define DIM_COGNOME 64
#define DIM_OCCHI 7
#define DIM_CAPELLI 7
#define DIM_CHIAVE_IMPRONTA 16
#define DIM_RESIDENZA 511
#define DIM_LISTA_SOGGETTI 10
#define DIM_FILTRO_STRINGA 20
#define MIN_ALTEZZA 0
#define MAX_ALTEZZA 250
#define MAX_PESO 200.0
#define MIN_PESO 0
#define MAX_RANGE_ENUM 3
#define MIN_RANGE_ENUM 0
#define N_NOMI 6
#define N_COGNOMI 6
#define N_COLORI 6
#define DIM_STRINGA_FPRINTF 40

//variabili globali
typedef enum {CORTI, MEDI, LUNGHI, ALTRO} TipoCapelli;
typedef enum {LIBERO, RICERCATO, ARRESTO, EVASO} StatoSoggetto;

typedef struct {
    double latitudine;
    double longitudine;
} PosizioneGPS;
typedef struct {
    char nome[DIM_NOME+1];
    char cognome[DIM_COGNOME+1];
    int altezza;
    float peso;
    char coloreOcchi[DIM_OCCHI+1];
    char coloreCapelli[DIM_CAPELLI+1];
    TipoCapelli tipoCapelli;
    _Bool barba;
    char improntaDigitale[DIM_CHIAVE_IMPRONTA+1];
    char residenza[DIM_RESIDENZA+1];
    PosizioneGPS ultimaPosizione;
    StatoSoggetto statoSoggetto;

} RecordSoggetto;


//utilities
void ordinaDati(RecordSoggetto *rSoggetto);



#endif //UNTITLED2_SORT_LIBRARIES_DEFINE_H
