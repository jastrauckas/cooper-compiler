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

%left IF
%left ELSE
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ OREQ XOREQ
%left LOGOR
%left LOGAND
%left '^'
%left '|'
%left '&'
%left EQEQ NOTEQ
%left '>' '<' LTEQ GTEQ
%left SHL SHR
%left '+' '-'
%left '*' '/' 
%right '!' '~'
%right SIZEOF

%start translation_unit
%%
/* Grammar rules go here */
/* for now, really just declarations and expressions */
/* inspiration from http://www.lysator.liu.se/c/ANSI-C-grammar-y.html#expression */
/* 
flows in order of precedence, but some precedence is established 
with the %left statements is above to allow similar cases to be combined  
*/

primary_expr:
	IDENT
|	NUMBER			
|	STRING
|	CHARLIT
|	'(' expr ')'

postfix_expr:
	primary_expr
|	postfix_expr '[' expr ']'
| 	postfix_expr '(' ')'
| 	postfix_expr '(' arglist ')'
| 	postfix_expr '.' IDENT
| 	postfix_expr INDSEL IDENT
| 	postfix_expr PLUSPLUS
| 	postfix_expr MINUSMINUS

arglist:
	assign_expr
|	arglist ',' assign_expr

unary_expr: 
	postfix_expr
|	PLUSPLUS unary_expr 
|	MINUSMINUS unary_expr 
|	unary_op cast_expr
|	SIZEOF	unary_expr
|	SIZEOF '(' type_name ')'

unary_op:
	'&'
| 	'*'
|	'+'
|	'-'
|	'~'
|	'!'

cast_expr:
	unary_expr
|	'(' type_name ')' cast_expr

binary_expr:
	cast_expr
|	binary_expr '+' binary_expr
|	binary_expr '-' binary_expr
|	binary_expr '*' binary_expr
|	binary_expr '/' binary_expr
|	binary_expr '&' binary_expr
|	binary_expr '|' binary_expr
|	binary_expr '^' binary_expr
|	binary_expr SHL binary_expr
|	binary_expr SHR binary_expr
|	binary_expr LOGOR binary_expr
|	binary_expr LOGAND binary_expr
|	binary_expr EQEQ binary_expr
|	binary_expr NOTEQ binary_expr
|	binary_expr '>' binary_expr
|	binary_expr '<' binary_expr
|	binary_expr LTEQ binary_expr
|	binary_expr GTEQ binary_expr

conditional_expr:
	binary_expr
|	binary_expr '?' expr ':' conditional_expr	

assign_expr:
	conditional_expr
|	unary_expr assign_op assign_expr

assign_op:
	'='
|	TIMESEQ
|	DIVEQ
|	MODEQ
|	PLUSEQ
|	MINUSEQ
|	SHLEQ
|	SHREQ
|	ANDEQ
|	OREQ
|	XOREQ

expr:
	assign_expr
|	expr ',' assign_expr

constant_expr:
	conditional_expr

declaration:
	dec_specs ';'
|	dec_specs init_declarator_list ';'

dec_specs:
	storage_spec
|	storage_spec dec_specs
| 	type_spec
|	type_spec dec_specs
|	type_qual 
|	type_qual dec_specs

init_declarator_list:
	init_declarator
|	init_declarator_list ',' init_declarator

init_declarator:
	declarator
|	declarator '=' initializer

storage_spec:
	TYPEDEF
|	EXTERN
|	STATIC
| 	AUTO
|	REGISTER

type_spec:
	VOID
|	CHAR
|	SHORT
|	INT
| 	LONG
| 	FLOAT
| 	DOUBLE
|	SIGNED
|	UNSIGNED
|	struct_union_spec
|	enum_spec

struct_union_spec:
	s_or_u IDENT '{' struct_declaration_list '}'
|	s_or_u '{' struct_declaration_list '}'
|	s_or_u IDENT

s_or_u:
	STRUCT
| 	UNION

