#ifndef ASTH
#define ASTH

typedef struct tnode
{
	int op; 		// token codes should be fine
	YYSTYPE operand; 	// only leaf nodes should really have this
	struct tnode *c1, *c2, *c3; // children (three at most)
	struct tnode *p;	// parent
} TNODE;

TNODE *new_leaf(YYSTYPE leafval);
TNODE *new_tree(int op, TNODE *c1, TNODE *c2, TNODE *c3);
#endif
