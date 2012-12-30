#ifndef QUADH
#define QUADH

#include "symTable.h"
#include "ast.h"

// keep track of temp values
extern int temp_id;

// for now, assume the only constants are integers!
typedef struct quad_node {
	int id;			// for keeping track of temp valuesi
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
QUAD *build_quad(int opcode, QUADNODE *src1, QUADNODE *src2);
QUADNODE *new_quad_node(char *name);
QUADBLOCKLIST *generate_quads(BLOCKLIST *blist);
QUADNODE *ast_to_quads(TNODE *ast);
QUADLIST *merge_quad_lists(QUADLIST *ql1, QUADLIST *ql2);
QUADLIST *insert_quad(QUADLIST *ql, QUAD *q);
QUADBLOCK *new_quad_block(int id);
QUADBLOCK *add_quads_to_block(QUADLIST *ql, QUADBLOCK *qb);
QUADBLOCKLIST *add_quad_block(QUADBLOCKLIST *qb_list, QUADBLOCK *qb);
void output_quads(QUADBLOCKLIST *qb_list);
void print_quad(QUAD *q);
void print_quad_node(QUADNODE *qn);
void print_op(int op);

#endif
