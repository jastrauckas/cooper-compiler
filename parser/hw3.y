/* The parser for Compilers assignment 2 */
/* Julia Astrauckas */

%{
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
	SYMTABLE *new_members = NULL;
	TABLECELL *tc; // store stuff here
	SYMTABLE *curr_table; // points to the current scope's symbol table
	char curr_file[MAXLEN+1];
	int stat;
	int node_type;

	/* functions that will be defined */
	SCALAR extract_value(YYSTYPE val);
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
%}


%token TOKEOF
%token AUTO
%token BREAK
%token CASE
%token CHAR
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token ENUM
%token EXTERN
%token FLOAT
%token FOR
%token GOTO
%token IF
%token INLINE
%token INT
%token LONG
%token REGISTER
%token RESTRICT
%token RETURN
%token SHORT
%token SIGNED
%token SIZEOF
%token STATIC
%token STRUCT
%token SWITCH
%token TYPEDEF
%token UNION
%token UNSIGNED
%token VOID
%token VOLATILE
%token WHILE
%token _BOOL
%token _COMPLEX
%token _IMAGINARY
%token INDSEL
%token PLUSPLUS
%token MINUSMINUS
%token SHL
%token SHR
%token LTEQ
%token GTEQ
%token EQEQ
%token NOTEQ
%token LOGAND
%token LOGOR
%token ELLIPSES
%token TIMESEQ
%token DIVEQ
%token MODEQ
%token PLUSEQ
%token MINUSEQ
%token SHLEQ
%token SHREQ
%token ANDEQ
%token OREQ
%token XOREQ
%token IDENT
%token CHARLIT
%token STRING
%token NUMBER
%token ERRC
%token ERRS
%token NEWLINE
%token FILEDIR

%left ','
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ OREQ XOREQ
%left '?' ':'
%left LOGOR
%left LOGAND
%left '|'
%left '&'
%left EQEQ NOTEQ
%left '>' '<' LTEQ GTEQ
%left SHL SHR
%left '+' '-'
%left '*' '/' 
%left '[' ']' 
%left PLUSPLUS MINUSMINUS
%right '!' '~'
%left INDSEL


%start translation-unit
%%

/* TOP LEVEL - EXTERNAL DEFINITIONS */

translation-unit:
	external-declaration
|	translation-unit external-declaration

external-declaration:
	function-definition 	{fprintf(stdout, "function defined\n");}
|	declaration				{fprintf(stdout, "declaration on line %d\n", line);}

declaration:
	declaration-specifiers declarator ';'
|	declaration-specifiers ';'

declaration-specifiers:
	storage-class-specifier
|	storage-class-specifier declaration-specifiers
| 	type-specifier
| 	type-specifier declaration-specifiers
| 	type-qualifier
| 	type-qualifier declaration-specifiers

storage-class-specifier:
	TYPEDEF	
|	EXTERN
|	STATIC
|	AUTO
|	REGISTER

type-specifier:
	VOID
|	CHAR
|	SHORT
|	INT
|	LONG
|	FLOAT
|	DOUBLE
|	SIGNED
|	UNSIGNED 
|	_BOOL
|	_COMPLEX
| 	struct-or-union-specifier

type-qualifier:
	CONST
|	RESTRICT
|	VOLATILE

struct-or-union-specifier:
	struct-or-union IDENT
|	struct-or-union IDENT '{' struct-declaration-list '}'	{  //INSTALL(curr_table, $2);
															   //printf("installed %s\n", $2.ident_val);
															}

struct-declaration-list:
	struct-declaration
|	struct-declaration-list struct-declaration

struct-declaration:
	specifier-qualifier-list struct-declarator-list ';'

specifier-qualifier-list:
	type-specifier
|	type-specifier specifier-qualifier-list
|	type-qualifier
|	type-qualifier specifier-qualifier-list

struct-declarator-list:
	struct-declarator
|	struct-declarator-list ',' struct-declarator

struct-declarator:
	declarator

struct-or-union:
	STRUCT
