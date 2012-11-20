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
#line 4 "hw3.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include "lexer.h"
	#include "symTable.h"
	#include "symTable.c"
	#include "ast.h"
	#include "ast.c"
	
	#define YYDEBUG 1
	#define MAXLEN 512

	SYMTABLE t;
	SYMTABLE *new_members = NULL; // use this to create symtable for struct members
	TABLECELL *tc; // store stuff here
	SYMTABLE *curr_table; // points to the current scope's symbol table
	char curr_file[MAXLEN+1];
	char *current_ident;
	int stat;
	int node_type;
	int TYPESPEC;

	/* functions that will be defined */
	SCALAR extract_value(YYSTYPE val);
	void INSTALL(SYMTABLE *t, char *name, YYSTYPE val);
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
#line 111 "hw3.tab.c"

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
#line 223 "hw3.tab.c"

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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   534

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

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
       2,     2,     2,    85,     2,     2,     2,     2,    76,     2,
      90,    91,    83,    81,    71,    82,    92,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,    87,
      78,    72,    77,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,    93,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,    75,    89,    86,     2,     2,     2,
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
       0,     0,     3,     5,     8,    10,    12,    16,    19,    21,
      24,    26,    29,    31,    34,    36,    38,    40,    42,    44,
      46,    48,    50,    52,    54,    56,    58,    60,    62,    64,
      66,    68,    70,    72,    75,    81,    83,    86,    90,    92,
      95,    97,   100,   102,   106,   108,   110,   112,   114,   119,
     123,   126,   131,   135,   137,   140,   142,   145,   148,   150,
     152,   154,   158,   160,   164,   169,   173,   178,   182,   186,
     189,   192,   194,   198,   200,   203,   206,   209,   212,   215,
     218,   221,   224,   226,   231,   233,   235,   239,   243,   247,
     251,   255,   259,   263,   267,   271,   275,   279,   283,   287,
     291,   295,   299,   303,   305,   311,   313,   317,   321,   325,
     329,   333,   337,   341,   345,   349,   353,   357,   359
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      95,     0,    -1,    96,    -1,    95,    96,    -1,   110,    -1,
      97,    -1,    98,   109,    87,    -1,    98,    87,    -1,    99,
      -1,    99,    98,    -1,   100,    -1,   100,    98,    -1,   101,
      -1,   101,    98,    -1,    15,    -1,    29,    -1,     4,    -1,
      23,    -1,    35,    -1,     7,    -1,    26,    -1,    21,    -1,
      22,    -1,    16,    -1,    12,    -1,    27,    -1,    34,    -1,
      38,    -1,    39,    -1,   102,    -1,     8,    -1,    24,    -1,
      36,    -1,   108,    63,    -1,   108,    63,    88,   103,    89,
      -1,   104,    -1,   103,   104,    -1,   105,   106,    87,    -1,
     100,    -1,   100,   105,    -1,   101,    -1,   101,   105,    -1,
     107,    -1,   106,    71,   107,    -1,   109,    -1,    30,    -1,
      33,    -1,    63,    -1,   109,    79,    66,    80,    -1,   109,
      79,    80,    -1,    83,   109,    -1,    63,    90,    91,   111,
      -1,    88,   112,    89,    -1,   113,    -1,   112,   113,    -1,
      97,    -1,   112,    97,    -1,   123,    87,    -1,    63,    -1,
      66,    -1,    65,    -1,    90,   123,    91,    -1,   114,    -1,
     115,    79,    80,    -1,   115,    79,    66,    80,    -1,   115,
      90,    91,    -1,   115,    90,   116,    91,    -1,   115,    92,
      63,    -1,   115,    41,    63,    -1,   115,    42,    -1,   115,
      43,    -1,   122,    -1,   116,    71,   122,    -1,   115,    -1,
      42,   117,    -1,    43,   117,    -1,    76,   118,    -1,    83,
     118,    -1,    81,   118,    -1,    82,   118,    -1,    86,   118,
      -1,    85,   118,    -1,   117,    -1,    90,   119,    91,   118,
      -1,    21,    -1,   118,    -1,   120,    83,   118,    -1,   120,
      84,   118,    -1,   120,    81,   118,    -1,   120,    82,   118,
      -1,   120,    44,   118,    -1,   120,    45,   118,    -1,   120,
      78,   118,    -1,   120,    77,   118,    -1,   120,    46,   118,
      -1,   120,    47,   118,    -1,   120,    48,   118,    -1,   120,
      49,   118,    -1,   120,    76,   118,    -1,   120,    75,   118,
      -1,   120,    93,   118,    -1,   120,    50,   118,    -1,   120,
      51,   118,    -1,   120,    -1,   120,    73,   123,    74,   121,
      -1,   121,    -1,   117,    72,   122,    -1,   117,    53,   122,
      -1,   117,    54,   122,    -1,   117,    55,   122,    -1,   117,
      56,   122,    -1,   117,    57,   122,    -1,   117,    58,   122,
      -1,   117,    59,   122,    -1,   117,    60,   122,    -1,   117,
      61,   122,    -1,   117,    62,   122,    -1,   122,    -1,   123,
      71,   122,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    77,    80,    81,    84,    90,    93,    97,
     101,   111,   120,   124,   131,   132,   133,   134,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     152,   153,   154,   157,   162,   170,   171,   174,   177,   178,
     179,   180,   183,   184,   187,   190,   191,   195,   199,   204,
     208,   214,   217,   220,   221,   222,   223,   226,   229,   230,
     231,   232,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   250,   251,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   265,   266,   269,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   292,   293,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   310,   311
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
  "':'", "'|'", "'&'", "'>'", "'<'", "'['", "']'", "'+'", "'-'", "'*'",
  "'/'", "'!'", "'~'", "';'", "'{'", "'}'", "'('", "')'", "'.'", "'^'",
  "$accept", "translation-unit", "external-declaration", "declaration",
  "declaration-specifiers", "storage-class-specifier", "type-specifier",
  "type-qualifier", "struct-or-union-specifier", "struct-declaration-list",
  "struct-declaration", "specifier-qualifier-list",
  "struct-declarator-list", "struct-declarator", "struct-or-union",
  "declarator", "function-definition", "block", "body", "statement",
  "primary-expression", "postfix-expression", "argument-expression-list",
  "unary-expression", "cast-expression", "type-name", "binary-expression",
  "conditional-expression", "assignment-expression", "expression", 0
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
     325,    44,    61,    63,    58,   124,    38,    62,    60,    91,
      93,    43,    45,    42,    47,    33,   126,    59,   123,   125,
      40,    41,    46,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    98,    99,    99,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   102,   102,   103,   103,   104,   105,   105,
     105,   105,   106,   106,   107,   108,   108,   109,   109,   109,
     109,   110,   111,   112,   112,   112,   112,   113,   114,   114,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     2,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     1,     2,     3,     1,     2,
       1,     2,     1,     3,     1,     1,     1,     1,     4,     3,
       2,     4,     3,     1,     2,     1,     2,     2,     1,     1,
       1,     3,     1,     3,     4,     3,     4,     3,     3,     2,
       2,     1,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     5,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    19,    30,    24,    14,    23,    21,    22,    17,
      31,    20,    25,    15,    45,    46,    26,    18,    32,    27,
      28,     0,     0,     2,     5,     0,     8,    10,    12,    29,
       0,     4,     0,     1,     3,    47,     0,     7,     0,     9,
      11,    13,    33,     0,    50,     0,     6,     0,     0,    51,
       0,    49,    38,    40,     0,    35,     0,     0,     0,    58,
      60,    59,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    53,    62,    73,    82,    85,   103,   105,   117,     0,
      48,    39,    41,    34,    36,     0,    42,    44,     0,    74,
      75,    82,    76,    78,    79,    77,    81,    80,    84,     0,
       0,    52,    56,    54,     0,    69,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    37,     0,    61,    68,     0,    63,    65,     0,
      71,    67,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   106,    90,    91,    94,    95,    96,    97,   101,
     102,     0,    99,    98,    93,    92,    88,    89,    86,    87,
     100,   118,    43,    83,    64,     0,    66,     0,    72,   104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    54,
      55,    56,    85,    86,    30,    87,    31,    49,    70,    71,
      72,    73,   149,    91,    75,    99,    76,    77,    78,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int16 yypact[] =
{
     334,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -75,   296,   -92,   -92,   -49,   462,   462,   462,   -92,
     -39,   -92,   -42,   -92,   -92,   -92,   -57,   -92,   -68,   -92,
     -92,   -92,   -30,   -14,   -92,   -29,   -92,   495,   158,   -92,
      -1,   -92,   495,   495,     9,   -92,   -57,   170,   170,   -92,
     -92,   -92,   382,   382,   382,   382,   382,   382,   216,   -92,
      78,   -92,   -92,   -38,   329,   -92,   330,   -92,   -92,   -69,
     -92,   -92,   -92,   -92,   -92,   -58,   -92,   -20,   382,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -11,
     -64,   -92,   -92,   -92,    20,   -92,   -92,    -5,   352,    24,
     382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
     -92,   -57,   -92,   382,   -92,   -92,     4,   -92,   -92,   -63,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -21,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   382,   -92,   382,   -92,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,    66,   -47,    50,   -92,    93,   103,   -92,   -92,
      35,     3,   -92,   -46,   -92,    21,   -92,   -92,   -92,    22,
     -92,   -92,   -92,   -48,   140,   -92,   -92,   -91,    14,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      74,    69,   139,   104,   105,   106,    35,   139,   185,    89,
      90,    45,   100,   141,    35,    32,     2,     3,   140,    46,
      74,     4,    74,   102,    42,     6,    36,   144,   186,   142,
       7,     8,   100,    10,    36,    11,    12,    50,    37,    14,
      74,   107,    15,    16,    17,    18,    38,    19,    20,    43,
     139,    51,   108,   187,   109,    81,    82,    44,    47,    45,
      74,   146,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,   171,    48,   147,    39,    40,    41,    80,
     143,    74,     1,   145,   184,     2,     3,   151,    34,    84,
       4,    74,   103,     5,     6,   182,   189,     0,    83,     7,
       8,     9,    10,     0,    11,    12,     0,    13,    14,     0,
       0,    15,    16,    17,    18,     0,    19,    20,     0,     0,
      57,    58,   150,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,    74,     0,     0,
      52,    59,     0,    60,    61,    52,    52,    52,     0,     0,
      53,     0,     0,   181,    62,    53,    53,    53,     0,    63,
      64,    65,     1,    66,    67,     2,     3,   101,    68,     0,
       4,     0,     0,     5,     6,     0,     0,     0,     0,     7,
       8,     9,    10,     0,    11,    12,     0,    13,    14,     0,
       0,    15,    16,    17,    18,     0,    19,    20,     0,   188,
      57,    58,    92,    93,    94,    95,    96,    97,     0,     0,
       0,     0,    57,    58,     0,     0,     0,     0,     0,     0,
       0,    59,     0,    60,    61,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    62,    60,    61,    98,     0,    63,
      64,    65,     0,    66,    67,     0,    62,     0,    68,     0,
       0,    63,    64,    65,     0,    66,    67,     0,    57,    58,
      88,   163,   164,   165,   166,   167,   168,   169,   170,     0,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    59,
       0,    60,    61,   183,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,    33,    63,    64,    65,
       1,    66,    67,     2,     3,     0,    68,     0,     4,     0,
       0,     5,     6,     0,     0,     0,     0,     7,     8,     9,
      10,     0,    11,    12,     0,    13,    14,     0,     0,    15,
      16,    17,    18,     0,    19,    20,     0,     0,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     0,     5,
       6,     0,     0,     0,     0,     7,     8,     9,    10,    21,
      11,    12,     0,    13,    14,     0,     0,    15,    16,    17,
      18,     0,    19,    20,   121,   122,   123,   124,   125,   126,
     127,   128,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     0,     0,    57,    58,     0,    21,     0,     0,
       0,   120,     0,   129,     0,   130,   131,   132,   133,     0,
       0,   134,   135,   136,   137,    59,     0,    60,    61,     0,
       0,     0,     0,   138,    57,    58,     0,     0,    62,     0,
       0,     0,     0,    63,    64,    65,     0,    66,    67,     0,
       0,     0,    68,   148,     0,    59,     0,    60,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,     0,    63,    64,    65,     1,    66,    67,     2,
       3,     0,    68,     0,     4,     0,     0,     5,     6,     0,
       0,     0,     0,     7,     8,     9,    10,     0,    11,    12,
       0,    13,    14,     0,     0,    15,    16,    17,    18,     0,
      19,    20,     2,     3,     0,     0,     0,     4,     0,     0,
       0,     6,     0,     0,     0,     0,     7,     8,     0,    10,
       0,    11,    12,     0,     0,    14,     0,     0,    15,    16,
      17,    18,     0,    19,    20
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-92))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      48,    48,    71,    41,    42,    43,    63,    71,    71,    57,
      58,    79,    68,    71,    63,    90,     7,     8,    87,    87,
      68,    12,    70,    70,    63,    16,    83,    91,    91,    87,
      21,    22,    88,    24,    83,    26,    27,    66,    87,    30,
      88,    79,    33,    34,    35,    36,    25,    38,    39,    91,
      71,    80,    90,    74,    92,    52,    53,    36,    88,    79,
     108,    66,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   129,    88,    80,    26,    27,    28,    80,
      91,   129,     4,    63,    80,     7,     8,    63,    22,    54,
      12,   139,    70,    15,    16,   141,   187,    -1,    89,    21,
      22,    23,    24,    -1,    26,    27,    -1,    29,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      42,    43,   108,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,   185,    -1,    -1,
      47,    63,    -1,    65,    66,    52,    53,    54,    -1,    -1,
      47,    -1,    -1,   139,    76,    52,    53,    54,    -1,    81,
      82,    83,     4,    85,    86,     7,     8,    89,    90,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    -1,    26,    27,    -1,    29,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    38,    39,    -1,   185,
      42,    43,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    76,    65,    66,    21,    -1,    81,
      82,    83,    -1,    85,    86,    -1,    76,    -1,    90,    -1,
      -1,    81,    82,    83,    -1,    85,    86,    -1,    42,    43,
      90,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    63,
      -1,    65,    66,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,     0,    81,    82,    83,
       4,    85,    86,     7,     8,    -1,    90,    -1,    12,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    -1,    26,    27,    -1,    29,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,     4,    -1,
      -1,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    63,
      26,    27,    -1,    29,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    38,    39,    44,    45,    46,    47,    48,    49,
      50,    51,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    42,    43,    -1,    63,    -1,    -1,
      -1,    72,    -1,    73,    -1,    75,    76,    77,    78,    -1,
      -1,    81,    82,    83,    84,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    93,    42,    43,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    85,    86,    -1,
      -1,    -1,    90,    91,    -1,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    83,     4,    85,    86,     7,
       8,    -1,    90,    -1,    12,    -1,    -1,    15,    16,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    -1,    26,    27,
      -1,    29,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      38,    39,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     7,     8,    12,    15,    16,    21,    22,    23,
      24,    26,    27,    29,    30,    33,    34,    35,    36,    38,
      39,    63,    95,    96,    97,    98,    99,   100,   101,   102,
     108,   110,    90,     0,    96,    63,    83,    87,   109,    98,
      98,    98,    63,    91,   109,    79,    87,    88,    88,   111,
      66,    80,   100,   101,   103,   104,   105,    42,    43,    63,
      65,    66,    76,    81,    82,    83,    85,    86,    90,    97,
     112,   113,   114,   115,   117,   118,   120,   121,   122,   123,
      80,   105,   105,    89,   104,   106,   107,   109,    90,   117,
     117,   117,   118,   118,   118,   118,   118,   118,    21,   119,
     123,    89,    97,   113,    41,    42,    43,    79,    90,    92,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      72,    44,    45,    46,    47,    48,    49,    50,    51,    73,
      75,    76,    77,    78,    81,    82,    83,    84,    93,    71,
      87,    71,    87,    91,    91,    63,    66,    80,    91,   116,
     122,    63,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   118,   118,   118,   118,   118,   118,   118,
     118,   123,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   122,   107,   118,    80,    71,    91,    74,   122,   121
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
        case 4:

