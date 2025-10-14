#include "temporeando.h"
#include "../listas/2_find-y-sort/listas-utils.h"
const int MAX_CORREDORES = 5;
Corredor* worker = NULL;


void mandarACorrer(t_list* lista){
    Corredor* elemento = quitarPrimero(lista);
    elemento->cambio_estado = true;
    worker = elemento;
}

void nuevoElemento (t_list* lista, int tiempo_a_correr){
    Corredor* elemento = quitarPrimero(lista);
    elemento->cambio_estado = true;
    worker = elemento;
}

bool hayQueDesalojar(Corredor* candidato){
    return worker->prioridad > candidato->prioridad;
}



void tiempo(){
    //creoTiempo
    //creo hilo
    //espera -> join
    //----------->cuando vuelve, chequea el flag
}




int main (char* argv[], int argc){
    int tiempo_espera_prioridad = 2000;
    
    lista_prueba = list_create();
    
    Corredor* elemento1 = inicializarCorredor("Liebre",0);
    Corredor* elemento2 = inicializarCorredor("Tortuga",10);
    Corredor* elemento3 = inicializarCorredor("Usain Bolt",8);
    Corredor* elemento4 = inicializarCorredor("Tortuga",10);
    Corredor* elemento5 = inicializarCorredor("Liam despues de ver las ofertas de Despegar.com",2);

    agregarOrdenarYMostrar(lista_prueba, elemento1);
    sleep(2);
    agregarOrdenarYMostrar(lista_prueba, elemento1);
    
    if(hayQueDesalojar(obtenerPrimero(lista_prueba))){
        Corredor *estaba_ejecutando = worker;
        mandarACorrer(lista_prueba);
        agregarOrdenarYMostrar(lista_prueba, estaba_ejecutando);
    } else{
        
    }
    
    sleep(2);
    agregarOrdenarYMostrar(lista_prueba, elemento1);
    sleep(2);
    agregarOrdenarYMostrar(lista_prueba, elemento1);
    sleep(2);
    agregarOrdenarYMostrar(lista_prueba, elemento1);
    sleep(2);
    
    
    list_add(lista_prueba, elemento1);
    list_add(lista_prueba, elemento2); 
    list_add(lista_prueba, elemento3); 
    list_add(lista_prueba, elemento4); 
    list_add(lista_prueba, elemento5);

    list_sort(lista_prueba,ordenarPorPrioridad);
    
    t_temporal* cronometro = temporal_create();
    temporal_destroy(cronometro);

}

