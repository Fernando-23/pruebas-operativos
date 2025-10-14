#include "listas-utils.h"

//t_list* lista_prueba = NULL;

void mostrarCorredor(void* corredor_void){
    Corredor* corredor = (Corredor*)corredor_void;
    printf("Corredor - mensaje: %s, prioridad: %d \n",corredor->nombre,corredor->prioridad);
}

int main(){
    Corredor* elem_1 = malloc(sizeof(Corredor));
    Corredor* elem_2 = malloc(sizeof(Corredor));
    Corredor* elem_3 = malloc(sizeof(Corredor));
    
    elem_1->nombre = "mensaje 1";
    elem_1->prioridad = 1;
    elem_2->nombre = "mensaje 2";
    elem_2->prioridad = 2;
    elem_3->nombre = "mensaje 3";
    elem_3->prioridad = 3;
    lista_prueba = list_create();

    list_add(lista_prueba, elem_1);
    list_add(lista_prueba, elem_2);
    list_add(lista_prueba, elem_3);
    int tam = list_size(lista_prueba);
    printf("Tamaño de la lista: %d\n",tam);
    int i = 1;

    printf("Lista antes de sacar elementos\n");
    list_iterate(lista_prueba, mostrarCorredor);

    while(tam > 0){ //3 2 1
        Corredor* fifo_prueba = (Corredor *)(list_remove(lista_prueba, 0));
        printf("Se sacó el elemento: %d.\n", i);
        printf("PRUEBITA: MENSAJE: %s, PRIORIDAD: %d.\n", fifo_prueba->nombre, fifo_prueba->prioridad);
        
        printf("Lista despues de sacar el elemento: %d. \n", i);
        if(list_is_empty(lista_prueba)){
            printf("La lista esta vacia\n");
        }else{
            list_iterate(lista_prueba, mostrarCorredor);
        }
       
        free(fifo_prueba);
        tam--;
        i++;
    }
    
    return 0;
}