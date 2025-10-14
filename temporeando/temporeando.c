#include "temporeando.h"
const int MAX_CORREDORES = 5;
t_list* lista = NULL;

bool ordenarPorPrioridad(void *corredor_vigente_void,void* corredor_desafiante_void){
    Corredor* corredor_vigente = (Corredor*)corredor_vigente_void;
    Corredor* corredor_desafiante = (Corredor*)corredor_desafiante_void;
    return corredor_vigente->prioridad < corredor_desafiante->prioridad;
}

void mandarACorrer(t_list lista, int tiempo_a_correr){
    int index_a_ejecutar = 0;
    for(lista != NULL){
        if(){
            
        }       
    
    }
    
    
}



int main (char* argv[], int argc){
    int tiempo_espera_prioridad = 2000;
    
    lista = list_create();
    Corredor* elemento1 = malloc(sizeof(Corredor));
    Corredor* elemento2 = malloc(sizeof(Corredor));
    Corredor* elemento3 = malloc(sizeof(Corredor));
    Corredor* elemento4 = malloc(sizeof(Corredor));
    Corredor* elemento5 = malloc(sizeof(Corredor));
    
    
    
    elemento1->nombre = "Liebre";
    elemento2->nombre = "Tortuga";
    elemento3->nombre = "Fer despues de ver las ofertas de coto";
    elemento4->nombre = "Usain Bolt";
    elemento5->nombre = "Liam despues de ver las ofertas de Despegar.com";

    elemento1->prioridad = 0;
    elemento2->prioridad = 10;
    elemento3->prioridad = 5;
    elemento4->prioridad = 8;
    elemento5->prioridad = 2;
    
    list_add(lista, elemento1);
    list_add(lista, elemento2); 
    list_add(lista, elemento3); 
    list_add(lista, elemento4); 
    list_add(lista, elemento5);

    list_sort(lista,ordenarPorPrioridad);
    
    
    
    t_temporal* cronometro = temporal_create();




    temporal_destroy(cronometro);
}

