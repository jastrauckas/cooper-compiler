// classes
enum {INT_CLASS, REAL_CLASS};

// types
char *int_type = "INT";
char *long_type = "LONG";
char *longlong_type = "LONGLONG";
char *float_type = "FLOAT";
char *double_type = "DOUBLE";
char *longdouble_type = "LONGDOUBLE";

typedef union 
{
	char *ident_val;
	// do these need to be ints to accomodate codes for wide characters?
	int char_literal;
	int *string_literal;
	float float_val;
	long double double_val;
	long long int int_val;
} YYSTYPE;

typedef struct Metatype
{
	char *tokname;
	int num_class;
	char *num_type;
	int is_signed;
} MTYPE;

MTYPE mval;
YYSTYPE yylval;

// helper functions
void set_int_type(char *suf, MTYPE *m);
void set_double_type(char *suf, MTYPE *m);
void printchar(FILE *f, int charcode);
		
