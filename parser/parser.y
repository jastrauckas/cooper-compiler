/* The parser for Compilers assignment 4 */
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
	
	enum {GLOBAL_SCOPE, PROTO_SCOPE, FN_SCOPE};

	SYMTABLE t;
	SYMTABLE st;
	SYMTABLE *new_members = NULL; // use this to create symtable for struct members
	TABLECELL *tc; // store stuff here
	TABLECELL *current_table_entry;
	SYMTABLE *curr_table; // points to the current scope's symbol table
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
%}


%token TOKEOF AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM
%token EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT
%token SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE
%token WHILE _BOOL _COMPLEX _IMAGINARY INDSEL PLUSPLUS MINUSMINUS SHL SHR
%token LTEQ GTEQ EQEQ NOTEQ LOGAND LOGOR ELLIPSES TIMESEQ DIVEQ MODEQ PLUSEQ
%token MINUSEQ SHLEQ SHREQ ANDEQ OREQ XOREQ IDENT CHARLIT STRING NUMBER 
%token ERRC ERRS NEWLINE FILEDIR

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
%left '[' ']' 
%left '+' '-'
%left '*' '/' 
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
	function-definition 	{
										fprintf(stdout, "function defined at <%s> %d\n", curr_file, line);
										print_tree_invert($$.ast,0);
									}
|	declaration
|	statement				{
										print_tree_invert($$.ast, 0);
									}

declaration:
	declaration-specifiers declarator {
										TYPESPEC = 0;
										fprintf(stdout, "\ndeclaration at <%s> line %d\n", curr_file, line);
									}
		';' 	{
										$$ = $1;
										$$.ast->c1 = $2.ast;
										INSTALL(curr_table, current_ident, $$); 
										print_tree_invert($$.ast,0);
									}
|	declaration-specifiers ';'				

declaration-specifiers:
	storage-class-specifier {
										$$.ast = new_node(SCALAR_NODE);
										$$.ast->spec_bits = TYPESPEC;
									}
|	storage-class-specifier declaration-specifiers {
										$$.ast = $2.ast; 
									  	$$.ast->spec_bits = (TYPESPEC | $$.ast->spec_bits);
									}
| 	type-specifier	{
										if (TYPESPEC == IS_STRUCT)
											{$$ = $1;}
										else
										{
											$$.ast = new_node(SCALAR_NODE);
											$$.ast->spec_bits = TYPESPEC;
										} 
										
									}
| 	type-specifier declaration-specifiers {
										if (TYPESPEC == IS_STRUCT) 
											{$$=$1;} // throw away everything else
									   	else
										{
											$$.ast = $2.ast; 
									  		$$.ast->spec_bits = TYPESPEC;
										}
									}
| 	type-qualifier	{
										$$.ast = new_node(SCALAR_NODE);
										$$.ast->spec_bits = TYPESPEC;
									}
| 	type-qualifier declaration-specifiers {
										$$.ast = $2.ast; 
									  	$$.ast->spec_bits = TYPESPEC;
									}


storage-class-specifier:
	EXTERN		{TYPESPEC = TYPESPEC | IS_EXTERN;}
|	STATIC		{TYPESPEC = TYPESPEC | IS_STATIC;}
|	AUTO		{TYPESPEC = TYPESPEC | IS_AUTO;}
|	REGISTER	{TYPESPEC = TYPESPEC | IS_REGISTER;}
/*|	TYPEDEF*/ 	

type-specifier:
	VOID	{TYPESPEC = TYPESPEC | IS_VOID;}
|	CHAR	{TYPESPEC = TYPESPEC | IS_CHAR;}
|	SHORT	{TYPESPEC = TYPESPEC | IS_SHORT;}
|	INT		{TYPESPEC = TYPESPEC | IS_INT;}
|	LONG	{TYPESPEC = TYPESPEC | IS_LONG;}
|	FLOAT	{TYPESPEC = TYPESPEC | IS_FLOAT;}
|	DOUBLE	{TYPESPEC = TYPESPEC | IS_DOUBLE;}
|	SIGNED	{TYPESPEC = TYPESPEC | IS_SIGNED;}
|	UNSIGNED 	
|	_BOOL	
|	_COMPLEX	
| 	struct-or-union-specifier	{$$=$1; $$.ast->spec_bits = 0; TYPESPEC = IS_STRUCT;}

