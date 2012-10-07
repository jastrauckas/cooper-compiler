/* 
Definitions and prototypes for the structs and functions needed
to create a symbol table for the parser, implemented as a hash table

Julia Astrauckas
ECE 466
*/

#ifndef TABLEH
#define TABLEH
#include "lexer.h"


/* STRUCTS */

// symbol table entries 
typedef struct tableCell
{
	// use the IDENT name as the key
	char *name; 
	// separate chaining -> double linked list
	struct tableCell *nextCell;
	struct tableCell *prevCell;
	// copy yylval in here so we have the info 
	YYSTYPE value;
} TABLECELL;

// symbol table
typedef struct symbolTable
{
	// keep track of the capacity and how full it is
	long occupied;
	long capacity;
	TABLECELL **cells;
} SYMTABLE;


/* FUNCTIONS */

// we need a hash function!
long h(char *key, long max);

// initialize and resize table
void init_table(SYMTABLE *t, long c);
void resize_table(SYMTABLE *t);

// insert into and delete from existing table
void ins_table(SYMTABLE *t, char *key, YYSTYPE val);
void update_table(SYMTABLE *t, char *key, YYSTYPE val);
void del_table(SYMTABLE *t, char *key);

// check membership
TABLECELL *in_table(SYMTABLE *t, char *key);

// print contents
void write_table(SYMTABLE *t);
#endif
