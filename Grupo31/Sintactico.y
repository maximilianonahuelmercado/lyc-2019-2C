%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "files_h/tercetos.h"
	#include "files_h/constantes.h"
	#include "files_h/ts.h"
	#include "files_h/pila.h"

	// Declaraciones onbligatorias para quitar advertencias
	int yylineno;
	FILE  *yyin;
	int yylex();
	int yyerror(char *msg);
	int yyparse();

	// Cabecera funciones varias
		void insertarEnArrayDeclaracion(char *);
		void validarDeclaracionTipoDato(char *);
		char * negarComparador(char*);
		char * obtenerNuevoNombreEtiqueta(char *);
		void insertarEnArrayComparacionTipos(char *);
		void insertarEnArrayComparacionTiposDirecto(char *);
		void imprimirArrayComparacionTipos();
		void compararTipos();
		char * tipoConstanteConvertido(char*);
		void insertarEnArrayTercetos(char *operador, char *operando1, char *operando2);
		void crearTercetosDelArray();
		char * guardarTipoDato(char *);

		// Declaro la pila (estructura externa que me servira para resolver GCI)
		t_pila pila;
		t_pila pila_condicion_doble;
		t_pila pila_ciclo_especial;
		char condicion[5]; // puede ser AND u OR

		t_pila pilaTipo;


		// Arrays
		char * arrayDeclaraciones[100];	// array para declaraciones
		char * arrayTipoDato[100]; // array para tipos de dato
		int longitud_arrayDeclaraciones = 0; // incremento en el array arrayDeclaraciones
		int longitud_arrayTipoDato = 0; // incremento en el arrayTipoDato
		char * arrayComparacionTipos[100];	// array para comparar tipos
		int longitud_arrayComparacionTipos = 0; // incremento en el array arrayComparacionTipos
		// Auxiliar para manejar tercetos;
		int indiceExpresion, indiceTermino, indiceFactor, indiceLongitud;
		int indiceAux, indiceUltimo, indiceIzq, indiceDer, indiceComparador, indiceComparador1, indiceComparador2,
		indiceId;
		int indicePrincipioBloque;
		char idAsignarStr[50];
		char * tipoDato;

		int startEtiqueta = 0;
%}

// Especifica el valor semantico que tendra la variable global propia de bison yylval.
// Como la variable yytext (global de lexico) sera sobrescrita, debera guardarse su valor en yyval.
// Ejemplo: strcpy(yylval.str, yytext);
// Mas info: http://www.gnu.org/software/bison/manual/html_node/Union-Decl.html#Union-Decl
%union {
	char * int_val;
	char * real_val;
	char * str_val;
	char * cmp_val;
}

// Start symbol
%start programa

// Tokens
%token VAR
%token ENDVAR
%token REAL
%token INTEGER
%token STRING
%token IF THEN ELSE ENDIF
%token REPEAT ENDREPEAT
%token MOD
%token DIV
%token INLIST
%token OP_AND
%token OP_OR
%token OP_NOT
%token CMP_MAYOR
%token CMP_MENOR
%token CMP_MAYORIGUAL
%token CMP_MENORIGUAL
%token CMP_DISTINTO
%token CMP_IGUAL
%token OP_ASIG
%token OP_DOSP
%token OP_SUM
%token OP_RES
%token OP_MUL
%token OP_DIV
%token CAR_COMA
%token CAR_PUNTO
%token CAR_PYC
%token CAR_PA
%token CAR_PC
%token CAR_CA
%token CAR_CC
%token CAR_LA
%token CAR_LC
%token PRINT
%token READ
%token CONST_INT
%token CONST_REAL
%token CONST_STR
%token ID


//Reglas gramaticales
%%

programa:
	{	printf("\tInicia el COMPILADOR\n\n");	}
	est_declaracion bloque
	{	printf("\n\tFin COMPILADOR OK\n");
		prepararTSParaAssembler();
		crearArchivoTS();
		crearArchivoTercetosIntermedia();
	}	;

