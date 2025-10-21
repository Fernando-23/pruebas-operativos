// linkeando.c
#define _GNU_SOURCE
#include <unistd.h>   // link(), unlink()
#include <stdio.h>    // printf(), perror(), FILE
#include <errno.h>    // errno
#include <sys/stat.h> // mkdir()
#include <sys/types.h>

int main(void) {
    const char *dir_src = "./fuente-posta";
    const char *dir_dst = "./dir-hardlink";
    const char *path_original = "./fuente-posta/original.txt";
    const char *path_hardlink = "./dir-hardlink/original-hardlink.txt";

    // Crear archivo original (w+ crea/trunca)
    FILE *fp = fopen(path_original, "r+");
    if (fp == NULL) {
        perror("Error creando archivo original");
        return 1;
    }

    fclose(fp);

    /*
    // Si ya existe el hard link, lo borramos para poder recrearlo
    if (unlink(path_hardlink) == -1 && errno != ENOENT) {
        perror("Error eliminando hardlink previo");
        return 1;
    }
    */

    // Crear hard link (mismo filesystem)
    if (link(path_original, path_hardlink) == -1) {
        perror("Error creando hard link");
        return 1;
    }

    printf("Hard link '%s' -> '%s' creado OK.\n", path_hardlink, path_original);

    return 0;
}
