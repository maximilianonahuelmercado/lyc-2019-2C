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
		void insertarEnArrayDeclaracion(char **);
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
		void guardarTipoDato(char *);


		// Declaro la pila (estructura externa que me servira para resolver GCI)
		t_pila pila;
		t_pila pila_condicion_doble;
		t_pila pila_ciclo_especial;
		t_pila pilaDatos;
		t_pila pilaTemporal;
		t_pila pilaDatosInversa;
		char condicion[5];

		// Para assembler
		FILE * pfASM; // Final.asm
		t_pila pila;  // Pila saltos
		t_pila pVariables;  // Pila variables

		void generarASM();
		void generarEncabezado();
		void generarDatos();
		void generarCodigo();
		void imprimirInstrucciones();
		void generarFin();

		int startEtiqueta = 0;



		// Arrays
		char * arrayDeclaraciones[100];	// array para declaraciones
		char * arrayTipoDato[100]; // array para tipos de dato
		int longitud_arrayDeclaraciones = 0; // incremento en el array arrayDeclaraciones
		int longitud_arrayTipoDato = 0; // incremento en el arrayTipoDato
		char * arrayComparacionTipos[100];	// array para comparar tipos
		int longitud_arrayComparacionTipos = 0; // incremento en el array arrayComparacionTipos
		char * tipoDato[100];
    char * ids[100];

		// Auxiliar para manejar tercetos;
		int indiceExpresion, indiceTermino, indiceFactor, indiceLongitud;
		int indiceAux, indiceUltimo, indiceIzq, indiceDer, indiceComparador, indiceComparador1, indiceComparador2,
		indiceId;
		int indicePrincipioBloque;
		char idAsignarStr[50];


		int startEtiqueta = 0;
%}



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
	{	printf("\tInicia el COMPILADOR\n\n");
		crear_pila(&pilaDatos);
		crear_pila(&pilaTemporal);


	}

	est_declaracion bloque
	{	printf("\n\tFin COMPILADOR OK\n");
		prepararTSParaAssembler();
		crearArchivoTS();
		crearArchivoTercetosIntermedia();
		generarASM();
	}	;

est_declaracion:
	VAR {	printf("\t\tDECLARACIONES VAR\n");	}
	declaraciones
	ENDVAR {	printf("\t\tFIN DECLARACIONES ENDVAR\n");	}	;

declaraciones:
declaracion | declaraciones declaracion;

declaracion:
	CAR_CA NODO
	{
			while((pila_vacia(&pilaDatos) != PILA_VACIA ) && (pila_vacia(&pilaTemporal) != PILA_VACIA))
			{
				sacar_de_pila(&pilaTemporal, &tipoDato);
			  sacar_de_pila(&pilaDatos, &ids);
				insertarEnArrayDeclaracion(ids);
				printf("TIPO: %s", tipoDato);
				if(strcmp(&tipoDato, "STRING") == 0)
				{
					printf("\tENTRE POR STRING");
					validarDeclaracionTipoDato("STRING");
				}
				else{
						if(strcmp(tipoDato, "REAL") == 0)
							{
									printf("\tENTRE POR REAL");
									validarDeclaracionTipoDato("REAL");
							}

						else{
							printf("\tENTRE POR INTEGER");
							validarDeclaracionTipoDato("INTEGER");
						}
				}
			}
  }
 CAR_CC;

NODO:
TIPO_DATO CAR_CC OP_DOSP CAR_CA ID
{
	poner_en_pila(&pilaDatos, yylval.str_val);
};
NODO:
	TIPO_DATO CAR_COMA NODO CAR_COMA ID
	{
		poner_en_pila(&pilaDatos, yylval.str_val);
	};

