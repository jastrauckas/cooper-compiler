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
#line 4 "parser.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include "lexer.h"
	#include "symTable.h"
	#include "symTable.c"
	#include "ast.c"
	#include "ast.h"
	#include "quad.c"
	#include "quad.h"
	
	#define YYDEBUG 1
	#define MAXLEN 512
	
	enum {GLOBAL_SCOPE, FN_SCOPE, BLOCK_SCOPE};

	SYMTABLE t;
	SYMTABLE st;
	SYMTABLE *fn_args;
	SYMTABLE *saved_table;
	SYMTABLE *new_members = NULL; // use this to create symtable for struct members
	TABLECELL *tc; // store stuff here
	TABLECELL *current_table_entry;
	SYMTABLE *curr_table; // points to the current scope's symbol table
	SYMTABLE *global_table;
	SYMTABLE *struct_table; // points to the struct scope's symbol table
	SYMTABLE *curr_member_table; // points to the struct scope's symbol table
	char curr_file[MAXLEN+1];
	char *current_ident;
	int curr_scope = GLOBAL_SCOPE;
	int stat;
	int ts;
	int node_type;
	int dec_start_line;
	int TYPESPEC;
	int temp_id;
	extern int block_id;
	BLOCKLIST *global_block_list;
	BLOCKLIST *current_block_list;
	BASICBLOCK *current_block;
	TABLECELL *fn_entry;
	// saved block should probably be a stack, not a single block
	BLOCKLIST *saved_blocks; // for blocks we need to return to, like loop condition stuff

	/* functions that will be defined */
	TNODE *extract_value(YYSTYPE val);
	void INSTALL(SYMTABLE *t, char *name, YYSTYPE val);
	int UPDATE(SYMTABLE *t, char *key, YYSTYPE val);
	YYSTYPE FIXNUM(YYSTYPE v);
	YYSTYPE RETRIEVE(SYMTABLE *t, char *key);
	YYSTYPE UNARY(YYSTYPE v, int op);
	YYSTYPE BINARY(YYSTYPE v1, YYSTYPE v2, int op);
	YYSTYPE OPASSIGN(YYSTYPE v1, YYSTYPE v2, int op);
	YYSTYPE TERNARY(YYSTYPE v1, YYSTYPE v2, YYSTYPE v3);
	SYMTABLE *SPOP(SYMTABLE *t);
	SYMTABLE *SPUSH(SYMTABLE *t);
	void PRINTEXP(YYSTYPE v);


