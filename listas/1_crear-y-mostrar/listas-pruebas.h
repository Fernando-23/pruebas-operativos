#ifndef LISTAS_PRUEBAS_H_
#define LISTAS_PRUEBAS_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <commons/collections/list.h>

typedef struct{
    int quid;
    char* query; // string_length(char* string);
}Qcb;

void crearQCBMock(Qcb* qcb,char* query);
void mostrarLista(void* qcb_void);
void detonarQcb(void* qcb);



//comando compilar gcc -o lista listas-pruebas.c -lcommons -lcrypto

#endif /*LISTAS_H_*/