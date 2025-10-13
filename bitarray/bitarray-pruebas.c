#include "bitarray-prueba.h"

int main(int argc,char* argv[]){
    
    int tamanio_fs = 1024;
    int tamanio_bloque = 16;

    int cant_bloques = tamanio_fs / tamanio_bloque;

    void* bitmap_prueba = malloc(cant_bloques/8);

    t_bitarray* bitarray_prueba = bitarray_create_with_mode(bitmap_prueba,cant_bloques/8,LSB_FIRST);
    printf("Valor max del bitarray %ld \n",bitarray_get_max_bit(bitarray_prueba));
    
    for (int i = 0; i < cant_bloques; i++) {
        printf("valor del bit %d es %d\n",i, bitarray_test_bit(bitarray_prueba, i));
    }
    
    printf("Seteando el 1er bit en true\n");
    bitarray_set_bit(bitarray_prueba,0);
    
    for (int i = 0; i < cant_bloques; i++) {
        printf("valor del bit %d es %d\n",i, bitarray_test_bit(bitarray_prueba, i));
    }
}