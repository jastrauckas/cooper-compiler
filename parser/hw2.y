/* The parser for Compilers assignment 2 */
/* Julia Astrauckas */

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include "lexer.h"
	#include "symTable.h"

	SYMTABLE t;
	TABLECELL *tc; // store stuff here
	SYMTABLE *curr_table; // points to the current scope's symbol table

	/* functions that will be defined */
	void INSTALL(SYMTABLE *t, YYSTYPE val);
	void UPDATE(SYMTABLE *t, char *key, YYSTYPE val);
	YYSTYPE ADD(YYSTYPE v1, YYSTYPE v2);
	YYSTYPE MULTIPLY(YYSTYPE v1, YYSTYPE v2);
	YYSTYPE SUBTRACT(YYSTYPE v1, YYSTYPE v2);
	YYSTYPE DIVIDE(YYSTYPE v1, YYSTYPE v2);
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
|	assignment
|	function /* does this really belong here? */

assignment: 
	IDENT '=' math ';'		{
								printf("assignment\n");
								$$ = $3;
								UPDATE(curr_table, $1.ident_val, $3);
								write_table(curr_table); 
							}
| 	IDENT '=' IDENT ';'			

declaration: 
	INT list	';'			{
								printf("declaration\n");
							}

list: 
	IDENT					{
								printf("list\n");
								INSTALL(curr_table, $1);
							}
| 	list ',' IDENT          {
								printf("list\n");
								INSTALL(curr_table, $3);
							}


math:
	NUMBER                 	{$$ = $1;} 
| 	math '+' math         	{$$ = ADD($1, $3);}
| 	math '-' math          	{$$ = SUBTRACT($1, $3);}        	
| 	math '*' math          	{$$ = MULTIPLY($1, $3);}        	
| 	math '/' math          	{$$ = DIVIDE($1, $3);}        	

function:
	IDENT '(' ')' '{' body '}'	{printf("function\n");}

body: 
	assignment
|	declaration
|	assignment body
|	declaration body

%%
/* Function definitions go here */
int main()
{
	init_table(&t, 512);
	curr_table = &t; // initialize scope to global scope
	yyparse();
	return 0;
}

void yyerror (char const *s)
{
	fprintf(stderr, "%s\n", s);
}


// add a new identifier to the current symbol table
void INSTALL(SYMTABLE *t, YYSTYPE val)
{
	if (in_table(t, val.ident_val))
	{
    	fprintf(stderr, "Error: redeclaration of %s\n", val.ident_val);
		return;
    }
   	ins_table(t, val.ident_val, val); // junk value 
}

void UPDATE(SYMTABLE *t, char *key, YYSTYPE val)
{
    if (!in_table(t, key))
    {
        fprintf(stderr, "Error: identifier %s undeclared\n", val.ident_val);
        return;
    }
	update_table(t, key, val);
}


/* ARITHMETIC */
// for now it is only defined for integers
YYSTYPE ADD(YYSTYPE v1, YYSTYPE v2)
{
	YYSTYPE *res = malloc(sizeof(YYSTYPE));
	res->int_val = v1.int_val + v2.int_val;
	res->metadata.tokname = "NUMBER";
	return *res;
}
YYSTYPE MULTIPLY(YYSTYPE v1, YYSTYPE v2)
{
    YYSTYPE res;
    res.int_val = v1.int_val * v2.int_val;
	res.metadata.tokname = "NUMBER";
	return res;
}
YYSTYPE SUBTRACT(YYSTYPE v1, YYSTYPE v2)
{
    YYSTYPE res;
    res.int_val = v1.int_val - v2.int_val;
	res.metadata.tokname = "NUMBER";
	return res;
}
YYSTYPE DIVIDE(YYSTYPE v1, YYSTYPE v2)
{
    YYSTYPE res;
    res.int_val = v1.int_val / v2.int_val;
	res.metadata.tokname = "NUMBER";
	return res;
}

/* SYMBOL TABLE */
// I'll put the symtable functions in here for now...
// silly hash function that just adds char values
long h(char *key, long max)
{
    int l = strlen(key);
    long sum = 0;
    int i;
    for (i=0; i<l; i++)
    {
        sum += key[i];
    }
    sum %= max;
    return sum;
}

