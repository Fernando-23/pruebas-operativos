#include "listas-utils.h"

int main(){

    lista_prueba = list_create();
    
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
    elem_2->prioridad = 1;
    elem_2->esta_libre =false;
    elem_3->nombre = "bob esponja";
    elem_3->prioridad = 2;
    elem_3->esta_libre =false;
    elem_4->nombre = "nietche";
    elem_4->prioridad = 3;
    elem_4->esta_libre =false;
    elem_5->nombre = "la llorona";
    elem_5->prioridad = 2;
    elem_5->esta_libre =false;
    elem_6->nombre = "el exorcista";
    elem_6->prioridad = 2;
    elem_6->esta_libre =true;
    elem_7->nombre = "la insoportable";
    elem_7->prioridad = 1;
    elem_7->esta_libre =false;
    elem_8->nombre = "Liam Karol Trepat";
    elem_8->prioridad = 3;
    elem_8->esta_libre =false;
    elem_9->nombre = "brasil";
    elem_9->prioridad = 2;
    elem_9->esta_libre =false;
    elem_10->nombre = "clash royale";
    elem_10->prioridad = 1;
    elem_10->esta_libre = false;

    agregarOrdenarYMostrar(lista_prueba, elem_1);
    agregarOrdenarYMostrar(lista_prueba, elem_2);
    agregarOrdenarYMostrar(lista_prueba, elem_3);
    agregarOrdenarYMostrar(lista_prueba, elem_4);
    agregarOrdenarYMostrar(lista_prueba, elem_5);
    agregarOrdenarYMostrar(lista_prueba, elem_6);
    agregarOrdenarYMostrar(lista_prueba, elem_7);
    agregarOrdenarYMostrar(lista_prueba, elem_8);
    agregarOrdenarYMostrar(lista_prueba, elem_9);
    agregarOrdenarYMostrar(lista_prueba, elem_10);

    
}