struct_declaration_list:
	struct_declaration
|	struct_declaration_list struct_declaration

struct_declaration:
	spec_qual_list struct_declarator_list ';'

spec_qual_list:
	type_spec spec_qual_list
|	type_spec
| 	type_qual spec_qual_list
|	type_qual 

struct_declarator_list:
	struct_declarator
|	struct_declarator_list ',' struct_declarator

struct_declarator:
	declarator
|	':' constant_expr
|	declarator ':' constant_expr

enum_spec:
	ENUM '{' enum_list '}'
|	ENUM IDENT '{' enum_list '}'
|	ENUM IDENT

enum_list:
	enumerator
|	enum_list ',' enumerator

enumerator:
	IDENT
|	IDENT '=' constant_expr

type_qual:
	CONST
|	VOLATILE

declarator:
	pointer direct_declarator
|	direct_declarator

direct_declarator:
	IDENT
|	'(' declarator ')'
|	direct_declarator '[' constant_expr ']'
|	direct_declarator '[' ']'
|	direct_declarator '(' param_type_list ')'
|	direct_declarator '(' id_list ')'
|	direct_declarator '(' ')'

pointer: 
	'*'
|	'*' type_qual_list
|	'*' pointer
|	'*' type_qual_list pointer

type_qual_list:
	type_qual
|	type_qual_list type_qual

param_type_list:
	param_list
|	param_list ',' ELLIPSES

param_list:
	param_declaration
|	param_list ',' param_declaration

param_declaration:
	dec_specs declarator
|	dec_specs abstract_declarator
|	dec_specs

id_list:
	IDENT
|	id_list ',' IDENT

type_name:
	spec_qual_list
|	spec_qual_list abstract_declarator

abstract_declarator:
	pointer
| 	direct_abstract_declarator
| 	pointer direct_abstract_declarator

direct_abstract_declarator: 
	'(' abstract_declarator ')'
| 	'[' ']'
| 	'[' constant_expr ']'
| 	direct_abstract_declarator '[' ']'
| 	direct_abstract_declarator '[' constant_expr ']'
| 	'(' ')'
| 	'(' param_type_list ')'
| 	direct_abstract_declarator '(' ')'
| 	direct_abstract_declarator '(' param_type_list ')'

initializer:
	assign_expr
|	'{' initializer_list '}'
|	'{' initializer_list ',' '}'

initializer_list:
	initializer
|	initializer_list ',' initializer

statement:
	labeled_stmt
|	compound_stmt
|	expr_stmt
|	selection_stmt
|	iter_stmt
|	jump_stmt

labeled_stmt:
	IDENT ':' statement
|	CASE constant_expr ':' statement %prec CASE
| 	DEFAULT ':' statement

compound_stmt:
	'{' '}'
|	'{' stmt_list '}'
|	'{' declaration_list '}'
|	'{' declaration_list stmt_list '}'

declaration_list:
	declaration
|	declaration_list declaration

stmt_list:
	statement
|	stmt_list statement

expr_stmt:
	';'
|	expr ';'

selection_stmt:
	IF '(' expr ')' statement %prec IF
|	IF '(' expr ')' statement ELSE statement
| SWITCH '(' expr ')' statement

iter_stmt:
	WHILE '(' expr ')' statement
|	DO statement WHILE '(' expr ')' ';'
| 	FOR '(' expr_stmt expr_stmt ')' statement
|	FOR '(' expr_stmt expr_stmt expr ')' statement

jump_stmt:
	GOTO IDENT ';' 
| 	CONTINUE ';'
| 	BREAK ';'	
| 	RETURN ';'
| 	RETURN expr ';' %prec RETURN

translation_unit:
	external_declaration
	| translation_unit external_declaration

external_declaration:
	function_definition
| 	declaration

function_definition:
	dec_specs declarator declaration_list compound_stmt
|	dec_specs declarator compound_stmt
| 	declarator declaration_list compound_stmt
| 	declarator compound_stmt

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