est_declaracion:
	VAR {	printf("\t\tDECLARACIONES VAR\n");	}
	declaracion
	ENDVAR {	printf("\t\tFIN DECLARACIONES ENDVAR\n");	}	;

declaracion:
	CAR_CA NODO CAR_CC;

NODO:
TIPO_DATO CAR_CC OP_DOSP CAR_CA ID
{
	insertarEnArrayDeclaracion(yylval.str_val);
  sacar_de_pila(&pilaTipo,&tipoDato);
	printf("\nArray declaraciones: %s , TIPO DE DATO %s", arrayDeclaraciones[0], tipoDato);
	if(strcmp(tipoDato, "STRING") == 0)
	{
		validarDeclaracionTipoDato("STRING");
	}
	else{
			if(strcmp(tipoDato, "REAL") == 0)
				validarDeclaracionTipoDato("REAL");
			else
				validarDeclaracionTipoDato("INTEGER");
	}

};
NODO:
	TIPO_DATO CAR_COMA NODO CAR_COMA ID
	{
		printf("\nArray declaraciones: %s , TIPO DE DATO %s", arrayDeclaraciones[0], tipoDato);
		insertarEnArrayDeclaracion(yylval.str_val);
		if(strcmp(tipoDato, "STRING") == 0)
		{
			validarDeclaracionTipoDato("STRING");
		}
		else{
				if(strcmp(tipoDato, "REAL") == 0)
					validarDeclaracionTipoDato("REAL");
				else
					validarDeclaracionTipoDato("INTEGER");
		}

	};

TIPO_DATO:
	STRING {
	guardarTipoDato("STRING");
	poner_en_pila(&pilaTipo,tipoDato);
	printf("ENTRE A STRING %s\n", tipoDato);
	}
	|
	INTEGER {
		guardarTipoDato("INTEGER");
		poner_en_pila(&pilaTipo,tipoDato);
		printf("ENTRE A ENTERO %s\n", tipoDato);
	}
	| REAL{
		guardarTipoDato("REAL");
		poner_en_pila(&pilaTipo,tipoDato);
		printf("ENTRE A REAL %s\n", tipoDato);
	};


bloque:
	sentencia
	| bloque sentencia;

sentencia:
	ciclo
	{
		crearTerceto(obtenerNuevoNombreEtiqueta("fin_repeat"),"_","_");
	}
	| seleccion
		{
			crearTerceto(obtenerNuevoNombreEtiqueta("fin_seleccion"),"_","_");
		}
	| asignacion
	| entrada_salida
	| modulo
	| division
	| inlist;

ciclo:
	REPEAT
	{	printf("\t\tREPEAT\n");
		//indiceAux=crearTerceto(obtenerNuevoNombreEtiqueta("inicio_repeat"),"_","_");
		//poner_en_pila(&pila,&indiceAux);
	}
	{printf("\t\tPASA REPEAT\n");}
	CAR_PA condicion CAR_PC
	{
		printf("\t\tPASA CONDICION\n");
		//indicePrincipioBloque = obtenerIndiceActual();
	}
	bloque
	{printf("\t\tPASA BLOQUE\n");}
	ENDREPEAT
	{	printf("\t\tENDREPEAT\n");
	int indiceDesapilado;
	int indiceActual = obtenerIndiceActual();
	if(pila_vacia(&pila_condicion_doble) == PILA_VACIA)
	{
		sacar_de_pila(&pila, &indiceDesapilado);
		modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual+1));
	}
	else
	{
		if(strcmp(condicion,"AND") == 0)
		{
			sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
			modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual+1));
			sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
			modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual+1));
		}
		if(strcmp(condicion,"OR") == 0)
		{
			sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
			modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual+1));
			sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
			modificarTerceto(indiceDesapilado, 2, armarIndiceI(indicePrincipioBloque));
		}
		// Debo desapilar el ultimo porque no me sirve
		sacar_de_pila(&pila, &indiceDesapilado);
	}
	sacar_de_pila(&pila, &indiceDesapilado);
	crearTerceto("JMP",armarIndiceI(indiceDesapilado),"_");
	}	;

