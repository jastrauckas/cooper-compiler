#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "symTable.h"

extern SYMTABLE *struct_table;

// don't care if children are null
TNODE *new_tree(int op, TNODE *c1, TNODE *c2, TNODE *c3)
{
	TNODE *root = malloc(sizeof(TNODE));
	c1->p = root;
	if (!c2)
	{
		root->node_type = UNOP;
	}
	else if (!c3)
	{
		root->node_type = BINOP;
		c2->p = root;
	}
	else
	{
		root->node_type = TERNOP;
		c2->p = root;
		c3->p = root;
	}
	root->p = NULL;
	root->op = op;
	root->c1 = c1;
	root->c2 = c2;
	root->c3 = c3;
	return root;
}

TNODE *new_scalar_node(SCALAR value, int ntype)
{
	TNODE *leaf = malloc(sizeof(TNODE));
	leaf->op = -1; // if I want to, I can tell it's a leaf!
	leaf->node_type = ntype;
	memcpy(&leaf->value, &value, sizeof(SCALAR));
	return leaf;
}

TNODE *new_ident_node(char *ident, int ntype)
{
	TNODE *node = malloc(sizeof(TNODE));
	node->op = -1;
	node->node_type = ntype;
	memcpy(node->name, ident, 255);
	return node;
}

TNODE *new_node(int ntype)
{
	TNODE *node = malloc(sizeof(TNODE));
	node->op = -1;
	node->node_type = ntype;
	return node;
}

void print_tree(TNODE *t, int level)
{
	int i;
	char *name;
	for (i=0; i<level; i++)
	{
		printf("\t");
	}
	print_node(t);
	if (t->c1) {print_tree(t->c1, level+1);}			
	if (t->c2) {print_tree(t->c2, level+1);}			
  	if (t->c3) {print_tree(t->c3, level+1);}			
}

void print_tree_invert(TNODE *t, int level)
{
	int i;
	char *name;
	int d;
	d  = get_depth(t, 0);
	if (t->c1) {print_tree_invert(t->c1, level+1);}			
	if (t->c2) {print_tree_invert(t->c2, level+1);}			
  	if (t->c3) {print_tree_invert(t->c3, level+1);}			
	for (i=0; i<d-1; i++)
	{
		printf("\t");
	}
	print_node(t);
}

void print_node(TNODE *t)
{
	switch (t->node_type)
	{
		case VAR_NODE:
			printf("variable: %s\n", t->name);
			break;
		case ARRAY_NODE:
			printf("array of size %d of type:\n", t->size);
			break;
		case PTR_NODE:
			printf("pointer to\n", t->size);
			break;
		case SCALAR_NODE:
			print_scalar(t);
			break;
		case STRUCT_NODE:
			printf("struct %s ", t->name);
		 	TABLECELL *tcell = in_table(struct_table, t->name);
			if (tcell && tcell->members)
			{
				printf("defined at line %d with members: \n", tcell->def_line);
				write_table((SYMTABLE *)tcell->members);
			}		
			else
			{
				printf("(incomplete)\n");
			}
			break;
		case UNION_NODE:
			printf("union %s ", t->name);
		 	tcell = in_table(struct_table, t->name);
			if (tcell && tcell->members)
			{
				printf("defined at line %d with members: \n", tcell->def_line);
				write_table((SYMTABLE *)tcell->members);
			}		
			else
			{
				printf("(incomplete)\n");
			}
			break;
		default:
			printf("unhandled Node Type %d\n", t->node_type);
	}
}

void print_scalar(TNODE *t)
{
	int base_type = 0;
	int short_type = 0;
	int long_type = 0;
	int invalid = 0;
	char type_str[1024];
	char *pos = &type_str[0];
	int bits = t->spec_bits;
	if ((bits & IS_LONG) == IS_LONG)
	{
		strncpy(pos, "long ", 5);
		pos += 5;
		long_type = 1;
	}
	if ((bits & IS_SHORT) == IS_SHORT)
	{
		strncpy(pos, "short ", 6);
		pos += 6;
		short_type++;
		if (long_type)
		{
			invalid = 1;
		}
	}
	if ((bits & IS_INT) == IS_INT)
	{
		strncpy(pos, "int ", 4);
		pos += 4;
		base_type++;
	}
	if ((bits & IS_FLOAT) == IS_FLOAT)
	{
		strncpy(pos, "float ", 6);
		pos += 6;
		base_type++;
	}
	if ((bits & IS_DOUBLE) == IS_DOUBLE)
	{
		strncpy(pos, "double ", 7);
		pos += 7;
		base_type++;
	}
	if ((bits & IS_CHAR) == IS_CHAR)
	{
		strncpy(pos, "char ", 5);
		pos += 5;
		base_type++;
	}
	*pos = '\0';
	if (!base_type && !short_type && !long_type) 
		printf("unknown scalar\n");
	else if (base_type > 1)
		printf("invalid type: %s\n", type_str);
	else
		printf("%s\n", type_str);

}	

int get_depth(TNODE *t, int maxdepth)
{
	if (!t)
		return maxdepth;
	maxdepth++;
	int d1, d2, d3;
	d1 = get_depth(t->c1, maxdepth);
	d2 = get_depth(t->c2, maxdepth);
	d3 = get_depth(t->c3, maxdepth);
	if (d1 > maxdepth) {maxdepth = d1;}
	if (d2 > maxdepth) {maxdepth = d2;}
	if (d3 > maxdepth) {maxdepth = d3;}
	return maxdepth;
}
