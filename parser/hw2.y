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
	YYSTYPE RETRIEVE(SYMTABLE *t, char *key);
	YYSTYPE UNARY(char *key, int op);
	YYSTYPE BINARY(YYSTYPE v1, YYSTYPE v2, int op);
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

%left ','
%left '='
%left '?' ':'
%left '+' '-'
%left '*' '/'
%left PLUSPLUS MINUSMINUS

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

value: 
	IDENT '=' math			{
								printf("assignment\n");
								$$ = $3;
								UPDATE(curr_table, $1.ident_val, $3);
							}
|	math					{$$ = $1;}
| 	value ',' value			{$$ = $3;}
| 	value '?' value ':' value	{$$ = TERNARY($1, $2, $3);}

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
	IDENT					{$$ = RETRIEVE(curr_table, $1.ident_val);}
|	NUMBER                 	{$$ = $1;}
| 	'(' math ')'			{$$ = $2;} 
| 	math '+' math         	{$$ = BINARY($1, $3, '+');}
| 	math '-' math          	{$$ = BINARY($1, $3, '-');}        	
| 	math '*' math          	{$$ = BINARY($1, $3, '*');}        	
| 	math '/' math          	{$$ = BINARY($1, $3, '/');}
| unaryexp

unaryexp:        	
	IDENT PLUSPLUS          {$$ = UNARY($1.ident_val, PLUSPLUS);}  
| 	IDENT MINUSMINUS        {$$ = UNARY($1.ident_val, MINUSMINUS);}        	
| 	PLUSPLUS IDENT        	{$$ = UNARY($2.ident_val, PLUSPLUS);}        	
| 	MINUSMINUS IDENT        {$$ = UNARY($2.ident_val, MINUSMINUS);}        	

function:
	IDENT '(' ')' block 	{printf("function\n");}

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
	value ';'
|	declaration
|	value ';' body
|	declaration body

%%
/* Function definitions go here */
int main()
{
	init_table(&t, 512, NULL);
	curr_table = &t; // initialize scope to global scope
	yyparse();
	return 0;
}

void yyerror (char const *s)
{
	fprintf(stderr, "%s\n", s);
}

void PRINTEXP(YYSTYPE v)
{
	if (v.has_val)
		printf("expression value: %d\n", (int) v.int_val);
}


// add a new identifier to the current symbol table
void INSTALL(SYMTABLE *t, YYSTYPE val)
{
	if (in_table(t, val.ident_val))
	{
    	fprintf(stderr, "Error: redeclaration of %s\n", val.ident_val);
		return;
    }
	val.has_val = 0;
   	ins_table(t, val.ident_val, val); // junk value 
}

// add or update the value associated with an identifier
void UPDATE(SYMTABLE *t, char *key, YYSTYPE val)
{
	TABLECELL *tc;
    if (!in_table(t, key))
    {
        fprintf(stderr, "Error: identifier %s undeclared\n", val.ident_val);
        return;
    }
	if (!val.has_val)
	{
		fprintf(stderr, "Error: identifier %s undefined\n", key);
		return;	
	}
	val.has_val = 1;
	update_table(t, key, val);
}

YYSTYPE RETRIEVE(SYMTABLE *t, char *key)
{
	YYSTYPE res;
	TABLECELL *tc;
	if (!(tc = in_table(t, key)))
	{
		fprintf(stderr, "Error: identifier %s undefined\n", key);
		return res;	
	}
	res = tc->value;
	return res;
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

YYSTYPE UNARY(char *key, int op)
{
	TABLECELL *tc = in_table(curr_table, key);
	if (!tc)
	{
		fprintf(stderr, "Error: identifier %s undeclared\n", key);
		tc = calloc(sizeof(TABLECELL),1);
		return tc->value;
	}
	YYSTYPE v = tc->value;
	if (!v.has_val)
	{	
		fprintf(stderr, "Error: identifier %s undefined\n", v.ident_val);
		return v;
	}
	switch (op)
	{
		case PLUSPLUS:
			tc->value.int_val = tc->value.int_val + 1;
			break;
		case MINUSMINUS:
			tc->value.int_val = tc->value.int_val -1;
	}
	return tc->value;
}


YYSTYPE BINARY(YYSTYPE v1, YYSTYPE v2, int op)
{
    YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
    if (!CHECK(v1) || !CHECK(v2))
    {
        return *res;
    }
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

YYSTYPE TERNARY(YYSTYPE v1, YYSTYPE v2, YYSTYPE v3)
{
	YYSTYPE *res = calloc(sizeof(YYSTYPE),1);
	if (!CHECK(v1) | !CHECK(v2) | !CHECK(v3))
		return *res;
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
        fprintf(stderr, "Error: identifier %s undefined\n", v.ident_val);
        return 0;
    }
	return 1;
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
void init_table(SYMTABLE *t, long c, SYMTABLE *parent)
{
	t->parent = parent;
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
    init_table(new_table, 2*t->capacity, t->parent);
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

// check membership and return data if found
TABLECELL *in_table(SYMTABLE *t, char *key)
{
	SYMTABLE *ct;
	ct = t;
    TABLECELL *currcell;
	while (ct)
	{
    	int index = h(key, ct->capacity);
    	currcell = ct->cells[index];
    	while (currcell != NULL)
    	{
        	if (!strcmp(key, currcell->name))
        	{
            	return currcell; // return pointer to cell found
        	}
    	}
		// keep moving up in the stack
		//printf("checking parent...\n");
		ct = ct->parent;
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