modulo:
	expresion MOD expresion
	{ printf("\t\tMOD\n");};

division:
	expresion DIV expresion
	{ printf("\t\tDIV\n");};

inlist:
	{printf("\t\tINLIST\n");}
	INLIST CAR_PA ID CAR_PYC CAR_CA lista_expresiones CAR_CC CAR_PC;

lista_expresiones:
			expresion
			{

				crearTerceto("CMP",armarIndiceI(indiceId),armarIndiceD(indiceExpresion));
				indiceComparador = crearTerceto("JNE","_","_");
				poner_en_pila(&pila_ciclo_especial,&indiceComparador);
			}

			| lista_expresiones CAR_PYC expresion
			{
				crearTerceto("CMP",armarIndiceI(indiceId),armarIndiceD(indiceExpresion));
				indiceComparador = crearTerceto("JNE","_","_");
				poner_en_pila(&pila_ciclo_especial,&indiceComparador);
			};

asignacion:
				lista_id expresion
			{
					printf("\t\tASIGNACION\n");
					compararTipos();

					indiceAux = crearTerceto(idAsignarStr,"_","_");

					crearTerceto("=",armarIndiceI(indiceAux),armarIndiceD(indiceExpresion));
		 };

lista_id:
	ID OP_ASIG
	{
		insertarEnArrayComparacionTipos(yylval.str_val);
		strcpy(idAsignarStr, yylval.str_val);
	};

entrada_salida:
	READ	ID
	{
		printf("\t\tREAD\n");
		indiceAux = crearTerceto(yylval.str_val,"_","_");
		crearTerceto("READ",armarIndiceI(indiceAux),"_");
	}
	| PRINT ID
	 {
			indiceAux = crearTerceto(yylval.str_val,"_","_");
			crearTerceto("PRINT",armarIndiceI(indiceAux),"_");
		}
	|
	PRINT CONST_STR
	{
		indiceAux = crearTerceto(yylval.str_val,"_","_");
		crearTerceto("DISPLAY",armarIndiceI(indiceAux),"_");
	};



seleccion:
	IF CAR_PA condicion CAR_PC THEN
	bloque
	{printf("\t\tIF\n");}
	ENDIF
	{
		printf("\t\tENDIF\n");
		int indiceDesapilado;
		int indiceActual = obtenerIndiceActual();
		if(pila_vacia(&pila_condicion_doble) == PILA_VACIA)
		{
			sacar_de_pila(&pila, &indiceDesapilado);
			modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual));
		}
		else
		{
			if(strcmp(condicion,"AND") == 0)
			{
				sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
				modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual));
				sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
				modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual));
			}
			if(strcmp(condicion,"OR") == 0)
			{
				sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
				modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual));
				sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
				modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceComparador+1));
			}
		}
	}
	|
	IF CAR_PA condicion CAR_PC THEN
	bloque {printf("\t\tIF\n");}
	ELSE
	{
		printf("\t\tELSE\n");
		int indiceDesapilado;
		int indiceActual = obtenerIndiceActual();
		if(pila_vacia(&pila_condicion_doble) == PILA_VACIA)
		{
			sacar_de_pila(&pila, &indiceDesapilado);
			modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual+1));
		}
		else
		{
			if(strcmp(condicion,"AND") == 0)
			{
				sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
				modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual+1));
				sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
				modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual+1));
			}
			if(strcmp(condicion,"OR") == 0)
			{
				sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
				modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual+1));
				sacar_de_pila(&pila_condicion_doble, &indiceDesapilado);
				modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceComparador+1));
			}
		}
		indiceAux = crearTerceto("JMP","_","_");
		poner_en_pila(&pila, &indiceAux);

		startEtiqueta = 0;
	}
	bloque
	ENDIF
	 {
		printf("\t\tENDIF (con else)\n");
		int indiceDesapilado;
		int indiceActual = obtenerIndiceActual();
		sacar_de_pila(&pila, &indiceDesapilado);
		modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual));
	}	;


