#ifndef QUADH
#define QUADH

#include "symTable.h"
#include "ast.h"

// opcodes beyond lexical operators
// I will make them very large numbers so they (hopefully) won't collide
enum {LOAD_OP = 1025, PRE_STORE_OP, STORE_OP, LEA_OP};

// quad generation is different for lvalues and rvalues
enum {LVAL, RVAL};

// while generating quads, keep track of what is going on in the tree
enum {NORMAL_MODE, ARRAY_STORE_MODE, ARRAY_LOAD_MODE};

// keep track of temp values
extern int temp_id;

// for now, assume the only constants are integers!
typedef struct quad_node {
	int id;			// for keeping track of temp values
	int is_constant;
	int val;		// if a constant	
	char *name;		// if a local variable
} QUADNODE;

typedef struct quad {
	// the four fields 
	int opcode;
	QUADNODE *dest;
	QUADNODE *src1;
	QUADNODE *src2;
	// linked list capabilities
	struct quad *next;
	struct quad *prev;
} QUAD;
	
typedef struct quad_list {
	QUAD *head;
	QUAD *tail;
} QUADLIST;

typedef struct quad_block {
	int id; 
	QUADLIST *quads;
	struct quad_block *next;
	struct quad_block *prev;
} QUADBLOCK;

typedef struct quad_block_list {
	QUADBLOCK *head;
	QUADBLOCK *tail;
} QUADBLOCKLIST;


extern QUADLIST *cur_quad_list;
// function prototypes
// build a quad node for vars, constants, and temp values!
QUADNODE *new_quad_node_var(char *name);
QUADNODE *new_quad_node_const(int val);
QUADNODE *new_quad_node();
QUADNODE *ast_to_quads(TNODE *ast, int side);
QUAD *build_quad(int opcode, QUADNODE *dest, QUADNODE *src1, QUADNODE *src2);
QUAD *build_binop_quad(TNODE *ast, int side);
QUAD *build_unop_quad(TNODE *ast, int side);
QUAD *pop_quad(QUADLIST *ql);
QUADLIST *merge_quad_lists(QUADLIST *ql1, QUADLIST *ql2);
QUADLIST *insert_quad(QUADLIST *ql, QUAD *q);
QUADBLOCK *new_quad_block(int id);
QUADBLOCK *add_quads_to_block(QUADLIST *ql, QUADBLOCK *qb);
QUADBLOCKLIST *generate_quads(BLOCKLIST *blist);
QUADBLOCKLIST *add_quad_block(QUADBLOCKLIST *qb_list, QUADBLOCK *qb);
void output_quads(QUADBLOCKLIST *qb_list);
void print_quad(QUAD *q);
void print_quad_node(QUADNODE *qn);
void print_op(int op);

#endif
