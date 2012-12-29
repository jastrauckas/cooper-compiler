#ifndef QUADH
#define QUADH

#include "symTable.h"

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

QUAD *build_quad(int opcode, QUADNODE *src1, QUADNODE *src2);

#endif
