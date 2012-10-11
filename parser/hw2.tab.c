/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 4 "hw2.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include "lexer.h"
	#include "symTable.h"
	#include "symTable.c"

	#define MAXLEN 512

	SYMTABLE t;
	TABLECELL *tc; // store stuff here
	SYMTABLE *curr_table; // points to the current scope's symbol table
	char curr_file[MAXLEN+1];
	int stat;

	/* functions that will be defined */
	void INSTALL(SYMTABLE *t, YYSTYPE val);
	int UPDATE(SYMTABLE *t, char *key, YYSTYPE val);
	YYSTYPE FIXNUM(YYSTYPE v);
	YYSTYPE RETRIEVE(SYMTABLE *t, char *key);
	YYSTYPE UNARY(YYSTYPE v, int op);
	YYSTYPE BINARY(YYSTYPE v1, YYSTYPE v2, int op);
	YYSTYPE OPASSIGN(YYSTYPE v1, YYSTYPE v2, int op);
	YYSTYPE TERNARY(YYSTYPE v1, YYSTYPE v2, YYSTYPE v3);
	void SPOP();
	void SPUSH();
	void PRINTEXP(YYSTYPE v);


/* Line 268 of yacc.c  */
#line 103 "hw2.tab.c"

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
     TOKEOF = 258,
     AUTO = 259,
     BREAK = 260,
     CASE = 261,
     CHAR = 262,
     CONST = 263,
     CONTINUE = 264,
     DEFAULT = 265,
     DO = 266,
     DOUBLE = 267,
     ELSE = 268,
     ENUM = 269,
     EXTERN = 270,
     FLOAT = 271,
     FOR = 272,
     GOTO = 273,
     IF = 274,
     INLINE = 275,
     INT = 276,
     LONG = 277,
     REGISTER = 278,
     RESTRICT = 279,
     RETURN = 280,
     SHORT = 281,
     SIGNED = 282,
     SIZEOF = 283,
     STATIC = 284,
     STRUCT = 285,
     SWITCH = 286,
     TYPEDEF = 287,
     UNION = 288,
     UNSIGNED = 289,
     VOID = 290,
     VOLATILE = 291,
     WHILE = 292,
     _BOOL = 293,
     _COMPLEX = 294,
     _IMAGINARY = 295,
     INDSEL = 296,
     PLUSPLUS = 297,
     MINUSMINUS = 298,
     SHL = 299,
     SHR = 300,
     LTEQ = 301,
     GTEQ = 302,
     EQEQ = 303,
     NOTEQ = 304,
     LOGAND = 305,
     LOGOR = 306,
     ELLIPSES = 307,
     TIMESEQ = 308,
     DIVEQ = 309,
     MODEQ = 310,
     PLUSEQ = 311,
     MINUSEQ = 312,
     SHLEQ = 313,
     SHREQ = 314,
     ANDEQ = 315,
     OREQ = 316,
     XOREQ = 317,
     IDENT = 318,
     CHARLIT = 319,
     STRING = 320,
     NUMBER = 321,
     ERRC = 322,
     ERRS = 323,
     NEWLINE = 324,
     FILEDIR = 325
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 215 "hw2.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1643

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNRULES -- Number of states.  */
#define YYNSTATES  339

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,     2,     2,     2,     2,    74,     2,
      83,    84,    79,    77,    88,    78,    87,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    90,    91,
      76,    71,    75,    89,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    85,     2,    86,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    92,    73,    93,    82,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    15,    17,    22,
      26,    31,    35,    39,    42,    45,    47,    51,    53,    56,
      59,    62,    65,    70,    72,    74,    76,    78,    80,    82,
      84,    89,    91,    95,    99,   103,   107,   111,   115,   119,
     123,   127,   131,   135,   139,   143,   147,   151,   155,   159,
     161,   167,   169,   173,   175,   177,   179,   181,   183,   185,
     187,   189,   191,   193,   195,   197,   201,   203,   206,   210,
     212,   215,   217,   220,   222,   225,   227,   231,   233,   237,
     239,   241,   243,   245,   247,   249,   251,   253,   255,   257,
     259,   261,   263,   265,   267,   269,   275,   280,   283,   285,
     287,   289,   292,   296,   299,   301,   304,   306,   308,   312,
     314,   317,   321,   326,   332,   335,   337,   341,   343,   347,
     349,   351,   354,   356,   358,   362,   367,   371,   376,   381,
     385,   387,   390,   393,   397,   399,   402,   404,   408,   410,
     414,   417,   420,   422,   424,   428,   430,   433,   435,   437,
     440,   444,   447,   451,   455,   460,   463,   467,   471,   476,
     478,   482,   487,   489,   493,   495,   497,   499,   501,   503,
     505,   509,   514,   518,   521,   525,   529,   534,   536,   539,
     541,   544,   546,   549,   555,   563,   569,   575,   583,   590,
     598,   602,   605,   608,   611,   615,   617,   620,   622,   624,
     629,   633,   637
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     146,     0,    -1,    63,    -1,    66,    -1,    65,    -1,    64,
      -1,    83,   105,    84,    -1,    95,    -1,    96,    85,   105,
      86,    -1,    96,    83,    84,    -1,    96,    83,    97,    84,
      -1,    96,    87,    63,    -1,    96,    41,    63,    -1,    96,
      42,    -1,    96,    43,    -1,   103,    -1,    97,    88,   103,
      -1,    96,    -1,    42,    98,    -1,    43,    98,    -1,    99,
     100,    -1,    28,    98,    -1,    28,    83,   132,    84,    -1,
      74,    -1,    79,    -1,    77,    -1,    78,    -1,    82,    -1,
      81,    -1,    98,    -1,    83,   132,    84,   100,    -1,   100,
      -1,   101,    77,   101,    -1,   101,    78,   101,    -1,   101,
      79,   101,    -1,   101,    80,   101,    -1,   101,    74,   101,
      -1,   101,    73,   101,    -1,   101,    72,   101,    -1,   101,
      44,   101,    -1,   101,    45,   101,    -1,   101,    51,   101,
      -1,   101,    50,   101,    -1,   101,    48,   101,    -1,   101,
      49,   101,    -1,   101,    75,   101,    -1,   101,    76,   101,
      -1,   101,    46,   101,    -1,   101,    47,   101,    -1,   101,
      -1,   101,    89,   105,    90,   102,    -1,   102,    -1,    98,
     104,   103,    -1,    71,    -1,    53,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,
      -1,    61,    -1,    62,    -1,   103,    -1,   105,    88,   103,
      -1,   102,    -1,   108,    91,    -1,   108,   109,    91,    -1,
     111,    -1,   111,   108,    -1,   112,    -1,   112,   108,    -1,
     123,    -1,   123,   108,    -1,   110,    -1,   109,    88,   110,
      -1,   124,    -1,   124,    71,   135,    -1,    32,    -1,    15,
      -1,    29,    -1,     4,    -1,    23,    -1,    35,    -1,     7,
      -1,    26,    -1,    21,    -1,    22,    -1,    16,    -1,    12,
      -1,    27,    -1,    34,    -1,   113,    -1,   120,    -1,   114,
      63,    92,   115,    93,    -1,   114,    92,   115,    93,    -1,
     114,    63,    -1,    30,    -1,    33,    -1,   116,    -1,   115,
     116,    -1,   117,   118,    91,    -1,   112,   117,    -1,   112,
      -1,   123,   117,    -1,   123,    -1,   119,    -1,   118,    88,
     119,    -1,   124,    -1,    90,   106,    -1,   124,    90,   106,
      -1,    14,    92,   121,    93,    -1,    14,    63,    92,   121,
      93,    -1,    14,    63,    -1,   122,    -1,   121,    88,   122,
      -1,    63,    -1,    63,    71,   106,    -1,     8,    -1,    36,
      -1,   126,   125,    -1,   125,    -1,    63,    -1,    83,   124,
      84,    -1,   125,    85,   106,    86,    -1,   125,    85,    86,
      -1,   125,    83,   128,    84,    -1,   125,    83,   131,    84,
      -1,   125,    83,    84,    -1,    79,    -1,    79,   127,    -1,
      79,   126,    -1,    79,   127,   126,    -1,   123,    -1,   127,
     123,    -1,   129,    -1,   129,    88,    52,    -1,   130,    -1,
     129,    88,   130,    -1,   108,   124,    -1,   108,   133,    -1,
     108,    -1,    63,    -1,   131,    88,    63,    -1,   117,    -1,
     117,   133,    -1,   126,    -1,   134,    -1,   126,   134,    -1,
      83,   133,    84,    -1,    85,    86,    -1,    85,   106,    86,
      -1,   134,    85,    86,    -1,   134,    85,   106,    86,    -1,
      83,    84,    -1,    83,   128,    84,    -1,   134,    83,    84,
      -1,   134,    83,   128,    84,    -1,   103,    -1,    92,   136,
      93,    -1,    92,   136,    88,    93,    -1,   135,    -1,   136,
      88,   135,    -1,   138,    -1,   139,    -1,   142,    -1,   143,
      -1,   144,    -1,   145,    -1,    63,    90,   137,    -1,     6,
     106,    90,   137,    -1,    10,    90,   137,    -1,    92,    93,
      -1,    92,   141,    93,    -1,    92,   140,    93,    -1,    92,
     140,   141,    93,    -1,   107,    -1,   140,   107,    -1,   137,
      -1,   141,   137,    -1,    91,    -1,   105,    91,    -1,    19,
      83,   105,    84,   137,    -1,    19,    83,   105,    84,   137,
      13,   137,    -1,    31,    83,   105,    84,   137,    -1,    37,
      83,   105,    84,   137,    -1,    11,   137,    37,    83,   105,
      84,    91,    -1,    17,    83,   142,   142,    84,   137,    -1,
      17,    83,   142,   142,   105,    84,   137,    -1,    18,    63,
      91,    -1,     9,    91,    -1,     5,    91,    -1,    25,    91,
      -1,    25,   105,    91,    -1,   147,    -1,   146,   147,    -1,
     148,    -1,   107,    -1,   108,   124,   140,   139,    -1,   108,
     124,   139,    -1,   124,   140,   139,    -1,   124,   139,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   133,   134,   135,   136,   139,   140,   141,
     142,   143,   144,   145,   146,   149,   150,   153,   154,   155,
     156,   157,   158,   161,   162,   163,   164,   165,   166,   169,
     170,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   193,
     194,   197,   198,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   214,   215,   218,   221,   222,   225,
     226,   227,   228,   229,   230,   233,   234,   237,   238,   241,
     242,   243,   244,   245,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   261,   262,   263,   266,   267,
     270,   271,   274,   277,   278,   279,   280,   283,   284,   287,
     288,   289,   292,   293,   294,   297,   298,   301,   302,   305,
     306,   309,   310,   313,   314,   315,   316,   317,   318,   319,
     322,   323,   324,   325,   328,   329,   332,   333,   336,   337,
     340,   341,   342,   345,   346,   349,   350,   353,   354,   355,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   369,
     370,   371,   374,   375,   378,   379,   380,   381,   382,   383,
     386,   387,   388,   391,   392,   393,   394,   397,   398,   401,
     402,   405,   406,   409,   410,   411,   414,   415,   416,   417,
     420,   421,   422,   423,   424,   427,   428,   431,   432,   435,
     436,   437,   438
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEOF", "AUTO", "BREAK", "CASE",
  "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM",
  "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INLINE", "INT", "LONG",
  "REGISTER", "RESTRICT", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE",
  "WHILE", "_BOOL", "_COMPLEX", "_IMAGINARY", "INDSEL", "PLUSPLUS",
  "MINUSMINUS", "SHL", "SHR", "LTEQ", "GTEQ", "EQEQ", "NOTEQ", "LOGAND",
  "LOGOR", "ELLIPSES", "TIMESEQ", "DIVEQ", "MODEQ", "PLUSEQ", "MINUSEQ",
  "SHLEQ", "SHREQ", "ANDEQ", "OREQ", "XOREQ", "IDENT", "CHARLIT", "STRING",
  "NUMBER", "ERRC", "ERRS", "NEWLINE", "FILEDIR", "'='", "'^'", "'|'",
  "'&'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'!'", "'~'", "'('",
  "')'", "'['", "']'", "'.'", "','", "'?'", "':'", "';'", "'{'", "'}'",
  "$accept", "primary_expr", "postfix_expr", "arglist", "unary_expr",
  "unary_op", "cast_expr", "binary_expr", "conditional_expr",
  "assign_expr", "assign_op", "expr", "constant_expr", "declaration",
  "dec_specs", "init_declarator_list", "init_declarator", "storage_spec",
  "type_spec", "struct_union_spec", "s_or_u", "struct_declaration_list",
  "struct_declaration", "spec_qual_list", "struct_declarator_list",
  "struct_declarator", "enum_spec", "enum_list", "enumerator", "type_qual",
  "declarator", "direct_declarator", "pointer", "type_qual_list",
  "param_type_list", "param_list", "param_declaration", "id_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_stmt",
  "compound_stmt", "declaration_list", "stmt_list", "expr_stmt",
  "selection_stmt", "iter_stmt", "jump_stmt", "translation_unit",
  "external_declaration", "function_definition", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,    61,    94,   124,    38,    62,    60,    43,    45,    42,
      47,    33,   126,    40,    41,    91,    93,    46,    44,    63,
      58,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    99,    99,    99,    99,    99,    99,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   105,   105,   106,   107,   107,   108,
     108,   108,   108,   108,   108,   109,   109,   110,   110,   111,
     111,   111,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   113,   114,   114,
     115,   115,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   139,   139,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   148,   148
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    82,    85,   119,    90,     0,    80,    89,    87,    88,
      83,    86,    91,    81,    98,    79,    99,    92,    84,   120,
     123,   130,     0,   198,     0,    69,    71,    93,     0,    94,
      73,     0,   122,     0,     0,   195,   197,   114,     0,   134,
     132,   131,     0,    67,     0,    75,    77,    70,    72,    97,
       0,    74,     0,   177,     0,   202,     0,     0,     0,   121,
       1,   196,     0,   117,     0,   115,   135,   133,   124,     0,
      68,     0,   200,     0,     0,   104,     0,   100,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     5,     4,     3,    23,    25,
      26,    24,    28,    27,     0,   181,   173,     7,    17,    29,
       0,    31,    49,    51,    64,     0,   179,   164,   165,     0,
       0,   166,   167,   168,   169,    77,   178,   201,   143,   129,
     142,     0,   136,   138,     0,     2,   126,    29,    66,     0,
       0,     0,     0,   112,    76,     0,   159,    78,   199,     0,
     103,    96,   101,     0,     0,   107,   109,   105,   192,     0,
     191,     0,     0,     0,     0,     0,   193,     0,     0,    21,
       0,     0,     0,    18,    19,     0,     0,   145,     0,     0,
      13,    14,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    53,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   175,     0,
     174,   180,     0,     0,   140,   147,   141,   148,   127,     0,
     128,     0,   125,   113,   118,   116,   162,     0,    95,   110,
       0,   102,     0,     0,   172,     0,     0,   190,     0,   194,
       0,     0,     0,   170,     6,     0,   147,   146,     0,    12,
       9,     0,    15,     0,    11,    52,    39,    40,    47,    48,
      43,    44,    42,    41,    38,    37,    36,    45,    46,    32,
      33,    34,    35,     0,    65,   176,   155,     0,     0,   151,
       0,   149,     0,     0,   137,   139,   144,     0,   160,   108,
     111,   171,     0,     0,     0,    22,     0,     0,    30,    10,
       0,     8,     0,   156,   150,   152,   157,     0,   153,     0,
     161,   163,     0,     0,     0,   183,   185,   186,    16,    50,
     158,   154,     0,   188,     0,     0,   187,   189,   184
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   261,   109,   110,   111,   112,   113,   114,
     196,   115,   139,    53,    54,    44,    45,    25,    26,    27,
      28,    76,    77,    78,   154,   155,    29,    64,    65,    30,
      31,    32,    33,    41,   287,   132,   133,   134,   178,   288,
     227,   147,   237,   116,   117,   118,    56,   120,   121,   122,
     123,   124,    34,    35,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -207
