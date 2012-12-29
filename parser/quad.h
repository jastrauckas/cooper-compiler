#ifndef QUADH
#define QUADH

#include "symTable.h"

// for now, assume the only constants are integers!
typedef struct quad_node {
	int val;
	char *name;
} QUADNODE;

typedef struct quad {
	int opcode;
	QUADNODE *result;
	QUADNODE *arg1;
	QUADNODE *arg2;
} QUAD;

#endif
