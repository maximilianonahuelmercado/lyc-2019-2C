
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "files_h/tercetos.h"
	#include "files_h/constantes.h"
	#include "files_h/ts.h"
	#include "files_h/pila.h"
	#include "files_h/cola.h"

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
		void guardarTipoDato(char *);


		// Declaro la pila (estructura externa que me servira para resolver GCI)
		t_pila pila;
		t_pila pila_condicion_doble;
		t_pila pila_ciclo_especial;
		t_pila pilaDatos;
		t_pila pilaDatosInversa;
		char condicion[5]; // puede ser AND u OR

		t_cola cola;



		// Arrays
		char * arrayDeclaraciones[100];	// array para declaraciones
		char * arrayTipoDato[100]; // array para tipos de dato
		int longitud_arrayDeclaraciones = 0; // incremento en el array arrayDeclaraciones
		int longitud_arrayTipoDato = 0; // incremento en el arrayTipoDato
		char * arrayComparacionTipos[100];	// array para comparar tipos
		int longitud_arrayComparacionTipos = 0; // incremento en el array arrayComparacionTipos
		char * tipoDato;

		// Auxiliar para manejar tercetos;
		int indiceExpresion, indiceTermino, indiceFactor, indiceLongitud;
		int indiceAux, indiceUltimo, indiceIzq, indiceDer, indiceComparador, indiceComparador1, indiceComparador2,
		indiceId;
		int indicePrincipioBloque;
		char idAsignarStr[50];


		int startEtiqueta = 0;


/* Line 189 of yacc.c  */
#line 139 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 70 "Sintactico.y"

	char * int_val;
	char * real_val;
	char * str_val;
	char * cmp_val;



