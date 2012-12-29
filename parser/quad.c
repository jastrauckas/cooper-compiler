#include "quad.h"

QUAD *build_quad(int opcode, QUADNODE *src1, QUADNODE *src2)
{
	QUAD *q = malloc(sizeof(QUAD));
	q->opcode = opcode;
	q->src1 = src1;
	q->src2 = src2;
	q->name = NULL; // fill in later with variable ident if applicable
	q->dest = new_quad_node(char *name);
	return q;
}

QUADNODE *new_quad_node(char *name) 
{
	QUADNODE *qn = malloc(sizeof(QUADNODE));
	qn->id = temp_id++;
	qn->name = name;
	qn->is_constant = 0; // change when assigining a value!
	return qn;
}