/* Line 268 of yacc.c  */
#line 133 "parser.tab.c"

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
#line 245 "parser.tab.c"

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
#define YYFINAL  90
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   740

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNRULES -- Number of states.  */
#define YYNSTATES  254

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
       2,     2,     2,    85,     2,     2,     2,    93,    76,     2,
      90,    91,    83,    81,    71,    82,    92,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,    87,
      78,    72,    77,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,    94,     2,     2,     2,     2,     2,
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
       0,     0,     3,     5,     8,    10,    12,    14,    15,    20,
      23,    25,    28,    30,    33,    35,    38,    40,    42,    44,
      46,    48,    50,    52,    54,    56,    58,    60,    62,    64,
      66,    68,    70,    72,    74,    76,    79,    80,    87,    89,
      92,    96,    98,   101,   103,   106,   108,   112,   114,   116,
     118,   120,   125,   129,   132,   133,   141,   142,   149,   151,
     155,   158,   159,   164,   166,   169,   171,   174,   176,   178,
     180,   182,   184,   187,   188,   195,   196,   200,   202,   205,
     206,   213,   220,   228,   236,   238,   240,   242,   246,   248,
     252,   257,   261,   266,   270,   274,   277,   280,   282,   286,
     288,   291,   294,   297,   300,   303,   306,   309,   312,   314,
     319,   321,   323,   327,   331,   335,   337,   341,   345,   347,
     351,   355,   357,   361,   365,   369,   373,   375,   379,   383,
     385,   389,   391,   395,   397,   401,   403,   407,   409,   413,
     415,   421,   423,   427,   431,   435,   439,   443,   447,   451,
     455,   459,   463,   467,   469
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      96,     0,    -1,    97,    -1,    96,    97,    -1,   113,    -1,
      98,    -1,   121,    -1,    -1,   100,   112,    99,    87,    -1,
     100,    87,    -1,   101,    -1,   101,   100,    -1,   102,    -1,
     102,   100,    -1,   103,    -1,   103,   100,    -1,    15,    -1,
      29,    -1,     4,    -1,    23,    -1,    35,    -1,     7,    -1,
      26,    -1,    21,    -1,    22,    -1,    16,    -1,    12,    -1,
      27,    -1,    34,    -1,    38,    -1,    39,    -1,   104,    -1,
       8,    -1,    24,    -1,    36,    -1,   111,    63,    -1,    -1,
     111,    63,   105,    88,   106,    89,    -1,   107,    -1,   106,
     107,    -1,   108,   109,    87,    -1,   102,    -1,   102,   108,
      -1,   103,    -1,   103,   108,    -1,   110,    -1,   109,    71,
     110,    -1,   112,    -1,    30,    -1,    33,    -1,    63,    -1,
     112,    79,    66,    80,    -1,   112,    79,    80,    -1,    83,
     112,    -1,    -1,   100,   112,    90,   116,    91,   114,   118,
      -1,    -1,   100,   112,    90,    91,   115,   118,    -1,   117,
      -1,   116,    71,   117,    -1,   100,   112,    -1,    -1,    88,
     119,   120,    89,    -1,   121,    -1,   120,   121,    -1,    98,
      -1,   120,    98,    -1,   122,    -1,   118,    -1,   127,    -1,
     128,    -1,    87,    -1,   148,    87,    -1,    -1,    19,    90,
     148,    91,   124,   121,    -1,    -1,    13,   126,   121,    -1,
     123,    -1,   123,   125,    -1,    -1,    37,    90,   148,    91,
     129,   121,    -1,    17,    90,   122,   122,    91,   121,    -1,
      17,    90,   122,   122,   148,    91,   121,    -1,    11,   121,
      37,    90,   148,    91,    87,    -1,    63,    -1,    66,    -1,
      65,    -1,    90,   148,    91,    -1,   130,    -1,   131,    79,
      80,    -1,   131,    79,    66,    80,    -1,   131,    90,    91,
      -1,   131,    90,   132,    91,    -1,   131,    92,    63,    -1,
     131,    41,    63,    -1,   131,    42,    -1,   131,    43,    -1,
     147,    -1,   132,    71,   147,    -1,   131,    -1,    42,   133,
      -1,    43,   133,    -1,    76,   134,    -1,    83,   134,    -1,
      81,   134,    -1,    82,   134,    -1,    86,   134,    -1,    85,
     134,    -1,   133,    -1,    90,   135,    91,   134,    -1,    21,
      -1,   134,    -1,   136,    83,   134,    -1,   136,    84,   134,
      -1,   136,    93,   134,    -1,   136,    -1,   137,    81,   136,
      -1,   137,    82,   136,    -1,   137,    -1,   138,    44,   137,
      -1,   138,    45,   137,    -1,   138,    -1,   139,    78,   138,
      -1,   139,    77,   138,    -1,   139,    46,   138,    -1,   139,
      47,   138,    -1,   139,    -1,   140,    48,   139,    -1,   140,
      49,   139,    -1,   140,    -1,   141,    76,   140,    -1,   141,
      -1,   142,    94,   141,    -1,   142,    -1,   143,    75,   142,
      -1,   143,    -1,   144,    50,   143,    -1,   144,    -1,   145,
      51,   144,    -1,   145,    -1,   145,    73,   148,    74,   146,
      -1,   146,    -1,   133,    72,   147,    -1,   133,    53,   147,
      -1,   133,    54,   147,    -1,   133,    55,   147,    -1,   133,
      56,   147,    -1,   133,    57,   147,    -1,   133,    58,   147,
      -1,   133,    59,   147,    -1,   133,    60,   147,    -1,   133,
      61,   147,    -1,   133,    62,   147,    -1,   147,    -1,   148,
      71,   147,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   101,   104,   108,   109,   116,   116,   126,
     129,   133,   137,   147,   156,   160,   167,   168,   169,   170,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   188,   189,   190,   193,   197,   197,   211,   212,
     215,   225,   226,   227,   228,   231,   232,   235,   238,   239,
     243,   248,   253,   257,   263,   263,   291,   291,   317,   325,
     331,   338,   338,   354,   355,   356,   357,   360,   364,   365,
     366,   369,   370,   373,   373,   389,   389,   397,   398,   401,
     401,   416,   417,   418,   421,   425,   429,   430,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   448,   449,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   463,   464,
     467,   470,   471,   472,   473,   476,   477,   478,   482,   483,
     484,   487,   488,   489,   490,   491,   494,   495,   496,   499,
     500,   503,   504,   507,   508,   511,   512,   515,   516,   519,
     520,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   537,   538
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
  "'/'", "'!'", "'~'", "';'", "'{'", "'}'", "'('", "')'", "'.'", "'%'",
  "'^'", "$accept", "translation-unit", "external-declaration",
  "declaration", "$@1", "declaration-specifiers",
  "storage-class-specifier", "type-specifier", "type-qualifier",
  "struct-or-union-specifier", "@2", "struct-declaration-list",
  "struct-declaration", "specifier-qualifier-list",
  "struct-declarator-list", "struct-declarator", "struct-or-union",
  "declarator", "function-definition", "@3", "@4", "declaration-list",
  "function-argument", "compound-statement", "$@5", "body", "statement",
  "expression-statement", "if-clause", "$@6", "else-clause", "$@7",
  "selection-statement", "iteration-statement", "$@8",
  "primary-expression", "postfix-expression", "argument-expression-list",
  "unary-expression", "cast-expression", "type-name",
  "multiplicative-expression", "additive-expression", "shift-expression",
  "relational-expression", "equality-expression", "and-expression",
  "xor-expression", "or-expression", "logand-expression",
  "logor-expression", "conditional-expression", "assignment-expression",
  "expression", 0
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
      40,    41,    46,    37,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    96,    97,    97,    97,    99,    98,    98,
     100,   100,   100,   100,   100,   100,   101,   101,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   103,   104,   105,   104,   106,   106,
     107,   108,   108,   108,   108,   109,   109,   110,   111,   111,
     112,   112,   112,   112,   114,   113,   115,   113,   116,   116,
     117,   119,   118,   120,   120,   120,   120,   121,   121,   121,
     121,   122,   122,   124,   123,   126,   125,   127,   127,   129,
     128,   128,   128,   128,   130,   130,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   132,   132,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   134,   134,
     135,   136,   136,   136,   136,   137,   137,   137,   138,   138,
     138,   139,   139,   139,   139,   139,   140,   140,   140,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   145,   146,
     146,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   148,   148
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     4,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     6,     1,     2,
       3,     1,     2,     1,     2,     1,     3,     1,     1,     1,
       1,     4,     3,     2,     0,     7,     0,     6,     1,     3,
       2,     0,     4,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     2,     0,     6,     0,     3,     1,     2,     0,
       6,     6,     7,     7,     1,     1,     1,     3,     1,     3,
       4,     3,     4,     3,     3,     2,     2,     1,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     4,
       1,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    21,    32,     0,    26,    16,    25,     0,     0,
      23,    24,    19,    33,    22,    27,    17,    48,    49,    28,
      20,    34,     0,    29,    30,     0,     0,    84,    86,    85,
       0,     0,     0,     0,     0,     0,    71,    61,     0,     0,
       2,     5,     0,    10,    12,    14,    31,     0,     4,    68,
       6,    67,    77,    69,    70,    88,    99,   108,   111,   115,
     118,   121,   126,   129,   131,   133,   135,   137,   139,   141,
     153,     0,     0,     0,     0,     0,     0,   100,   101,   108,
     102,   104,   105,   103,   107,   106,     0,   110,     0,     0,
       1,     3,    50,     0,     9,     7,    11,    13,    15,    35,
      75,    78,     0,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,     0,     0,     0,    65,     0,     0,    63,     0,    87,
      53,     0,     0,     0,     0,     0,    94,     0,    89,    91,
       0,    97,    93,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   142,   112,   113,   114,   116,   117,   119,
     120,   124,   125,   123,   122,   127,   128,   130,   132,   134,
     136,   138,     0,   154,     0,     0,    73,    79,     7,    62,
      66,    64,   109,     0,    52,    56,     0,     0,    58,     8,
       0,    76,    90,     0,    92,     0,     0,     0,     0,     0,
       0,    51,     0,    60,     0,    54,    41,    43,     0,    38,
       0,    98,   140,     0,    81,     0,    74,    80,    57,    59,
       0,    42,    44,    37,    39,     0,    45,    47,    83,    82,
      55,     0,    40,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    39,    40,    41,   153,    42,    43,    44,    45,    46,
     154,   228,   229,   230,   245,   246,    47,   247,    48,   240,
     222,   207,   208,    49,    86,   146,    50,    51,    52,   219,
     101,   155,    53,    54,   220,    55,    56,   160,    57,    58,
      88,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -189
