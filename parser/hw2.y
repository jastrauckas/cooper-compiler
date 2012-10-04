/* The parser for Compilers assignment 2 */
/* Julia Astrauckas */

%{
	#include <stdio.h>
	#include "lexer.h"
%}

%token <sym> TOKEOF
%token <sym> AUTO
%token <sym> BREAK
%token <sym> CASE
%token <sym> CHAR
%token <sym> CONST
%token <sym> CONTINUE
%token <sym> DEFAULT
%token <sym> DO
%token <sym> DOUBLE
%token <sym> ELSE
%token <sym> ENUM
%token <sym> EXTERN
%token <sym> FLOAT
%token <sym> FOR
%token <sym> GOTO
%token <sym> IF
%token <sym> INLINE
%token <sym> INT
%token <sym> LONG
%token <sym> REGISTER
%token <sym> RESTRICT
%token <sym> RETURN
%token <sym> SHORT
%token <sym> SIGNED
%token <sym> SIZEOF
%token <sym> STATIC
%token <sym> STRUCT
%token <sym> SWITCH
%token <sym> TYPEDEF
%token <sym> UNION
%token <sym> UNSIGNED
%token <sym> VOID
%token <sym> VOLATILE
%token <sym> WHILE
%token <sym> _BOOL
%token <sym> _COMPLEX
%token <sym> _IMAGINARY
%token <sym> INDSEL
%token <sym> PLUSPLUS
%token <sym> MINUSMINUS
%token <sym> SHL
%token <sym> SHR
%token <sym> LTEQ
%token <sym> GTEQ
%token <sym> EQEQ
%token <sym> NOTEQ
%token <sym> LOGAND
%token <sym> LOGOR
%token <sym> ELLIPSES
%token <sym> TIMESEQ
%token <sym> DIVEQ
%token <sym> MODEQ
%token <sym> PLUSEQ
%token <sym> MINUSEQ
%token <sym> SHLEQ
%token <sym> SHREQ
%token <sym> ANDEQ
%token <sym> OREQ
%token <sym> XOREQ
%token <sym> IDENT
%token <val> CHARLIT
%token <val> STRING
%token <val> NUMBER
%token <sym> ERRC
%token <sym> ERRS
%token <sym> NEWLINE

%left '+' '-'
%left '*' '/'

%%
/* Grammar rules go here */
/* for now, really just declarations and expressions */


run: 
	expression run 
|	expression    				/* forces bison to process many stmts */

expression:
	declaration 
|	statement
|	function /* does this really belong here? */

statement: 
	IDENT '=' math ';'			{printf("statement\n");}

declaration: 
	INT list	';'				{printf("declaration\n");}

list: 
	IDENT						{printf("list\n");}
| 	list ',' IDENT            	{printf("list\n");}


math:							 
	NUMBER                      
| 	math '+' math         	
| 	math '-' math         	
| 	math '*' math         	
| 	math '/' math         	

function:
	IDENT '(' ')' '{' body '}'	{printf("function\n");}

body: 
	statement
|	declaration
|	statement body
|	declaration body

%%
/* Function definitions go here */
int main()
{
	yyparse();
	return 0;
}

void yyerror (char const *s)
{
	fprintf(stderr, "%s\n", s);
}
