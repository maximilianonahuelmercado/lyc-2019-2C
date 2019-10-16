#include "../files_h/cola.h"

void crear_cola(t_cola *pc)
{
	(*pc)->fte = (*pc)->fdo = NULL;
}

int cola_llena(const t_cola *pc)
{
	t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo));
	free(aux);
	return aux == NULL;
}

int cola_vacia(t_cola *pc)
{
	return pc->pri == NULL;
}

int poner_en_cola(t_cola *pc, const char *dato)
{
	t_nodo *pnue = (t_nodo *)malloc(sizeof(t_nodo));
	if(!*pnue)
		return SIN_MEM;
	pnue->dato = *dato;
	pnue->psig = NULL;
	if(pc->ult)
	{
		pc->ult->psig = pnue;
		pc->ult = pnue;
	}
	else
	{
		pc->pri = pnue;
		pc->ult = pnue;
	}
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
	t_nodo *aux;
	if(pc->pri == NULL)
		return COLA_VACIA;
	aux = pc->pri;
	*dato = aux->dato;
	if(pc->pri == p->ult)
	{
		pc->pri = NULL;
		pc->ult = NULL;
	}
	else
		pc->pri = aux->psig;
	free(aux);
	return TODO_OK;
}
