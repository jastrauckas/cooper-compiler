#include <stdio.h>
#include "symTable.h"
#include "lexer.h"

main()
{
	printf("Creating a new symbol table...\n");
	SYMTABLE t;
	YYSTYPE yylval; // only one of these! make sure deep copies work
	char *varname;
	// should create a hash table of initial size 4
	init_table(&t, 4);
	
	// put some stuff in
	printf("inserting items...\n");
	varname = "thing1";
	yylval.metadata.tokname = "CHARLIT";
	ins_table(&t, varname, yylval);

	varname = "thing2";
	yylval.metadata.tokname = "NUMBER";
	ins_table(&t, varname, yylval);
		
    // check that it's there
	write_table(&t);

	printf("adding another item, should cause both collision and resize\n");	
	varname = "1thing"; // collision!
	yylval.metadata.tokname = "STRLIT";
	ins_table(&t, varname, yylval);

    printf("writing new table...\n");
	write_table(&t);
}
