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
%left '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ OREQ XOREQ
%left '?' ':'
%left LOGOR
%left LOGAND
%left '|'
%left '&'
%left EQEQ NOTEQ
%left '>' '<' LTEQ GTEQ
%left LSH RSH
%left '+' '-'
%left '*' '/' 
%left PLUSPLUS MINUSMINUS
%left '!' '~'
%left INDSEL

%%
/* Grammar rules go here */
/* for now, really just declarations and expressions */


run: 
	expression run 
|	expression    				/* forces bison to process many stmts */

expression:
	declaration 
|	value ';'				{PRINTEXP($1);}
|	function /* does this belong here? */
| 	FILEDIR					{strncpy(curr_file, $1.ident_val, MAXLEN); line=0;}

value: 
	IDENT '=' math			{
								stat = UPDATE(curr_table, $1.ident_val, $3);
								$$ = $3;
								if (stat) {$$.int_val=0;}
							}
|	IDENT TIMESEQ math		{$$ = OPASSIGN($1, $3, TIMESEQ);}
|	IDENT DIVEQ math		{$$ = OPASSIGN($1, $3, DIVEQ);}
|	IDENT MODEQ math		{$$ = OPASSIGN($1, $3, MODEQ);}
|	IDENT PLUSEQ math		{$$ = OPASSIGN($1, $3, PLUSEQ);}
|	IDENT MINUSEQ math		{$$ = OPASSIGN($1, $3, MINUSEQ);}
|	IDENT SHLEQ math		{$$ = OPASSIGN($1, $3, SHLEQ);}
|	IDENT SHREQ math		{$$ = OPASSIGN($1, $3, SHREQ);}
|	IDENT ANDEQ math		{$$ = OPASSIGN($1, $3, ANDEQ);}
|	IDENT OREQ math			{$$ = OPASSIGN($1, $3, OREQ);}
|	IDENT XOREQ math		{$$ = OPASSIGN($1, $3, XOREQ);}
|	math					{$$ = $1;}
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
| 	math LSH math          	{$$ = BINARY($1, $3, LSH);}
| 	math RSH math          	{$$ = BINARY($1, $3, RSH);}
| 	math '+' math         	{$$ = BINARY($1, $3, '+');}
| 	math '-' math          	{$$ = BINARY($1, $3, '-');}        	
| 	math '*' math          	{$$ = BINARY($1, $3, '*');}        	
| 	math '/' math          	{$$ = BINARY($1, $3, '/');}
| unaryexp

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
								printf("entering function scope\n");
							}

scopepop:
	'}'						{
								SPOP(); 
                                printf("leaving function scope\n");
							}
body: 
	value ';'				{PRINTEXP($1);}
|	declaration
| 	block
|	body value ';'			{PRINTEXP($1);}
|	body declaration
| 	body block

%%
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