type-qualifier:
	CONST		{TYPESPEC = TYPESPEC | IS_CONST;}
|	RESTRICT	{TYPESPEC = TYPESPEC | IS_RESTRICT;}
|	VOLATILE	{TYPESPEC = TYPESPEC | IS_RESTRICT;}

struct-or-union-specifier:
	struct-or-union IDENT {
									$$ = $1;
									strncpy($$.ast->name, $2.ident_val, 255);
								}
|	struct-or-union IDENT {
									$$.ast = new_ident_node($2.ident_val, STRUCT_NODE);
									INSTALL(struct_table, $2.ident_val, $2);
									SYMTABLE members;
									init_table(&members, 512, NULL);
									current_table_entry = in_table(struct_table, $2.ident_val);
									current_table_entry->members = (struct symTable *) &members;
									current_table_entry->def_line = line;
								} 
	'{' struct-declaration-list '}'	{  
									strncpy($$.ast->name, $2.ident_val, 255);
								}

struct-declaration-list:
	struct-declaration 
|	struct-declaration-list struct-declaration

struct-declaration:
	specifier-qualifier-list struct-declarator-list ';' {
										$$ = $1;
										$$.ast->c1 = $2.ast;
										INSTALL((SYMTABLE*)current_table_entry->members, current_ident, $$); 
										//printf("MEMBER INSTALLED: \n");
										//print_tree_invert($$.ast,0);
									}


specifier-qualifier-list:
	type-specifier {$$.ast = new_node(SCALAR_NODE); $$.ast->spec_bits = TYPESPEC;}
|	type-specifier specifier-qualifier-list {$$ = $2; $$.ast->spec_bits = TYPESPEC | $$.ast->spec_bits;}
|	type-qualifier {$$.ast = new_node(SCALAR_NODE); $$.ast->spec_bits = TYPESPEC;}
|	type-qualifier specifier-qualifier-list {$$.ast->spec_bits = TYPESPEC | $$.ast->spec_bits;}

struct-declarator-list:
	struct-declarator {$$ = $1;}
|	struct-declarator-list ',' struct-declarator {$$ = $3;}

struct-declarator:
	declarator	{$$ = $1;}

struct-or-union:
	STRUCT	{$$.ast = new_node(STRUCT_NODE);}
|	UNION	{$$.ast = new_node(UNION_NODE);}	


declarator:
	IDENT			{
								$$ = $1;
								$$.ast = new_ident_node($1.ident_val, VAR_NODE);
								current_ident = $1.ident_val;
							}
| 	declarator '[' NUMBER ']'  {
								$$.ast = new_node(ARRAY_NODE); 
								$$.ast->size = $3.int_val;
								$$.ast->c1 = $1.ast;
							}
| 	declarator '[' ']'	{
						  		$$.ast = new_node(PTR_NODE);
						  		$$.ast->c1 = $1.ast;
							}
|	'*' declarator		{
						  		$$.ast = new_node(PTR_NODE);
						  		$$.ast->c1 = $2.ast;
						}

function-definition:
	declaration-specifiers declarator '(' declaration-list ')' {
				TYPESPEC = 0;
				curr_scope = FN_SCOPE;
				$$ = $1;
				$$.ast->c1 = new_node(FN_NODE);
				strncpy($$.ast->c1->name, $2.ident_val, 255);
                INSTALL(curr_table, $2.ident_val, $$);	
			} block {
                curr_scope = GLOBAL_SCOPE; 
			}

| 	declaration-specifiers declarator '(' ')' {
				curr_scope = FN_SCOPE;
				$$ = $1;
				$$.ast->c1 = new_node(FN_NODE);
				strncpy($$.ast->c1->name, $2.ident_val, 256);
                INSTALL(curr_table, $2.ident_val, $$);	
			} block {
                curr_scope = GLOBAL_SCOPE; 
			}
/*
| 	declarator '(' declaration-list ')' {
				curr_scope = FN_SCOPE;
				$$ = $1;
				$$.ast->node_type = SCALAR_NODE;
				$$.ast->spec_bits = IS_VOID;
				$$.ast->c1 = new_node(FN_NODE);
				strncpy($$.ast->c1->name, $1.ident_val, 256);
                INSTALL(curr_table, $1.ident_val, $$);	
			} block {
				$$ = $1;
                curr_scope = GLOBAL_SCOPE; 
			}

| 	declarator '(' ')' block
*/

