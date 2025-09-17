#ifndef SERVIDOR_H_
#define SERVIDOR_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <commons/collections/list.h>
#include <commons/string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include "../../utils/utils.h"

typedef struct 
{
    int socket;
    
}ArgsEsperarCliente;

typedef struct{
    char* query;
    int prioridad;
    int quid;
    int fd;
}QCB;



void* gestionarQueryIndividual(void* args);
void* atenderQuerys(void *args);
void* atenderWorker(void *args);
void *gestionarWorkerIndividual(void *args);

#endif /*SERVIDOR_H_*/