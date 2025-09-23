#ifndef LISTAS_PRUEBAS2_H_
#define LISTAS_PRUEBAS2_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <commons/collections/list.h>
//#include "../1_crear-y-mostrar/listas-pruebas.h"

t_list* lista_prueba;

typedef struct {
    char* mensaje;
    int prioridad;
}Pruebita;

void mostrarPruebita(void* pruebita_void);
bool ordenarPorPrioridad(void *,void*);

#endif /*LISTAS_PRUEBAS2_H_*/