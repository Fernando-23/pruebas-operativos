#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <commons/collections/list.h>
#include <commons/config.h>
#include <commons/string.h>
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

void enviarMensajito(Mensaje* mensaje_a_enviar,int socket_servidor);
Mensaje* recibirMensajito(int socket_cliente);
void liberarMensajito(Mensaje* mensajito_a_liberar);

/*
CONVENCIONES GESTION KAROL-AQUINO
el repo e' de lo' socio

STRUCTS
CamelCase

Variables
snake_case

Constantes
SNAKE_CASE

Funciones
camelCase

*/


#endif /* UTILS_H_*/