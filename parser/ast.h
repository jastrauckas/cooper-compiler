#ifndef ASTH
#define ASTH

enum 
{
	UNOP, BINOP, TERNOP, VAR_NODE, ARRAY_NODE, PTR_NODE, FN_NODE,	
	SCALAR_NODE, TYPEDEF_NODE,
	STRUCT_NODE, UNION_NODE
} NODETYPE;


#define IS_SIGNED 		0000001
#define IS_CONST		0000002
#define IS_VOLATILE		0000004
#define IS_RESTRICT		0000010
#define IS_INT			0000020
#define IS_FLOAT		0000040
#define IS_DOUBLE		0000100
#define IS_SHORT		0000200
#define IS_LONG			0000400
#define IS_VOID			0001000
#define IS_CHAR			0002000
#define IS_TYPEDEF		0004000
#define IS_EXTERN		0010000
#define IS_STATIC		0020000
#define IS_AUTO			0040000
#define IS_REGISTER		0100000
#define IS_STRUCT		0100000

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
void print_tree_invert(TNODE *t, int level);
void print_node(TNODE *t);
void print_scalar(TNODE *t);

#endif