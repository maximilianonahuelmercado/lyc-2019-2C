
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR = 258,
     ENDVAR = 259,
     REAL = 260,
     INTEGER = 261,
     STRING = 262,
     IF = 263,
     THEN = 264,
     ELSE = 265,
     ENDIF = 266,
     REPEAT = 267,
     ENDREPEAT = 268,
     MOD = 269,
     DIV = 270,
     INLIST = 271,
     OP_AND = 272,
     OP_OR = 273,
     OP_NOT = 274,
     CMP_MAYOR = 275,
     CMP_MENOR = 276,
     CMP_MAYORIGUAL = 277,
     CMP_MENORIGUAL = 278,
     CMP_DISTINTO = 279,
     CMP_IGUAL = 280,
     OP_ASIG = 281,
     OP_DOSP = 282,
     OP_SUM = 283,
     OP_RES = 284,
     OP_MUL = 285,
     OP_DIV = 286,
     CAR_COMA = 287,
     CAR_PUNTO = 288,
     CAR_PYC = 289,
     CAR_PA = 290,
     CAR_PC = 291,
     CAR_CA = 292,
     CAR_CC = 293,
     CAR_LA = 294,
     CAR_LC = 295,
     PRINT = 296,
     READ = 297,
     CONST_INT = 298,
     CONST_REAL = 299,
     CONST_STR = 300,
     ID = 301
   };
#endif
/* Tokens.  */
#define VAR 258
#define ENDVAR 259
#define REAL 260
#define INTEGER 261
#define STRING 262
#define IF 263
#define THEN 264
#define ELSE 265
#define ENDIF 266
#define REPEAT 267
#define ENDREPEAT 268
#define MOD 269
#define DIV 270
#define INLIST 271
#define OP_AND 272
#define OP_OR 273
#define OP_NOT 274
#define CMP_MAYOR 275
#define CMP_MENOR 276
#define CMP_MAYORIGUAL 277
#define CMP_MENORIGUAL 278
#define CMP_DISTINTO 279
#define CMP_IGUAL 280
#define OP_ASIG 281
#define OP_DOSP 282
#define OP_SUM 283
#define OP_RES 284
#define OP_MUL 285
#define OP_DIV 286
#define CAR_COMA 287
#define CAR_PUNTO 288
#define CAR_PYC 289
#define CAR_PA 290
#define CAR_PC 291
#define CAR_CA 292
#define CAR_CC 293
#define CAR_LA 294
#define CAR_LC 295
#define PRINT 296
#define READ 297
#define CONST_INT 298
#define CONST_REAL 299
#define CONST_STR 300
#define ID 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 70 "Sintactico.y"

	char * int_val;
	char * real_val;
	char * str_val;
	char * cmp_val;



/* Line 1676 of yacc.c  */
#line 153 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


