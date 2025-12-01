// linkeando.c
#define _GNU_SOURCE
#include <unistd.h>   // link(), unlink()
#include <stdio.h>    // printf(), perror(), FILE
#include <errno.h>    // errno
#include <sys/stat.h> // mkdir()
#include <sys/types.h>
#include <stdlib.h>
#include <commons/string.h>

int main(int argc,char* argv[]){

    char* directorio = argv[1];
    printf("Carpeta a usar: %s\n",directorio);
    
    
    char* jack_sparrow = string_from_format("rm -rf %s",directorio);
    
    system(jack_sparrow);
    free(jack_sparrow);
    return 0;
}
