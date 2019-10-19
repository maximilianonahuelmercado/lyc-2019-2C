#ifndef COLA_H
#define COLA_H

#include <stdlib.h>
#include <string.h>

#define COLA_LLENA -1
#define COLA_VACIA 0
#define TODO_OK 1
#define SIN_MEM -1

typedef struct s_nodo_c
{
	char * dato;
	struct s_nodo_c *sig;
} t_nodo_c;

typedef struct
{
	t_nodo_c *pri, *ult;

}t_cola;

void crear_cola(t_cola *);
int poner_en_cola(t_cola *, const char *datos);
int sacar_de_cola(t_cola *, char *);
int frente_de_cola(const t_cola *, char *);
int cola_vacia(const t_cola *);
int cola_llena(const t_cola *);
void vaciar_cola(t_cola *);

#endif // COLA_H