static const yytype_int16 yypact[] =
{
    1013,  -207,  -207,  -207,  -207,   -47,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,    15,    45,  -207,     7,  1577,  1577,  -207,   -39,  -207,
    1577,   281,   101,    51,   833,  -207,  -207,   -82,   -15,  -207,
    -207,    15,   -51,  -207,   -28,  -207,   652,  -207,  -207,   -19,
    1607,  -207,   322,  -207,     7,  -207,   281,   942,  1189,   101,
    -207,  -207,   -15,    20,   -11,  -207,  -207,  -207,  -207,    45,
    -207,  1102,  -207,   281,  1607,  1607,   765,  -207,   119,  1607,
      -7,  1320,    21,   -29,   684,    39,    67,   102,  1127,  1345,
     108,   125,  1372,  1372,    43,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  1044,  -207,  -207,  -207,    54,   211,
    1320,  -207,  1445,  -207,  -207,   115,  -207,  -207,  -207,   412,
     491,  -207,  -207,  -207,  -207,   143,  -207,  -207,  -207,  -207,
      30,    89,   139,  -207,    35,  -207,  -207,  -207,  -207,   155,
      13,  1320,   -15,  -207,  -207,  1102,  -207,  -207,  -207,   795,
    -207,  -207,  -207,  1320,   140,  -207,   152,  -207,  -207,   163,
    -207,   684,   220,  1160,   170,  1320,  -207,   147,  1044,  -207,
    1320,  1320,  1320,  -207,  -207,   684,    80,    57,   190,   212,
    -207,  -207,  1268,  1320,   213,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  1320,  -207,  1320,  1320,
    1320,  1320,  1320,  1320,  1320,  1320,  1320,  1320,  1320,  1320,
    1320,  1320,  1320,  1320,  1320,  1320,  1320,  -207,  -207,   570,
    -207,  -207,   868,  1216,  -207,    42,  -207,   130,  -207,  1452,
    -207,   214,  -207,  -207,  -207,  -207,  -207,    50,  -207,  -207,
     119,  -207,  1320,   684,  -207,   195,  1160,  -207,    83,  -207,
     196,    88,    90,  -207,  -207,   903,   171,  -207,  1320,  -207,
    -207,    95,  -207,   -14,  -207,  -207,   146,   146,   -13,   -13,
     467,   467,   172,  1463,  1453,   332,  1500,   -13,   -13,   154,
     154,  -207,  -207,    -5,  -207,  -207,  -207,   199,   200,  -207,
     201,   130,   977,  1241,  -207,  -207,  -207,  1069,  -207,  -207,
    -207,  -207,  1320,  1293,   684,  -207,   684,   684,  -207,  -207,
    1320,  -207,  1320,  -207,  -207,  -207,  -207,   202,  -207,   215,
    -207,  -207,   113,   684,   123,   285,  -207,  -207,  -207,  -207,
    -207,  -207,   208,  -207,   684,   684,  -207,  -207,  -207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,  -207,  -207,   -54,  -207,   -97,   258,   -53,   -16,
    -207,    22,   -61,     2,     0,  -207,   231,  -207,   -33,  -207,
    -207,   232,   -68,   -57,  -207,    65,  -207,   247,   176,    28,
     -10,   -30,   -12,  -207,   -56,  -207,    91,  -207,   144,  -123,
    -206,  -134,  -207,   -44,  -207,     6,   -31,   203,  -157,  -207,
    -207,  -207,  -207,   287,  -207
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      24,   131,    23,    59,   137,   138,   246,   226,   152,    40,
      62,   236,    42,   197,    46,    73,    37,    75,   150,   291,
     159,   119,   157,     3,    49,    47,    48,   137,   138,    67,
      51,   198,   199,    68,    24,   169,    23,    55,   173,   174,
     162,    75,    75,    75,   125,    38,    75,   177,    63,    39,
     291,    19,    72,    50,   257,   146,   137,   130,   126,   125,
      69,   161,   127,    70,   211,   212,   213,   214,   156,    66,
      20,    75,   311,    74,   216,   126,   221,   142,    79,   148,
     234,   152,   143,   216,   158,   312,    21,   137,   138,   303,
      22,   141,   239,    20,    21,   179,   180,   181,    43,   137,
     138,   142,    79,    79,    79,    20,   233,    79,    20,    21,
     167,   177,   160,   222,    20,   223,    75,   244,   225,   230,
     224,   126,   163,   231,    21,   222,   176,   223,    22,   146,
     164,   253,    79,   175,    22,    75,    21,   182,   297,   183,
     255,   184,   223,   298,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   308,   290,   321,   254,   256,   262,   304,   216,   137,
     138,   216,   306,   228,   307,   221,   216,    79,   216,   309,
     265,   300,    20,   310,    57,   165,    58,   248,   137,   138,
     176,   170,   251,   252,   176,    59,    79,   332,    21,   301,
     284,   216,    22,   216,   137,   263,   217,   334,   171,   153,
     225,   216,    42,   292,    71,   293,   198,   199,   200,   201,
     202,   203,   130,   211,   212,   213,   214,   229,   240,   130,
     156,   241,   319,   213,   214,   216,   317,   283,   249,   137,
     138,   232,   242,   256,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   243,   255,   130,   223,   245,   137,   329,
     325,   247,   326,   327,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   258,   259,   264,   296,   302,   333,
     305,   146,   195,   313,   314,     1,   330,   315,     2,     3,
     337,   338,   130,     4,   328,     5,     6,     7,   335,   336,
     144,   331,     8,     9,    10,   299,   149,    11,    12,   140,
      13,    14,   250,    15,    16,    17,    18,    19,   235,     0,
     295,    61,   219,     0,   322,   324,     1,    80,    81,     2,
       3,    82,    83,    84,     4,     0,     5,     6,     7,    85,
      86,    87,     0,     8,     9,    10,     0,    88,    11,    12,
      89,    13,    14,    90,    15,    16,    17,    18,    19,    91,
       0,     0,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,   198,   199,   200,   201,
     202,   203,     0,     0,     0,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,    99,
     100,   101,     0,   102,   103,   104,   208,   209,   210,   211,
     212,   213,   214,   105,    52,   106,     1,    80,    81,     2,
       3,    82,    83,    84,     4,     0,     5,     6,     7,    85,
      86,    87,     0,     8,     9,    10,     0,    88,    11,    12,
      89,    13,    14,    90,    15,    16,    17,    18,    19,    91,
       0,     0,     0,     0,    92,    93,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     0,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,    99,
     100,   101,     0,   102,   103,   104,    80,    81,     0,     0,
      82,    83,    84,   105,    52,   218,     0,     0,    85,    86,
      87,   198,   199,   200,   201,     0,    88,     0,     0,    89,
       0,     0,    90,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,    92,    93,     0,     0,     0,     0,     0,
       0,     0,   209,   210,   211,   212,   213,   214,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,    99,   100,
     101,     0,   102,   103,   104,    80,    81,     0,     0,    82,
      83,    84,   105,    52,   220,     0,     0,    85,    86,    87,
       0,     0,     0,     0,     0,    88,     0,     0,    89,     0,
       0,    90,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,    99,   100,   101,
       0,   102,   103,   104,     0,     0,     1,     0,     0,     2,
       3,   105,    52,   285,     4,     0,     5,     6,     7,     0,
       0,     0,     0,     8,     9,    10,     0,     0,    11,    12,
       0,    13,    14,     0,    15,    16,    17,    18,    19,    80,
      81,     0,     0,    82,    83,    84,     0,     0,     0,     0,
       0,    85,    86,    87,     0,     0,     0,     0,     0,    88,
       0,     0,    89,     0,     0,    90,     0,     0,     0,     0,
       0,    91,     0,    71,     0,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,     0,    98,     0,
       0,    99,   100,   101,     0,   102,   103,   104,     0,     0,
       0,     0,     2,     3,     0,   105,    52,     4,     0,     5,
       0,     7,     0,     0,     0,     0,     8,     9,     0,     0,
       0,    11,    12,     0,     0,    14,     0,     0,    16,    17,
      18,    19,     2,     3,     0,     0,     0,     4,     0,     5,
       0,     7,     0,     0,     0,     0,     8,     9,     0,     0,
       0,    11,    12,     0,     0,    14,     0,     0,    16,    17,
      18,    19,     0,    60,     0,     0,     0,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     0,     8,     9,    10,     0,   151,    11,
      12,     0,    13,    14,     0,    15,    16,    17,    18,    19,
       0,     0,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,   238,     8,
       9,    10,     0,     0,    11,    12,    20,    13,    14,     0,
      15,    16,    17,    18,    19,     0,     0,     1,     0,     0,
       2,     3,    21,     0,     0,     4,    22,     5,     6,     7,
       0,     0,     0,     0,     8,     9,    10,     0,     0,    11,
      12,    20,    13,    14,     0,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     1,    21,     0,     2,
       3,   222,   286,   223,     4,     0,     5,     6,     7,     0,
       0,     0,     0,     8,     9,    10,     0,     0,    11,    12,
       0,    13,    14,     0,    15,    16,    17,    18,    19,     0,
       0,     1,    21,     0,     2,     3,   255,   286,   223,     4,
       0,     5,     6,     7,     0,     0,     0,     0,     8,     9,
      10,     0,     0,    11,    12,   128,    13,    14,     0,    15,
      16,    17,    18,    19,     0,     0,     0,     1,     0,     0,
       2,     3,     0,     0,     0,     4,   129,     5,     6,     7,
       0,     0,     0,     0,     8,     9,    10,     0,     0,    11,
      12,     0,    13,    14,     0,    15,    16,    17,    18,    19,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     0,
       7,   316,     0,     0,     0,     8,     9,     0,     0,     0,
      11,    12,    89,     0,    14,     0,    20,    16,    17,    18,
      19,     0,     0,     0,     0,     0,    92,    93,     0,     0,
       0,     0,    21,     0,     0,     0,    22,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,    95,    96,
      97,    92,    93,     0,     0,     0,     0,     0,    98,     0,
       0,    99,   100,   101,     0,   102,   103,   104,     0,     0,
      89,     0,   135,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,    98,    92,    93,    99,   100,   101,     0,
     102,   103,   104,     0,     0,    89,     0,     0,     0,     0,
       0,   145,   320,     0,     0,   135,    95,    96,    97,    92,
      93,     0,     0,     0,     0,     0,    98,     0,     0,    99,
     100,   101,     0,   102,   103,   104,     0,     0,    89,     0,
     135,    95,    96,    97,   145,     0,     0,     0,     0,     0,
       0,    98,    92,    93,    99,   100,   101,     0,   102,   103,
     104,     0,     0,     0,     0,     0,     0,    89,   166,     0,
       0,     0,     0,   135,    95,    96,    97,     0,     0,     0,
       0,    92,    93,     0,    98,     0,     0,    99,   100,   101,
       0,   102,   103,   104,    89,     0,     0,     0,     0,     0,
       0,   105,   135,    95,    96,    97,     0,     0,    92,    93,
       0,     0,     0,    98,     0,     0,    99,   100,   101,    89,
     102,   103,   104,     0,     0,   136,     0,     0,     0,   135,
      95,    96,    97,    92,    93,     0,     0,     0,     0,     0,
      98,     0,     0,    99,   100,   101,    89,   102,   103,   104,
       0,     0,   289,     0,   135,    95,    96,    97,     0,     0,
      92,    93,     0,     0,     0,    98,     0,     0,    99,   100,
     101,    89,   102,   103,   104,     0,     0,   318,     0,     0,
       0,   135,    95,    96,    97,    92,    93,     0,     0,     0,
       0,     0,    98,     0,     0,    99,   100,   101,    89,   102,
     103,   104,   260,     0,     0,     0,   135,    95,    96,    97,
       0,     0,    92,    93,     0,     0,     0,    98,     0,     0,
      99,   100,   101,    89,   102,   103,   104,   323,     0,     0,
       0,     0,     0,   135,    95,    96,    97,    92,    93,     0,
       0,     0,     0,     0,    98,     0,     0,    99,   100,   101,
      89,   102,   103,   104,     0,     0,     0,     0,   135,    95,
      96,    97,     0,     0,    92,    93,     0,     0,     0,    98,
       0,     0,    99,   100,   101,     0,   102,   103,   168,     0,
       0,     0,     0,     0,     0,   135,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,    99,
     100,   101,     0,   102,   103,   172,     1,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     0,     8,     9,    10,     0,     0,    11,    12,
       0,    13,    14,     0,    15,    16,    17,    18,    19,   198,
     199,   200,   201,   202,   203,   204,   205,   198,   199,   200,
     201,   202,   203,     0,   294,     0,     0,   198,   199,   200,
     201,   202,   203,   204,     0,     0,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   209,   210,   211,   212,   213,
     214,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     0,     8,     9,
      10,     0,     0,    11,    12,     0,    13,    14,     0,    15,
      16,    17,    18,    19,     2,     3,     0,     0,     0,     4,
       0,     5,     0,     7,     0,     0,     0,     0,     8,     9,
       0,     0,     0,    11,    12,     0,     0,    14,     0,     0,
      16,    17,    18,    19
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-207))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    57,     0,    33,    58,    58,   163,   130,    76,    21,
      92,   145,    22,   110,    24,    46,    63,    50,    75,   225,
      81,    52,    79,     8,    63,    25,    26,    81,    81,    41,
      30,    44,    45,    84,    34,    89,    34,    31,    92,    93,
      84,    74,    75,    76,    54,    92,    79,   104,    63,    21,
     256,    36,    46,    92,   177,    71,   110,    57,    56,    69,
      88,    90,    56,    91,    77,    78,    79,    80,    78,    41,
      63,   104,    86,    92,    88,    73,   120,    88,    50,    73,
     141,   149,    93,    88,    91,    90,    79,   141,   141,   246,
      83,    71,   153,    63,    79,    41,    42,    43,    91,   153,
     153,    88,    74,    75,    76,    63,    93,    79,    63,    79,
      88,   168,    91,    83,    63,    85,   149,   161,   130,    84,
     130,   119,    83,    88,    79,    83,   104,    85,    83,   145,
      63,   175,   104,    90,    83,   168,    79,    83,    88,    85,
      83,    87,    85,    93,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   258,   223,   297,    84,   177,   182,    84,    88,   223,
     223,    88,    84,    84,    84,   219,    88,   149,    88,    84,
     196,   242,    63,    88,    83,    83,    85,   165,   242,   242,
     168,    83,   170,   171,   172,   225,   168,    84,    79,   243,
     216,    88,    83,    88,   258,   183,    91,    84,    83,    90,
     222,    88,   222,    83,    71,    85,    44,    45,    46,    47,
      48,    49,   222,    77,    78,    79,    80,    88,    88,   229,
     240,    91,   293,    79,    80,    88,   292,   215,    91,   293,
     293,    86,    90,   255,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    90,    83,   255,    85,    37,   312,   312,
     304,    91,   306,   307,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    84,    63,    63,    63,    83,   323,
      84,   297,    71,    84,    84,     4,    84,    86,     7,     8,
     334,   335,   292,    12,   310,    14,    15,    16,    13,    91,
      69,    86,    21,    22,    23,   240,    74,    26,    27,    62,
      29,    30,   168,    32,    33,    34,    35,    36,   142,    -1,
     229,    34,   119,    -1,   302,   303,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
      78,    79,    -1,    81,    82,    83,    74,    75,    76,    77,
      78,    79,    80,    91,    92,    93,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
      78,    79,    -1,    81,    82,    83,     5,     6,    -1,    -1,
       9,    10,    11,    91,    92,    93,    -1,    -1,    17,    18,
      19,    44,    45,    46,    47,    -1,    25,    -1,    -1,    28,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,
      79,    -1,    81,    82,    83,     5,     6,    -1,    -1,     9,
      10,    11,    91,    92,    93,    -1,    -1,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    28,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,    79,
      -1,    81,    82,    83,    -1,    -1,     4,    -1,    -1,     7,
       8,    91,    92,    93,    12,    -1,    14,    15,    16,    -1,
      -1,    -1,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,     5,
       6,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    71,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    77,    78,    79,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,     7,     8,    -1,    91,    92,    12,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,     7,     8,    -1,    -1,    -1,    12,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,     0,    -1,    -1,    -1,     4,    -1,    -1,
       7,     8,    -1,    -1,    -1,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,    23,    -1,    93,    26,
      27,    -1,    29,    30,    -1,    32,    33,    34,    35,    36,
      -1,    -1,     4,    -1,    -1,     7,     8,    -1,    -1,    -1,
      12,    -1,    14,    15,    16,    -1,    -1,    -1,    93,    21,
      22,    23,    -1,    -1,    26,    27,    63,    29,    30,    -1,
      32,    33,    34,    35,    36,    -1,    -1,     4,    -1,    -1,
       7,     8,    79,    -1,    -1,    12,    83,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    26,
      27,    63,    29,    30,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    79,    -1,     7,
       8,    83,    84,    85,    12,    -1,    14,    15,    16,    -1,
      -1,    -1,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    -1,
      -1,     4,    79,    -1,     7,     8,    83,    84,    85,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    63,    29,    30,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,     4,    -1,    -1,
       7,     8,    -1,    -1,    -1,    12,    84,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    26,
      27,    -1,    29,    30,    -1,    32,    33,    34,    35,    36,
      -1,     7,     8,    -1,    -1,    -1,    12,    -1,    14,    -1,
      16,    84,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    -1,    30,    -1,    63,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    83,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    42,    43,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    77,    78,    79,    -1,    81,    82,    83,    -1,    -1,
      28,    -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    42,    43,    77,    78,    79,    -1,
      81,    82,    83,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    63,    64,    65,    66,    42,
      43,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
      78,    79,    -1,    81,    82,    83,    -1,    -1,    28,    -1,
      63,    64,    65,    66,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    42,    43,    77,    78,    79,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    28,    91,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    42,    43,    -1,    74,    -1,    -1,    77,    78,    79,
      -1,    81,    82,    83,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    63,    64,    65,    66,    -1,    -1,    42,    43,
      -1,    -1,    -1,    74,    -1,    -1,    77,    78,    79,    28,
      81,    82,    83,    -1,    -1,    86,    -1,    -1,    -1,    63,
      64,    65,    66,    42,    43,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    77,    78,    79,    28,    81,    82,    83,
      -1,    -1,    86,    -1,    63,    64,    65,    66,    -1,    -1,
      42,    43,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,
      79,    28,    81,    82,    83,    -1,    -1,    86,    -1,    -1,
      -1,    63,    64,    65,    66,    42,    43,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    77,    78,    79,    28,    81,
      82,    83,    84,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    42,    43,    -1,    -1,    -1,    74,    -1,    -1,
      77,    78,    79,    28,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    42,    43,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,    79,
      28,    81,    82,    83,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    42,    43,    -1,    -1,    -1,    74,
      -1,    -1,    77,    78,    79,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
      78,    79,    -1,    81,    82,    83,     4,    -1,    -1,     7,
       8,    -1,    -1,    -1,    12,    -1,    14,    15,    16,    -1,
      -1,    -1,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    44,
      45,    46,    47,    48,    49,    50,    51,    44,    45,    46,
      47,    48,    49,    -1,    52,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    73,    74,    75,    76,
      77,    78,    79,    80,    89,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,     4,    -1,    -1,     7,     8,    -1,    -1,    -1,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,     7,     8,    -1,    -1,    -1,    12,
      -1,    14,    -1,    16,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     7,     8,    12,    14,    15,    16,    21,    22,
      23,    26,    27,    29,    30,    32,    33,    34,    35,    36,
      63,    79,    83,   107,   108,   111,   112,   113,   114,   120,
     123,   124,   125,   126,   146,   147,   148,    63,    92,   123,
     126,   127,   124,    91,   109,   110,   124,   108,   108,    63,
      92,   108,    92,   107,   108,   139,   140,    83,    85,   125,
       0,   147,    92,    63,   121,   122,   123,   126,    84,    88,
      91,    71,   139,   140,    92,   112,   115,   116,   117,   123,
       5,     6,     9,    10,    11,    17,    18,    19,    25,    28,
      31,    37,    42,    43,    63,    64,    65,    66,    74,    77,
      78,    79,    81,    82,    83,    91,    93,    95,    96,    98,
      99,   100,   101,   102,   103,   105,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   124,   107,   139,    63,    84,
     108,   128,   129,   130,   131,    63,    86,    98,   102,   106,
     121,    71,    88,    93,   110,    92,   103,   135,   139,   115,
     117,    93,   116,    90,   118,   119,   124,   117,    91,   106,
      91,    90,   137,    83,    63,    83,    91,   105,    83,    98,
      83,    83,    83,    98,    98,    90,   105,   117,   132,    41,
      42,    43,    83,    85,    87,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    71,   104,   100,    44,    45,
      46,    47,    48,    49,    50,    51,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    89,    88,    91,    93,   141,
      93,   137,    83,    85,   124,   126,   133,   134,    84,    88,
      84,    88,    86,    93,   106,   122,   135,   136,    93,   106,
      88,    91,    90,    90,   137,    37,   142,    91,   105,    91,
     132,   105,   105,   137,    84,    83,   126,   133,    84,    63,
      84,    97,   103,   105,    63,   103,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   105,   103,    93,    84,   128,   133,    86,
     106,   134,    83,    85,    52,   130,    63,    88,    93,   119,
     106,   137,    83,   142,    84,    84,    84,    84,   100,    84,
      88,    86,    90,    84,    84,    86,    84,   128,    86,   106,
      93,   135,   105,    84,   105,   137,   137,   137,   103,   102,
      84,    86,    84,   137,    84,    13,    91,   137,   137
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
      

