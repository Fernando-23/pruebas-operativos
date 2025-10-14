#include "temporeando.h"

int main(){

    int tiempo_de_espera = 4000;
    const int conversion = 1000;
    printf("Provoleta temporizador activado...\n\n");

    t_temporal* temporizador = temporal_create();
    sleep(tiempo_de_espera / conversion);
   
    int64_t prueba_antes_int64_t = temporal_gettime(temporizador);

    printf("Tiempo pasado en int64_t ANTES del stop: %ld\n",prueba_antes_int64_t);
    sleep(2);
    temporal_stop(temporizador);
    int64_t prueba_int64_t = temporal_gettime(temporizador);
    
    printf("Tiempo pasado en int64_t DESPUES del stop: %ld\n",prueba_int64_t);
    
    
}