#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    struct timespec inicio, fin;

    // Descomentar lineas de clock_gettime para que funque
    clock_gettime(CLOCK_REALTIME, &inicio); //IntelliSense es bobo, gcc lo entiende.

    sleep(2);

    clock_gettime(CLOCK_REALTIME, &fin); 




    double tiempo_milisegundos = (fin.tv_sec - inicio.tv_sec) * 1000 + // segundos * 1000 es milisegundos
                         (fin.tv_nsec - inicio.tv_nsec) / 1e6; // para fer: 1e6= 1 × 10⁶ (resultado en milisegundos)


    printf("Tiempo real transcurrido: %.3f milisegundos\n", tiempo_milisegundos);
    return 0;
}