condicion:
			comparacion
			{
				printf("\t\tCOMPARACION\n");

				startEtiqueta = 0;
			}
			| OP_NOT comparacion
			{	printf("\t\tCONDICION NOT\n");
				char *operador = obtenerTerceto(indiceComparador,1);
				char *operadorNegado = negarComparador(operador);
				modificarTerceto(indiceComparador,1,operadorNegado);

				startEtiqueta = 0;
			}
			| comparacion { indiceComparador1 = indiceComparador; } OP_AND comparacion
			{
				printf("\t\tCONDICION DOBLE AND\n");
				indiceComparador2 = indiceComparador;
				strcpy(condicion, "AND");
				poner_en_pila(&pila_condicion_doble,&indiceComparador1);
				poner_en_pila(&pila_condicion_doble,&indiceComparador2);

				startEtiqueta = 0;
			}
			| comparacion
					{
						indiceComparador1 = indiceComparador;
						char *operador = obtenerTerceto(indiceComparador1,1);
						char *operadorNegado = negarComparador(operador);
						modificarTerceto(indiceComparador1,1,operadorNegado);
						startEtiqueta = 0;
				}
		OP_OR comparacion
		{
				printf("\t\tCONDICION DOBLE OR\n");
				indiceComparador2 = indiceComparador;
				strcpy(condicion, "OR");
				poner_en_pila(&pila_condicion_doble,&indiceComparador1);
				poner_en_pila(&pila_condicion_doble,&indiceComparador2);

				startEtiqueta = 0;
			}	;

comparacion:
				{printf("\t\tENTRO COMPARAXION\n");}
	   		expresion comparador expresion
				{
				{printf("\t\tENTRO COMPARADOR\n");}
				compararTipos();
				indiceDer = indiceExpresion;
				crearTerceto("CMP",armarIndiceI(indiceIzq),armarIndiceD(indiceDer));
				char comparadorDesapilado[8];
				sacar_de_pila(&pila, &comparadorDesapilado);
				indiceComparador = crearTerceto(comparadorDesapilado,"_","_");
				poner_en_pila(&pila,&indiceComparador);
			};

