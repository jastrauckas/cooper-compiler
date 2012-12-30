#include "quad.h"

QUADLIST *cur_quad_list;

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
	QUADNODE *qn = calloc(1, sizeof(QUADNODE));
	qn->name = name;
	if (!name)
	{
		qn->id = temp_id++;
	}
	else
	{
		qn->id = -1;
	}
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
		//printf("bb%d\n", cur_b->id);
        // loop through all AST's in this basic block
		while (stmt)
        {
			cur_quad_list = malloc(sizeof(QUADLIST));
            ast_to_quads(stmt->ast);
			qlist = cur_quad_list;
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

QUADNODE *ast_to_quads(TNODE *ast)
{
	QUAD *q;
	QUADNODE *s1;
	QUADNODE *s2;
	switch(ast->node_type)
	{
		case UNOP:
			//printf("UNOP\n");
			s1 = ast_to_quads(ast->c1);
			q = build_quad(ast->op, s1, NULL);
			cur_quad_list = insert_quad(cur_quad_list, q);
			return q->dest;
			break;			
		case BINOP:
			//printf("BINOP\n");
			if (ast->op == '=')
			{
				s1 = ast_to_quads(ast->c2);
				q = build_quad(ast->op, s1, NULL);
				q->dest = ast_to_quads(ast->c1);
			}
			else
			{
				s1 = ast_to_quads(ast->c1);
				s2 = ast_to_quads(ast->c2);
				q = build_quad(ast->op, s1, s2);
			}
			cur_quad_list = insert_quad(cur_quad_list, q);
			return q->dest;
			break;			
		case CONST_NODE:
			//printf("CONST\n");
			s1 = new_quad_node(NULL);
			s1->is_constant = 1;
			s1->val = (int) ast->value.int_val;
			return s1;
		case VAR_NODE:
			//printf("VAR\n");
			s1 = new_quad_node(ast->name);	
			return s1;
		case SCALAR_NODE:
			// this is like a type, so ignore it is we are 
			// assuming ints
			//printf("TYPE\n");
			s1 = ast_to_quads(ast->c1);
		default:
			//printf("OTHER\n");
			if (ast->c1) 
				s1 = ast_to_quads(ast->c1);
			else
				s1 = malloc(sizeof(QUADNODE));
			return s1;
	}
}

QUADLIST *insert_quad(QUADLIST *ql, QUAD *q)
{
	if (!ql->head)
	{
		ql->head = q;
		ql->tail = q;
		return ql;
	}
	ql->tail->next = q;
	q->prev = ql->tail;
	ql->tail = q;
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

void output_quads(QUADBLOCKLIST *qb_list)
{
	QUADBLOCK *cur_block;
	QUADLIST *ql;
	QUAD *q;
	cur_block = qb_list->head;
	while (cur_block)
	{
		printf("bb%d:\n", cur_block->id);
		ql = cur_block->quads;
		q = ql->head;
		while(q)
		{
			print_quad(q);
			q = q->next;
		}
		cur_block = cur_block->next;
	}
	
}

void print_quad(QUAD *q)
{
	if (!q)
		return;
	printf("\t");
	if (q->dest) 
	{
		print_quad_node(q->dest);
		printf(" = ");
	}
	
	if (q->opcode >= 0 )
	{
		print_op(q->opcode);
	}
	
	if (q->src1)
	{
		print_quad_node(q->src1);
		printf(" ");
	}
	
	if (q->src2)
	{
		print_quad_node(q->src2);
	}
	printf("\n");
}

void print_quad_node(QUADNODE *qn)
{
	if (!qn)
		return;
	if (qn->is_constant)
	{
		printf("%d", qn->val);
		return;
	}
	if (qn->name)
		printf("%s", qn->name);
	else
		printf("%%T%d", qn->id);
}

void print_op(int op)
{
	switch (op)
	{
		case '+':
			printf("ADD ");
			break;
		case '-':
			printf("SUB ");
			break;
		case '*':
			printf("MUL ");
			break;
		case '/':
			printf("DIV ");
			break;
		case '=':
			printf("");
			break;
		default:
			printf("OP ");
	}
}
