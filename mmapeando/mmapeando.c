#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <commons/bitarray.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc,char* argv[]){
    FILE *archivo = fopen("file-prueba", "a+"); 
    int fd_archivo = fileno(archivo); 
    //"prueba operativos\n"
    ftruncate(fd_archivo,19);

    /*
    que corno recibe mmap?
    mmap(0 siempre, tamanio de arch, permisos, file descriptor del arch, offset)
        
    */
    void* mapeo_archivo = mmap(NULL,19,PROT_WRITE | PROT_READ, MAP_SHARED,fd_archivo,0);

    //modifico el archivo
    strncpy(mapeo_archivo,"prueba operativos",strlen("prueba operativos") + 1);

    //sincronizo el cambio (aca modifico posta)
    msync(mapeo_archivo, strlen("prueba operativos") + 1, MS_SYNC);

    /*debido a que este senior se tiene q ir a laburar
    esto continuara en el sgte capitulo con una abstraccion del calculo
    del strlen +1
    y probablemente otra derrota de river (pongan huevo loco)
    */
}
