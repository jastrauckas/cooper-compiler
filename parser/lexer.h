#ifndef LEXER
#define LEXER
// classes
enum {INT_CLASS, REAL_CLASS};

// types
/*
char *int_type = "INT";
char *long_type = "LONG";
char *longlong_type = "LONGLONG";
char *float_type = "FLOAT";
char *double_type = "DOUBLE";
char *longdouble_type = "LONGDOUBLE";
*/
typedef struct Metatype
{
	char *tokname;
	int num_class;
	char *num_type;
	int is_signed;
} MTYPE;

typedef struct 
{
	char *ident_val;
	// do these need to be ints to accomodate codes for wide characters?
	int char_literal;
	int *string_literal;
	float float_val;
	long double double_val;
	long long int int_val;
	MTYPE metadata; 
} YYSTYPE;

MTYPE mval;
YYSTYPE yylval;

// forward declarations? For Bison?
int yylex (void);
void yyerror (char const *);

// helper functions
void set_int_type(char *suf, MTYPE *m);
void set_double_type(char *suf, MTYPE *m);
void printchar(FILE *f, int charcode);
#endif


// actual token names (moved from lexer.l)
// maybe I should just let Bison do this...
/*
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
enum yytokentype
{
		TOKEOF=0,
		AUTO=257,
		BREAK,
		CASE,
		CHAR,
		CONST,
		CONTINUE,
		DEFAULT,
		DO,
		DOUBLE,
		ELSE,
		ENUM,
		EXTERN,
		FLOAT,
		FOR,
		GOTO,
		IF,
		INLINE,
		INT,
		LONG,
		REGISTER,
		RESTRICT,
		RETURN,
		SHORT,
		SIGNED,
		SIZEOF,
		STATIC,
		STRUCT,
		SWITCH,
		TYPEDEF,
		UNION,
		UNSIGNED,
		VOID,
		VOLATILE,
		WHILE,
		_BOOL,
		_COMPLEX,
		_IMAGINARY,
		INDSEL,
		PLUSPLUS,
		MINUSMINUS,
		SHL,
		SHR,
		LTEQ,
		GTEQ,
		EQEQ,
		NOTEQ,
		LOGAND,
		LOGOR,
		ELLIPSES,
		TIMESEQ,
		DIVEQ,
		MODEQ,
		PLUSEQ,
		MINUSEQ,
		SHLEQ,
		SHREQ,
		ANDEQ,
		OREQ,
		XOREQ,
		IDENT=513,
		CHARLIT,
		STRING,
		NUMBER,
		ERRC,
		ERRS,
		NEWLINE
};
#endif
*/		
