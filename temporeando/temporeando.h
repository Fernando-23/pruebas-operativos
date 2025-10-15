#ifndef TEMPOREANDO_H_
#define TEMPOREANDO_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <commons/string.h>
#include <commons/temporal.h>
#include "../listas/2_find-y-sort/listas-utils.h"

void mandarACorrer(t_list* lista);
void* simulacionWorker(void*);
bool hayQueDesalojar(Corredor* candidato);
void* SUPERsleep(void* tiempo_sin_casteado);
void subidaDePrioridad(Corredor* corredor_a_esperar);
Corredor* sigaEnReady(char* nombre);
void agregarOrdenarYMostrarDesalojoVer(t_list* lista,Corredor* corredor);
void* aging(void* nombre);


#endif /*TEMPOREANDO_H_*/