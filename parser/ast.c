#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

// don't care if children are null
TNODE *new_tree(int op, TNODE *c1, TNODE *c2, TNODE *c3)
{
	TNODE *root = malloc(sizeof(TNODE));
	root->p = NULL;
	root->op = op;
	root->c1 = c1;
	root->c2 = c2;
	root->c3 = c3;
	return root;
}

TNODE *new_leaf(YYSTYPE leafval)
{
	TNODE *leaf = malloc(sizeof(TNODE));
	memcpy(&leaf->operand, &leafval, sizeof(YYSTYPE));
	leaf->op = -1; // if I want to, I can tell it's a leaf!
}

