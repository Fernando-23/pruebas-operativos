#include "listas-utils.h"

//t_list* lista_prueba = NULL;

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


int main(){
    Corredor* elem_1 = malloc(sizeof(Corredor));
    Corredor* elem_2 = malloc(sizeof(Corredor));
    Corredor* elem_3 = malloc(sizeof(Corredor));
    Corredor* elem_4 = malloc(sizeof(Corredor));
    Corredor* elem_5 = malloc(sizeof(Corredor));
    Corredor* elem_6 = malloc(sizeof(Corredor));
    Corredor* elem_7 = malloc(sizeof(Corredor));
    Corredor* elem_8 = malloc(sizeof(Corredor));
    Corredor* elem_9 = malloc(sizeof(Corredor));
    Corredor* elem_10 = malloc(sizeof(Corredor));
    
    elem_1->nombre = "soy juan carlos abrime";
    elem_1->prioridad = 1;
    elem_1->esta_libre = false;
    elem_2->nombre = "quintero al arco";
    elem_2->prioridad = 3;
    elem_2->esta_libre =false;
    elem_3->nombre = "bob esponja";
    elem_3->prioridad = 2;
    elem_3->esta_libre =false;
    elem_4->nombre = "nietche";
    elem_4->prioridad = 2;
    elem_4->esta_libre =false;
    elem_5->nombre = "la llorona";
    elem_5->prioridad = 4;
    elem_5->esta_libre =false;
    elem_6->nombre = "el exorcista";
    elem_6->prioridad = 2;
    elem_6->esta_libre =true;
    elem_7->nombre = "la insoportable";
    elem_7->prioridad = 5;
    elem_7->esta_libre =false;
    elem_8->nombre = "Liam Karol Trepat";
    elem_8->prioridad = 4;
    elem_8->esta_libre =false;
    elem_9->nombre = "brasil";
    elem_9->prioridad = 2;
    elem_9->esta_libre =false;
    elem_10->nombre = "clash royale";
    elem_10->prioridad = 1;
    elem_10->esta_libre = false;
    lista_prueba = list_create();

    list_add(lista_prueba, elem_1);
    list_add(lista_prueba, elem_2);
    list_add(lista_prueba, elem_3);
    list_add(lista_prueba, elem_4);
    list_add(lista_prueba, elem_5);
    list_add(lista_prueba, elem_6);
    list_add(lista_prueba, elem_7);
    list_add(lista_prueba, elem_8);
    list_add(lista_prueba, elem_9);
    list_add(lista_prueba, elem_10);

    printf("Lista sin ordenar:\n");
    list_iterate(lista_prueba,mostrarCorredor);
    
    list_sort(lista_prueba,ordenarPorPrioridad);
    printf("Lista ordenada:\n");
    list_iterate(lista_prueba,mostrarCorredor);
    
    printf("Encuentro el primero que esta libre con list_find:\n");
    Corredor* corredor_encontrada =(Corredor *)list_find(lista_prueba,buscarCorredorPorId);
    printf("Corredor %s con prioridad %d libre encontrada con list_find sisenior\n",
        corredor_encontrada->nombre,corredor_encontrada->prioridad);
}