static const yytype_int16 yypact[] =
{
     422,  -189,  -189,  -189,   452,  -189,  -189,  -189,   -45,   -43,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,   -39,  -189,  -189,   562,   562,  -189,  -189,  -189,
     588,   588,   588,   588,   588,   588,  -189,  -189,   120,   217,
    -189,  -189,   -41,   668,   668,   668,  -189,   -58,  -189,  -189,
    -189,  -189,   100,  -189,  -189,  -189,   -25,   112,  -189,    39,
       3,    72,    -3,    87,    57,    43,    78,    95,    -1,  -189,
    -189,   -52,   110,   536,   588,   588,   588,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,   422,  -189,    59,   -23,
    -189,  -189,  -189,   -14,  -189,    41,  -189,  -189,  -189,    71,
    -189,  -189,   115,  -189,  -189,    10,   478,   129,   588,   588,
     588,   588,   588,   588,   588,   588,   588,   588,   588,   588,
     588,   588,   588,   588,   588,   588,   588,   588,   588,   588,
     588,   588,   588,   588,   588,   588,   588,   588,   588,  -189,
      85,   536,   -12,   -11,  -189,   -41,   335,  -189,   588,  -189,
    -189,    11,   302,   117,   119,   452,  -189,   128,  -189,  -189,
     -10,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,    39,    39,     3,
       3,    72,    72,    72,    72,    -3,    -3,    87,    57,    43,
      78,    95,    18,  -189,   588,   507,  -189,  -189,   130,  -189,
    -189,  -189,  -189,   132,  -189,  -189,   -14,    -8,  -189,  -189,
     701,  -189,  -189,   588,  -189,   588,     2,   452,    23,   452,
     452,  -189,   126,   130,   668,  -189,   701,   701,   122,  -189,
     -14,  -189,  -189,   131,  -189,   452,  -189,  -189,  -189,  -189,
     126,  -189,  -189,  -189,  -189,    -9,  -189,   130,  -189,  -189,
    -189,   -14,  -189,  -189
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,   180,   -82,  -189,   -31,  -189,  -140,   -46,  -189,
    -189,  -189,    -6,   -87,  -189,   -28,  -189,   -27,  -189,  -189,
    -189,  -189,    13,  -188,  -189,  -189,    -4,   -70,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,   -24,     6,
    -189,    75,    70,    61,    69,    88,    93,    96,    92,    99,
    -189,    27,   -85,   -18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int16 yytable[] =
{
      72,    77,    78,   141,   144,    99,    79,    79,    79,    79,
      79,    79,    96,    97,    98,    95,   102,   103,   104,   138,
      89,   161,    92,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   238,   139,    80,    81,    82,    83,
      84,    85,    93,   126,   127,    73,    94,    74,   138,    92,
     136,    75,   250,   193,   105,   145,   142,   143,    89,   138,
     138,   213,   251,   224,   200,   106,   150,   107,   149,    93,
     226,   195,   137,   138,   128,   129,   157,   203,   252,   196,
     197,   214,   147,   225,   122,   123,   226,   226,   226,   138,
     158,   204,   215,   233,   138,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,   100,   235,   145,   124,   125,   198,   192,
     151,   206,   119,   120,    79,   174,   175,   176,   231,     2,
       3,   152,   121,   132,     5,   130,   131,   133,     7,   241,
     242,    87,   201,    10,    11,   135,    13,   140,    14,    15,
     148,   211,    17,   134,   202,    18,    19,    20,    21,   -36,
      23,    24,    25,    26,   227,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   194,   216,   218,   156,   223,
     227,   227,   227,    27,   118,    28,    29,   181,   182,   183,
     184,    79,   162,   206,   179,   180,    30,   177,   178,   185,
     186,    31,    32,    33,   209,    34,    35,   210,   212,   151,
      38,   243,   221,   234,    37,   236,   237,    90,   248,    91,
     187,     1,   244,   253,     2,     3,   188,   190,     4,     5,
     189,   249,     6,     7,     8,   191,     9,   239,    10,    11,
      12,    13,   232,    14,    15,     0,    16,    17,     0,     0,
      18,    19,    20,    21,    22,    23,    24,     0,     0,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,     0,    31,    32,
      33,     0,    34,    35,    36,    37,     1,    38,     0,     2,
       3,     0,     0,     0,     5,     0,     0,     6,     7,     0,
       0,     0,     0,    10,    11,    12,    13,     0,    14,    15,
       0,    16,    17,     0,     0,    18,    19,    20,    21,     1,
      23,    24,     2,     3,     0,     0,     4,     5,     0,     0,
       6,     7,     8,     0,     9,     0,    10,    11,    12,    13,
       0,    14,    15,     0,    16,    17,     0,     0,    18,    19,
      20,    21,    22,    23,    24,     0,     0,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,    27,     0,
      28,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,    31,    32,    33,     0,
      34,    35,    36,    37,   199,    38,     1,     0,     0,     2,
       3,     0,     0,     4,     5,     0,     0,     6,     7,     8,
       0,     9,     0,    10,    11,    12,    13,     0,    14,    15,
       0,    16,    17,     0,     0,    18,    19,    20,    21,    22,
      23,    24,     0,     4,    25,    26,     0,     0,     0,     8,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    28,    29,    22,
       0,     0,     0,     0,    25,    26,     0,     0,    30,     0,
       0,     0,     0,    31,    32,    33,     0,    34,    35,    36,
      37,     0,    38,     0,     0,    27,     0,    28,    29,     0,
      25,    26,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,    31,    32,    33,     0,    34,    35,    36,
      37,    27,    38,    28,    29,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    30,     0,     0,     0,     0,    31,
      32,    33,     0,    34,    35,     0,     0,     0,    38,   159,
      27,     0,    28,    29,     0,     0,     0,     0,    25,    26,
       0,     0,     0,    30,     0,     0,     0,     0,    31,    32,
      33,     0,    34,    35,     0,     0,     0,    38,   217,    27,
       0,    28,    29,     0,    25,    26,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,    31,    32,    33,
       0,    34,    35,    36,     0,    27,    38,    28,    29,     0,
      25,    26,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,    31,    32,    33,     0,    34,    35,     0,
       0,    27,    76,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,    31,
      32,    33,     1,    34,    35,     2,     3,     0,    38,     0,
       5,     0,     0,     6,     7,     0,     0,     0,     0,    10,
      11,    12,    13,     0,    14,    15,     0,    16,    17,     0,
       0,    18,    19,    20,    21,     0,    23,    24,     2,     3,
       0,     0,     0,     5,     0,     0,     0,     7,     0,     0,
       0,     0,    10,    11,     0,    13,     0,    14,    15,     0,
       0,    17,     0,     0,    18,    19,    20,    21,     0,    23,
      24
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-189))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       4,    25,    26,    73,    86,    63,    30,    31,    32,    33,
      34,    35,    43,    44,    45,    42,    41,    42,    43,    71,
      38,   106,    63,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   222,    87,    30,    31,    32,    33,
      34,    35,    83,    46,    47,    90,    87,    90,    71,    63,
      51,    90,   240,   138,    79,    86,    74,    75,    76,    71,
      71,    71,    71,    71,   146,    90,    93,    92,    91,    83,
     210,   141,    73,    71,    77,    78,    66,    66,    87,    91,
      91,    91,    86,    91,    81,    82,   226,   227,   228,    71,
      80,    80,    74,    91,    71,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,    13,    91,   146,    44,    45,   145,   137,
      79,   152,    83,    84,   148,   119,   120,   121,   213,     7,
       8,    90,    93,    76,    12,    48,    49,    94,    16,   226,
     227,    21,   146,    21,    22,    50,    24,    37,    26,    27,
      91,   155,    30,    75,   148,    33,    34,    35,    36,    88,
      38,    39,    42,    43,   210,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    90,   194,   195,    63,   206,
     226,   227,   228,    63,    72,    65,    66,   126,   127,   128,
     129,   215,    63,   224,   124,   125,    76,   122,   123,   130,
     131,    81,    82,    83,    87,    85,    86,    88,    80,    79,
      90,    89,    80,   217,    88,   219,   220,     0,    87,    39,
     132,     4,   228,   251,     7,     8,   133,   135,    11,    12,
     134,   235,    15,    16,    17,   136,    19,   224,    21,    22,
      23,    24,   215,    26,    27,    -1,    29,    30,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    85,    86,    87,    88,     4,    90,    -1,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    -1,    26,    27,
      -1,    29,    30,    -1,    -1,    33,    34,    35,    36,     4,
      38,    39,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      15,    16,    17,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    26,    27,    -1,    29,    30,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      85,    86,    87,    88,    89,    90,     4,    -1,    -1,     7,
       8,    -1,    -1,    11,    12,    -1,    -1,    15,    16,    17,
      -1,    19,    -1,    21,    22,    23,    24,    -1,    26,    27,
      -1,    29,    30,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    11,    42,    43,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    66,    37,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    85,    86,    87,
      88,    -1,    90,    -1,    -1,    63,    -1,    65,    66,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    85,    86,    87,
      88,    63,    90,    65,    66,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    83,    -1,    85,    86,    -1,    -1,    -1,    90,    91,
      63,    -1,    65,    66,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    85,    86,    -1,    -1,    -1,    90,    91,    63,
      -1,    65,    66,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    83,
      -1,    85,    86,    87,    -1,    63,    90,    65,    66,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    85,    86,    -1,
      -1,    63,    90,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    83,     4,    85,    86,     7,     8,    -1,    90,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    -1,    26,    27,    -1,    29,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    38,    39,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,    38,
      39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     7,     8,    11,    12,    15,    16,    17,    19,
      21,    22,    23,    24,    26,    27,    29,    30,    33,    34,
      35,    36,    37,    38,    39,    42,    43,    63,    65,    66,
      76,    81,    82,    83,    85,    86,    87,    88,    90,    96,
      97,    98,   100,   101,   102,   103,   104,   111,   113,   118,
     121,   122,   123,   127,   128,   130,   131,   133,   134,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   121,    90,    90,    90,    90,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   119,    21,   135,   148,
       0,    97,    63,    83,    87,   112,   100,   100,   100,    63,
      13,   125,    41,    42,    43,    79,    90,    92,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    72,    83,
      84,    93,    81,    82,    44,    45,    46,    47,    77,    78,
      48,    49,    76,    94,    75,    50,    51,    73,    71,    87,
      37,   122,   148,   148,    98,   100,   120,   121,    91,    91,
     112,    79,    90,    99,   105,   126,    63,    66,    80,    91,
     132,   147,    63,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   134,   134,   134,   136,   136,   137,
     137,   138,   138,   138,   138,   139,   139,   140,   141,   142,
     143,   144,   148,   147,    90,   122,    91,    91,   112,    89,
      98,   121,   134,    66,    80,    91,   100,   116,   117,    87,
      88,   121,    80,    71,    91,    74,   148,    91,   148,   124,
     129,    80,   115,   112,    71,    91,   102,   103,   106,   107,
     108,   147,   146,    91,   121,    91,   121,   121,   118,   117,
     114,   108,   108,    89,   107,   109,   110,   112,    87,   121,
     118,    71,    87,   110
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
#line 104 "parser.y"
    {
										//fprintf(stdout, "function defined at <%s> %d\n", curr_file, line);
										//print_tree_invert($$.ast,0);
									}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 109 "parser.y"
    {
										(yyval) = (yyvsp[(1) - (1)]);
										//push_list_node(global_asts, $$.ast);
										//print_tree_invert($$.ast, 0);
									}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 116 "parser.y"
    {
										TYPESPEC = 0;
										//fprintf(stdout, "declaration at <%s> line %d\n", curr_file, line);
									}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 120 "parser.y"
    {
										(yyval) = (yyvsp[(1) - (4)]);
										(yyval).ast->c1 = (yyvsp[(2) - (4)]).ast;
										INSTALL(curr_table, current_ident, (yyval)); 
										//print_tree_invert($$.ast,0);
									}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    {
										(yyval).ast = new_node(SCALAR_NODE);
										(yyval).ast->spec_bits = TYPESPEC;
									}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 133 "parser.y"
    {
										(yyval).ast = (yyvsp[(2) - (2)]).ast; 
									  	(yyval).ast->spec_bits = (TYPESPEC | (yyval).ast->spec_bits);
									}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 137 "parser.y"
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

  case 13:

