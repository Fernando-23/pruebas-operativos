#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>   // struct stat, stat()
#include <errno.h>
#include <string.h>     // strerror()

int main(int argc, char *argv[]) {
    /*if (argc != 2) {
        fprintf(stderr, "Uso: %s <ruta-archivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];
    struct stat info;

    if (stat(path, &info) == -1) {
        fprintf(stderr, "Error al hacer stat de '%s': %s\n",
                path, strerror(errno));
        return EXIT_FAILURE;
    }

    printf("Archivo: %s\n", path);
    printf("Cantidad de hard links: %lu\n", (unsigned long) info.st_nlink);
    */
    char* ruta_falsos = "/home/utnso/Desktop/falsos";
    //mkdir(ruta_falsos,0777);
    //link("/home/utnso/Desktop/reales/volar","/home/utnso/Desktop/falsos/no-volar");
    //unlink("/home/utnso/Desktop/falsos/no-volar");
    rmdir(ruta_falsos);
    return EXIT_SUCCESS;
}
