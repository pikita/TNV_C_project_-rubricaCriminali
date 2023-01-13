

#ifndef UNTITLED2_USERINPUT_H
#define UNTITLED2_USERINPUT_H
#include "../sort_libraries_define/sort_libraries_define.h"
//user input
void inserisciRecord(RecordSoggetto *rSoggetto);
void inserisciNome(char *n);
void inserisciCognome(char *c);
int inserisciAltezza();
void inserisciColoreOcchi(char *s);
void inserisciColoreCapelli(char *s);
void inserisciChiaveImprontaDigitale(char *s);
float inserisciPeso();
TipoCapelli tipoCapelli();
StatoSoggetto statoSoggetto();
int barba();
void residenza(char *s);
PosizioneGPS ultimaPosizioneSoggetto();


#endif //UNTITLED2_USERINPUT_H