/* Line 1806 of yacc.c  */
#line 2044 "hw2.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 440 "hw2.y"

/* Function definitions go here */
int main()
{
	init_table(&t, 512, NULL);
	curr_table = &t; // initialize scope to global scope
	strcpy(curr_file, "stdin");
	line = 1;
	yyparse();
	return 0;
}

void yyerror (char const *s)
{
	fprintf(stderr, "%s\n", s);
}

void PRINTEXP(YYSTYPE v)
{
	printf("%s:%d: ", curr_file, line); 
	printf("exprval=%lld\n", v.int_val);
}


// add a new identifier to the current symbol table
void INSTALL(SYMTABLE *t, YYSTYPE val)
{
	if (in_table(t, val.ident_val))
	{
		fprintf(stderr, "%s:%d: ", curr_file, line); 
    	fprintf(stderr, "Error: redeclaration of %s\n", val.ident_val);
		return;
    }
	val.has_val = 0;
   	ins_table(t, val.ident_val, val); // junk value 
}

// make sure the number has an integer equivalent
YYSTYPE FIXNUM(YYSTYPE v)
{
	if (v.metadata.num_class == REAL_CLASS)
	{
		fprintf(stderr, "%s:%d: ", curr_file, line); 
		fprintf(stderr, "Warning: rounding real number to integer\n");
		if (!strcmp(v.metadata.num_type, "DOUBLE"))
		{
			v.int_val = llrint(v.double_val);		
		}
		else if (!strcmp(v.metadata.num_type, "LONGDOUBLE"))
		{
			v.int_val = llrintl(v.double_val);
		}
		else
		{
			v.int_val = llrintf(v.float_val);
		}
	}
	return v;
}

