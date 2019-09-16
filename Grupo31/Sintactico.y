%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "files_h/constantes.h"
	#include "files_h/ts.h"

	// Declaraciones onbligatorias para quitar advertencias
	int yylineno;
	FILE  *yyin;
	int yylex();
	int yyerror(char *msg);
	int yyparse();
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
		bloque
	{	printf("\n\tFin COMPILADOR OK\n");
		crearArchivoTS();
	}	;

est_declaracion:
	VAR {	printf("\t\tDECLARACIONES VAR\n");	}
	declaracion
	ENDVAR {	printf("\t\tFIN DECLARACIONES ENDVAR\n");	}	;

declaracion:
	CAR_CA NODO CAR_CC;

NODO:
	TIPO_DATO CAR_CC OP_DOSP CAR_CA ID;
NODO:
	TIPO_DATO CAR_COMA NODO CAR_COMA ID;
TIPO_DATO:
	INTEGER | REAL | STRING ;

bloque:
	sentencia
	| bloque sentencia;

sentencia:
	ciclo
	| seleccion
	| asignacion
	| entrada_salida
	| est_declaracion
	| modulo
	| division
	| inlist;

ciclo:
	REPEAT
	{	printf("\t\tREPEAT\n");
	}
	CAR_PA condicion CAR_PC
	bloque
	ENDREPEAT
	{	printf("\t\tENDREPEAT\n");
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
			| lista_expresiones CAR_PYC expresion ;

asignacion:
				lista_id expresion
			{	printf("\t\tASIGNACION\n");
		};

lista_id:
	ID OP_ASIG;

entrada_salida:
	READ	ID
	{printf("\t\tREAD\n");}
	| PRINT ID
	{printf("\t\tPRINT\n");}
	|
	PRINT CONST_STR
	{printf("\t\tPRINT\n");};


seleccion:
	IF CAR_PA condicion CAR_PC THEN
	bloque
	{printf("\t\tIF\n");}
	ENDIF {printf("\t\tENDIF\n");}
	|
	IF CAR_PA condicion CAR_PC THEN
	bloque {printf("\t\tIF\n");}
	ELSE {printf("\t\tELSE\n");}
	bloque
	ENDIF {printf("\t\tENDIF\n");} ;

condicion:
			comparacion
			| OP_NOT comparacion
			{	printf("\t\tCONDICION NOT\n");
			}
			| comparacion OP_AND comparacion
			{	printf("\t\tCONDICION DOBLE AND\n");
			}
			| comparacion OP_OR comparacion
			{	printf("\t\tCONDICION DOBLE OR\n");
			}	;

comparacion:
	   		expresion comparador expresion;

comparador:
	CMP_MAYOR
	| CMP_MENOR

	| CMP_MAYORIGUAL

	| CMP_MENORIGUAL

	| CMP_IGUAL

	| CMP_DISTINTO;

expresion:
	termino
	| expresion OP_SUM termino

	| expresion OP_RES termino;

termino:
	factor
	| termino OP_MUL factor

	| termino OP_DIV factor;

factor:
	ID
	| CONST_INT

	| CONST_REAL

	| CONST_STR

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
