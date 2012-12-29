#include "quad.h"

QUAD *build_quad(int opcode, QUADNODE *src1, QUADNODE *src2)
{
	QUAD *q = malloc(sizeof(QUAD));
	q->opcode = opcode;
	q->src1 = src1;
	q->src2 = src2;
	q->dest = new_quad_node(NULL);
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

QUADBLOCKLIST *generate_quads(BLOCKLIST *list) 
{
	int s;
	int c=0;
	QUADLIST *qlist;
	QUADLIST *block_qlist;
	QUADBLOCK *qblock;
	QUADBLOCKLIST *quad_blocks = malloc(sizeof(QUADBLOCKLIST));
    BASICBLOCK *cur_b = list->head;
	LISTNODE *stmt;

    while (cur_b)
    {
        s = 0;
		block_qlist = malloc(sizeof(QUADLIST));
		qblock = new_quad_block(cur_b->id);
        stmt = cur_b->contents;
		printf("bb%d\n", cur_b->id);
        // loop through all AST's in this basic block
		while (stmt)
        {
            qlist = ast_to_quads(stmt->ast);
			block_qlist = merge_quad_lists(block_qlist, qlist);
			stmt = stmt->next;
        }
		// at end of basic block, wrap the quads in a block and add the
		// block to the main list
		qblock->quads = block_qlist;
		quad_blocks = add_quad_block(quad_blocks, qblock);

		/*
        if (cur_b->default_exit)
        {
            printf("Next block: BASIC BLOCK %d\n", cur_b->default_exit->id);
        } 
        if (cur_b->true_exit)
        {
            printf("If TRUE: BASIC BLOCK %d\n", cur_b->true_exit->id);
        } 
        if (cur_b->false_exit)
        {
            printf("If FALSE: BASIC BLOCK %d\n", cur_b->false_exit->id);
        }
		*/
        cur_b = cur_b->next;
    }
	return quad_blocks;
}

QUADLIST *ast_to_quads(TNODE *ast)
{
	QUADLIST *ql = malloc(sizeof(QUADLIST));
	return ql;
}

QUADLIST *merge_quad_lists(QUADLIST *ql1, QUADLIST *ql2)
{
	// check for uninitialized lists
	if (!ql1->head)
		return ql2;
	else if (!ql2->head)
		return ql1;
	// if both are initialized, merge them
	ql1->tail->next = ql2->head;
	ql2->head->prev = ql1->tail;
	ql1->tail = ql2->tail;
	return ql1;
}

QUADBLOCK *new_quad_block(int id) 
{
	QUADBLOCK *qb = malloc(sizeof(QUADBLOCK));
	qb->id = id;
	return qb;
}

QUADBLOCK *add_quads_to_block(QUADLIST *ql, QUADBLOCK *qb)
{
	if (!qb->quads)
	{
		qb->quads = ql;
		return qb;
	}
	qb->quads = merge_quad_lists(qb->quads, ql);
	return qb;
}

QUADBLOCKLIST *add_quad_block(QUADBLOCKLIST *qb_list, QUADBLOCK *qb)
{
	if (!qb_list->head)
	{
		qb_list->head = qb;
		qb_list->tail = qb;
		return qb_list;
	}
	qb_list->tail->next = qb;
	qb->prev = qb_list->tail;
	qb_list->tail = qb;
	return qb_list;
}