// add or update the value associated with an identifier
int UPDATE(SYMTABLE *t, char *key, YYSTYPE val)
{
	TABLECELL *tc;
    if (!in_table(t, key))
    {
		fprintf(stderr, "%s:%d: ", curr_file, line); 
        fprintf(stderr, "Error: identifier %s undeclared\n", val.ident_val);
        return 1;
    }
	if (!val.has_val) // don't bother updating
	{
		return 1;	
	}
	val.has_val = 1;
	update_table(t, key, val);
	return 0;
}

YYSTYPE RETRIEVE(SYMTABLE *t, char *key)
{
	YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
	TABLECELL *tc;
	if (!(tc = in_table(t, key)))
	{
		fprintf(stderr, "%s:%d: ", curr_file, line); 
		fprintf(stderr, "Error: identifier %s undeclared\n", key);
		res->int_val = 0;
		return *res;	
	}
	*res = tc->value;
    if (!res->has_val)
	{
        fprintf(stderr, "%s:%d: ", curr_file, line);
        fprintf(stderr, "Error: identifier %s undefined\n", key);
        res->int_val=0;
	}	
	return *res;
}

/* SCOPE */
void SPOP()
{
	SYMTABLE *temp = curr_table;
	curr_table = curr_table->parent;
	free(temp->cells);
	free(temp);
}

