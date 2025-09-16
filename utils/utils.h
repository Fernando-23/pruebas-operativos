#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <commons/collections/list.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>


typedef struct{
    int size;
    char *mensaje;
}Mensaje;

int crearConexion(char *ip, char* puerto);
int iniciarServidor(char *puerto);
int esperarCliente(int socket_servidor);

#endif /* UTILS_H_*/