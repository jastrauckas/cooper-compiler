#ifndef ASTH
#define ASTH

enum 
{
	UNOP, BINOP, TERNOP, VAR_NODE, ARRAY_NODE, PTR_NODE, FN_NODE,	
	REAL_NODE, INT_NODE, STR_NODE, CHAR_NODE,
	STRUCT_NODE, UNION_NODE
} NODETYPE;


#define IS_SIGNED 		000001
#define IS_CONST		000002
#define IS_VOLATILE		000004
#define IS_RESTRICT		000010
#define IS_INT			000020
#define IS_FLOAT		000040
#define IS_DOUBLE		000100
#define IS_SHORT		000200
#define IS_LONG			000400

typedef union scalar
{
	long long int int_val;
	long double ld_val;
	char char_val;
	char str_val[1024];
} SCALAR;

typedef struct tnode
{
	int node_type;
	int op; 		// token codes should be fine
	int spec_bits;  // use bitmasks for storage and type specifiers
	SCALAR value;  	// if scalar, put value here
	int size;		// for arrays
	char name[256];	// if an identifier
	char print_val[256];		// what to print for this node
	struct tnode *c1, *c2, *c3; // children (three at most)
	struct tnode *p;	// parent
} TNODE;

TNODE *new_scalar_node(SCALAR value, int ntype);
TNODE *new_node(int ntype);
TNODE *new_ident_node(char *ident, int ntype);
TNODE *new_var_node(SCALAR value, int ntype);
TNODE *new_tree(int op, TNODE *c1, TNODE *c2, TNODE *c3);
void print_tree(TNODE *t, int level);
void print_node(TNODE *t);

#endif