void SPUSH()
{
	SYMTABLE *temp = malloc(sizeof(SYMTABLE));
	init_table(temp, 256, curr_table);
	curr_table = temp;
}

/* ARITHMETIC */
// for now it is only defined for integers

YYSTYPE UNARY(YYSTYPE v, int op)
{
	switch (op)
	{
		case PLUSPLUS:
			v.int_val = v.int_val + 1;
			break;
		case MINUSMINUS:
			v.int_val = v.int_val -1;
			break;
		case '+':
			v.int_val = ((v.int_val > 0) ? v.int_val : (-1*v.int_val));
			break;
		case '-':
			v.int_val = ((v.int_val < 0) ? v.int_val : (-1*v.int_val));
			break;
	}
	if (v.ident_val && in_table(curr_table, v.ident_val))
	{
		UPDATE(curr_table, v.ident_val, v);
	}
	return v;
}


YYSTYPE BINARY(YYSTYPE v1, YYSTYPE v2, int op)
{
    YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
	res->metadata.tokname = "NUMBER";
	res->has_val = 1;
	switch (op)
	{
		case '/':
			res->int_val = v1.int_val / v2.int_val; break;
		case '*':
			res->int_val = v1.int_val * v2.int_val; break;
		case '+':
			res->int_val = v1.int_val + v2.int_val; break;
		case '-':
			res->int_val = v1.int_val - v2.int_val; break;
		case SHL:
			res->int_val = v1.int_val << v2.int_val; break;
		case SHR:
			res->int_val = v1.int_val >> v2.int_val; break;
	}
	return *res;
}


