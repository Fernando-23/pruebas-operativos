#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <commons/bitarray.h>


int main(int argc,char* argv[]){
    
    int tamanio_fs = 1024;
    int tamanio_bloque = 16;

    int cant_bloques = tamanio_fs / tamanio_bloque;

    FILE* bitmap_arch = fopen("bitmap.bin","a+");
    
    int bitmap_fd = fileno(bitmap_arch);
    ftruncate(bitmap_fd,cant_bloques/8);
    
    char* bitmap_mmap = mmap(NULL, cant_bloques/8, PROT_WRITE | PROT_READ, MAP_SHARED, bitmap_fd, 0);
    t_bitarray* bitarray_prueba = bitarray_create_with_mode(bitmap_mmap, cant_bloques / 8,LSB_FIRST);
    //--------------------------------------------------------16 bloques -> 16 bits -> 2 bytes
    fclose(bitmap_arch);
    printf("Valor max del bitarray %ld \n",bitarray_get_max_bit(bitarray_prueba));
    
    for (int i = 0; i < cant_bloques; i++) {
        printf("valor del bit %d es %d\n",i, bitarray_test_bit(bitarray_prueba, i));
    }
    sleep(10);

    for (int i = 0; i < cant_bloques; i += 2) {
        bitarray_set_bit(bitarray_prueba,i);
        msync(bitmap_mmap, cant_bloques/8, MS_SYNC);
        printf("valor del bit %d es %d\n",i, bitarray_test_bit(bitarray_prueba, i));
        sleep(1);
    }
    //bitarray_set_bit(bitarray_prueba,4);
 
    //for (int i = 0; i < cant_bloques; i++) {
    //    printf("valor del bit %d es %d\n",i, bitarray_test_bit(bitarray_prueba, i));
    //}
    

    munmap(bitmap_mmap,cant_bloques/8);
    bitarray_destroy(bitarray_prueba);
    
}