TIPO_DATO:

	STRING {
	poner_en_pila(&pilaTemporal, "STRING");
	}
	|
	INTEGER {
	 poner_en_pila(&pilaTemporal, "INTEGER");

	}
	| REAL{
		poner_en_pila(&pilaTemporal, "REAL");

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
		indiceAux=crearTerceto(obtenerNuevoNombreEtiqueta("inicio_repeat"),"_","_");
		poner_en_pila(&pila,&indiceAux);
	}
	{printf("\t\tPASA REPEAT\n");}
	CAR_PA condicion CAR_PC
	{
		printf("\t\tPASA CONDICION\n");
		indicePrincipioBloque = obtenerIndiceActual();
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

void insertarEnArrayDeclaracion(char ** val)
{
    char * aux = (char *) malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(aux, val);
    arrayDeclaraciones[longitud_arrayDeclaraciones] = aux;
		printf("\t\t\tArrayDeclaraciones: %s\n", arrayDeclaraciones[longitud_arrayDeclaraciones]);
    longitud_arrayDeclaraciones++;
}


void validarDeclaracionTipoDato(char * tipo)
{
	printf("ENTRE A validarDeclaracionTipoDato\n");
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

//////// ASSEMBLER ///////
//Funcion que se encarga de generar el archivo y completarlo
void generarASM(){
    // Crear archivo
	pfASM = fopen("Final.asm", "w");

    // Crear pilas para sacar los tercetos.

    crear_pila(&pVariables);

    generarEncabezado();
    generarDatos();
    generarCodigo();
    generarFin();

    // Cerrar archivo
    fclose(pfASM);
}

void generarEncabezado(){
    fprintf(pfASM, "\nINCLUDE macros2.asm\t\t ;incluye macros\n");
    fprintf(pfASM, "INCLUDE number.asm\t\t ;incluye el asm para impresion de numeros\n");
    fprintf(pfASM, "\n.MODEL LARGE\t\t ; tipo del modelo de memoria usado.\n");
    fprintf(pfASM, ".386\n");
	fprintf(pfASM, ".387\n");
    fprintf(pfASM, ".STACK 200h\t\t ; bytes en el stack\n");
}

void generarDatos(){
    //Encabezado del sector de datos
    fprintf(pfASM, "\t\n.DATA\t\t ; comienzo de la zona de datos.\n");
    fprintf(pfASM, "\tTRUE equ 1\n");
    fprintf(pfASM, "\tFALSE equ 0\n");
    fprintf(pfASM, "\tMAXTEXTSIZE equ %d\n",COTA_STR);


    // fprintf(arch, "NEW_LINE DB 0AH,0DH,'$'\n");
	// fprintf(arch, "CWprevio DW ?\n");

	int i;
	int tamTS = obtenerTamTS();
	for(i=0; i<tamTS; i++)
	{
		if(strcmp(tablaSimbolos[i].tipo, "INTEGER") == 0 )
		{
			fprintf(pfASM, "\t%s dd 0\n",tablaSimbolos[i].nombre);
		}
		if(strcmp(tablaSimbolos[i].tipo, "REAL") == 0 )
		{
			fprintf(pfASM, "\t%s dd 0.0\n",tablaSimbolos[i].nombre);
		}
		if(strcmp(tablaSimbolos[i].tipo, "STRING") == 0 )
		{
			fprintf(pfASM, "\t%s db MAXTEXTSIZE dup(?), '$'\n",tablaSimbolos[i].nombre);
		}
		if(strcmp(tablaSimbolos[i].tipo, "CONST_INT") == 0 || strcmp(tablaSimbolos[i].tipo, "CONST_REAL") == 0 )
		{
            fprintf(pfASM, "\t%s dd %s\n",tablaSimbolos[i].nombre, tablaSimbolos[i].valor);
		}
		if(strcmp(tablaSimbolos[i].tipo, "CONST_STR") == 0)
		{
			int longitud = strlen(tablaSimbolos[i].valor);
			int size = COTA_STR - longitud;
			fprintf(pfASM, "\t%s db %s, '$', %d dup(?)\n", tablaSimbolos[i].nombre, tablaSimbolos[i].valor, size);
		}
	}
	// Auxiliares declarados
	int tamTercetos = obtenerIndiceActual();
	for(i=0; i<tamTercetos; i++)
	{
		if(strstr(tercetos[i].operador, "ETIQ") == NULL)
		{
			fprintf(pfASM, "\t@aux%d dd 0.0\n",i);
		}
	}
}

void imprimirFuncString(){
    int c;
    FILE *file;
    file = fopen("string.asm", "r");
    if (file) {
        fprintf(pfASM,"\n");
        while ((c = getc(file)) != EOF)
            fprintf(pfASM,"%c",c);
        fprintf(pfASM,"\n\n");
        fclose(file);
    }
}

void generarCodigo(){
    fprintf(pfASM, "\n.CODE ;Comienzo de la zona de codigo\n");

	//Imprimo funciones de manejo de strings
    imprimirFuncString();

    //Inicio codigo usuario
    fprintf(pfASM, "START: \t\t;Código assembler resultante de compilar el programa fuente.\n");
    fprintf(pfASM, "\tmov AX,@DATA \t\t;Inicializa el segmento de datos\n");
    fprintf(pfASM, "\tmov DS,AX\n");
    fprintf(pfASM, "\tfinit\n\n");

	int i;
	int tamTercetos = obtenerIndiceActual();

	char aux1[50];
	char aux2[50];

	char auxEtiqueta[50];

	int flag;
	for(i=0; i<tamTercetos; i++)
	{
		// sprintf(auxEtiqueta,"ETIQUETA%d:",i);
		char operador[50];
		strcpy(operador,tercetos[i].operador);
		flag = 0;

		if(strcmp(operador, "=") == 0)
		{
			flag = 1;
			fprintf(pfASM,"\t;ASIGNACIÓN\n");
			sacar_de_pila(&pVariables,&aux2);
			sacar_de_pila(&pVariables,&aux1);

			char * tipo = recuperarTipoTS(aux1);
    		char auxTipo[50] = "";
			strcpy(auxTipo, tipo);

			// fprintf(pfASM,"\t%s\n",auxEtiqueta);

			if(strcmp(tipo,"CONST_STR") == 0 || strcmp(tipo,"STRING") == 0)
			{
				fprintf(pfASM, "\tmov ax,@DATA\n");
                fprintf(pfASM, "\tmov es,ax\n");
                fprintf(pfASM, "\tmov si,OFFSET %s ;apunta el origen al auxiliar\n",aux1);
                fprintf(pfASM, "\tmov di,OFFSET %s ;apunta el destino a la cadena\n",aux2);
				fprintf(pfASM, "\tcall COPIAR ;copia los string\n\n");
			}
			else
			{
				fprintf(pfASM, "\tfld %s\n",aux1);
                fprintf(pfASM, "\tfstp %s\n\n",aux2);
			}

		}

		if(strcmp(operador, "CMP") == 0)
		{
			flag = 1;
			fprintf(pfASM,"\t;CMP\n");
			sacar_de_pila(&pVariables,&aux2);
			sacar_de_pila(&pVariables,&aux1);

			// fprintf(pfASM,"\t%s\n",auxEtiqueta);
			fprintf(pfASM, "\tfld %s\n",aux1);
            fprintf(pfASM, "\tfld %s\n",aux2);
            fprintf(pfASM, "\tfcomp\n");
            fprintf(pfASM, "\tfstsw ax\n");
            fprintf(pfASM, "\tfwait\n");
            fprintf(pfASM, "\tsahf\n\n");
		}

		if(strstr(operador, "ETIQ") != NULL)
		{
			flag = 1;
			fprintf(pfASM,"\n\n%s:\n",operador);
		}

		if(strcmp(operador, "JMP") == 0)
		{
			flag = 1;
			int indiceIzquierdo = desarmarIndice(tercetos[i].operandoIzq);
			char* etiqueta = obtenerTerceto(indiceIzquierdo, 1);
            fprintf(pfASM, "\tjmp %s\n",etiqueta);
		}

		if(strcmp(operador, "JE") == 0)
		{
			flag = 1;
			int indiceIzquierdo = desarmarIndice(tercetos[i].operandoIzq);
			char* etiqueta = obtenerTerceto(indiceIzquierdo, 1);
            fprintf(pfASM, "\tje %s\n",etiqueta);
		}

		if(strcmp(operador, "JNE") == 0)
		{
			flag = 1;
			int indiceIzquierdo = desarmarIndice(tercetos[i].operandoIzq);
			char* etiqueta = obtenerTerceto(indiceIzquierdo, 1);
            fprintf(pfASM, "\tjne %s\n", etiqueta);
		}

		if(strcmp(operador, "JB") == 0)
		{
			flag = 1;
			int indiceIzquierdo = desarmarIndice(tercetos[i].operandoIzq);
			char* etiqueta = obtenerTerceto(indiceIzquierdo, 1);
            fprintf(pfASM, "\tjb %s\n", etiqueta);
		}

		if(strcmp(operador, "JBE") == 0)
		{
			flag = 1;
			int indiceIzquierdo = desarmarIndice(tercetos[i].operandoIzq);
			char* etiqueta = obtenerTerceto(indiceIzquierdo, 1);
            fprintf(pfASM, "\tjbe %s\n", etiqueta);
		}

		if(strcmp(operador, "JA") == 0)
		{
			flag = 1;
			int indiceIzquierdo = desarmarIndice(tercetos[i].operandoIzq);
			char* etiqueta = obtenerTerceto(indiceIzquierdo, 1);
            fprintf(pfASM, "\tja %s\n", etiqueta);
		}

		if(strcmp(operador, "JAE") == 0)
		{
			flag = 1;
			int indiceIzquierdo = desarmarIndice(tercetos[i].operandoIzq);
			char* etiqueta = obtenerTerceto(indiceIzquierdo, 1);
            fprintf(pfASM, "\tjae %s\n", etiqueta);
		}

		if(strcmp(operador, "-") == 0)
		{
			flag = 1;
			fprintf(pfASM,"\t;RESTA\n");
			sacar_de_pila(&pVariables,&aux2);
			sacar_de_pila(&pVariables,&aux1);

			// fprintf(pfASM,"\t%s\n",auxEtiqueta);
            fprintf(pfASM, "\tfld %s\n",aux1);
            fprintf(pfASM, "\tfld %s\n",aux2);
            fprintf(pfASM, "\tfsub\n");

			char auxStr[50] = "";
			sprintf(auxStr, "@aux%d",i);
			fprintf(pfASM, "\tfstp %s\n\n",auxStr);
			insertarTokenEnTS("",auxStr);
			poner_en_pila(&pVariables,&auxStr);
		}

		if(strcmp(operador, "+") == 0)
		{
			flag = 1;
			fprintf(pfASM,"\t;SUMA\n");
			sacar_de_pila(&pVariables,&aux2);
			sacar_de_pila(&pVariables,&aux1);

			// fprintf(pfASM,"\t%s\n",auxEtiqueta);
			fprintf(pfASM, "\tfld %s\n",aux1);
            fprintf(pfASM, "\tfld %s\n",aux2);
            fprintf(pfASM, "\tfadd\n");

			char auxStr[50] = "";
			sprintf(auxStr, "@aux%d",i);
			fprintf(pfASM, "\tfstp %s\n\n",auxStr);
			insertarTokenEnTS("",auxStr);
			poner_en_pila(&pVariables,&auxStr);
		}

		if(strcmp(operador, "*") == 0)
		{
			flag = 1;
			fprintf(pfASM,"\t;MULTIPLICACION\n");
			sacar_de_pila(&pVariables,&aux2);
			sacar_de_pila(&pVariables,&aux1);

			// fprintf(pfASM,"\t%s\n",auxEtiqueta);
			fprintf(pfASM, "\tfld %s\n",aux1);
            fprintf(pfASM, "\tfld %s\n",aux2);
            fprintf(pfASM, "\tfmul\n");

			char auxStr[50] = "";
			sprintf(auxStr, "@aux%d",i);
			fprintf(pfASM, "\tfstp %s\n\n",auxStr);
			insertarTokenEnTS("",auxStr);
			poner_en_pila(&pVariables,&auxStr);
		}

		if(strcmp(operador, "/") == 0)
		{
			flag = 1;
			fprintf(pfASM,"\t;DIVISION\n");
			sacar_de_pila(&pVariables,&aux2);
			sacar_de_pila(&pVariables,&aux1);

			// fprintf(pfASM,"\t%s\n",auxEtiqueta);
			fprintf(pfASM, "\tfld %s\n",aux1);
            fprintf(pfASM, "\tfld %s\n",aux2);
            fprintf(pfASM, "\tfdiv\n");

			char auxStr[50] = "";
			sprintf(auxStr, "@aux%d",i);
			fprintf(pfASM, "\tfstp %s\n\n",auxStr);
			insertarTokenEnTS("",auxStr);
			poner_en_pila(&pVariables,&auxStr);
		}

		if(strcmp(operador, "GET") == 0)
		{
			flag = 1;
			fprintf(pfASM,"\t;GET\n");
			sacar_de_pila(&pVariables,&aux1);

			char * tipo = recuperarTipoTS(aux1);
    		char auxTipo[50] = "";
			strcpy(auxTipo, tipo);

			// fprintf(pfASM,"\t%s\n",auxEtiqueta);
			if(strcmp(tipo,"CONST_STR") == 0 || strcmp(tipo,"STRING") == 0)
			{
				fprintf(pfASM,"\tdisplayString %s\n",aux1);
                fprintf(pfASM, "\tnewLine 1\n\n");
			}
			if(strcmp(tipo,"CONST_INT") == 0 || strcmp(tipo,"INTEGER") == 0)
			{
   				fprintf(pfASM,"\tDisplayInteger %s 2\n",aux1);
                fprintf(pfASM, "\tnewLine 1\n\n");
			}
			if(strcmp(tipo,"CONST_REAL") == 0 || strcmp(tipo,"REAL") == 0)
			{
				fprintf(pfASM,"\tDisplayFloat %s 2\n",aux1);
                fprintf(pfASM, "\tnewLine 1\n\n");
			}
		}

		if(strcmp(operador, "DISPLAY") == 0)
		{
			flag = 1;
			fprintf(pfASM,"\t;DISPLAY\n");
			sacar_de_pila(&pVariables,&aux1);

			char * tipo = recuperarTipoTS(aux1);
    		char auxTipo[50] = "";
			strcpy(auxTipo, tipo);

			// fprintf(pfASM,"\t%s\n",auxEtiqueta);
			if(strcmp(tipo,"CONST_STR") == 0 || strcmp(tipo,"STRING") == 0)
			{
				fprintf(pfASM,"\tgetString %s\n\n",aux1);
			}
			else
			{
				fprintf(pfASM,"\tGetFloat %s\n\n",aux1);
			}
		}

		if(flag == 0)
		{
			char * nombre = recuperarNombreTS(operador);
			char auxNombre[50] = "";
			strcpy(auxNombre, nombre);
            poner_en_pila(&pVariables,&auxNombre);
		}

	}

	while(pila_vacia(&pVariables) != PILA_VACIA)
	{
		char varApilada[50] = "";
		sacar_de_pila(&pVariables, &varApilada);
		printf("\n Se saco de pila: %s ", varApilada);
	}
}

void generarFin(){
    fprintf(pfASM, "\nTERMINAR: ;Fin de ejecución.\n");
    fprintf(pfASM, "\tmov ax, 4C00h ;termina la ejecución.\n");
    fprintf(pfASM, "\tint 21h ;syscall\n");
    fprintf(pfASM, "\nEND START ;final del archivo.");
}