/* Line 1806 of yacc.c  */
#line 147 "parser.y"
    {
										if (TYPESPEC == IS_STRUCT) 
											{(yyval)=(yyvsp[(1) - (2)]);} // throw away everything else
									   	else
										{
											(yyval).ast = (yyvsp[(2) - (2)]).ast; 
									  		(yyval).ast->spec_bits = TYPESPEC;
										}
									}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 156 "parser.y"
    {
										(yyval).ast = new_node(SCALAR_NODE);
										(yyval).ast->spec_bits = TYPESPEC;
									}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    {
										(yyval).ast = (yyvsp[(2) - (2)]).ast; 
									  	(yyval).ast->spec_bits = TYPESPEC;
									}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 167 "parser.y"
    {TYPESPEC = TYPESPEC | IS_EXTERN;}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 168 "parser.y"
    {TYPESPEC = TYPESPEC | IS_STATIC;}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 169 "parser.y"
    {TYPESPEC = TYPESPEC | IS_AUTO;}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 170 "parser.y"
    {TYPESPEC = TYPESPEC | IS_REGISTER;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 174 "parser.y"
    {TYPESPEC = TYPESPEC | IS_VOID;}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 175 "parser.y"
    {TYPESPEC = TYPESPEC | IS_CHAR;}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 176 "parser.y"
    {TYPESPEC = TYPESPEC | IS_SHORT;}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 177 "parser.y"
    {TYPESPEC = TYPESPEC | IS_INT;}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 178 "parser.y"
    {TYPESPEC = TYPESPEC | IS_LONG;}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 179 "parser.y"
    {TYPESPEC = TYPESPEC | IS_FLOAT;}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 180 "parser.y"
    {TYPESPEC = TYPESPEC | IS_DOUBLE;}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 181 "parser.y"
    {TYPESPEC = TYPESPEC | IS_SIGNED;}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 185 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]); (yyval).ast->spec_bits = 0; TYPESPEC = IS_STRUCT;}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 188 "parser.y"
    {TYPESPEC = TYPESPEC | IS_CONST;}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 189 "parser.y"
    {TYPESPEC = TYPESPEC | IS_RESTRICT;}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 190 "parser.y"
    {TYPESPEC = TYPESPEC | IS_RESTRICT;}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 193 "parser.y"
    {
									(yyval) = (yyvsp[(1) - (2)]);
									strncpy((yyval).ast->name, (yyvsp[(2) - (2)]).ident_val, 255);
								}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    {
									(yyval).ast = new_ident_node((yyvsp[(2) - (2)]).ident_val, STRUCT_NODE);
									INSTALL(struct_table, (yyvsp[(2) - (2)]).ident_val, (yyvsp[(2) - (2)]));
									SYMTABLE members;
									init_table(&members, 512, NULL);
									current_table_entry = in_table(struct_table, (yyvsp[(2) - (2)]).ident_val);
									current_table_entry->members = (struct symTable *) &members;
									current_table_entry->def_line = line;
								}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 206 "parser.y"
    {  
									strncpy((yyval).ast->name, (yyvsp[(2) - (6)]).ident_val, 255);
								}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 215 "parser.y"
    {
										(yyval) = (yyvsp[(1) - (3)]);
										(yyval).ast->c1 = (yyvsp[(2) - (3)]).ast;
										INSTALL((SYMTABLE*)current_table_entry->members, current_ident, (yyval)); 
										//printf("MEMBER INSTALLED: \n");
										//print_tree_invert($$.ast,0);
									}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 225 "parser.y"
    {(yyval).ast = new_node(SCALAR_NODE); (yyval).ast->spec_bits = TYPESPEC;}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 226 "parser.y"
    {(yyval) = (yyvsp[(2) - (2)]); (yyval).ast->spec_bits = TYPESPEC | (yyval).ast->spec_bits;}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 227 "parser.y"
    {(yyval).ast = new_node(SCALAR_NODE); (yyval).ast->spec_bits = TYPESPEC;}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    {(yyval).ast->spec_bits = TYPESPEC | (yyval).ast->spec_bits;}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 231 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 232 "parser.y"
    {(yyval) = (yyvsp[(3) - (3)]);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 235 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 238 "parser.y"
    {(yyval).ast = new_node(STRUCT_NODE);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 239 "parser.y"
    {(yyval).ast = new_node(UNION_NODE);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 243 "parser.y"
    {
								(yyval) = (yyvsp[(1) - (1)]);
								(yyval).ast = new_ident_node((yyvsp[(1) - (1)]).ident_val, VAR_NODE);
								current_ident = (yyvsp[(1) - (1)]).ident_val;
							}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 248 "parser.y"
    {
								(yyval).ast = new_node(ARRAY_NODE); 
								(yyval).ast->size = (yyvsp[(3) - (4)]).int_val;
								(yyval).ast->c1 = (yyvsp[(1) - (4)]).ast;
							}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 253 "parser.y"
    {
						  		(yyval).ast = new_node(PTR_NODE);
						  		(yyval).ast->c1 = (yyvsp[(1) - (3)]).ast;
							}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 257 "parser.y"
    {
						  		(yyval).ast = new_node(PTR_NODE);
						  		(yyval).ast->c1 = (yyvsp[(2) - (2)]).ast;
						}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 263 "parser.y"
    {
				TYPESPEC = 0;
				(yyval) = (yyvsp[(1) - (5)]);
				(yyval).ast->c1 = new_node(FN_NODE);
				strncpy((yyval).ast->c1->name, (yyvsp[(2) - (5)]).ident_val, 255);
				// install function ident in symtable
                INSTALL(saved_table, (yyvsp[(2) - (5)]).ident_val, (yyval));
				curr_table = SPUSH(saved_table);	
				// in the SYMBOL TABLE, store the function's parameters AND
				// blocks of code
				fn_entry = in_table(curr_table->parent, (yyvsp[(2) - (5)]).ident_val);
				fn_entry->members = (struct symTable *) fn_args;
				fn_entry->blocks = init_block_list(NULL);
				current_block_list = fn_entry->blocks;
				current_block = fn_entry->blocks->head; 					
			}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 278 "parser.y"
    {
				printf("Function %s parameters:\n", (yyvsp[(2) - (7)]).ident_val);
				write_table(fn_args);
				printf("Function %s basic blocks:\n", (yyvsp[(2) - (7)]).ident_val);
				program_dump(fn_entry->blocks);
				// restore global scope and basic block list
                curr_scope = GLOBAL_SCOPE; 
				curr_table = SPOP(curr_table);
				global_block_list = push_new_block(global_block_list, NULL);
				current_block = global_block_list->tail;
		
			}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 291 "parser.y"
    {
				curr_scope = FN_SCOPE;
				(yyval) = (yyvsp[(1) - (4)]);
				(yyval).ast->c1 = new_node(FN_NODE);
				strncpy((yyval).ast->c1->name, (yyvsp[(2) - (4)]).ident_val, 256);
				// already in function scope, function ident goes up one level
                INSTALL(curr_table->parent, (yyvsp[(2) - (4)]).ident_val, (yyval));	
				// in the SYMBOL TABLE, store the function's parameters AND
				// blocks of code
				fn_entry = in_table(curr_table->parent, (yyvsp[(2) - (4)]).ident_val);
				fn_entry->members = (struct symTable *) curr_table;
				fn_entry->blocks = init_block_list(NULL);
				current_block_list = fn_entry->blocks;
				current_block = fn_entry->blocks->head; 					
			}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 305 "parser.y"
    {
				printf("Function defined with 0 parameters\n");
				printf("Function basic blocks:\n");
				program_dump(fn_entry->blocks);
				// restore global scope and basic block list
                curr_scope = GLOBAL_SCOPE; 
				curr_table = SPOP(curr_table);
				global_block_list = push_new_block(global_block_list, NULL);
				current_block = global_block_list->tail;
			}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 317 "parser.y"
    {
				curr_scope = FN_SCOPE;
				fn_args = init_table(fn_args, 8, NULL);
				saved_table = curr_table;
				curr_table = fn_args;
				(yyval) = (yyvsp[(1) - (1)]);
				INSTALL(curr_table, current_ident, (yyval)); 
			}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 325 "parser.y"
    {
				(yyval) = (yyvsp[(3) - (3)]);
				INSTALL(curr_table, current_ident, (yyval)); 
			}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 331 "parser.y"
    {
				(yyval) = (yyvsp[(1) - (2)]);
				(yyval).ast->c1 = (yyvsp[(2) - (2)]).ast;
			}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 338 "parser.y"
    {
				if (curr_scope != FN_SCOPE) 
				{
					curr_table = SPUSH(curr_table);
					struct_table = SPUSH(struct_table);
				}
			}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 345 "parser.y"
    {
				if (curr_scope != FN_SCOPE) 
				{
					curr_table = SPOP(curr_table);
					struct_table = SPOP(struct_table);
				}
			}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 360 "parser.y"
    {
				(yyval) = (yyvsp[(1) - (1)]); 
				current_block = push_ast_to_block(current_block, (yyval).ast);
			}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 364 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 365 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 366 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 370 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]);}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 373 "parser.y"
    {
				// new block for condition expression
				current_block_list = push_new_block(current_block_list, NULL);
				push_ast_to_block(current_block_list->tail, (yyvsp[(3) - (4)]).ast);
				current_block->default_exit = current_block_list->tail;
				current_block = current_block_list->tail;
				saved_blocks = push_block(saved_blocks, current_block);
				// new block for true conditional code
				current_block_list = push_new_block(current_block_list, NULL);
				current_block = current_block_list->tail;
				// now contents of statement will be pushed to new block
			}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 384 "parser.y"
    {
				peek_block(saved_blocks)->true_exit = current_block;
			}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 389 "parser.y"
    {
				current_block_list = push_new_block(current_block_list, NULL);
				current_block = current_block_list->tail;
				peek_block(saved_blocks)->false_exit = current_block;
				saved_blocks = pop_block(saved_blocks);
			}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 401 "parser.y"
    {
				// new block for condition expression
				current_block_list = push_new_block(current_block_list, NULL);
				push_ast_to_block(current_block_list->tail, (yyvsp[(3) - (4)]).ast);
				current_block->default_exit = current_block_list->tail;
				current_block = current_block_list->tail;
				saved_blocks = push_block(saved_blocks, current_block);
				// new block for true conditional code
				current_block_list = push_new_block(current_block_list, NULL);
				current_block = current_block_list->tail;
				// now contents of statement will be pushed to new block
			}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 412 "parser.y"
    {
				peek_block(saved_blocks)->true_exit = current_block;
			}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 421 "parser.y"
    {
				// go get its symbol table expression!
				(yyval) = RETRIEVE(curr_table, (yyvsp[(1) - (1)]).ident_val);
			}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 425 "parser.y"
    {
				(yyval)=(yyvsp[(1) - (1)]); 
				(yyval).ast = extract_value((yyval));
			}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 430 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 433 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 435 "parser.y"
    {(yyval)=(yyvsp[(1) - (4)]); (yyval).ast->index = (yyvsp[(3) - (4)]).int_val; printf("%d\n", (yyval).ast->node_type);}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 452 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 453 "parser.y"
    {(yyval) = UNARY((yyvsp[(2) - (2)]), PLUSPLUS);}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 454 "parser.y"
    {(yyval) = UNARY((yyvsp[(2) - (2)]), MINUSMINUS);}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 455 "parser.y"
    {(yyval) = UNARY((yyvsp[(2) - (2)]), '&');}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 456 "parser.y"
    {(yyval) = UNARY((yyvsp[(2) - (2)]), '*');}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 457 "parser.y"
    {(yyval) = UNARY((yyvsp[(2) - (2)]), '+');}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 458 "parser.y"
    {(yyval) = UNARY((yyvsp[(2) - (2)]), '-');}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 459 "parser.y"
    {(yyval) = UNARY((yyvsp[(2) - (2)]), '~');}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 460 "parser.y"
    {(yyval) = UNARY((yyvsp[(2) - (2)]), '!');}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 463 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 464 "parser.y"
    {(yyval) = (yyvsp[(2) - (4)]);}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 470 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 471 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '*');}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 472 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '/');}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 473 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '%');}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 476 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 477 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '+');}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 478 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '-');}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 482 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 483 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), SHL);}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 484 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), SHR);}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 487 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 488 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '<');}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 489 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '>');}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 490 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), LTEQ);}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 491 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), GTEQ);}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 494 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 495 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), EQEQ);}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 496 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NOTEQ);}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 499 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 500 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '&');}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 503 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 504 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '+');}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 507 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 508 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '+');}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 511 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 512 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '+');}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 515 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 516 "parser.y"
    {(yyval) = BINARY((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '+');}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 519 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 520 "parser.y"
    {(yyval) = TERNARY((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 523 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 524 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), '=');}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 525 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), TIMESEQ);}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 526 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), DIVEQ);}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 527 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), MODEQ);}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 528 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), PLUSEQ);}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 529 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), MINUSEQ);}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 530 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), SHLEQ);}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 531 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), SHREQ);}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 532 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), ANDEQ);}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 533 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), OREQ);}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 534 "parser.y"
    {(yyval) = OPASSIGN((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), XOREQ);}
    break;



