#ifndef COLA_H
#define COLA_H

#include <stdlib.h>
#include <string.h>

#define COLA_LLENA -1
#define COLA_VACIA 0
#define TODO_OK 1
#define SIN_MEM -1

typedef struct s_nodo
{
	void * dato;
	int frente;
	int fondo;
	int ce;
} t_nodo;

typedef t_nodo *t_cola;

void crear_cola(t_cola *);
int poner_en_cola(t_cola *, const char *);
int sacar_de_cola(t_cola *, char *);
int frente_de_cola(const t_cola *, char *);
int cola_vacia(const t_cola *);
int cola_llena(const t_cola *);
void vaciar_cola(t_cola *);

#endif // COLA_H
