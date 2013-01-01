#include "quad.h"

char *cur_var_name;
int mode;
int ind;
QUADLIST *cur_quad_list;
QUADLIST *quad_stack; // put deferred quads here
BASICBLOCK *cur_b;

QUAD *build_quad(int opcode, QUADNODE *dest, QUADNODE *src1, QUADNODE *src2)
{
	QUAD *q = malloc(sizeof(QUAD));
	q->opcode = opcode;
	q->src1 = src1;
	q->src2 = src2;
	if (!dest)
	{
		dest = new_quad_node();
	}
	q->dest = dest;
	return q;
}

QUADNODE *new_quad_node_var(char *name) 
{
	QUADNODE *qn = calloc(1, sizeof(QUADNODE));
	qn->name = name;
	qn->id = -1;
	qn->is_constant = 0; // change when assigining a value!
	return qn;
}

QUADNODE *new_quad_node_const(int val)
{
	QUADNODE *qn = calloc(1, sizeof(QUADNODE));
	qn->is_constant = 1;
	qn->val = val;
	qn->name = NULL;
	qn->id = -1;
	return qn;
}

QUADNODE *new_quad_node()
{
	QUADNODE *qn = calloc(1, sizeof(QUADNODE));
	qn->is_constant = 0;
	qn->name = NULL;
	qn->id = temp_id++;
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
    cur_b = list->head;
	LISTNODE *stmt;

    while (cur_b)
    {
        s = 0;
		free(quad_stack);
		quad_stack = NULL;
		block_qlist = malloc(sizeof(QUADLIST));
		qblock = new_quad_block(cur_b->id);
        stmt = cur_b->contents;
		//printf("bb%d\n", cur_b->id);
        // loop through all AST's in this basic block
		while (stmt)
        {
			cur_quad_list = malloc(sizeof(QUADLIST));
            ast_to_quads(stmt->ast, LVAL);
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

QUAD *build_binop_quad(TNODE *ast, int side)
{
	QUAD *q;
	QUADNODE *s1, *s2;
	QUADNODE dummy;
	char *label1, *label2;
	int b1, b2;
	switch (ast->op)
	{
		case '=':
			if (ast->c1 && ast->c1->c1 && ast->c1->c1->node_type == ARRAY_NODE) 
			{
				q = build_quad(STORE_OP, &dummy, 
					ast_to_quads(ast->c2, RVAL), ast_to_quads(ast->c1, LVAL));
				q->dest = NULL;
			}
			else if (ast->c2 && ast->c2->c1 && ast->c2->c1->node_type == ARRAY_NODE) 
			{
				q = build_quad(LOAD_OP, ast_to_quads(ast->c1, LVAL), 
					ast_to_quads(ast->c2, RVAL), NULL);
			}
			else
			{
				s1 = ast_to_quads(ast->c2, RVAL);
        		q = build_quad(ast->op, ast_to_quads(ast->c1, LVAL), s1, NULL);
			}
			break;
		case '>':
			s1 = ast_to_quads(ast->c1, side);
			s2 = ast_to_quads(ast->c2, side);
			q = build_quad(CMP_OP, &dummy, s1, s2);	
			q->dest = NULL;
			cur_quad_list = insert_quad(cur_quad_list, q);
			label1 = calloc(32, sizeof(char));
			label2 = calloc(32, sizeof(char));
			b1 = 
			sprintf(label1, "bb%d", cur_b->true_exit->id); 
			sprintf(label2, "bb%d", cur_b->false_exit->id);
			s1 = new_quad_node_var(label1);
			s2 = new_quad_node_var(label2);
			q = build_quad(BRGT_OP, &dummy, s1, s2);
			q->dest = NULL; 
			break;
		case '<':
			s1 = ast_to_quads(ast->c1, side);
			s2 = ast_to_quads(ast->c2, side);
			q = build_quad(CMP_OP, &dummy, s1, s2);	
			q->dest = NULL;
			cur_quad_list = insert_quad(cur_quad_list, q);
			label1 = calloc(32, sizeof(char));
			label2 = calloc(32, sizeof(char));
			sprintf(label1, "bb%d", cur_b->true_exit->id); 
			sprintf(label2, "bb%d", cur_b->false_exit->id);
			s1 = new_quad_node_var(label1);
			s2 = new_quad_node_var(label2);
			q = build_quad(BRLT_OP, &dummy, s1, s2);
			q->dest = NULL; 
			break;
		default:
			s1 = ast_to_quads(ast->c1, side);
			s2 = ast_to_quads(ast->c2, side);
			q = build_quad(ast->op, NULL, s1, s2);
			break;
	}
	return q;
}

QUAD *build_unop_quad(TNODE *ast, int side)
{
	QUAD *q;
	QUADNODE *s1;
	switch (ast->op)
	{	
		case '*':
			// need to be able to distinguish between a pointer
			// and multiplication later on
			s1 = ast_to_quads(ast->c1, side);
			if (side == RVAL) 
				q = build_quad(LOAD_OP, NULL, s1, NULL);
			else
				q = build_quad(PRE_STORE_OP, NULL, s1, NULL);
				return q;
			break;
		default:
			s1 = ast_to_quads(ast->c1, side);
			q = build_quad(ast->op, NULL, s1, NULL);
	}
	return q;
}

QUADNODE *ast_to_quads(TNODE *ast, int side)
{
	QUAD *q;
	QUADNODE *s1, *s2, *d1, *d2;
	switch(ast->node_type)
	{
		case UNOP:
			//printf("UNOP with opcode %d\n", ast->op);
			q = build_unop_quad(ast, side);
			cur_quad_list = insert_quad(cur_quad_list, q);
			return q->dest;
			break;			
		case BINOP:
			//printf("BINOP with types %d %d\n", ast->c1->c1->node_type, ast->c2->node_type);
			q = build_binop_quad(ast, side);
			cur_quad_list = insert_quad(cur_quad_list, q);
			return q->dest;
			break;
		case PTR_NODE:
			// I have some redundant info here in the AST (so skip)
			s1 = ast_to_quads(ast->c1, side);
			return s1;
			break;
		case CONST_NODE:
			//printf("CONST\n");
			s1 = new_quad_node_const((int) ast->value.int_val);
			return s1;
		case VAR_NODE:
			//printf("VAR\n");
			cur_var_name = ast->name;
			s1 = new_quad_node_var(ast->name);	
			return s1;
			break;
		case SCALAR_NODE:
			//printf("SCALAR with value %d\n", ast->index);
			// this is like a type, so ignore (assume ints) 
			ind = ast->index;
			s1 = ast_to_quads(ast->c1, side);
			return s1;
			break;
		
		case ARRAY_NODE:
			//printf("ARRAY (type is %d)\n", ast->node_type);
			s1 = ast_to_quads(ast->c1, side);
			// load address of array
			q = build_quad(LEA_OP, NULL, s1, NULL);
			d1 = q->dest;
			cur_quad_list = insert_quad(cur_quad_list, q);
			// mutiply the size of int (4) by the element index
			q = build_quad('*', NULL, new_quad_node_const(4), 
					new_quad_node_const(ind));
			d2 = q->dest;
			cur_quad_list = insert_quad(cur_quad_list, q);
			// add that value to the base address
			q = build_quad('+', NULL, d1, d2); 
			cur_quad_list = insert_quad(cur_quad_list, q);
			return q->dest;
			break;
		default:
			//printf("OTHER\n");
			if (ast->c1) 
				s1 = ast_to_quads(ast->c1, side);
			else
				s1 = NULL;
			return s1;
	}
}

QUAD *pop_quad(QUADLIST *ql)
{
	if (!ql)
		return NULL;
	QUAD *q;
	if (ql->tail) 
	{
		q = ql->tail;
		ql->tail = ql->tail->prev;
		if (ql->tail)
			ql->tail->next = NULL;
		else	
		{
			ql->head = NULL;
			ql->tail = NULL;
		}
		return q;
	}
	else
	{
		return NULL;
	}
}

QUADLIST *insert_quad(QUADLIST *ql, QUAD *q)
{
	if (!q)
	{
		return ql;
	}
	if (!ql)
	{
		ql = malloc(sizeof(QUADLIST));
		ql->head = q;
		ql->tail = q;
		return ql;
	}
	if (!ql->head)
	{
		ql->head = q;
		ql->tail = q;
		return ql;
	}
	q->prev = ql->tail;
	if (ql->tail) 
		{ql->tail->next = q;}
	else
		{ql->head = q;}
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
	QUAD *stashed;
	cur_block = qb_list->head;
	while (cur_block)
	{
		printf("bb%d:\n", cur_block->id);
		ql = cur_block->quads;
		q = ql->head;
		while(q)
		{
			// pop off stack if applicable
			stashed = pop_quad(quad_stack);
			print_quad(q);
			if (stashed)
				print_quad(stashed);
			q = q->next;
		}
		cur_block = cur_block->next;
	}
	
}


void print_quad(QUAD *q)
{
	QUADNODE *temp;
	QUAD *copy;
	QUADNODE dummy;
	if (!q)
		return;
	// put some hacks in place for the store instruction
	// need to reverse both order of args and order fo quads
	if (q->opcode == PRE_STORE_OP)
	{
		//printf("ADDING TO STACK\n");
		//temp = q->dest;
		//q->dest = q->src1;
		//q->src1 = temp;
		q->src2 = q->dest;
		copy = build_quad(STORE_OP, &dummy, q->src1, q->src2);
		q->dest = NULL;
		copy->dest = NULL;
		quad_stack = insert_quad(quad_stack, copy);
		return;	
	}
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
		case LOAD_OP:
			printf("LOAD ");
			break;
		case STORE_OP:
			printf("STORE ");
			break;
		case LEA_OP:
			printf("LEA ");
			break;
		case CMP_OP:
			printf("CMP ");
			break;
		case BRGT_OP:
			printf("BRGT ");
			break;
		case BRLT_OP:
			printf("BRLT ");
			break;
		default:
			printf("OP ");
	}
}
