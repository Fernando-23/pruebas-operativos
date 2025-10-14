#ifndef LISTAS_UTILS_H_
#define LISTAS_UTILS_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <commons/collections/list.h>
#include <pthread.h>

extern t_list* lista_prueba;

typedef struct {
    char* nombre;
    int prioridad;
    bool esta_libre;
    bool cambio_estado;
    int64_t inicio;
}Corredor;

void mostrarCorredor(void* pruebita_void);
bool ordenarPorPrioridad(void *,void*);
bool buscarCorredorPorId(void* args);
void agregarOrdenarYMostrar(t_list* lista, Corredor* corredor);
Corredor* inicializarCorredor(char* nombre,int prioridad);
Corredor* quitarPrimero(t_list* lista);
Corredor* obtenerPrimero(t_list* lista);

#endif /*LISTAS_PRUEBAS2_H_*/