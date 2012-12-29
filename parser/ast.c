#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "symTable.h"
#include "parser.tab.h"

extern SYMTABLE *struct_table;
int block_id = 0;

// don't care if children are null
TNODE *new_tree(int op, TNODE *c1, TNODE *c2, TNODE *c3)
{
	TNODE *root = malloc(sizeof(TNODE));
	c1->p = root;
	if (!c2)
	{
		root->node_type = UNOP;
	}
	else if (!c3)
	{
		root->node_type = BINOP;
		c2->p = root;
	}
	else
	{
		root->node_type = TERNOP;
		c2->p = root;
		c3->p = root;
	}
	root->p = NULL;
	root->op = op;
	root->c1 = c1;
	root->c2 = c2;
	root->c3 = c3;
	return root;
}

TNODE *new_scalar_node(SCALAR value, int ntype)
{
	TNODE *leaf = malloc(sizeof(TNODE));
	leaf->op = -1; // if I want to, I can tell it's a leaf!
	leaf->node_type = ntype;
	memcpy(&leaf->value, &value, sizeof(SCALAR));
	return leaf;
}

TNODE *new_ident_node(char *ident, int ntype)
{
	TNODE *node = malloc(sizeof(TNODE));
	node->op = -1;
	node->node_type = ntype;
	memcpy(node->name, ident, 255);
	return node;
}

TNODE *new_node(int ntype)
{
	TNODE *node = malloc(sizeof(TNODE));
	node->op = -1;
	node->node_type = ntype;
	return node;
}

void print_tree(TNODE *t, int level)
{
	int i;
	char *name;
	int d;
	d  = get_depth(t, 0);
	
	switch(t->node_type)
	{
		case VAR:
			if (t->c1) {print_tree_invert(t->c1, level+1);}			
			if (t->c2) {print_tree_invert(t->c2, level+1);}			
			if (t->c3) {print_tree_invert(t->c3, level+1);}			
			for (i=0; i<level; i++)
			{
				printf("  ");
			}
			print_node(t);
			break;

		default:
			for (i=0; i<level; i++)
            {
                printf("  ");
            }
            print_node(t);
			if (t->c1) {print_tree(t->c1, level+1);}			
			if (t->c2) {print_tree(t->c2, level+1);}			
  			if (t->c3) {print_tree(t->c3, level+1);}			
	}
}

void print_tree_invert(TNODE *t, int level)
{
	if (!t)
	{
		fprintf(stderr, "No ast associated with yylval node\n");
		return;
	}
	int i;
	char *name;
	int d;
	d  = get_depth(t, 0);
	switch(t->node_type)
	{
		case UNOP:
		case BINOP:
		case TERNOP:
			for (i=0; i<level; i++)
            {
                printf("  ");
            }
            print_node(t);
			if (t->c1) {print_tree(t->c1, level+1);}			
			if (t->c2) {print_tree(t->c2, level+1);}			
  			if (t->c3) {print_tree(t->c3, level+1);}			
			break;
		
		default:
			if (t->c1) {print_tree_invert(t->c1, level+1);}			
			if (t->c2) {print_tree_invert(t->c2, level+1);}			
  			if (t->c3) {print_tree_invert(t->c3, level+1);}			
			for (i=0; i<d-1; i++)
			{
				printf("  ");
			}
			print_node(t);
	}
}

void print_node(TNODE *t)
{
	switch (t->node_type)
	{
		case VAR_NODE:
			printf("variable: %s\n", t->name);
			break;
		case FN_NODE:
			printf("function: %s returns \n", t->name);
			break;
		case ARRAY_NODE:
			printf("array of size %d of type\n", t->size);
			break;
		case PTR_NODE:
			printf("pointer to\n", t->size);
			break;
		case SCALAR_NODE:
			print_scalar(t);
			break;
		case CONST_NODE:
			if (t->field == REAL_FIELD)
				printf("real: %Lf\n", t->value.ld_val);
			else if (t->field == INT_FIELD)
				printf("int: %lld\n", t->value.int_val);
			break;
		case STRUCT_NODE:
			printf("struct %s ", t->name);
		 	TABLECELL *tcell = in_table(struct_table, t->name);
			if (tcell && tcell->members)
			{
				printf("defined at line %d with members: \n", tcell->def_line);
				write_table((SYMTABLE *)tcell->members);
			}		
			else
			{
				printf("(incomplete)\n");
			}
			break;
		case UNION_NODE:
			printf("union %s ", t->name);
		 	tcell = in_table(struct_table, t->name);
			if (tcell && tcell->members)
			{
				printf("defined at line %d with members: \n", tcell->def_line);
				write_table((SYMTABLE *)tcell->members);
			}		
			else
			{
				printf("(incomplete)\n");
			}
			break;
		case BINOP:
			print_binop(t);
			break;
		default:
			printf("unhandled Node Type %d\n", t->node_type);
	}
}

void print_binop(TNODE *t)
{
	int op = t->op;
	switch(op)
	{
		case '+':
			printf("+\n");
			break;
		case '-':
			printf("-\n");
			break;
		case '*':
			printf("*\n");
			break;
		case '/':
			printf("/\n");
			break;
		case '=':
			printf("=\n");
			break;
		case '>':
			printf(">\n");
			break;
		case '<':
			printf("<\n");
			break;
		case LTEQ:
			printf("<=\n");
			break;
		case GTEQ:
			printf(">=\n");
			break;
		default:
			printf("binary operation with operands\n");
		
	}
}

