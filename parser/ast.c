#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

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


void print_node(TNODE *t)
{
	if (t->node_type == VAR_NODE)
	{
		printf("Variable: %s\n", t->name);
	}
}
