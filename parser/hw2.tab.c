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
     FILEDIR = 325,
     RSH = 326,
     LSH = 327
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
#line 217 "hw2.tab.c"

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
#define YYLAST   1526

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  203
/* YYNRULES -- Number of states.  */
#define YYNSTATES  324

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,     2,     2,     2,     2,    76,     2,
      87,    88,    83,    81,    71,    82,    91,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,    93,
      78,    72,    77,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    90,    92,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,    75,    95,    86,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    79,    80
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    15,    17,    22,
      26,    31,    35,    39,    42,    45,    47,    51,    53,    56,
      59,    62,    65,    70,    72,    74,    76,    78,    80,    82,
      84,    89,    91,    95,    97,    99,   101,   103,   105,   107,
     109,   111,   113,   115,   117,   119,   121,   123,   125,   127,
     129,   131,   137,   139,   143,   145,   147,   149,   151,   153,
     155,   157,   159,   161,   163,   165,   167,   171,   173,   176,
     180,   182,   185,   187,   190,   192,   195,   197,   201,   203,
     207,   209,   211,   213,   215,   217,   219,   221,   223,   225,
     227,   229,   231,   233,   235,   237,   239,   245,   250,   253,
     255,   257,   259,   262,   266,   269,   271,   274,   276,   278,
     282,   284,   287,   291,   296,   302,   305,   307,   311,   313,
     317,   319,   321,   324,   326,   328,   332,   337,   341,   346,
     351,   355,   357,   360,   363,   367,   369,   372,   374,   378,
     380,   384,   387,   390,   392,   394,   398,   400,   403,   405,
     407,   410,   414,   417,   421,   425,   430,   433,   437,   441,
     446,   448,   452,   457,   459,   463,   465,   467,   469,   471,
     473,   475,   479,   484,   488,   491,   495,   499,   504,   506,
     509,   511,   514,   516,   519,   525,   533,   539,   545,   553,
     560,   568,   572,   575,   578,   581,   585,   587,   590,   592,
     594,   599,   603,   607
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,    63,    -1,    66,    -1,    65,    -1,    64,
      -1,    87,   108,    88,    -1,    97,    -1,    98,    89,   108,
      90,    -1,    98,    87,    88,    -1,    98,    87,    99,    88,
      -1,    98,    91,    63,    -1,    98,    41,    63,    -1,    98,
      42,    -1,    98,    43,    -1,   106,    -1,    99,    71,   106,
      -1,    98,    -1,    42,   100,    -1,    43,   100,    -1,   101,
     102,    -1,    28,   100,    -1,    28,    87,   135,    88,    -1,
      76,    -1,    83,    -1,    81,    -1,    82,    -1,    86,    -1,
      85,    -1,   100,    -1,    87,   135,    88,   102,    -1,   102,
      -1,   103,   104,   103,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    76,    -1,    75,    -1,    92,    -1,    80,
      -1,    79,    -1,    51,    -1,    50,    -1,    48,    -1,    49,
      -1,    78,    -1,    77,    -1,    46,    -1,    47,    -1,   103,
      -1,   103,    73,   108,    74,   105,    -1,   105,    -1,   100,
     107,   106,    -1,    72,    -1,    53,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,
      -1,    61,    -1,    62,    -1,   106,    -1,   108,    71,   106,
      -1,   105,    -1,   111,    93,    -1,   111,   112,    93,    -1,
     114,    -1,   114,   111,    -1,   115,    -1,   115,   111,    -1,
     126,    -1,   126,   111,    -1,   113,    -1,   112,    71,   113,
      -1,   127,    -1,   127,    72,   138,    -1,    32,    -1,    15,
      -1,    29,    -1,     4,    -1,    23,    -1,    35,    -1,     7,
      -1,    26,    -1,    21,    -1,    22,    -1,    16,    -1,    12,
      -1,    27,    -1,    34,    -1,   116,    -1,   123,    -1,   117,
      63,    94,   118,    95,    -1,   117,    94,   118,    95,    -1,
     117,    63,    -1,    30,    -1,    33,    -1,   119,    -1,   118,
     119,    -1,   120,   121,    93,    -1,   115,   120,    -1,   115,
      -1,   126,   120,    -1,   126,    -1,   122,    -1,   121,    71,
     122,    -1,   127,    -1,    74,   109,    -1,   127,    74,   109,
      -1,    14,    94,   124,    95,    -1,    14,    63,    94,   124,
      95,    -1,    14,    63,    -1,   125,    -1,   124,    71,   125,
      -1,    63,    -1,    63,    72,   109,    -1,     8,    -1,    36,
      -1,   129,   128,    -1,   128,    -1,    63,    -1,    87,   127,
      88,    -1,   128,    89,   109,    90,    -1,   128,    89,    90,
      -1,   128,    87,   131,    88,    -1,   128,    87,   134,    88,
      -1,   128,    87,    88,    -1,    83,    -1,    83,   130,    -1,
      83,   129,    -1,    83,   130,   129,    -1,   126,    -1,   130,
     126,    -1,   132,    -1,   132,    71,    52,    -1,   133,    -1,
     132,    71,   133,    -1,   111,   127,    -1,   111,   136,    -1,
     111,    -1,    63,    -1,   134,    71,    63,    -1,   120,    -1,
     120,   136,    -1,   129,    -1,   137,    -1,   129,   137,    -1,
      87,   136,    88,    -1,    89,    90,    -1,    89,   109,    90,
      -1,   137,    89,    90,    -1,   137,    89,   109,    90,    -1,
      87,    88,    -1,    87,   131,    88,    -1,   137,    87,    88,
      -1,   137,    87,   131,    88,    -1,   106,    -1,    94,   139,
      95,    -1,    94,   139,    71,    95,    -1,   138,    -1,   139,
      71,   138,    -1,   141,    -1,   142,    -1,   145,    -1,   146,
      -1,   147,    -1,   148,    -1,    63,    74,   140,    -1,     6,
     109,    74,   140,    -1,    10,    74,   140,    -1,    94,    95,
      -1,    94,   144,    95,    -1,    94,   143,    95,    -1,    94,
     143,   144,    95,    -1,   110,    -1,   143,   110,    -1,   140,
      -1,   144,   140,    -1,    93,    -1,   108,    93,    -1,    19,
      87,   108,    88,   140,    -1,    19,    87,   108,    88,   140,
      13,   140,    -1,    31,    87,   108,    88,   140,    -1,    37,
      87,   108,    88,   140,    -1,    11,   140,    37,    87,   108,
      88,    93,    -1,    17,    87,   145,   145,    88,   140,    -1,
      17,    87,   145,   145,   108,    88,   140,    -1,    18,    63,
      93,    -1,     9,    93,    -1,     5,    93,    -1,    25,    93,
      -1,    25,   108,    93,    -1,   150,    -1,   149,   150,    -1,
     151,    -1,   110,    -1,   111,   127,   143,   142,    -1,   111,
     127,   142,    -1,   127,   143,   142,    -1,   127,   142,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   133,   134,   135,   136,   139,   140,   141,
     142,   143,   144,   145,   146,   149,   150,   153,   154,   155,
     156,   157,   158,   161,   162,   163,   164,   165,   166,   169,
     170,   173,   174,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     196,   197,   200,   201,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   217,   218,   221,   224,   225,
     228,   229,   230,   231,   232,   233,   236,   237,   240,   241,
     244,   245,   246,   247,   248,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   264,   265,   266,   269,
     270,   273,   274,   277,   280,   281,   282,   283,   286,   287,
     290,   291,   292,   295,   296,   297,   300,   301,   304,   305,
     308,   309,   312,   313,   316,   317,   318,   319,   320,   321,
     322,   325,   326,   327,   328,   331,   332,   335,   336,   339,
     340,   343,   344,   345,   348,   349,   352,   353,   356,   357,
     358,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     372,   373,   374,   377,   378,   381,   382,   383,   384,   385,
     386,   389,   390,   391,   394,   395,   396,   397,   400,   401,
     404,   405,   408,   409,   412,   413,   414,   417,   418,   419,
     420,   423,   424,   425,   426,   427,   430,   431,   434,   435,
     438,   439,   440,   441
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
  "NUMBER", "ERRC", "ERRS", "NEWLINE", "FILEDIR", "','", "'='", "'?'",
  "':'", "'|'", "'&'", "'>'", "'<'", "RSH", "LSH", "'+'", "'-'", "'*'",
  "'/'", "'!'", "'~'", "'('", "')'", "'['", "']'", "'.'", "'^'", "';'",
  "'{'", "'}'", "$accept", "primary_expr", "postfix_expr", "arglist",
  "unary_expr", "unary_op", "cast_expr", "binary_expr", "binary_op",
  "conditional_expr", "assign_expr", "assign_op", "expr", "constant_expr",
  "declaration", "dec_specs", "init_declarator_list", "init_declarator",
  "storage_spec", "type_spec", "struct_union_spec", "s_or_u",
  "struct_declaration_list", "struct_declaration", "spec_qual_list",
  "struct_declarator_list", "struct_declarator", "enum_spec", "enum_list",
  "enumerator", "type_qual", "declarator", "direct_declarator", "pointer",
  "type_qual_list", "param_type_list", "param_list", "param_declaration",
  "id_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "labeled_stmt", "compound_stmt", "declaration_list",
  "stmt_list", "expr_stmt", "selection_stmt", "iter_stmt", "jump_stmt",
  "translation_unit", "external_declaration", "function_definition", 0
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
     325,    44,    61,    63,    58,   124,    38,    62,    60,   326,
     327,    43,    45,    42,    47,    33,   126,    40,    41,    91,
      93,    46,    94,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    97,    97,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   114,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   116,   116,   116,   117,
     117,   118,   118,   119,   120,   120,   120,   120,   121,   121,
     122,   122,   122,   123,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   128,   128,   128,   128,
     128,   129,   129,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   133,   134,   134,   135,   135,   136,   136,
     136,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   139,   139,   140,   140,   140,   140,   140,
     140,   141,   141,   141,   142,   142,   142,   142,   143,   143,
     144,   144,   145,   145,   146,   146,   146,   147,   147,   147,
     147,   148,   148,   148,   148,   148,   149,   149,   150,   150,
     151,   151,   151,   151
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    83,    86,   120,    91,     0,    81,    90,    88,    89,
      84,    87,    92,    82,    99,    80,   100,    93,    85,   121,
     124,   131,     0,   199,     0,    70,    72,    94,     0,    95,
      74,     0,   123,     0,     0,   196,   198,   115,     0,   135,
     133,   132,     0,    68,     0,    76,    78,    71,    73,    98,
       0,    75,     0,   178,     0,   203,     0,     0,     0,   122,
       1,   197,     0,   118,     0,   116,   136,   134,   125,     0,
      69,     0,   201,     0,     0,   105,     0,   101,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     5,     4,     3,    23,    25,
      26,    24,    28,    27,     0,   182,   174,     7,    17,    29,
       0,    31,    50,    52,    65,     0,   180,   165,   166,     0,
       0,   167,   168,   169,   170,    78,   179,   202,   144,   130,
     143,     0,   137,   139,     0,     2,   127,    29,    67,     0,
       0,     0,     0,   113,    77,     0,   160,    79,   200,     0,
     104,    97,   102,     0,     0,   108,   110,   106,   193,     0,
     192,     0,     0,     0,     0,     0,   194,     0,     0,    21,
       0,     0,     0,    18,    19,     0,     0,   146,     0,     0,
      13,    14,     0,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    54,     0,    20,    48,    49,
      44,    45,    43,    42,     0,    38,    37,    47,    46,    41,
      40,    33,    34,    35,    36,    39,     0,     0,   183,   176,
       0,   175,   181,     0,     0,   141,   148,   142,   149,   128,
       0,     0,   129,   126,   114,   119,   117,   163,     0,    96,
     111,     0,   103,     0,     0,   173,     0,     0,   191,     0,
     195,     0,     0,     0,   171,     6,     0,   148,   147,     0,
      12,     9,     0,    15,     0,    11,    53,     0,    32,    66,
     177,   156,     0,     0,   152,     0,   150,     0,     0,   138,
     140,   145,     0,   161,   109,   112,   172,     0,     0,     0,
      22,     0,     0,    30,     0,    10,     8,     0,   157,   151,
     153,   158,     0,   154,     0,   162,   164,     0,     0,     0,
     184,   186,   187,    16,    51,   159,   155,     0,   189,     0,
       0,   188,   190,   185
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   262,   109,   110,   111,   112,   216,   113,
     114,   196,   115,   139,    53,    54,    44,    45,    25,    26,
      27,    28,    76,    77,    78,   154,   155,    29,    64,    65,
      30,    31,    32,    33,    41,   272,   132,   133,   134,   178,
     273,   228,   147,   238,   116,   117,   118,    56,   120,   121,
     122,   123,   124,    34,    35,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -188