|	UNION	


declarator:
	IDENT			{$$.ast = new_ident_node($1.ident_val, VAR_NODE);}
| 	declarator '[' NUMBER ']'
| 	declarator '[' ']'
|	'*' declarator
| 	'&' declarator

function-definition:
	IDENT '(' ')' block

block:
	'{' body '}'

body:
	statement
|	body statement
|	declaration
| 	body declaration

statement:
	expression ';'

primary-expression:
	IDENT
|	NUMBER
|	STRING
| 	'(' expression ')'

postfix-expression:
	primary-expression
|	postfix-expression '[' ']'
|	postfix-expression '[' NUMBER ']'
|	postfix-expression '(' ')'
|	postfix-expression '(' argument-expression-list ')'
|	postfix-expression '.' IDENT
|	postfix-expression INDSEL IDENT
|	postfix-expression PLUSPLUS
|	postfix-expression MINUSMINUS
/*
| 	'(' type-name ')' '{' initializer-list '}'
| 	'(' type-name ')' '{' initializer-list ',' '}'
*/

argument-expression-list:
	assignment-expression
|	argument-expression-list ',' assignment-expression

unary-expression:
	postfix-expression
|	PLUSPLUS unary-expression
|	MINUSMINUS unary-expression
| 	'&' cast-expression
| 	'*' cast-expression
| 	'+' cast-expression
| 	'-' cast-expression
| 	'~' cast-expression
| 	'!' cast-expression

cast-expression:
	unary-expression
|	'(' type-name ')' cast-expression

type-name:
	INT

binary-expression:
	cast-expression
|	binary-expression '*' cast-expression	%prec '*'
|	binary-expression '/' cast-expression	%prec '/'
|	binary-expression '+' cast-expression	%prec '+'
|	binary-expression '-' cast-expression
|	binary-expression SHL cast-expression
|	binary-expression SHR cast-expression
|	binary-expression '<' cast-expression
|	binary-expression '>' cast-expression
|	binary-expression LTEQ cast-expression
|	binary-expression GTEQ cast-expression
|	binary-expression EQEQ cast-expression
|	binary-expression NOTEQ cast-expression
|	binary-expression '&' cast-expression
|	binary-expression '|' cast-expression
|	binary-expression '^' cast-expression
|	binary-expression LOGAND cast-expression
|	binary-expression LOGOR cast-expression

conditional-expression:
	binary-expression
|	binary-expression '?' expression ':' conditional-expression

assignment-expression:
	conditional-expression
|	unary-expression '=' assignment-expression
|	unary-expression TIMESEQ assignment-expression
|	unary-expression DIVEQ assignment-expression
|	unary-expression MODEQ assignment-expression
|	unary-expression PLUSEQ assignment-expression
|	unary-expression MINUSEQ assignment-expression
|	unary-expression SHLEQ assignment-expression
|	unary-expression SHREQ assignment-expression
|	unary-expression ANDEQ assignment-expression
|	unary-expression OREQ assignment-expression
|	unary-expression XOREQ assignment-expression

expression:
	assignment-expression
|	expression ',' assignment-expression




