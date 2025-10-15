#include "temporeando.h"

const int MAX_CORREDORES = 5;
const int TIEMPO_BAJADA_PRIORIDAD = 6;
Corredor* worker = NULL;

void agregarOrdenarYMostrarDesalojoVer(t_list* lista,Corredor* corredor){
    agregarOrdenarYMostrar(lista,corredor);
    pthread_t thread_prioridad;
    pthread_create(&thread_prioridad,NULL,aging,(void *)corredor);
    pthread_detach(thread_prioridad);
}


//simula que envia a un worker
void mandarACorrer(t_list* lista){
    Corredor* elemento = quitarPrimero(lista);
    elemento->cambio_estado = true;
    worker = elemento;
    printf("Corredor: %s enviado a correr \n",elemento->nombre);
    pthread_t thread_worker;
    pthread_create(&thread_worker,NULL,simulacionWorker,NULL);
    pthread_detach(thread_worker);
}

bool hayQueDesalojar(Corredor* candidato){
    return worker->prioridad > candidato->prioridad;
}

void *SUPERsleep(void* tiempo_sin_casteado){
    int tiempo_casteado = *((int *)tiempo_sin_casteado);
    sleep(tiempo_casteado); //sleep(1)
}

void* simulacionWorker(void*){
    pthread_t thread_corriendo;
    pthread_create(&thread_corriendo,NULL,SUPERsleep,(void *)&(worker->tiempo));
    pthread_join(thread_corriendo,NULL);
    printf("Muere, Corredor: %s\n", worker->nombre);
    worker->esta_libre = true;
    
    
}

void subidaDePrioridad(Corredor* corredor_a_esperar){
    pthread_t thread_bajada;
    int tiempo_aux = TIEMPO_BAJADA_PRIORIDAD;
    pthread_create(&thread_bajada,NULL,SUPERsleep,(void *)&(tiempo_aux));
    pthread_join(thread_bajada,NULL);

    if (corredor_a_esperar->cambio_estado == false && corredor_a_esperar->prioridad != 0){
        corredor_a_esperar->prioridad--;
        printf("Bajó de prioridad el Corredor: %s, Prioridad: %d\n",corredor_a_esperar->nombre,corredor_a_esperar->prioridad);

        return;
    }
   
}

Corredor* sigaEnReady(char* nombre){
   
    bool esElCorredorPorNombre(void *ptr){
        Corredor* corredor = (Corredor *) ptr;
        return string_equals_ignore_case(corredor->nombre, nombre);
    }

    return list_find(lista_prueba, esElCorredorPorNombre);
}

void* aging(void* corredor_a_chequear_sin_castear){
    Corredor* corredor_a_chequear = (Corredor*)corredor_a_chequear_sin_castear;
    char* nombre = corredor_a_chequear->nombre;
    
    Corredor* corredor;
    do {
       corredor = sigaEnReady(nombre); 
       subidaDePrioridad(corredor);
    } while( corredor != NULL);

}




int main (){
    
    lista_prueba = list_create();
    
    Corredor* elemento1 = inicializarCorredor("Liebre",1,80);
    Corredor* elemento2 = inicializarCorredor("Tortuga",10,80);
    Corredor* elemento3 = inicializarCorredor("Usain Bolt",8,80);
    Corredor* elemento4 = inicializarCorredor("Tortuga",0,80);
    Corredor* elemento5 = inicializarCorredor("Liam despues de ver las ofertas de Despegar.com",2,3);
    worker = inicializarCorredor("WORKER",0,0);

    agregarOrdenarYMostrarDesalojoVer(lista_prueba, elemento1);
    mandarACorrer(lista_prueba);


    sleep(3);

    agregarOrdenarYMostrarDesalojoVer(lista_prueba, elemento2); 

    if (worker->esta_libre == true && list_size(lista_prueba) == 1){
        mandarACorrer(lista_prueba);
    
    } else{
        if(hayQueDesalojar(elemento2)){
        
        Corredor *estaba_ejecutando = worker;
        
        mandarACorrer(lista_prueba);
        agregarOrdenarYMostrarDesalojoVer(lista_prueba, estaba_ejecutando);
        }
    }

        sleep(3);

    agregarOrdenarYMostrarDesalojoVer(lista_prueba, elemento3); 
    
    if (worker->esta_libre == true && list_size(lista_prueba) == 1){
       
        mandarACorrer(lista_prueba);
    
    } else{
        
        if(hayQueDesalojar(elemento3)){
       
        Corredor *estaba_ejecutando = worker;
        
        mandarACorrer(lista_prueba);
        agregarOrdenarYMostrarDesalojoVer(lista_prueba, estaba_ejecutando);
        }
        
    }
        
        sleep(3);

        printf("LIAM LO HIZO\n");
        agregarOrdenarYMostrarDesalojoVer(lista_prueba, elemento4); 

    if (worker->esta_libre == true && list_size(lista_prueba) == 1){
        mandarACorrer(lista_prueba);
    
    } else{ 
        
        if(hayQueDesalojar(elemento4)){
        
        Corredor *estaba_ejecutando = worker;
        
        mandarACorrer(lista_prueba);
        agregarOrdenarYMostrarDesalojoVer(lista_prueba, estaba_ejecutando);
        }
    }

        sleep(3);
    agregarOrdenarYMostrarDesalojoVer(lista_prueba, elemento5); 

    if (worker->esta_libre == true && list_size(lista_prueba) == 1){
        mandarACorrer(lista_prueba);
    
    } else{
        if(hayQueDesalojar(elemento5)){
        
        Corredor *estaba_ejecutando = worker;
        
        mandarACorrer(lista_prueba);
        agregarOrdenarYMostrarDesalojoVer(lista_prueba, estaba_ejecutando);
        }
    }


    t_temporal* cronometro = temporal_create();
    temporal_destroy(cronometro);
    return 0;
}





//// compilar codigo dificil
/*
*/