declaration-list:
	function-argument
| 	declaration-list ',' function-argument

function-argument:
	declaration-specifiers declarator
	

block:
	'{' {
				curr_table = SPUSH(curr_table);
				struct_table = SPUSH(struct_table);
			}
		body '}' {
				curr_table = SPOP(curr_table);
				struct_table = SPOP(struct_table);
			}

body:
	statement
|	body statement
|	declaration
| 	body declaration

statement:
	expression ';'

primary-expression:
	IDENT
|	NUMBER	{
				$$=$1; 
				$$.ast = extract_value($$);
			}
|	STRING
| 	'(' expression ')'

postfix-expression:
	primary-expression {$$ = $1;}
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
	postfix-expression {$$ = $1;}
|	PLUSPLUS unary-expression	{$$ = UNARY($2, PLUSPLUS);}
|	MINUSMINUS unary-expression	{$$ = UNARY($2, MINUSMINUS);}
| 	'&' cast-expression	{$$ = UNARY($2, '&');}
| 	'*' cast-expression	{$$ = UNARY($2, '*');}
| 	'+' cast-expression	{$$ = UNARY($2, '+');}
| 	'-' cast-expression	{$$ = UNARY($2, '-');}
| 	'~' cast-expression	{$$ = UNARY($2, '~');}
| 	'!' cast-expression	{$$ = UNARY($2, '!');}

cast-expression:
	unary-expression	{$$ = $1;}
|	'(' type-name ')' cast-expression

type-name:
	INT

binary-expression:
	cast-expression
|	binary-expression '*' cast-expression {$$ = BINARY($1, $3, '*');}
|	binary-expression '/' cast-expression {$$ = BINARY($1, $3, '/');}
|	binary-expression '+' cast-expression {$$ = BINARY($1, $3, '+');}
|	binary-expression '-' cast-expression {$$ = BINARY($1, $3, '-');}
|	binary-expression SHL cast-expression {$$ = BINARY($1, $3, SHL);}
|	binary-expression SHR cast-expression {$$ = BINARY($1, $3, SHR);}
|	binary-expression '<' cast-expression {$$ = BINARY($1, $3, '<');}
|	binary-expression '>' cast-expression {$$ = BINARY($1, $3, '>');}
|	binary-expression LTEQ cast-expression {$$ = BINARY($1, $3, LTEQ);}
|	binary-expression GTEQ cast-expression {$$ = BINARY($1, $3, GTEQ);}
|	binary-expression EQEQ cast-expression {$$ = BINARY($1, $3, EQEQ);}
|	binary-expression NOTEQ cast-expression {$$ = BINARY($1, $3, NOTEQ);}
|	binary-expression '&' cast-expression {$$ = BINARY($1, $3, '+');}
|	binary-expression '|' cast-expression {$$ = BINARY($1, $3, '+');}
|	binary-expression '^' cast-expression {$$ = BINARY($1, $3, '+');}
|	binary-expression LOGAND cast-expression {$$ = BINARY($1, $3, '+');}
|	binary-expression LOGOR cast-expression {$$ = BINARY($1, $3, '+');}

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



%%
/* Function definitions go here */
int main()
{
	init_table(&t, 512, NULL);
	init_table(&st, 512, NULL);
	curr_table = &t; // initialize scope to global scope
	struct_table = &st;
	strcpy(curr_file, "stdin");
	yyparse();
	return 0;
}

void yyerror (char const *s)
{
	fprintf(stderr, "%s\n", s);
}

// HW 3
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
SYMTABLE *SPOP(SYMTABLE *t)
{
	SYMTABLE *temp = t;
	t = t->parent;
	free(temp->cells);
	free(temp);
	return t;
}

SYMTABLE *SPUSH(SYMTABLE *t)
{
	SYMTABLE *temp = malloc(sizeof(SYMTABLE));
	init_table(temp, 256, t);
	t = temp;
	return t;
}

/* ARITHMETIC */
// for now it is only defined for integers

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

