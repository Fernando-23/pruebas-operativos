#include "listas-pruebas2.h"

t_list* lista_prueba = NULL;

void mostrarPruebita(void* pruebita_void){
    Pruebita* pruebita = (Pruebita *)pruebita_void;
    printf("Pruebita - mensaje: %s, numero: %d \n",pruebita->mensaje,pruebita->prioridad);
}

int main(){
    Pruebita* elem_1 = malloc(sizeof(Pruebita));
    Pruebita* elem_2 = malloc(sizeof(Pruebita));
    Pruebita* elem_3 = malloc(sizeof(Pruebita));
    
    elem_1->mensaje = "mensaje 1";
    elem_1->prioridad = 1;
    elem_2->mensaje = "mensaje 2";
    elem_2->prioridad = 2;
    elem_3->mensaje = "mensaje 3";
    elem_3->prioridad = 3;
    lista_prueba = list_create();

    list_add(lista_prueba, elem_1);
    list_add(lista_prueba, elem_2);
    list_add(lista_prueba, elem_3);
    int tam = list_size(lista_prueba);
    printf("Tamaño de la lista: %d\n",tam);
    int i = 1;

    printf("Lista antes de sacar elementos\n");
    list_iterate(lista_prueba, mostrarPruebita);

    while(tam > 0){ //3 2 1
        Pruebita* fifo_prueba = (Pruebita *)(list_remove(lista_prueba, 0));
        printf("Se sacó el elemento: %d.\n", i);
        printf("PRUEBITA: MENSAJE: %s, PRIORIDAD: %d.\n", fifo_prueba->mensaje, fifo_prueba->prioridad);
        
        printf("Lista despues de sacar el elemento: %d. \n", i);
        if(list_is_empty(lista_prueba)){
            printf("La lista esta vacia\n");
        }else{
            list_iterate(lista_prueba, mostrarPruebita);
        }
       
        free(fifo_prueba);
        tam--;
        i++;
    }
    
    return 0;
}