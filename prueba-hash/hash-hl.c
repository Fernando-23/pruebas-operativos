#include <commons/string.h>
#include <unistd.h>
#include <commons/crypto.h>
#include <pthread.h>
#include <commons/log.h>
#include <commons/string.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>



int main(){

    // Mismo content
    char* PATH_ORISHINAL = "archivos-hl/orishinal";
    char* PATH_ALGO_ORISHINAL = "archivos-hl/si-soy-yo";
    // Distinto content
    char* PATH_NO_ORISHINAL = "archivos-hl/no-soy-yo";
    FILE* arch = fopen(PATH_ORISHINAL,"a+");
    if(!arch) abort();

    fseek(arch,0,SEEK_END);
    
    long tamanio = ftell(arch);
    rewind(arch);

    void* contenido = malloc((size_t)tamanio);
    fread(contenido,1,(size_t)tamanio,arch);
    fclose(arch);

    



    char* hash_orishinal = crypto_md5(contenido, 4);
    char* hash_algo_orishinal = crypto_md5("holaa", 4);
    //char* hash_no_orishinal = crypto_md5();
    printf("%s\n",hash_orishinal);
    printf("%s\n",hash_algo_orishinal);
    free(contenido);
}

/*
    char hola[4] = "hola";
    char* hash_orishinal = crypto_md5("hola", 4);
    char* hash_algo_orishinal = crypto_md5(hola, 4);
    printf("%s\n",hash_orishinal);
    printf("%s\n",hash_algo_orishinal);

    struct stat info_orishinal;

    if (stat(PATH_ORISHINAL, &info_orishinal) == -1) {
        fprintf(stderr, "Error al hacer stat de '%s': %s\n",
                PATH_ORISHINAL, strerror(errno));
        return EXIT_FAILURE;
    }


    struct stat info_algo_orishinal;

    if (stat(PATH_ALGO_ORISHINAL, &info_algo_orishinal) == -1) {
        fprintf(stderr, "Error al hacer stat de '%s': %s\n",
                PATH_ALGO_ORISHINAL, strerror(errno));
        return EXIT_FAILURE;
    }

    struct stat info_no_orishinal;

    if (stat(PATH_NO_ORISHINAL, &info_no_orishinal) == -1) {
        fprintf(stderr, "Error al hacer stat de '%s': %s\n",
                PATH_NO_ORISHINAL, strerror(errno));
        return EXIT_FAILURE;
    }

*/