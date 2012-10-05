#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "symTable.h"

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
        if (!tc)
            printf("\tnothing in slot %d!\n", i);
        while (tc)
        {
            printf("\tslot %d: id %s, type %s\n", i, tc->name, tc->value.metadata.tokname);
            tc = tc->nextCell;
        }
    }
}