// HW2 GRAMMAR
/*
run: 
	expression run 
|	expression    			

expression:
	declaration 
|	value ';'				{PRINTEXP($1);}
|	function 
| 	FILEDIR					{strncpy(curr_file, $1.ident_val, MAXLEN);}

value: 
	math					{$$ = $1;}
|	IDENT '=' value			{
								stat = UPDATE(curr_table, $1.ident_val, $3);
								$$ = $3;
								//if (stat) {$$.int_val=0;}
							}
|	IDENT TIMESEQ value		{$$ = OPASSIGN($1, $3, TIMESEQ);}
|	IDENT DIVEQ value		{$$ = OPASSIGN($1, $3, DIVEQ);}
|	IDENT MODEQ value		{$$ = OPASSIGN($1, $3, MODEQ);}
|	IDENT PLUSEQ value		{$$ = OPASSIGN($1, $3, PLUSEQ);}
|	IDENT MINUSEQ value		{$$ = OPASSIGN($1, $3, MINUSEQ);}
|	IDENT SHLEQ value		{$$ = OPASSIGN($1, $3, SHLEQ);}
|	IDENT SHREQ value		{$$ = OPASSIGN($1, $3, SHREQ);}
|	IDENT ANDEQ value		{$$ = OPASSIGN($1, $3, ANDEQ);}
|	IDENT OREQ value			{$$ = OPASSIGN($1, $3, OREQ);}
|	IDENT XOREQ value		{$$ = OPASSIGN($1, $3, XOREQ);}
| 	value ',' value			{$$ = $3;}
| 	value '?' value ':' value	{$$ = TERNARY($1, $2, $3);}
|	IDENT '[' value ']'		{
								$$ = $3;
								$$.has_val = 0;
								$$.int_val = 0;
								printf("%s:%d: ", curr_file, line); 
								printf("Error: array not implemented\n");
							}
|	IDENT INDSEL IDENT		{
								$$ = $3;
								$$.has_val = 0;
								$$.int_val = 0;
								printf("%s:%d: ", curr_file, line); 
								printf("Error: struct/union not implemented\n");
							}

declaration: 
	INT list	';'			

list: 
	IDENT					{
								$$=$1; INSTALL(curr_table, $1);
							}
| 	list ',' IDENT          {
								$$=$3; INSTALL(curr_table, $3);
							}


math:
	IDENT					{$$ = RETRIEVE(curr_table, $1.ident_val);}
|	NUMBER                 	{$$ = FIXNUM($1);}
| 	'(' math ')'			{$$ = $2;} 
| 	math '+' math         	{$$ = BINARY($1, $3, '+');}
| 	math '-' math          	{$$ = BINARY($1, $3, '-');}        	
| 	math '*' math          	{$$ = BINARY($1, $3, '*');}        	
| 	math '/' math          	{$$ = BINARY($1, $3, '/');}
| 	math SHL math          	{$$ = BINARY($1, $3, SHL);}
| 	math SHR math          	{$$ = BINARY($1, $3, SHR);}
| 	unaryexp

unaryexp:        	
	math PLUSPLUS          	{$$ = UNARY($1, PLUSPLUS);}  
| 	math MINUSMINUS        	{$$ = UNARY($1, MINUSMINUS);}        	
| 	PLUSPLUS math        	{$$ = UNARY($2, PLUSPLUS);}        	
| 	MINUSMINUS math        	{$$ = UNARY($2, MINUSMINUS);}        	
| 	'+' math        		{$$ = UNARY($2, '+');}        	
| 	'-' math        		{$$ = UNARY($2, '-');}        	

function:
	IDENT '(' ')' block 
|	IDENT '(' ')' '\n' block
|	block	

block:
	scopepush body scopepop	{}

scopepush:
	'{'						{
								SPUSH(); 
								//printf("entering function scope\n");
							}

scopepop:
	'}'						{
								SPOP(); 
                                //printf("leaving function scope\n");
							}
body: 
	value ';'				{PRINTEXP($1);}
|	declaration
|	body value ';'			{PRINTEXP($2);}
|	body declaration
| 	block
| 	body block
*/

%%
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
	if (strcmp(num_type, int_type) || strcmp(num_type, long_type) || strcmp(num_type, longlong_type))
	{
		s.int_val = (long long) val.int_val;
		node_type = INT_NODE;	
	}
	else if (strcmp(num_type, float_type))
	{
		s.ld_val = (long double) val.float_val;
		node_type = REAL_NODE;
	}
	else if (strcmp(num_type, double_type) || strcmp(num_type, longdouble_type))
	{
		s.ld_val = (long double) val.double_val;
		node_type = REAL_NODE;
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

// special for struct members
void ADD_MEMBER(SYMTABLE *t, YYSTYPE member)
{
	if (!t)
	{
		init_table(t, 8, NULL);
	}
	INSTALL(t, member);
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

