#ifndef SERVIDOR_H_
#define SERVIDOR_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <commons/collections/list.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include "../../utils/utils.h"

typedef struct 
{
    int socket;
    
}ArgsEsperarCliente;


void RecibirString(Mensaje* mensajito_a_recibir,int socket_cliente);
void* esperarClienteVoid(void*);
#endif /*SERVIDOR_H_*/