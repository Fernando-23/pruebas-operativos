#ifndef LISTAS_PRUEBAS2_H_
#define LISTAS_PRUEBAS2_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <commons/collections/list.h>
//#include "../1_crear-y-mostrar/listas-pruebas.h"

t_list* lista_prueba;

typedef struct {
    char* nombre;
    int prioridad;
    bool esta_libre;
    int64_t inicio;
}Corredor;

void mostrarPruebita(void* pruebita_void);
bool ordenarPorPrioridad(void *,void*);
bool buscarPruebitaPorId(void* args);
void agregarOrdenarYMostrar(t_list* lista, Corredor* corredor);

#endif /*LISTAS_PRUEBAS2_H_*/