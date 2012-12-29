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
%}


%token TOKEOF AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM
%token EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT
%token SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE
%token WHILE _BOOL _COMPLEX _IMAGINARY INDSEL PLUSPLUS MINUSMINUS SHL SHR
%token LTEQ GTEQ EQEQ NOTEQ LOGAND LOGOR ELLIPSES TIMESEQ DIVEQ MODEQ PLUSEQ
%token MINUSEQ SHLEQ SHREQ ANDEQ OREQ XOREQ IDENT CHARLIT STRING NUMBER 
%token ERRC ERRS NEWLINE FILEDIR

%left IF
%left ELSE
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
										//fprintf(stdout, "function defined at <%s> %d\n", curr_file, line);
										//print_tree_invert($$.ast,0);
									}
|	declaration
|	statement				{
										$$ = $1;
										//push_list_node(global_asts, $$.ast);
										//print_tree_invert($$.ast, 0);
									}

declaration:
	declaration-specifiers declarator {
										TYPESPEC = 0;
										//fprintf(stdout, "declaration at <%s> line %d\n", curr_file, line);
									}
		';' 	{
										$$ = $1;
										$$.ast->c1 = $2.ast;
										INSTALL(curr_table, current_ident, $$); 
										//print_tree_invert($$.ast,0);
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
				$$ = $1;
				$$.ast->c1 = new_node(FN_NODE);
				strncpy($$.ast->c1->name, $2.ident_val, 255);
				// install function ident in symtable
                INSTALL(saved_table, $2.ident_val, $$);
				curr_table = SPUSH(saved_table);	
				// in the SYMBOL TABLE, store the function's parameters AND
				// blocks of code
				fn_entry = in_table(curr_table->parent, $2.ident_val);
				fn_entry->members = (struct symTable *) fn_args;
				fn_entry->blocks = init_block_list(NULL);
				current_block_list = fn_entry->blocks;
				current_block = fn_entry->blocks->head; 					
			} compound-statement {
				printf("Function %s parameters:\n", $2.ident_val);
				write_table(fn_args);
				printf("Function %s basic blocks:\n", $2.ident_val);
				program_dump(fn_entry->blocks);
				// restore global scope and basic block list
                curr_scope = GLOBAL_SCOPE; 
				curr_table = SPOP(curr_table);
				global_block_list = push_new_block(global_block_list, NULL);
				current_block = global_block_list->tail;
		
			}

| 	declaration-specifiers declarator '(' ')' {
				curr_scope = FN_SCOPE;
				$$ = $1;
				$$.ast->c1 = new_node(FN_NODE);
				strncpy($$.ast->c1->name, $2.ident_val, 256);
				// already in function scope, function ident goes up one level
                INSTALL(curr_table->parent, $2.ident_val, $$);	
				// in the SYMBOL TABLE, store the function's parameters AND
				// blocks of code
				fn_entry = in_table(curr_table->parent, $2.ident_val);
				fn_entry->members = (struct symTable *) curr_table;
				fn_entry->blocks = init_block_list(NULL);
				current_block_list = fn_entry->blocks;
				current_block = fn_entry->blocks->head; 					
			} compound-statement {
				printf("Function defined with 0 parameters\n");
				printf("Function basic blocks:\n");
				program_dump(fn_entry->blocks);
				// restore global scope and basic block list
                curr_scope = GLOBAL_SCOPE; 
				curr_table = SPOP(curr_table);
				global_block_list = push_new_block(global_block_list, NULL);
				current_block = global_block_list->tail;
			}

declaration-list:
	function-argument {
				curr_scope = FN_SCOPE;
				fn_args = init_table(fn_args, 8, NULL);
				saved_table = curr_table;
				curr_table = fn_args;
				$$ = $1;
				INSTALL(curr_table, current_ident, $$); 
			}
| 	declaration-list ',' function-argument {
				$$ = $3;
				INSTALL(curr_table, current_ident, $$); 
			}

function-argument:
	declaration-specifiers declarator {
				$$ = $1;
				$$.ast->c1 = $2.ast;
			}
	

compound-statement:
	'{' {
				if (curr_scope != FN_SCOPE) 
				{
					curr_table = SPUSH(curr_table);
					struct_table = SPUSH(struct_table);
				}
			}
		body '}' {
				if (curr_scope != FN_SCOPE) 
				{
					curr_table = SPOP(curr_table);
					struct_table = SPOP(struct_table);
				}
			}

body:
	statement
|	body statement
|	declaration
| 	body declaration

statement:
	expression-statement  	{
				$$ = $1; 
				current_block = push_ast_to_block(current_block, $$.ast);
			}
|	compound-statement		{$$ = $1;}
| 	selection-statement		{$$ = $1;}		
|	iteration-statement		{$$ = $1;}

expression-statement:
	';'
|	expression ';'	{$$ = $1;}

if-clause:
	IF '(' expression ')' {
				// new block for condition expression
				current_block_list = push_new_block(current_block_list, NULL);
				push_ast_to_block(current_block_list->tail, $3.ast);
				current_block->default_exit = current_block_list->tail;
				current_block = current_block_list->tail;
				saved_blocks = push_block(saved_blocks, current_block);
				// new block for true conditional code
				current_block_list = push_new_block(current_block_list, NULL);
				current_block = current_block_list->tail;
				// now contents of statement will be pushed to new block
			} statement {
				peek_block(saved_blocks)->true_exit = current_block;
			}

