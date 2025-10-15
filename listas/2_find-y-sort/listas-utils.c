#include "listas-utils.h"

t_list* lista_prueba = NULL;

void mostrarCorredor(void* corredor_void){
    Corredor* corredor = (Corredor*)corredor_void;
    printf("Corredor - mensaje: %s, prioridad: %d \n",corredor->nombre,corredor->prioridad);
}

bool ordenarPorPrioridad(void *corredor_vigente_void,void* corredor_desafiante_void){
    Corredor* corredor_vigente = (Corredor*)corredor_vigente_void;
    Corredor* corredor_desafiante = (Corredor*)corredor_desafiante_void;
    return corredor_vigente->prioridad <= corredor_desafiante->prioridad;
}

bool buscarCorredorPorId(void *args){
    Corredor* corredor = (Corredor*)args;
    return corredor->esta_libre;
}

void agregarOrdenarYMostrar(t_list* lista, Corredor* corredor){
    list_add(lista, corredor);
    list_sort(lista,ordenarPorPrioridad);
    list_iterate(lista,mostrarCorredor);
    printf("\n");
    printf("\n");
}

Corredor* inicializarCorredor(char* nombre, int prioridad, int tiempo){
    Corredor* nuevo_corredor = malloc(sizeof(Corredor));
    nuevo_corredor->cambio_estado = false;
    nuevo_corredor->esta_libre = false;
    nuevo_corredor->tiempo = tiempo;
    nuevo_corredor->nombre = nombre;
    nuevo_corredor->prioridad = prioridad;
    return nuevo_corredor;
}

//lo re quita de la lista
Corredor* quitarPrimero(t_list* lista){
    return (Corredor*)list_remove(lista,0);
}

//NO lo quita de la lista
Corredor* obtenerPrimero(t_list* lista){
    return (Corredor*)list_get(lista,0);
}