comparador:
			CMP_MAYOR
				{
					printf("\t\tENTRO A COMPARADOR");
					//char comparadorApilado[8] = "BLE";
					char comparadorApilado[8] = "JA";
					poner_en_pila(&pila,&comparadorApilado);
				}
				| CMP_MENOR
				{
					// char comparadorApilado[8] = "BGE";
					char comparadorApilado[8] = "JB";
					poner_en_pila(&pila,&comparadorApilado);
				}
				| CMP_MAYORIGUAL
				{
					// char comparadorApilado[8] = "BLT";
					char comparadorApilado[8] = "JAE";
					poner_en_pila(&pila,&comparadorApilado);
				}
				| CMP_MENORIGUAL
				{
					// char comparadorApilado[8] = "BGT";
					char comparadorApilado[8] = "JBE";
					poner_en_pila(&pila,&comparadorApilado);
				}
				| CMP_IGUAL
				{
					// char comparadorApilado[8] = "BNE";
					char comparadorApilado[8] = "JE";
					poner_en_pila(&pila,&comparadorApilado);
				}
				| CMP_DISTINTO
				{
					// char comparadorApilado[8] = "BEQ";
					char comparadorApilado[8] = "JNE";
					poner_en_pila(&pila,&comparadorApilado);
				} ;

			expresion:
				{printf("\t\tENTRO A EXPRESOPM");}
				termino	//{	indiceExpresion = indiceTermino;	}
				{printf("\t\tPASO TERMINO");}
				| expresion OP_SUM termino
				{
					//indiceExpresion = crearTerceto("+",armarIndiceI(indiceExpresion),armarIndiceD(indiceTermino));
				}
				| expresion OP_RES termino
				{
					//indiceExpresion = crearTerceto("-",armarIndiceI(indiceExpresion),armarIndiceD(indiceTermino));
				};

			termino:
			  {printf("\t\tENTRO TERMINO");}
				factor	//{	indiceTermino = indiceFactor;	}
				{printf("\t\tPASO FACTOR");}
				| termino OP_MUL factor
				{
					indiceTermino = crearTerceto("*",armarIndiceI(indiceTermino),armarIndiceD(indiceFactor));
				}
				| termino OP_DIV factor
				{
					indiceTermino = crearTerceto("/",armarIndiceI(indiceTermino),armarIndiceD(indiceFactor));
				}	;

			factor:
				{printf("\t\tENTRO FACTOR\n");}
				ID
				{ printf("\t\tENTRO ID\n");
					if(startEtiqueta == 0)
					{
						crearTerceto(obtenerNuevoNombreEtiqueta("inicio"),"_","_");
						startEtiqueta = 1;
						printf("\t\t\tID crear terceto paso\n");
					}
					printf("\t\tPto COntrol\n");
					insertarEnArrayComparacionTipos(yylval.str_val);
					indiceFactor = crearTerceto(yylval.str_val,"_","_");
					printf("\t\tSALIO ID\n");

				}
				| CONST_INT
				{
					if(startEtiqueta == 0)
					{
						crearTerceto(obtenerNuevoNombreEtiqueta("inicio"),"_","_");
						startEtiqueta = 1;
					}
					insertarEnArrayComparacionTipos(yylval.str_val);
					indiceFactor = crearTerceto(yylval.str_val,"_","_");
				}
				| CONST_REAL
				{
					if(startEtiqueta == 0)
					{
						crearTerceto(obtenerNuevoNombreEtiqueta("inicio"),"_","_");
						startEtiqueta = 1;
					}
					insertarEnArrayComparacionTipos(yylval.str_val);
					indiceFactor = crearTerceto(yylval.str_val,"_","_");
				}
				| CONST_STR
				{
					if(startEtiqueta == 0)
					{
						crearTerceto(obtenerNuevoNombreEtiqueta("inicio"),"_","_");
						startEtiqueta = 1;
					}
					insertarEnArrayComparacionTipos(yylval.str_val);
					indiceFactor = crearTerceto(yylval.str_val,"_","_");
				}
				| CAR_PA expresion CAR_PC;

%%


// Sección código
int main(int argc, char *argv[])
{
    if ((yyin = fopen(argv[1], "rt")) == NULL)
    {
		printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    }
    else
    {
		yyparse();
    }
    fclose(yyin);
    return 0;
}

int yyerror(char *msg)
{
    fflush(stderr);
    fprintf(stderr, "\n\n--- ERROR EN COMPILACION ---\nEn linea %d: %s.\n\n", yylineno, msg);
    exit(1);
}

void insertarEnArrayDeclaracion(char * val)
{
    char * aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
		printf("VALORRRR:  %s\n",val);
    strcpy(aux, val);
    arrayDeclaraciones[longitud_arrayDeclaraciones] = aux;
    longitud_arrayDeclaraciones++;
}

char * guardarTipoDato(char * val)
{
	char * aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
	strcpy(aux, val);
	tipoDato = aux;
}
void validarDeclaracionTipoDato(char * tipo)
{
	int i;
	for (i=0; i < longitud_arrayDeclaraciones; i++)
	{
		if(existeTokenEnTS(arrayDeclaraciones[i]) == NO_EXISTE)
		{
			insertarTokenEnTS(tipo,arrayDeclaraciones[i]);
		}
		else
		{
			char msg[300];
			sprintf(msg, "ERROR en etapa GCI - Variable \'%s\' ya declarada", arrayDeclaraciones[i]);
			yyerror(msg);
		}
	}
	// Reinicio el contador para leer otro tipo de dato
	longitud_arrayDeclaraciones = 0;
}

