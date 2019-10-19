#include "../files_h/cola.h"

void crear_cola(t_cola *pc)
{
	pc->pri = pc->ult = NULL;
}

int cola_llena(const t_cola *pc)
{
	t_nodo_c *aux = (t_nodo_c *)malloc(sizeof(t_nodo_c));
	free(aux);
	return aux == NULL;
}

int cola_vacia(const t_cola *pc)
{
	return pc->pri == NULL;
}

int poner_en_cola(t_cola *pc, const char *datos)
{
	t_nodo_c *pnue = (t_nodo_c *)malloc(sizeof(t_nodo_c));
	if(pnue==NULL)
		return SIN_MEM;
	pnue->dato = *datos;
	pnue->sig = NULL;
	if(pc->pri==NULL)
	{
		pc->pri = pnue;
	}
	else
	{
		pc->ult->sig = pnue;
	}
	pc->ult=pnue;
	return TODO_OK;
}

int ver_primero_cola(t_cola *pc, char *dato)
{
	if(pc->pri == NULL)
		return COLA_VACIA;
	*dato = pc->pri->dato;
	return TODO_OK;
}

int sacar_de_cola(t_cola *pc, char *dato)
{
	t_nodo_c *aux;
	if(pc->pri == NULL)
		return COLA_VACIA;
	aux = pc->pri;
	pc->pri = aux->sig;
	*dato = aux->dato;
	free(aux);
	if(pc->pri == NULL)
	{
		pc->ult = NULL;
	}
	return TODO_OK;
}