// initialize table
void init_table(SYMTABLE *t, long c)
{
    t->occupied = 0;
    t->capacity = c;
    if ((t->cells = calloc(c, sizeof(TABLECELL*))) < 0)
        fprintf(stderr, "failed to allocate table\n");
    int i;
    for (i=0; i<t->capacity; i++)
    {
        t->cells[i] = NULL;
    }
}

void resize_table(SYMTABLE *t)
{
    //printf("RESIZE\n");
    SYMTABLE *new_table = malloc(sizeof(SYMTABLE));
    init_table(new_table, 2*t->capacity);
    int i;
    TABLECELL *currcell;
    // copy over all the cells and their contents
    for (i=0; i<t->capacity; i++)
    {
        currcell = t->cells[i];
        while (currcell != NULL)
        {
            ins_table(new_table, currcell->name, currcell->value);
            currcell = currcell->nextCell;
        }
    }
    // free the memory from the old table
    free(t->cells);
    t->capacity = new_table->capacity;
    //printf("new capacity: %ld\n", t->capacity);
    t->occupied = new_table->occupied;
    t->cells = new_table->cells;
}

// insert into and delete from existing table
// make sure ins does a deep copy of everything, and resizes if needed 
void ins_table(SYMTABLE *t, char *key, YYSTYPE val)
{
    //printf("INSERTING %s\n", key);
    t->occupied++;
    // make a new cell that is home to our new node
    TABLECELL *new_cell = malloc(sizeof(TABLECELL));
    int l = strlen(key) + 1; // include null terminator! 
    new_cell->name = malloc(sizeof(char)*l);
    new_cell->nextCell = NULL;
    new_cell->prevCell = NULL;
    // copy over contents
    memcpy(new_cell->name, key, sizeof(char)*l);
    memcpy(&new_cell->value, &val, sizeof(YYSTYPE));
    int index = h(key, t->capacity);
    // find an empty slot to stick our new cell into
    TABLECELL *currcell, *lastcell;
    currcell = t->cells[index];
    lastcell = NULL;
    if (currcell == NULL)
    {
        t->cells[index] = new_cell;
        return;
    }
    while (currcell != NULL)
    {
        lastcell = currcell;
        currcell = currcell->nextCell;
    }
    // pointer updates!
    currcell = new_cell;
    lastcell->nextCell = currcell;
    currcell->prevCell = lastcell;
    currcell->nextCell = NULL;
    if ((t->occupied*2) > t->capacity)
    {
        //write_table(t);
        resize_table(t);
    }
    return;
}

void update_table(SYMTABLE *t, char *key, YYSTYPE val)
{
    TABLECELL *tc = in_table(t, key);
    if (!tc)
    {
        fprintf(stderr, "Key %s does not exist!\n", key);
        return;
    }
    memcpy(&(tc->value), &val, sizeof(YYSTYPE));
}

void del_table(SYMTABLE *t, char *key)
{
    TABLECELL *tc = in_table(t, key);
    TABLECELL *prevc, *nextc;
    prevc = tc->prevCell;
    nextc = tc->nextCell;
    if (prevc)
    {
        prevc->nextCell = nextc;
        nextc->prevCell = prevc;
        free(tc);
        return;
    }
    // if this was the first node, "install" its neighbor in array
    else if (nextc)
    {
        memcpy(tc, nextc, sizeof(TABLECELL));
        free(nextc);
        return;
    }
    else
    {
        free(tc);
        tc = NULL;
    }
}

// check membership
TABLECELL *in_table(SYMTABLE *t, char *key)
{
    int index = h(key, t->capacity);
    TABLECELL *currcell;
    currcell = t->cells[index];
    while (currcell != NULL)
    {
        if (!strcmp(key, currcell->name))
        {
            return currcell; // return pointer to cell found
        }
    }
    return NULL;
}


void write_table(SYMTABLE *t)
{
    int i;
    TABLECELL *tc;
    printf("TABLE CONTENTS:\n");
    for (i=0; i<t->capacity; i++)
    {
        tc = t->cells[i];
        /*
		if (!tc)
            printf("\tnothing in slot %d!\n", i);
        */
		while (tc)
        {
            printf("\tslot %d: id %s, type %s\n", i, tc->name, tc->value.metadata.tokname);
            tc = tc->nextCell;
        }
    }
}

