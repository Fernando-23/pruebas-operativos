#include "listas-pruebas2.h"

t_list* lista_prueba = NULL;

void mostrarPruebita(void* pruebita_void){
    Pruebita* pruebita = (Pruebita *)pruebita_void;
    printf("Pruebita - mensaje: %s, prioridad: %d \n",pruebita->mensaje,pruebita->prioridad);
}

bool ordenarPorPrioridad(void *pruebita_vigente_void,void* pruebita_desafiante_void){
    Pruebita* pruebita_vigente = (Pruebita*)pruebita_vigente_void;
    Pruebita* pruebita_desafiante = (Pruebita*)pruebita_desafiante_void;
    return pruebita_vigente->prioridad < pruebita_desafiante->prioridad;
}

bool buscarPruebitaPorId(void *args){
    Pruebita* pruebita = (Pruebita *)args;
    return pruebita->esta_libre;
}

int main(){
    Pruebita* elem_1 = malloc(sizeof(Pruebita));
    Pruebita* elem_2 = malloc(sizeof(Pruebita));
    Pruebita* elem_3 = malloc(sizeof(Pruebita));
    Pruebita* elem_4 = malloc(sizeof(Pruebita));
    Pruebita* elem_5 = malloc(sizeof(Pruebita));
    Pruebita* elem_6 = malloc(sizeof(Pruebita));
    Pruebita* elem_7 = malloc(sizeof(Pruebita));
    Pruebita* elem_8 = malloc(sizeof(Pruebita));
    Pruebita* elem_9 = malloc(sizeof(Pruebita));
    Pruebita* elem_10 = malloc(sizeof(Pruebita));
    
    elem_1->mensaje = "soy juan carlos abrime";
    elem_1->prioridad = 1;
    elem_1->esta_libre = false;
    elem_2->mensaje = "quintero al arco";
    elem_2->prioridad = 3;
    elem_2->esta_libre =false;
    elem_3->mensaje = "bob esponja";
    elem_3->prioridad = 2;
    elem_3->esta_libre =false;
    elem_4->mensaje = "nietche";
    elem_4->prioridad = 2;
    elem_4->esta_libre =false;
    elem_5->mensaje = "la llorona";
    elem_5->prioridad = 4;
    elem_5->esta_libre =false;
    elem_6->mensaje = "el apestoso";
    elem_6->prioridad = 2;
    elem_6->esta_libre =true;
    elem_7->mensaje = "la insoportable";
    elem_7->prioridad = 5;
    elem_7->esta_libre =false;
    elem_8->mensaje = "Liam Karol Trepat";
    elem_8->prioridad = 4;
    elem_8->esta_libre =false;
    elem_9->mensaje = "brasil";
    elem_9->prioridad = 2;
    elem_9->esta_libre =false;
    elem_10->mensaje = "clash royale";
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
    list_iterate(lista_prueba,mostrarPruebita);
    
    list_sort(lista_prueba,ordenarPorPrioridad);
    printf("Lista ordenada:\n");
    list_iterate(lista_prueba,mostrarPruebita);
    
    printf("Encuentro el primero que esta libre con list_find:\n");
    Pruebita* pruebita_encontrada =(Pruebita *)list_find(lista_prueba,buscarPruebitaPorId);
    printf("Pruebita %s con prioridad %d libre encontrada con list_find sisenior\n",
        pruebita_encontrada->mensaje,pruebita_encontrada->prioridad);
}