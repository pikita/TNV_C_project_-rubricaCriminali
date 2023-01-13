

#ifndef UNTITLED2_RANDOMGENERATION_H
#define UNTITLED2_RANDOMGENERATION_H
#include "../sort_libraries_define/sort_libraries_define.h"
//Random Generation
RecordSoggetto generaRecord();
void generaDati(RecordSoggetto *rSoggetto,int *counter);
void generaNome(char stringa[]);
void generaCognome(char stringa[]);
void generaColore(char stringa[]);
void generaChiave(char str[]);
void generaResidenza(char residenza[]);

#endif //UNTITLED2_RANDOMGENERATION_H
