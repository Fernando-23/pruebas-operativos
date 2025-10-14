#ifndef TEMPOREANDO_H_
#define TEMPOREANDO_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <commons/temporal.h>
#include <commons/collections/list.h>

typedef struct{
    int64_t inicio;
    int prioridad;
    char* nombre;
}Corredor;

void mandarACorrer(int tiempo_a_correr);

#endif /*TEMPOREANDO_H_*/