/* Line 1806 of yacc.c  */
#line 2868 "parser.tab.c"
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
#line 542 "parser.y"

/* Function definitions go here */
int main()
{
	temp_id = 0;
	block_id = 0;
	global_block_list = init_block_list(NULL);
	current_block_list = global_block_list;
	saved_blocks = init_block_list(NULL);
	current_block = global_block_list->head;
	init_table(&t, 512, NULL);
	init_table(&st, 512, NULL);
	curr_table = &t; // initialize scope to global scope
	global_table = curr_table;
	struct_table = &st;
	strcpy(curr_file, "stdin");
	yyparse();
	fprintf(stdout, "\n***** GLOBAL BLOCKS *****\n");
	program_dump(global_block_list);
	QUADBLOCKLIST *quad_blocks = generate_quads(global_block_list);
	output_quads(quad_blocks);
	return 0;
}

void yyerror (char const *s)
{
	fprintf(stderr, "%s\n", s);
}

TNODE *extract_value(YYSTYPE val)
{
	char *int_type = "INT";
	char *long_type = "LONG";
	char *longlong_type = "LONGLONG";
	char *float_type = "FLOAT";
	char *double_type = "DOUBLE";
	char *longdouble_type = "LONGDOUBLE";
	TNODE *t = new_node(CONST_NODE);
	char *num_type = val.metadata.num_type;
	if (strcmp(num_type, int_type) || strcmp(num_type, long_type) || strcmp(num_type, longlong_type))
	{
		t->value.int_val = (long long) val.int_val;
		t->field = INT_FIELD;
	}
	else if (strcmp(num_type, float_type))
	{
		t->value.ld_val = (long double) val.float_val;
		t->field = REAL_FIELD;
	}
	else if (strcmp(num_type, double_type) || strcmp(num_type, longdouble_type))
	{
		t->value.ld_val = (long double) val.double_val;
		t->field = REAL_FIELD;
	}
	else
	{
		fprintf(stderr, "No valid number found!\n");
	}
	return t;
}


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
	tc = in_table(t, key);
	if (!tc)
		tc = in_table(global_table, key);
	if (!tc && curr_scope == FN_SCOPE)
		tc = in_table(fn_args, key);
	if (!tc)
	{
		fprintf(stderr, "%s:%d: ", curr_file, line); 
		fprintf(stderr, "Error: identifier %s undeclared\n", key);
		res->int_val = 0;
		return *res;	
	}
	*res = tc->value;
	return *res;
}