/* Line 1806 of yacc.c  */
#line 80 "hw3.y"
    {fprintf(stdout, "function defined\n");}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 81 "hw3.y"
    {fprintf(stdout, "declaration on line %d\n", line);}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 84 "hw3.y"
    {
										(yyval) = (yyvsp[(1) - (3)]);
										(yyval).ast->c1 = (yyvsp[(2) - (3)]).ast;
										INSTALL(curr_table, current_ident, (yyval)); 
										print_tree_invert((yyval).ast,0);
									}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 93 "hw3.y"
    {
										(yyval).ast = new_node(SCALAR_NODE);
										(yyval).ast->spec_bits = TYPESPEC;
									}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 97 "hw3.y"
    {
										(yyval).ast = (yyvsp[(2) - (2)]).ast; 
									  	(yyval).ast->spec_bits = TYPESPEC | (yyval).ast->spec_bits;
									}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 101 "hw3.y"
    {
										if (TYPESPEC == IS_STRUCT)
											{(yyval) = (yyvsp[(1) - (1)]);}
										else
										{
											(yyval).ast = new_node(SCALAR_NODE);
											(yyval).ast->spec_bits = TYPESPEC;
										} 
										
									}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 111 "hw3.y"
    {
										if ((yyvsp[(1) - (2)]).ast->node_type == STRUCT_NODE) 
											{(yyval)=(yyvsp[(1) - (2)]);} // throw away everything else
									   	else
										{
											(yyval).ast = (yyvsp[(2) - (2)]).ast; 
									  		(yyval).ast->spec_bits = TYPESPEC | (yyval).ast->spec_bits;
										}
									}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 120 "hw3.y"
    {
										(yyval).ast = new_node(SCALAR_NODE);
										(yyval).ast->spec_bits = TYPESPEC;
									}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 124 "hw3.y"
    {
										(yyval).ast = (yyvsp[(2) - (2)]).ast; 
									  	(yyval).ast->spec_bits = TYPESPEC | (yyval).ast->spec_bits;
									}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 131 "hw3.y"
    {TYPESPEC = IS_EXTERN;}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 132 "hw3.y"
    {TYPESPEC = IS_STATIC;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 133 "hw3.y"
    {TYPESPEC = IS_AUTO;}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 134 "hw3.y"
    {TYPESPEC = IS_REGISTER;}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 138 "hw3.y"
    {TYPESPEC = IS_VOID;}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 139 "hw3.y"
    {TYPESPEC = IS_CHAR;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 140 "hw3.y"
    {TYPESPEC = IS_SHORT;}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 141 "hw3.y"
    {TYPESPEC = IS_INT;}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 142 "hw3.y"
    {TYPESPEC = IS_LONG;}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 143 "hw3.y"
    {TYPESPEC = IS_FLOAT;}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 144 "hw3.y"
    {TYPESPEC = IS_DOUBLE;}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 145 "hw3.y"
    {TYPESPEC = IS_SIGNED;}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 146 "hw3.y"
    {TYPESPEC = 0;}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 147 "hw3.y"
    {TYPESPEC = 0;}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 148 "hw3.y"
    {TYPESPEC = 0;}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 149 "hw3.y"
    {(yyval)=(yyvsp[(1) - (1)]); (yyval).ast->spec_bits = 0; TYPESPEC = IS_STRUCT;}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 152 "hw3.y"
    {TYPESPEC = IS_CONST;}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 153 "hw3.y"
    {TYPESPEC = IS_RESTRICT;}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 154 "hw3.y"
    {TYPESPEC = IS_RESTRICT;}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 157 "hw3.y"
    {
									//$$.ast = new_ident_node($2.ident_val, STRUCT_NODE);
									(yyval) = (yyvsp[(1) - (2)]);
									strncpy((yyval).ast->name, (yyvsp[(2) - (2)]).ident_val, 255);
								}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 162 "hw3.y"
    {  
									//INSTALL(curr_table, $2);
									//printf("installed %s\n", $2.ident_val);
									(yyval).ast = new_ident_node((yyvsp[(2) - (5)]).ident_val, STRUCT_NODE);
									strncpy((yyval).ast->name, (yyvsp[(2) - (5)]).ident_val, 255);
								}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 177 "hw3.y"
    {(yyval).ast = new_node(SCALAR_NODE); (yyval).ast->spec_bits = TYPESPEC;}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 187 "hw3.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 190 "hw3.y"
    {(yyval).ast = new_node(STRUCT_NODE);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 191 "hw3.y"
    {(yyval).ast = new_node(UNION_NODE);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 195 "hw3.y"
    {
								(yyval).ast = new_ident_node((yyvsp[(1) - (1)]).ident_val, VAR_NODE);
								current_ident = (yyvsp[(1) - (1)]).ident_val;
							}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 199 "hw3.y"
    {
								(yyval).ast = new_node(ARRAY_NODE); 
								(yyval).ast->size = (yyvsp[(3) - (4)]).int_val;
								(yyval).ast->c1 = (yyvsp[(1) - (4)]).ast;
							}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 204 "hw3.y"
    {
						  		(yyval).ast = new_node(PTR_NODE);
						  		(yyval).ast->c1 = (yyvsp[(1) - (3)]).ast;
							}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 208 "hw3.y"
    {
						  		(yyval).ast = new_node(PTR_NODE);
						  		(yyval).ast->c1 = (yyvsp[(2) - (2)]).ast;
						}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 214 "hw3.y"
    {(yyval).ast = new_ident_node((yyvsp[(1) - (4)]).ident_val, FN_NODE);}
    break;



/* Line 1806 of yacc.c  */
#line 2040 "hw3.tab.c"
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
#line 315 "hw3.y"

/* Function definitions go here */
int main()
{
	init_table(&t, 512, NULL);
	curr_table = &t; // initialize scope to global scope
	strcpy(curr_file, "stdin");
	yyparse();
	return 0;
}

void yyerror (char const *s)
{
	fprintf(stderr, "%s\n", s);
}

// HW 3
SCALAR extract_value(YYSTYPE val)
{
	char *int_type = "INT";
	char *long_type = "LONG";
	char *longlong_type = "LONGLONG";
	char *float_type = "FLOAT";
	char *double_type = "DOUBLE";
	char *longdouble_type = "LONGDOUBLE";
	SCALAR s;
	char *num_type = val.metadata.num_type;
	node_type = SCALAR_NODE;
	if (strcmp(num_type, int_type) || strcmp(num_type, long_type) || strcmp(num_type, longlong_type))
	{
		s.int_val = (long long) val.int_val;
	}
	else if (strcmp(num_type, float_type))
	{
		s.ld_val = (long double) val.float_val;
	}
	else if (strcmp(num_type, double_type) || strcmp(num_type, longdouble_type))
	{
		s.ld_val = (long double) val.double_val;
	}
	else
	{
		fprintf(stderr, "No valid number found!\n");
	}
	
	return s;
}


// HW 2
void PRINTEXP(YYSTYPE v)
{
	printf("%s:%d: ", curr_file, line); 
	printf("exprval=%lld\n", v.int_val);
}


// add a new identifier to the current symbol table
void INSTALL(SYMTABLE *t, char *name, YYSTYPE val)
{
	if (in_table(t, name))
	{
		fprintf(stderr, "%s:%d: ", curr_file, line); 
    	fprintf(stderr, "Error: redeclaration of %s\n", name);
		return;
    }
	val.has_val = 0;
   	ins_table(t, name, val); // junk value 
}

// special for struct members
void ADD_MEMBER(SYMTABLE *t, char *name, YYSTYPE member)
{
	if (!t)
	{
		init_table(t, 8, NULL);
	}
	INSTALL(t, name, member);
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
	// v1 is not actually a value, it is the YYSTYPE of an ident!
	TABLECELL *tc;
    YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
    if (!(tc = in_table(curr_table, v1.ident_val)))
    {
		fprintf(stderr, "%s:%d: ", curr_file, line); 
        fprintf(stderr, "Error: identifier %s undeclared\n", v1.ident_val);
        res->int_val = v2.int_val;
		res->has_val = 0;
		return *res;
    }

	*res = tc->value;
	res->metadata.tokname = "NUMBER";
	res->has_val = 1;
    
	if (!CHECK(*res))
    {
		res->int_val = v2.int_val;
		res->has_val = 0;
        return *res;
    }
	switch (op)
	{
		case PLUSEQ:
			printf("v1: %lld v2: %lld\n", res->int_val, v2.int_val); 
			res->int_val = res->int_val + v2.int_val; break; 
		case MINUSEQ:
			res->int_val = res->int_val - v2.int_val; break; 
		case TIMESEQ:
			res->int_val = res->int_val * v2.int_val; break; 
		case DIVEQ:
			res->int_val = res->int_val / v2.int_val; break; 
		case MODEQ:
			res->int_val = res->int_val % v2.int_val; break; 
		case SHLEQ:
			res->int_val = res->int_val << v2.int_val; break; 
		case SHREQ:
			res->int_val = res->int_val << v2.int_val; break; 
		case ANDEQ:
			res->int_val = res->int_val & v2.int_val; break; 
		case OREQ:
			res->int_val = res->int_val | v2.int_val; break; 
		case XOREQ:
			res->int_val = res->int_val ^ v2.int_val; break; 
	}
	
	UPDATE(curr_table, v1.ident_val, *res);
	return *res;
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