YYSTYPE OPASSIGN(YYSTYPE v1, YYSTYPE v2, int op)
{
	TABLECELL *tc;
    YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
	res->int_val = 0;
    if (!CHECK(v1))
    {
        return *res;
    }
    if (!(tc = in_table(curr_table, v1.ident_val)))
    {
		fprintf(stderr, "%s:%d: ", curr_file, line); 
        fprintf(stderr, "Error: identifier %s undeclared\n", v1.ident_val);
        return *res;
    }
	res->metadata.tokname = "NUMBER";
	res->has_val = 1;
	switch (op)
	{
		case PLUSEQ:
			v1.int_val = v1.int_val + v2.int_val; break; 
		case MINUSEQ:
			v1.int_val = v1.int_val - v2.int_val; break; 
		case TIMESEQ:
			v1.int_val = v1.int_val * v2.int_val; break; 
		case DIVEQ:
			v1.int_val = v1.int_val / v2.int_val; break; 
		case MODEQ:
			v1.int_val = v1.int_val % v2.int_val; break; 
		case SHLEQ:
			v1.int_val = v1.int_val << v2.int_val; break; 
		case SHREQ:
			v1.int_val = v1.int_val << v2.int_val; break; 
		case ANDEQ:
			v1.int_val = v1.int_val & v2.int_val; break; 
		case OREQ:
			v1.int_val = v1.int_val | v2.int_val; break; 
		case XOREQ:
			v1.int_val = v1.int_val ^ v2.int_val; break; 
	}
	UPDATE(curr_table, v1.ident_val, v1);
	return v1;
}

YYSTYPE TERNARY(YYSTYPE v1, YYSTYPE v2, YYSTYPE v3)
{
	YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
	if (v1.int_val)
	{
		return v2;
	}
	else
	{
		return v3;
	}
}


int CHECK(YYSTYPE v)
{
    if (!v.has_val)
    {
		fprintf(stderr, "%s:%d: ", curr_file, line); 
        fprintf(stderr, "Error: identifier %s undefined\n", v.ident_val);
        return 0;
    }
	return 1;
}