/* SCOPE */
SYMTABLE *SPOP(SYMTABLE *t)
{
	SYMTABLE *temp = t;
	t = t->parent;
	// don't clean up memory 
	// want pointers in basic blocks to still point to valid memory
	//free(temp->cells);
	//free(temp);
	return t;
}

SYMTABLE *SPUSH(SYMTABLE *t)
{
	SYMTABLE *temp = malloc(sizeof(SYMTABLE));
	init_table(temp, 256, t);
	t = temp;
	return t;
}

/* EXPRESSIONS */
YYSTYPE UNARY(YYSTYPE v, int op)
{
    YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
	res->ast = new_node(UNOP);
	res->ast->op = op;
	res->ast->c1 = v.ast;
	return *res;
}

YYSTYPE BINARY(YYSTYPE v1, YYSTYPE v2, int op)
{
    YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
	res->ast = new_node(BINOP);
	res->ast->op = op;
	res->ast->c1 = v1.ast;
	res->ast->c2 = v2.ast;
	return *res;
}

YYSTYPE OPASSIGN(YYSTYPE v1, YYSTYPE v2, int op)
{
    YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
	res->ast = new_node(BINOP);
	res->ast->op = op;
	res->ast->c1 = v1.ast;
	res->ast->c2 = v2.ast;
	return *res;
}

YYSTYPE TERNARY(YYSTYPE v1, YYSTYPE v2, YYSTYPE v3)
{
	YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
	res->ast = new_node(TERNOP);
	res->ast->c1 = v1.ast;
	res->ast->c2 = v2.ast;
	res->ast->c3 = v3.ast;
	return *res;
}

/*
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
*/


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