/* Line 214 of yacc.c  */
#line 276 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 288 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     8,     9,    14,    18,    24,    30,
      32,    34,    36,    38,    41,    43,    45,    47,    49,    51,
      53,    55,    56,    57,    58,    59,    70,    74,    78,    79,
      89,    91,    95,    98,   101,   104,   107,   110,   111,   120,
     121,   122,   134,   136,   139,   140,   145,   146,   151,   152,
     157,   159,   161,   163,   165,   167,   169,   170,   173,   177,
     181,   182,   185,   189,   193,   194,   197,   199,   201,   203
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    -1,    49,    50,    55,    -1,    -1,     3,
      51,    52,     4,    -1,    37,    53,    38,    -1,    54,    38,
      27,    37,    46,    -1,    54,    32,    53,    32,    46,    -1,
       7,    -1,     6,    -1,     5,    -1,    56,    -1,    55,    56,
      -1,    57,    -1,    70,    -1,    67,    -1,    69,    -1,    62,
      -1,    63,    -1,    64,    -1,    -1,    -1,    -1,    -1,    12,
      58,    59,    35,    74,    36,    60,    55,    61,    13,    -1,
      80,    14,    80,    -1,    80,    15,    80,    -1,    -1,    65,
      16,    35,    46,    34,    37,    66,    38,    36,    -1,    80,
      -1,    66,    34,    80,    -1,    68,    80,    -1,    46,    26,
      -1,    42,    46,    -1,    41,    46,    -1,    41,    45,    -1,
      -1,     8,    35,    74,    36,     9,    55,    71,    11,    -1,
      -1,    -1,     8,    35,    74,    36,     9,    55,    72,    10,
      73,    55,    11,    -1,    77,    -1,    19,    77,    -1,    -1,
      77,    75,    17,    77,    -1,    -1,    77,    76,    18,    77,
      -1,    -1,    78,    80,    79,    80,    -1,    20,    -1,    21,
      -1,    22,    -1,    23,    -1,    25,    -1,    24,    -1,    -1,
      81,    82,    -1,    80,    28,    82,    -1,    80,    29,    82,
      -1,    -1,    83,    84,    -1,    82,    30,    84,    -1,    82,
      31,    84,    -1,    -1,    85,    46,    -1,    43,    -1,    44,
      -1,    45,    -1,    35,    80,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   127,   139,   139,   144,   147,   176,   209,
     213,   217,   224,   225,   228,   232,   236,   237,   238,   239,
     240,   244,   248,   250,   255,   243,   289,   293,   297,   297,
     301,   309,   317,   328,   335,   341,   347,   358,   356,   389,
     391,   388,   434,   440,   448,   448,   459,   458,   478,   478,
     492,   499,   505,   511,   517,   523,   531,   531,   534,   538,
     544,   544,   547,   551,   557,   557,   572,   582,   592,   602
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "ENDVAR", "REAL", "INTEGER",
  "STRING", "IF", "THEN", "ELSE", "ENDIF", "REPEAT", "ENDREPEAT", "MOD",
  "DIV", "INLIST", "OP_AND", "OP_OR", "OP_NOT", "CMP_MAYOR", "CMP_MENOR",
  "CMP_MAYORIGUAL", "CMP_MENORIGUAL", "CMP_DISTINTO", "CMP_IGUAL",
  "OP_ASIG", "OP_DOSP", "OP_SUM", "OP_RES", "OP_MUL", "OP_DIV", "CAR_COMA",
  "CAR_PUNTO", "CAR_PYC", "CAR_PA", "CAR_PC", "CAR_CA", "CAR_CC", "CAR_LA",
  "CAR_LC", "PRINT", "READ", "CONST_INT", "CONST_REAL", "CONST_STR", "ID",
  "$accept", "programa", "$@1", "est_declaracion", "$@2", "declaracion",
  "NODO", "TIPO_DATO", "bloque", "sentencia", "ciclo", "$@3", "$@4", "$@5",
  "$@6", "modulo", "division", "inlist", "$@7", "lista_expresiones",
  "asignacion", "lista_id", "entrada_salida", "seleccion", "$@8", "$@9",
  "$@10", "condicion", "$@11", "$@12", "comparacion", "$@13", "comparador",
  "expresion", "$@14", "termino", "$@15", "factor", "$@16", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    49,    48,    51,    50,    52,    53,    53,    54,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    58,    59,    60,    61,    57,    62,    63,    65,    64,
      66,    66,    67,    68,    69,    69,    69,    71,    70,    72,
      73,    70,    74,    74,    75,    74,    76,    74,    78,    77,
      79,    79,    79,    79,    79,    79,    81,    80,    80,    80,
      83,    82,    82,    82,    85,    84,    84,    84,    84,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     4,     3,     5,     5,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     0,     0,    10,     3,     3,     0,     9,
       1,     3,     2,     2,     2,     2,     2,     0,     8,     0,
       0,    11,     1,     2,     0,     4,     0,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     0,     2,     3,     3,
       0,     2,     3,     3,     0,     2,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     4,    56,     0,     0,    21,     0,
       0,     0,    56,    12,    14,    18,    19,    20,     0,    16,
      56,    17,    15,     0,    60,     0,     0,    48,    22,    36,
      35,    34,    33,    13,     0,    32,    56,    56,    60,    60,
      57,    64,    11,    10,     9,     0,     0,     5,    48,     0,
      42,    56,     0,     0,    26,    27,    58,    59,    64,    64,
      56,    66,    67,    68,    61,     0,     6,     0,     0,    43,
       0,     0,     0,     0,    48,     0,    62,    63,     0,    65,
       0,     0,    56,    48,    48,    50,    51,    52,    53,    55,
      54,    56,     0,     0,    69,     0,     0,    56,    45,    47,
      49,    23,    56,     8,     7,     0,     0,    56,     0,    30,
      38,    40,    56,    56,     0,    56,     0,    31,    29,    56,
      25,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    26,    45,    46,    12,    13,
      14,    28,    52,   107,   116,    15,    16,    17,    18,   108,
      19,    20,    21,    22,   105,   106,   115,    49,    71,    72,
      50,    51,    91,    23,    24,    40,    41,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int8 yypact[] =
{
     -70,    14,     9,   -70,   -70,    21,     2,    17,   -70,   -24,
      13,    29,     3,   -70,   -70,   -70,   -70,   -70,    50,   -70,
     -70,   -70,   -70,    36,   -70,    82,    67,    65,   -70,   -70,
     -70,   -70,   -70,   -70,    44,    19,   -70,   -70,   -70,   -70,
      60,    25,   -70,   -70,   -70,    61,    48,   -70,   -70,    66,
      75,   -70,    68,    55,    19,    19,    60,    60,    25,    25,
     -70,   -70,   -70,   -70,   -70,    58,   -70,    82,    78,   -70,
      97,    91,    92,    53,    65,    77,   -70,   -70,   -20,   -70,
      80,    72,    21,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,    79,    76,   -70,    70,    71,    -6,   -70,   -70,
      19,   -70,   -70,   -70,   -70,   103,   108,    21,    -4,    19,
     -70,   -70,    12,   -70,    83,    21,   107,    19,   -70,    15,
     -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -70,   -70,    54,   -70,   -69,   -12,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,    49,   -70,   -70,
     -41,   -70,   -70,   -19,   -70,    57,   -70,    39,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int8 yytable[] =
{
      33,    35,     7,    -3,   -39,   -37,     8,    69,    38,    39,
     -28,     7,     4,    97,     3,     8,    94,    54,    55,   -28,
       7,    29,    30,     7,     8,   -24,   121,     8,   -28,     7,
     113,   -28,    73,     8,   114,     9,    10,   -28,   112,    25,
      11,    78,    98,    99,     9,    10,   119,    38,    39,    11,
      36,    37,    27,     9,    10,    32,     9,    10,    11,    31,
      60,    11,     9,    10,    38,    39,    34,    11,    61,    62,
      63,    47,   100,    85,    86,    87,    88,    89,    90,    53,
      67,    38,    39,   109,    48,    33,    68,    42,    43,    44,
      58,    59,   -44,   -46,   117,    56,    57,    76,    77,    66,
      33,    75,    70,    74,    79,    81,    82,    33,    83,    96,
      84,    93,    95,   102,   110,   101,   103,   104,   111,   118,
     120,    80,     0,    92
};

static const yytype_int8 yycheck[] =
{
      12,    20,     8,     0,    10,    11,    12,    48,    28,    29,
      16,     8,     3,    82,     0,    12,    36,    36,    37,    16,
       8,    45,    46,     8,    12,    13,    11,    12,    16,     8,
      34,    16,    51,    12,    38,    41,    42,    16,   107,    37,
      46,    60,    83,    84,    41,    42,   115,    28,    29,    46,
      14,    15,    35,    41,    42,    26,    41,    42,    46,    46,
      35,    46,    41,    42,    28,    29,    16,    46,    43,    44,
      45,     4,    91,    20,    21,    22,    23,    24,    25,    35,
      32,    28,    29,   102,    19,    97,    38,     5,     6,     7,
      30,    31,    17,    18,   113,    38,    39,    58,    59,    38,
     112,    46,    36,    35,    46,    27,     9,   119,    17,    37,
      18,    34,    32,    37,    11,    36,    46,    46,    10,    36,
      13,    67,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,     3,    50,    51,     8,    12,    41,
      42,    46,    55,    56,    57,    62,    63,    64,    65,    67,
      68,    69,    70,    80,    81,    37,    52,    35,    58,    45,
      46,    46,    26,    56,    16,    80,    14,    15,    28,    29,
      82,    83,     5,     6,     7,    53,    54,     4,    19,    74,
      77,    78,    59,    35,    80,    80,    82,    82,    30,    31,
      35,    43,    44,    45,    84,    85,    38,    32,    38,    77,
      36,    75,    76,    80,    35,    46,    84,    84,    80,    46,
      53,    27,     9,    17,    18,    20,    21,    22,    23,    24,
      25,    79,    74,    34,    36,    32,    37,    55,    77,    77,
      80,    36,    37,    46,    46,    71,    72,    60,    66,    80,
      11,    10,    55,    34,    38,    73,    61,    80,    36,    55,
      13,    11
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 127 "Sintactico.y"
    {	printf("\tInicia el COMPILADOR\n\n");
		crear_cola(&cola);
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 132 "Sintactico.y"
    {	printf("\n\tFin COMPILADOR OK\n");
		prepararTSParaAssembler();
		crearArchivoTS();
		crearArchivoTercetosIntermedia();
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 139 "Sintactico.y"
    {	printf("\t\tDECLARACIONES VAR\n");	}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    {	printf("\t\tFIN DECLARACIONES ENDVAR\n");	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 148 "Sintactico.y"
    {
	//printf("\nArray declaraciones: %s , TIPO DE DATO %s", arrayDeclaraciones[0], tipoDato);
	insertarEnArrayDeclaracion(yylval.str_val);
	if(cola_vacia(&cola) != COLA_VACIA)
	{

		sacar_de_cola(&cola, tipoDato);
		printf("\t\tTIPO DATO: %s\n", tipoDato);
	if(strcmp(tipoDato, "STRING") == 0)
	{

		validarDeclaracionTipoDato("STRING");
	}
	else{
			if(strcmp(tipoDato, "REAL") == 0)
			 	{

						validarDeclaracionTipoDato("REAL");
				}

			else{

				validarDeclaracionTipoDato("INTEGER");
			}
	}
}
}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 177 "Sintactico.y"
    {
	insertarEnArrayDeclaracion(yylval.str_val);
	if(cola_vacia(&cola)  != COLA_VACIA)
	{

		sacar_de_cola(&cola, &tipoDato);
		printf("\t\tTIPO DATO: %s\n", tipoDato);



	if(strcmp(tipoDato, "STRING") == 0)
	{

		validarDeclaracionTipoDato("STRING");
	}
	else{
			if(strcmp(tipoDato, "REAL") == 0)
			 	{

						validarDeclaracionTipoDato("REAL");
				}
			else{


				validarDeclaracionTipoDato("INTEGER");
			}
	}
}
}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 209 "Sintactico.y"
    {
		poner_en_cola(&cola, "STRING");
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 213 "Sintactico.y"
    {
	 poner_en_cola(&cola, "INTEGER");

	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 217 "Sintactico.y"
    {
		poner_en_cola(&cola, "REAL");

	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 229 "Sintactico.y"
    {
		crearTerceto(obtenerNuevoNombreEtiqueta("fin_repeat"),"_","_");
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 233 "Sintactico.y"
    {
			crearTerceto(obtenerNuevoNombreEtiqueta("fin_seleccion"),"_","_");
		}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 244 "Sintactico.y"
    {	printf("\t\tREPEAT\n");
		//indiceAux=crearTerceto(obtenerNuevoNombreEtiqueta("inicio_repeat"),"_","_");
		//poner_en_pila(&pila,&indiceAux);
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 248 "Sintactico.y"
    {printf("\t\tPASA REPEAT\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 250 "Sintactico.y"
    {
		printf("\t\tPASA CONDICION\n");
		//indicePrincipioBloque = obtenerIndiceActual();
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 255 "Sintactico.y"
    {printf("\t\tPASA BLOQUE\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 257 "Sintactico.y"
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
	}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 290 "Sintactico.y"
    { printf("\t\tMOD\n");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 294 "Sintactico.y"
    { printf("\t\tDIV\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 297 "Sintactico.y"
    {printf("\t\tINLIST\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 302 "Sintactico.y"
    {

				crearTerceto("CMP",armarIndiceI(indiceId),armarIndiceD(indiceExpresion));
				indiceComparador = crearTerceto("JNE","_","_");
				poner_en_pila(&pila_ciclo_especial,&indiceComparador);
			}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 310 "Sintactico.y"
    {
				crearTerceto("CMP",armarIndiceI(indiceId),armarIndiceD(indiceExpresion));
				indiceComparador = crearTerceto("JNE","_","_");
				poner_en_pila(&pila_ciclo_especial,&indiceComparador);
			}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 318 "Sintactico.y"
    {
					printf("\t\tASIGNACION\n");
					compararTipos();

					indiceAux = crearTerceto(idAsignarStr,"_","_");

					crearTerceto("=",armarIndiceI(indiceAux),armarIndiceD(indiceExpresion));
		 }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 329 "Sintactico.y"
    {
		insertarEnArrayComparacionTipos(yylval.str_val);
		strcpy(idAsignarStr, yylval.str_val);
	}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 336 "Sintactico.y"
    {
		printf("\t\tREAD\n");
		indiceAux = crearTerceto(yylval.str_val,"_","_");
		crearTerceto("READ",armarIndiceI(indiceAux),"_");
	}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 342 "Sintactico.y"
    {
			indiceAux = crearTerceto(yylval.str_val,"_","_");
			crearTerceto("PRINT",armarIndiceI(indiceAux),"_");
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 348 "Sintactico.y"
    {
		indiceAux = crearTerceto(yylval.str_val,"_","_");
		crearTerceto("DISPLAY",armarIndiceI(indiceAux),"_");
	}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 358 "Sintactico.y"
    {printf("\t\tIF\n");}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 360 "Sintactico.y"
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
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 389 "Sintactico.y"
    {printf("\t\tIF\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 391 "Sintactico.y"
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
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 424 "Sintactico.y"
    {
		printf("\t\tENDIF (con else)\n");
		int indiceDesapilado;
		int indiceActual = obtenerIndiceActual();
		sacar_de_pila(&pila, &indiceDesapilado);
		modificarTerceto(indiceDesapilado, 2, armarIndiceI(indiceActual));
	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 435 "Sintactico.y"
    {
				printf("\t\tCOMPARACION\n");

				startEtiqueta = 0;
			}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 441 "Sintactico.y"
    {	printf("\t\tCONDICION NOT\n");
				char *operador = obtenerTerceto(indiceComparador,1);
				char *operadorNegado = negarComparador(operador);
				modificarTerceto(indiceComparador,1,operadorNegado);

				startEtiqueta = 0;
			}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 448 "Sintactico.y"
    { indiceComparador1 = indiceComparador; }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 449 "Sintactico.y"
    {
				printf("\t\tCONDICION DOBLE AND\n");
				indiceComparador2 = indiceComparador;
				strcpy(condicion, "AND");
				poner_en_pila(&pila_condicion_doble,&indiceComparador1);
				poner_en_pila(&pila_condicion_doble,&indiceComparador2);

				startEtiqueta = 0;
			}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 459 "Sintactico.y"
    {
						indiceComparador1 = indiceComparador;
						char *operador = obtenerTerceto(indiceComparador1,1);
						char *operadorNegado = negarComparador(operador);
						modificarTerceto(indiceComparador1,1,operadorNegado);
						startEtiqueta = 0;
				}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 467 "Sintactico.y"
    {
				printf("\t\tCONDICION DOBLE OR\n");
				indiceComparador2 = indiceComparador;
				strcpy(condicion, "OR");
				poner_en_pila(&pila_condicion_doble,&indiceComparador1);
				poner_en_pila(&pila_condicion_doble,&indiceComparador2);

				startEtiqueta = 0;
			}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 478 "Sintactico.y"
    {printf("\t\tENTRO COMPARAXION\n");}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 480 "Sintactico.y"
    {
				{printf("\t\tENTRO COMPARADOR\n");}
				compararTipos();
				indiceDer = indiceExpresion;
				crearTerceto("CMP",armarIndiceI(indiceIzq),armarIndiceD(indiceDer));
				char comparadorDesapilado[8];
				sacar_de_pila(&pila, &comparadorDesapilado);
				indiceComparador = crearTerceto(comparadorDesapilado,"_","_");
				poner_en_pila(&pila,&indiceComparador);
			}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 493 "Sintactico.y"
    {
					printf("\t\tENTRO A COMPARADOR");
					//char comparadorApilado[8] = "BLE";
					char comparadorApilado[8] = "JA";
					poner_en_pila(&pila,&comparadorApilado);
				}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 500 "Sintactico.y"
    {
					// char comparadorApilado[8] = "BGE";
					char comparadorApilado[8] = "JB";
					poner_en_pila(&pila,&comparadorApilado);
				}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 506 "Sintactico.y"
    {
					// char comparadorApilado[8] = "BLT";
					char comparadorApilado[8] = "JAE";
					poner_en_pila(&pila,&comparadorApilado);
				}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 512 "Sintactico.y"
    {
					// char comparadorApilado[8] = "BGT";
					char comparadorApilado[8] = "JBE";
					poner_en_pila(&pila,&comparadorApilado);
				}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 518 "Sintactico.y"
    {
					// char comparadorApilado[8] = "BNE";
					char comparadorApilado[8] = "JE";
					poner_en_pila(&pila,&comparadorApilado);
				}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 524 "Sintactico.y"
    {
					// char comparadorApilado[8] = "BEQ";
					char comparadorApilado[8] = "JNE";
					poner_en_pila(&pila,&comparadorApilado);
				}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 531 "Sintactico.y"
    {printf("\t\tENTRO A EXPRESOPM");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 533 "Sintactico.y"
    {printf("\t\tPASO TERMINO");}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 535 "Sintactico.y"
    {
					//indiceExpresion = crearTerceto("+",armarIndiceI(indiceExpresion),armarIndiceD(indiceTermino));
				}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 539 "Sintactico.y"
    {
					//indiceExpresion = crearTerceto("-",armarIndiceI(indiceExpresion),armarIndiceD(indiceTermino));
				}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 544 "Sintactico.y"
    {printf("\t\tENTRO TERMINO");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 546 "Sintactico.y"
    {printf("\t\tPASO FACTOR");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 548 "Sintactico.y"
    {
					indiceTermino = crearTerceto("*",armarIndiceI(indiceTermino),armarIndiceD(indiceFactor));
				}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 552 "Sintactico.y"
    {
					indiceTermino = crearTerceto("/",armarIndiceI(indiceTermino),armarIndiceD(indiceFactor));
				}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 557 "Sintactico.y"
    {printf("\t\tENTRO FACTOR\n");}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 559 "Sintactico.y"
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
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 573 "Sintactico.y"
    {
					if(startEtiqueta == 0)
					{
						crearTerceto(obtenerNuevoNombreEtiqueta("inicio"),"_","_");
						startEtiqueta = 1;
					}
					insertarEnArrayComparacionTipos(yylval.str_val);
					indiceFactor = crearTerceto(yylval.str_val,"_","_");
				}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 583 "Sintactico.y"
    {
					if(startEtiqueta == 0)
					{
						crearTerceto(obtenerNuevoNombreEtiqueta("inicio"),"_","_");
						startEtiqueta = 1;
					}
					insertarEnArrayComparacionTipos(yylval.str_val);
					indiceFactor = crearTerceto(yylval.str_val,"_","_");
				}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 593 "Sintactico.y"
    {
					if(startEtiqueta == 0)
					{
						crearTerceto(obtenerNuevoNombreEtiqueta("inicio"),"_","_");
						startEtiqueta = 1;
					}
					insertarEnArrayComparacionTipos(yylval.str_val);
					indiceFactor = crearTerceto(yylval.str_val,"_","_");
				}
    break;



/* Line 1455 of yacc.c  */
#line 2309 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 604 "Sintactico.y"



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

