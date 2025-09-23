#ifndef CLIENTE_DESALOJO_H_
#define CLIENTE_DESALOJO_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <commons/string.h>
#include <commons/collections/list.h>
#include <pthread.h>
#include "../../utils/utils.h"

void enviarString(char* mensajito,int socket_servidor);
void* incrementarContador();
Mensaje* crearMensajeRegistroQuery(char* ruta,int prioridad);

#endif