void print_scalar(TNODE *t)
{
	int base_type = 0;
	int short_type = 0;
	int long_type = 0;
	int invalid = 0;
	char type_str[1024];
	char *pos = &type_str[0];
	int bits = t->spec_bits;
	if ((bits & IS_VOID) == IS_VOID)
	{
		if ((bits | IS_VOID) != IS_VOID)
			invalid = 1;
		strncpy(pos, "void ", 5);
		pos += 5;
		base_type++;
	}
	if ((bits & IS_LONG) == IS_LONG)
	{
		strncpy(pos, "long ", 5);
		pos += 5;
		long_type = 1;
	}
	if ((bits & IS_SHORT) == IS_SHORT)
	{
		strncpy(pos, "short ", 6);
		pos += 6;
		short_type++;
		if (long_type)
		{
			invalid = 1;
		}
	}
	if ((bits & IS_INT) == IS_INT)
	{
		strncpy(pos, "int ", 4);
		pos += 4;
		base_type++;
	}
	if ((bits & IS_FLOAT) == IS_FLOAT)
	{
		strncpy(pos, "float ", 6);
		pos += 6;
		base_type++;
	}
	if ((bits & IS_DOUBLE) == IS_DOUBLE)
	{
		strncpy(pos, "double ", 7);
		pos += 7;
		base_type++;
	}
	if ((bits & IS_CHAR) == IS_CHAR)
	{
		strncpy(pos, "char ", 5);
		pos += 5;
		base_type++;
	}
	*pos = '\0';
	if (!base_type && !short_type && !long_type) 
		printf("unknown scalar\n");
	else if (base_type > 1)
		printf("invalid type: %s\n", type_str);
	else
		printf("%s\n", type_str);

}	

int get_depth(TNODE *t, int maxdepth)
{
	if (!t)
		return maxdepth;
	maxdepth++;
	int d1, d2, d3;
	d1 = get_depth(t->c1, maxdepth);
	d2 = get_depth(t->c2, maxdepth);
	d3 = get_depth(t->c3, maxdepth);
	if (d1 > maxdepth) {maxdepth = d1;}
	if (d2 > maxdepth) {maxdepth = d2;}
	if (d3 > maxdepth) {maxdepth = d3;}
	return maxdepth;
}


LISTNODE *add_list_node(LISTNODE *prev, LISTNODE *next, TNODE *ast)
{
	LISTNODE *ln = malloc(sizeof(LISTNODE));
	ln->prev = prev;
	ln->next = next;
	ln->ast = ast;
	if (next)
		next->prev = ln;
	if (prev)
		prev->next = ln;
	return ln;
}

LISTNODE *push_list_node(LISTNODE *head, TNODE *ast)
{
	LISTNODE *tail = head;
	
	if (!head)
	{	
		head = add_list_node(NULL, NULL, ast);
		tail = head;
		return head;
	}

	while(tail->next)
	{
		tail = tail->next;
	}
	LISTNODE *new = add_list_node(tail, NULL, ast);
	tail->next = new;
	new->prev = tail;
	return head;
}

void program_dump(BLOCKLIST *list)
{
	int s = 0;
	BASICBLOCK *cur_b = list->head;
	while (cur_b)
	{
		if (cur_b->contents)
			printf("***** BASIC BLOCK %d *****\n", cur_b->id);
		
		LISTNODE *stmt = cur_b->contents;
		s = 0;
		while (stmt)
		{
			printf("Statement %d:\n", ++s);
			print_tree_invert(stmt->ast, 0);
			stmt = stmt->next;
		}
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
		cur_b = cur_b->next;
	}
}

BASICBLOCK *new_block(LISTNODE *contents)
{
 	BASICBLOCK *b = malloc(sizeof(BASICBLOCK));
	b->contents = contents;
	b->id = block_id;
	block_id++;
	return b;
}

BLOCKLIST *init_block_list(LISTNODE *contents)
{
	BLOCKLIST *l = malloc(sizeof(BLOCKLIST));
	l->head = new_block(contents);
	l->tail = l->head;
	return l;
}

BLOCKLIST *push_new_block(BLOCKLIST *list, LISTNODE *contents)
{
	BASICBLOCK *b = new_block(contents);
	list->tail->next = b;
	b->prev = list->tail;
	list->tail = b;
	return list;
}


BASICBLOCK *push_ast_to_block(BASICBLOCK *head, TNODE *ast)
{
	if (!head)
	{
		head = new_block(NULL);
		head->contents = add_list_node(NULL, NULL, ast);
		return head;
	}
	head->contents = push_list_node(head->contents, ast);
	return head;
}


BLOCKLIST *merge_block_lists(BLOCKLIST *l1, BLOCKLIST *l2)
{
	BLOCKLIST *l3;
	l1->tail->next = l2->head;
	l2->head->prev = l1->tail;
	l3->head = l1->head;
	l3->tail = l2->tail;
	return l3;
}

BLOCKLIST *push_block(BLOCKLIST *list, BASICBLOCK *block)
{
	list->tail->next = block;
	block->prev = list->tail;
	block->next = NULL;
	list->tail = block;
	return list;
}

BLOCKLIST *pop_block(BLOCKLIST *list)
{
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	return list;
}

BASICBLOCK *peek_block(BLOCKLIST *list)
{
	return list->tail;	
}