char * negarComparador(char* comparador)
{
	if(strcmp(comparador,"JA") == 0)
		return "JBE";
	if(strcmp(comparador,"JB") == 0)
		return "JAE";
	if(strcmp(comparador,"JNB") == 0)
		return "JB";
	if(strcmp(comparador,"JBE") == 0)
		return "JA";
	if(strcmp(comparador,"JE") == 0)
		return "JNE";
	if(strcmp(comparador,"JNE") == 0)
		return "JE";
	return NULL;
}

char * obtenerNuevoNombreEtiqueta(char * val)
{
	static char nombreEtiqueta[50];
	int indiceActualTerceto = obtenerIndiceActual();
	sprintf(nombreEtiqueta, "ETIQ_%s_%d", val, indiceActualTerceto);
	return nombreEtiqueta;
}

void insertarEnArrayComparacionTipos(char * val)
{
	printf("VAL:  %s\n",val);
	// Primero corroboramos existencia del token en la tabla de simbolos

	if(existeTokenEnTS(yylval.str_val) == NO_EXISTE)
	{
		printf("\t\tENTRO EN IF");
		char msg[300];
		sprintf(msg, "ERROR en etapa GCI - Variable \'%s\' no declarada en la seccion declaracion", yylval.str_val);
		yyerror(msg);
	}
  printf("\t\tSALIO DEL IF");
	// Luego insertamos el tipo de token en nuestro array
	char * tipo = recuperarTipoTS(val);
	printf("DEVOLUCION DE LA FUNCION recuperarTipoTS:  %s\n",tipo);
	tipo = tipoConstanteConvertido(tipo);
	printf("\t\tSALIO DE CONSTANTE");
	printf("DEVOLUCION DE LA FUNCION tipoConstanteConvertido: %s\n",tipo);
	char * aux = (char *) malloc(sizeof(strlen(tipo) + 1));
	strcpy(aux, tipo);
	printf("DEVOLUCION DE ASIGNACION DE AUX : %s\n",aux);
  arrayComparacionTipos[longitud_arrayComparacionTipos] = aux;
  longitud_arrayComparacionTipos++;
}

void insertarEnArrayComparacionTiposDirecto(char * tipo)
{
    char * aux = (char *) malloc(sizeof(char) * (strlen(tipo) + 1));
	strcpy(aux, tipo);
    arrayComparacionTipos[longitud_arrayComparacionTipos] = aux;
    longitud_arrayComparacionTipos++;
}

void imprimirArrayComparacionTipos()
{
	printf("\n ARRAY DE TIPOS: ");
	int i;
	for (i=0; i < longitud_arrayComparacionTipos; i++)
	{
		printf("\n %s ", arrayComparacionTipos[i]);
	}
}

void compararTipos()
{
	// imprimirArrayComparacionTipos();
	char* tipoBase = arrayComparacionTipos[0];
	int i;
	for (i=1; i < longitud_arrayComparacionTipos; i++)
	{
		char* tipoAComparar = arrayComparacionTipos[i];
		if(strcmp(tipoBase, tipoAComparar) != 0)
		{
			char msg[300];
		    sprintf(msg, "ERROR en etapa GCI - Tipo de datos incompatibles. Tipo 1: \'%s\' Tipo 2: \'%s\'", tipoBase, tipoAComparar);
			yyerror(msg);
		}
	}
	longitud_arrayComparacionTipos = 0;
}

char * tipoConstanteConvertido(char* tipoVar)
{
	if(strcmp(tipoVar, "INTEGER") != 0 && strcmp(tipoVar, "REAL") != 0 && strcmp(tipoVar, "STRING") != 0)
	{
		if(strcmp(tipoVar, "CONST_INT") == 0)
		{
			return "INTEGER";
		}
		else
			if(strcmp(tipoVar, "CONST_REAL") == 0)
			{
				return "REAL";
			}
			else
				if(strcmp(tipoVar, "CONST_STR") == 0)
				{
					return "STRING";
				}
				else
				{
					return NULL;
				}
	}
	return tipoVar;
}