else-clause:
	ELSE {
				current_block_list = push_new_block(current_block_list, NULL);
				current_block = current_block_list->tail;
				peek_block(saved_blocks)->false_exit = current_block;
				saved_blocks = pop_block(saved_blocks);
			} statement

selection-statement:
	if-clause %prec IF 
|	if-clause else-clause %prec ELSE

iteration-statement:
	WHILE '(' expression ')' {
				// new block for condition expression
				current_block_list = push_new_block(current_block_list, NULL);
				push_ast_to_block(current_block_list->tail, $3.ast);
				current_block->default_exit = current_block_list->tail;
				current_block = current_block_list->tail;
				saved_blocks = push_block(saved_blocks, current_block);
				// new block for true conditional code
				current_block_list = push_new_block(current_block_list, NULL);
				current_block = current_block_list->tail;
				// now contents of statement will be pushed to new block
			} statement {
				peek_block(saved_blocks)->true_exit = current_block;
			}

|	FOR '(' expression-statement expression-statement ')' statement
|	FOR '(' expression-statement expression-statement expression ')' statement
| 	DO statement WHILE '(' expression ')' ';'

primary-expression:
	IDENT	{
				// go get its symbol table expression!
				$$ = RETRIEVE(curr_table, $1.ident_val);
			}
|	NUMBER	{
				$$=$1; 
				$$.ast = extract_value($$);
			}
|	STRING
| 	'(' expression ')'	{$$ = $2;}

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
|	'(' type-name ')' cast-expression	{$$ = $2;}

type-name:
	INT

multiplicative-expression:
	cast-expression	{$$ = $1;}
|	multiplicative-expression '*' cast-expression {$$ = BINARY($1, $3, '*');}
|	multiplicative-expression '/' cast-expression {$$ = BINARY($1, $3, '/');}
|	multiplicative-expression '%' cast-expression {$$ = BINARY($1, $3, '%');}

additive-expression:
	multiplicative-expression {$$ = $1;}
|	additive-expression '+' multiplicative-expression {$$ = BINARY($1, $3, '+');}
|	additive-expression '-' multiplicative-expression {$$ = BINARY($1, $3, '-');}


shift-expression:
	additive-expression {$$ = $1;}
|	shift-expression SHL additive-expression {$$ = BINARY($1, $3, SHL);}
|	shift-expression SHR additive-expression {$$ = BINARY($1, $3, SHR);}

relational-expression:
	shift-expression {$$ = $1;}
|	relational-expression '<' shift-expression {$$ = BINARY($1, $3, '<');}
|	relational-expression '>' shift-expression {$$ = BINARY($1, $3, '>');}
|	relational-expression LTEQ shift-expression {$$ = BINARY($1, $3, LTEQ);}
|	relational-expression GTEQ shift-expression {$$ = BINARY($1, $3, GTEQ);}

equality-expression:
	relational-expression {$$ = $1;}
|	equality-expression EQEQ relational-expression {$$ = BINARY($1, $3, EQEQ);}
|	equality-expression NOTEQ relational-expression {$$ = BINARY($1, $3, NOTEQ);}

and-expression:
	equality-expression {$$ = $1;}
|	and-expression '&' equality-expression {$$ = BINARY($1, $3, '&');}

xor-expression:
	and-expression {$$ = $1;}
|	xor-expression '^' and-expression {$$ = BINARY($1, $3, '+');}

or-expression:
	xor-expression {$$ = $1;}
|	or-expression '|' xor-expression {$$ = BINARY($1, $3, '+');}

logand-expression:
	or-expression {$$ = $1;}
|	logand-expression LOGAND or-expression {$$ = BINARY($1, $3, '+');}

logor-expression:
logand-expression {$$ = $1;}
|	logor-expression LOGOR logand-expression {$$ = BINARY($1, $3, '+');}

conditional-expression:
	logor-expression {$$ = $1;}
|	logor-expression '?' expression ':' conditional-expression {$$ = TERNARY($1, $3, $5);}

assignment-expression:
	conditional-expression {$$ = $1;}
|	unary-expression '=' assignment-expression			{$$ = OPASSIGN($1, $3, '=');}
|	unary-expression TIMESEQ assignment-expression		{$$ = OPASSIGN($1, $3, TIMESEQ);}
|	unary-expression DIVEQ assignment-expression		{$$ = OPASSIGN($1, $3, DIVEQ);}
|	unary-expression MODEQ assignment-expression		{$$ = OPASSIGN($1, $3, MODEQ);}
|	unary-expression PLUSEQ assignment-expression		{$$ = OPASSIGN($1, $3, PLUSEQ);}
|	unary-expression MINUSEQ assignment-expression		{$$ = OPASSIGN($1, $3, MINUSEQ);}
|	unary-expression SHLEQ assignment-expression		{$$ = OPASSIGN($1, $3, SHLEQ);}
|	unary-expression SHREQ assignment-expression		{$$ = OPASSIGN($1, $3, SHREQ);}
|	unary-expression ANDEQ assignment-expression		{$$ = OPASSIGN($1, $3, ANDEQ);}
|	unary-expression OREQ assignment-expression			{$$ = OPASSIGN($1, $3, OREQ);}
|	unary-expression XOREQ assignment-expression		{$$ = OPASSIGN($1, $3, XOREQ);}

expression:
	assignment-expression
|	expression ',' assignment-expression



%%
/* Function definitions go here */
int main()
{
	temp_id = 0;
	block_id = 0;
	global_block_list = init_block_list(NULL);
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