static const yytype_int16 yypact[] =
{
    1017,  -188,  -188,  -188,  -188,   -45,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,     7,    81,  -188,    58,  1460,  1460,  -188,   -40,  -188,
    1460,   644,    98,    10,   826,  -188,  -188,   -63,   -22,  -188,
    -188,     7,   -16,  -188,   -15,  -188,   611,  -188,  -188,   -27,
    1490,  -188,   253,  -188,    58,  -188,   644,   942,   406,    98,
    -188,  -188,   -22,    32,   -21,  -188,  -188,  -188,  -188,    81,
    -188,  1099,  -188,   644,  1490,  1490,   759,  -188,    66,  1490,
      23,  1236,    30,    37,   676,    -6,    87,    79,  1124,  1261,
      82,    85,  1286,  1286,   106,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  1049,  -188,  -188,  -188,    92,   248,
    1236,  -188,  1361,  -188,  -188,    14,  -188,  -188,  -188,   345,
     436,  -188,  -188,  -188,  -188,   119,  -188,  -188,  -188,  -188,
      25,    89,   127,  -188,   -11,  -188,  -188,  -188,  -188,   109,
     -20,  1236,   -22,  -188,  -188,  1099,  -188,  -188,  -188,   789,
    -188,  -188,  -188,  1236,    35,  -188,   126,  -188,  -188,   129,
    -188,   676,   164,  1149,   111,  1236,  -188,    68,  1049,  -188,
    1236,  1236,  1236,  -188,  -188,   676,    27,    95,   117,   143,
    -188,  -188,   668,  1236,   149,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  1236,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  1236,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  1236,  1236,  -188,  -188,
     527,  -188,  -188,   864,   497,  -188,   -41,  -188,   103,  -188,
    1370,   151,  -188,  -188,  -188,  -188,  -188,  -188,    18,  -188,
    -188,    66,  -188,  1236,   676,  -188,   128,  1149,  -188,    39,
    -188,   130,    72,    75,  -188,  -188,   903,   108,  -188,  1236,
    -188,  -188,    86,  -188,   -38,  -188,  -188,    21,  1379,  -188,
    -188,  -188,   131,   132,  -188,   137,   103,   981,  1180,  -188,
    -188,  -188,  1074,  -188,  -188,  -188,  -188,  1236,  1209,   676,
    -188,   676,   676,  -188,  1236,  -188,  -188,  1236,  -188,  -188,
    -188,  -188,   134,  -188,   138,  -188,  -188,   100,   676,   105,
     203,  -188,  -188,  -188,  -188,  -188,  -188,   139,  -188,   676,
     676,  -188,  -188,  -188
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,  -188,  -188,   -57,  -188,  -103,    17,  -188,   -54,
     -65,  -188,   -46,   -70,    13,     0,  -188,   165,  -188,    26,
    -188,  -188,   161,   -55,   -59,  -188,    -5,  -188,   177,   104,
     -13,   -10,   -30,   -12,  -188,   -52,  -188,    15,  -188,    80,
    -113,  -187,  -135,  -188,   -82,  -188,     9,    96,   133,  -144,
    -188,  -188,  -188,  -188,   213,  -188
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      24,   137,   162,    59,   138,   131,   146,   197,    39,    40,
     237,   159,    42,    23,    46,     3,   150,   227,    37,   247,
     157,   152,    20,    49,   137,    47,    48,   138,    66,    67,
      51,    62,   169,   217,    24,   173,   174,    79,   222,   276,
      55,    63,   167,    19,   125,   177,   223,    23,   224,    38,
     142,   142,   296,   137,    50,    72,    69,   130,   176,   125,
     231,    79,    79,    79,   258,   127,    79,    74,   156,   126,
     276,   235,    68,    20,   143,   234,    75,   232,    70,   245,
     146,   163,   148,   240,   137,   217,   126,   138,    20,   282,
      21,    79,   217,   254,   152,   297,   137,    22,   217,   138,
      75,    75,    75,   288,   141,    75,   241,   218,    21,   177,
     217,   161,   223,   283,   224,   255,   158,   263,   226,   249,
     225,    20,   176,   160,   252,   253,   176,   289,   242,    20,
      75,   266,   126,   179,   180,   181,    79,   264,   222,   217,
     153,    21,    73,   217,    20,    22,   217,   306,   119,    21,
     164,    43,   269,    22,   275,    79,   293,   294,   267,   137,
     291,   250,   286,   292,    21,   257,   165,   137,    22,   170,
     138,   217,   171,   285,   295,    75,   217,   229,    21,   182,
     175,   183,   256,   184,   224,    57,   137,    58,   317,   138,
     277,    71,   278,   319,    75,   256,    59,   224,   230,   233,
     243,   246,   137,   244,   248,   259,   260,   310,   304,   311,
     312,   226,   265,    42,   281,   287,   320,   146,   290,   298,
     299,   137,   315,   130,   138,   302,   318,   300,   316,   313,
     130,   156,   321,   268,   144,   149,   284,   322,   323,   140,
     137,   307,   309,   314,   257,   280,   236,    61,   251,     0,
       0,     0,   220,     0,     0,     0,   130,     1,    80,    81,
       2,     3,    82,    83,    84,     4,     0,     5,     6,     7,
      85,    86,    87,     0,     8,     9,    10,   130,    88,    11,
      12,    89,    13,    14,    90,    15,    16,    17,    18,    19,
      91,     0,     0,     0,     0,    92,    93,     0,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,     0,     0,     0,     0,    94,    95,    96,    97,
     195,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,    99,   100,   101,     0,   102,   103,
     104,     0,     0,     0,     0,     0,   105,    52,   106,     1,
      80,    81,     2,     3,    82,    83,    84,     4,     0,     5,
       6,     7,    85,    86,    87,     0,     8,     9,    10,     0,
      88,    11,    12,    89,    13,    14,    90,    15,    16,    17,
      18,    19,    91,     0,     0,     0,     0,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,    99,   100,   101,     0,
     102,   103,   104,     0,    89,     0,     0,     0,   105,    52,
     219,    80,    81,     0,     0,    82,    83,    84,    92,    93,
       0,     0,     0,    85,    86,    87,     0,     0,     0,     0,
       0,    88,     0,     0,    89,     0,     0,    90,     0,   135,
      95,    96,    97,    91,     0,     0,     0,     0,    92,    93,
       0,     0,    98,     0,     0,     0,     0,    99,   100,   101,
       0,   102,   103,   104,     0,     0,   136,     0,     0,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,    99,   100,   101,
       0,   102,   103,   104,     0,    89,     0,     0,     0,   105,
      52,   221,    80,    81,     0,     0,    82,    83,    84,    92,
      93,     0,     0,     0,    85,    86,    87,     0,     0,     0,
       0,     0,    88,     0,     0,    89,     0,     0,    90,     0,
     135,    95,    96,    97,    91,     0,     0,     0,     0,    92,
      93,     0,     0,    98,     0,     0,     0,     0,    99,   100,
     101,     0,   102,   103,   104,     0,     0,   274,     0,     0,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,     0,     0,     0,     0,    99,   100,
     101,     0,   102,   103,   104,     1,     0,     0,     2,     3,
     105,    52,   270,     4,     0,     5,     6,     7,     0,     0,
       0,     0,     8,     9,    10,     0,     0,    11,    12,     0,
      13,    14,     0,    15,    16,    17,    18,    19,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,     0,     8,     9,    10,     0,     0,
      11,    12,     0,    13,    14,     0,    15,    16,    17,    18,
      19,    80,    81,    71,     0,    82,    83,    84,     0,     0,
       0,     0,     0,    85,    86,    87,    89,     0,     0,     0,
       0,    88,     0,     0,    89,    52,     0,    90,     0,     0,
      92,    93,     0,    91,     0,     0,     0,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,    95,    96,    97,     0,     0,     0,    52,    94,
      95,    96,    97,     0,    98,     0,     0,     0,     0,    99,
     100,   101,    98,   102,   103,   104,   261,    99,   100,   101,
       0,   102,   103,   104,     0,     0,     2,     3,     0,   105,
      52,     4,     0,     5,     0,     7,     0,     0,     0,     0,
       8,     9,     0,     0,     0,    11,    12,     0,     0,    14,
       0,     0,    16,    17,    18,    19,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,     0,
       8,     9,     0,     0,     0,    11,    12,     0,     0,    14,
       0,     0,    16,    17,    18,    19,    60,     0,     0,     0,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     0,     8,     9,    10,
       0,     0,    11,    12,   151,    13,    14,     0,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,   239,     8,     9,    10,     0,    20,
      11,    12,     0,    13,    14,     0,    15,    16,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     1,     0,    21,
       2,     3,     0,    22,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     0,     8,     9,    10,    20,     0,    11,
      12,     0,    13,    14,     0,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     1,    21,     0,     2,
       3,   223,   271,   224,     4,     0,     5,     6,     7,     0,
       0,     0,     0,     8,     9,    10,     0,     0,    11,    12,
       0,    13,    14,     0,    15,    16,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     1,    21,     0,     2,     3,
     256,   271,   224,     4,     0,     5,     6,     7,     0,     0,
       0,     0,     8,     9,    10,   128,     0,    11,    12,     0,
      13,    14,     0,    15,    16,    17,    18,    19,     0,     0,
       0,     1,     0,     0,     2,     3,     0,     0,     0,     4,
     129,     5,     6,     7,     0,     0,     0,     0,     8,     9,
      10,     0,     0,    11,    12,     0,    13,    14,     0,    15,
      16,    17,    18,    19,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,   301,
       8,     9,     0,     0,     0,    11,    12,    89,     0,    14,
      20,     0,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      21,     0,    89,     0,    22,     0,     0,     0,     0,     0,
       0,     0,   135,    95,    96,    97,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    98,     0,    89,     0,     0,
      99,   100,   101,     0,   102,   103,   104,   135,    95,    96,
      97,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      98,     0,    89,     0,     0,    99,   100,   101,     0,   102,
     103,   104,   135,    95,    96,    97,    92,    93,   145,   305,
       0,     0,     0,     0,     0,    98,     0,    89,     0,     0,
      99,   100,   101,     0,   102,   103,   104,   135,    95,    96,
      97,    92,    93,   145,     0,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,    99,   100,   101,    89,   102,
     103,   104,   135,    95,    96,    97,     0,   166,     0,     0,
       0,     0,    92,    93,     0,    98,     0,     0,     0,     0,
      99,   100,   101,     0,   102,   103,   104,    89,     0,     0,
       0,     0,   105,   135,    95,    96,    97,     0,     0,     0,
       0,    92,    93,     0,     0,     0,    98,     0,     0,     0,
       0,    99,   100,   101,    89,   102,   103,   104,     0,     0,
     303,     0,   135,    95,    96,    97,     0,     0,    92,    93,
       0,     0,     0,     0,     0,    98,     0,     0,     0,    89,
      99,   100,   101,     0,   102,   103,   104,   308,     0,   135,
      95,    96,    97,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    98,     0,    89,     0,     0,    99,   100,   101,
       0,   102,   103,   104,   135,    95,    96,    97,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,    99,   100,   101,     0,   102,   103,   168,   135,
      95,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,    99,   100,   101,
       0,   102,   103,   172,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       0,     8,     9,    10,     0,     0,    11,    12,     0,    13,
      14,     0,    15,    16,    17,    18,    19,   198,   199,   200,
     201,   202,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,     0,     0,   198,   199,   200,   201,   202,
     203,     0,     0,     0,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,   215,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,     1,     0,     0,     2,     3,     0,
       0,   215,     4,     0,     5,     6,     7,     0,     0,     0,
       0,     8,     9,    10,     0,     0,    11,    12,     0,    13,
      14,     0,    15,    16,    17,    18,    19,     2,     3,     0,
       0,     0,     4,     0,     5,     0,     7,     0,     0,     0,
       0,     8,     9,     0,     0,     0,    11,    12,     0,     0,
      14,     0,     0,    16,    17,    18,    19
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-188))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    58,    84,    33,    58,    57,    71,   110,    21,    21,
     145,    81,    22,     0,    24,     8,    75,   130,    63,   163,
      79,    76,    63,    63,    81,    25,    26,    81,    41,    41,
      30,    94,    89,    71,    34,    92,    93,    50,   120,   226,
      31,    63,    88,    36,    54,   104,    87,    34,    89,    94,
      71,    71,    90,   110,    94,    46,    71,    57,   104,    69,
      71,    74,    75,    76,   177,    56,    79,    94,    78,    56,
     257,   141,    88,    63,    95,    95,    50,    88,    93,   161,
     145,    87,    73,   153,   141,    71,    73,   141,    63,    71,
      83,   104,    71,   175,   149,    74,   153,    87,    71,   153,
      74,    75,    76,   247,    72,    79,    71,    93,    83,   168,
      71,    74,    87,    95,    89,    88,    93,   182,   130,   165,
     130,    63,   168,    93,   170,   171,   172,    88,    93,    63,
     104,   196,   119,    41,    42,    43,   149,   183,   220,    71,
      74,    83,    46,    71,    63,    87,    71,   282,    52,    83,
      63,    93,   217,    87,   224,   168,   259,    71,   204,   216,
      88,    93,   244,    88,    83,   177,    87,   224,    87,    87,
     224,    71,    87,   243,    88,   149,    71,    88,    83,    87,
      74,    89,    87,    91,    89,    87,   243,    89,    88,   243,
      87,    72,    89,    88,   168,    87,   226,    89,    71,    90,
      74,    37,   259,    74,    93,    88,    63,   289,   278,   291,
     292,   223,    63,   223,    63,    87,    13,   282,    88,    88,
      88,   278,    88,   223,   278,   277,   308,    90,    90,   294,
     230,   241,    93,   216,    69,    74,   241,   319,   320,    62,
     297,   287,   288,   297,   256,   230,   142,    34,   168,    -1,
      -1,    -1,   119,    -1,    -1,    -1,   256,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,   277,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      85,    86,    87,    -1,    28,    -1,    -1,    -1,    93,    94,
      95,     5,     6,    -1,    -1,     9,    10,    11,    42,    43,
      -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    28,    -1,    -1,    31,    -1,    63,
      64,    65,    66,    37,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    83,
      -1,    85,    86,    87,    -1,    -1,    90,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    83,
      -1,    85,    86,    87,    -1,    28,    -1,    -1,    -1,    93,
      94,    95,     5,     6,    -1,    -1,     9,    10,    11,    42,
      43,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    28,    -1,    -1,    31,    -1,
      63,    64,    65,    66,    37,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    85,    86,    87,    -1,    -1,    90,    -1,    -1,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    85,    86,    87,     4,    -1,    -1,     7,     8,
      93,    94,    95,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    -1,    21,    22,    23,    -1,    -1,    26,    27,    -1,
      29,    30,    -1,    32,    33,    34,    35,    36,     4,    -1,
      -1,     7,     8,    -1,    -1,    -1,    12,    -1,    14,    15,
      16,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
      26,    27,    -1,    29,    30,    -1,    32,    33,    34,    35,
      36,     5,     6,    72,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    28,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    28,    94,    -1,    31,    -1,    -1,
      42,    43,    -1,    37,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    94,    63,
      64,    65,    66,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    83,    76,    85,    86,    87,    88,    81,    82,    83,
      -1,    85,    86,    87,    -1,    -1,     7,     8,    -1,    93,
      94,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,    35,    36,     7,     8,    -1,    -1,
      -1,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,    35,    36,     0,    -1,    -1,    -1,
       4,    -1,    -1,     7,     8,    -1,    -1,    -1,    12,    -1,
      14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
      -1,    -1,    26,    27,    95,    29,    30,    -1,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,     7,     8,    -1,    -1,    -1,    12,    -1,    14,    15,
      16,    -1,    -1,    -1,    95,    21,    22,    23,    -1,    63,
      26,    27,    -1,    29,    30,    -1,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    83,
       7,     8,    -1,    87,    -1,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,    23,    63,    -1,    26,
      27,    -1,    29,    30,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    83,    -1,     7,
       8,    87,    88,    89,    12,    -1,    14,    15,    16,    -1,
      -1,    -1,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    83,    -1,     7,     8,
      87,    88,    89,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    -1,    21,    22,    23,    63,    -1,    26,    27,    -1,
      29,    30,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,     4,    -1,    -1,     7,     8,    -1,    -1,    -1,    12,
      88,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    -1,    -1,     7,     8,    -1,    -1,
      -1,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,    88,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      63,    -1,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    28,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    28,    -1,    -1,
      81,    82,    83,    -1,    85,    86,    87,    63,    64,    65,
      66,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    28,    -1,    -1,    81,    82,    83,    -1,    85,
      86,    87,    63,    64,    65,    66,    42,    43,    94,    95,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    28,    -1,    -1,
      81,    82,    83,    -1,    85,    86,    87,    63,    64,    65,
      66,    42,    43,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    83,    28,    85,
      86,    87,    63,    64,    65,    66,    -1,    93,    -1,    -1,
      -1,    -1,    42,    43,    -1,    76,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    85,    86,    87,    28,    -1,    -1,
      -1,    -1,    93,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    83,    28,    85,    86,    87,    -1,    -1,
      90,    -1,    63,    64,    65,    66,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    28,
      81,    82,    83,    -1,    85,    86,    87,    88,    -1,    63,
      64,    65,    66,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    28,    -1,    -1,    81,    82,    83,
      -1,    85,    86,    87,    63,    64,    65,    66,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    85,    86,    87,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    83,
      -1,    85,    86,    87,     4,    -1,    -1,     7,     8,    -1,
      -1,    -1,    12,    -1,    14,    15,    16,    -1,    -1,    -1,
      -1,    21,    22,    23,    -1,    -1,    26,    27,    -1,    29,
      30,    -1,    32,    33,    34,    35,    36,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     4,    -1,    -1,     7,     8,    -1,
      -1,    92,    12,    -1,    14,    15,    16,    -1,    -1,    -1,
      -1,    21,    22,    23,    -1,    -1,    26,    27,    -1,    29,
      30,    -1,    32,    33,    34,    35,    36,     7,     8,    -1,
      -1,    -1,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,
      -1,    21,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     7,     8,    12,    14,    15,    16,    21,    22,
      23,    26,    27,    29,    30,    32,    33,    34,    35,    36,
      63,    83,    87,   110,   111,   114,   115,   116,   117,   123,
     126,   127,   128,   129,   149,   150,   151,    63,    94,   126,
     129,   130,   127,    93,   112,   113,   127,   111,   111,    63,
      94,   111,    94,   110,   111,   142,   143,    87,    89,   128,
       0,   150,    94,    63,   124,   125,   126,   129,    88,    71,
      93,    72,   142,   143,    94,   115,   118,   119,   120,   126,
       5,     6,     9,    10,    11,    17,    18,    19,    25,    28,
      31,    37,    42,    43,    63,    64,    65,    66,    76,    81,
      82,    83,    85,    86,    87,    93,    95,    97,    98,   100,
     101,   102,   103,   105,   106,   108,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   127,   110,   142,    63,    88,
     111,   131,   132,   133,   134,    63,    90,   100,   105,   109,
     124,    72,    71,    95,   113,    94,   106,   138,   142,   118,
     120,    95,   119,    74,   121,   122,   127,   120,    93,   109,
      93,    74,   140,    87,    63,    87,    93,   108,    87,   100,
      87,    87,    87,   100,   100,    74,   108,   120,   135,    41,
      42,    43,    87,    89,    91,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    72,   107,   102,    46,    47,
      48,    49,    50,    51,    73,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    92,   104,    71,    93,    95,
     144,    95,   140,    87,    89,   127,   129,   136,   137,    88,
      71,    71,    88,    90,    95,   109,   125,   138,   139,    95,
     109,    71,    93,    74,    74,   140,    37,   145,    93,   108,
      93,   135,   108,   108,   140,    88,    87,   129,   136,    88,
      63,    88,    99,   106,   108,    63,   106,   108,   103,   106,
      95,    88,   131,   136,    90,   109,   137,    87,    89,    52,
     133,    63,    71,    95,   122,   109,   140,    87,   145,    88,
      88,    88,    88,   102,    71,    88,    90,    74,    88,    88,
      90,    88,   131,    90,   109,    95,   138,   108,    88,   108,
     140,   140,   140,   106,   105,    88,    90,    88,   140,    88,
      13,    93,   140,   140
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
#line 2016 "hw2.tab.c"
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
#line 443 "hw2.y"

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

