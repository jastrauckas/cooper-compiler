#include "lexer.h"

/* used for symbol table entries */
typedef struct tableCell
{
	// hash the IDENT name
	char *name; 
	// separate chaining -> double linked list
	tableCell *nextCell;
	tableCell *prevCell;
	// copy yylval in here so we have the info 
	YYSTYPE value;
} TABLECELL;
