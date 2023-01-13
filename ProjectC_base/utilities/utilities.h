
#ifndef UNTITLED2_UTILITIES_H
#define UNTITLED2_UTILITIES_H
//Subroutine di stampa
void stampaElencoCriminali(RecordSoggetto *rSoggetto,int *counter);
void stampaRecord(RecordSoggetto *rSoggetto);

void inserisciStringa(char *s, int dim, _Bool accettaspazio);
void svuotabuffer();

//user utilities
void modificaCriminale(RecordSoggetto *recordSoggetto, int indice);
void eliminaCriminale(RecordSoggetto *recordSoggetto, int indice,int *counter);

#endif //UNTITLED2_UTILITIES_H
