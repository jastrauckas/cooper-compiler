%s STR
%s ESC
%s CHL
%option noyywrap
%{
	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include "lexer.h"
	#include "hw2.tab.h"
	extern YYSTYPE yylval;
	int buf[2048]; 
	char minibuf[128];
	char *end; 
	int n, overflow, bptr=0;
	char *fname = "<stdin>";
	long l;
	long long ll;
	long double ld;
	int last_tok;

	// why won't these work in the header file...?
	char *int_type = "INT";
	char *long_type = "LONG";
	char *longlong_type = "LONGLONG";
	char *float_type = "FLOAT";
	char *double_type = "DOUBLE";
	char *longdouble_type = "LONGDOUBLE";

%}

delim 		[ \t\n]
ws 			{delim}+
letter		[A-Za-z]
digit		[0-9]
nondigit	[_A-Za-z]
octdig		[0-7]
octseq		{octdig}{1,3}
hexdig		[0-9A-Fa-f]
hexseq		{hexdig}+
special		['"?\\]
cnormal 	[^\'\\\n]
snormal 	[^\"\\\n]
escape 		[abfnrtv0]
ident 		{nondigit}({nondigit}|{digit})*
lsuf		[lL]|(ll)|(LL)
usuf		[uU]
intsuf		({lsuf}?{usuf}?)|({usuf}?{lsuf}?)
decint		[1-9]{digit}*{intsuf}
octint		0{octdig}*{intsuf}
hexint		((0x)|(0X)){hexdig}+{intsuf}?
sign		[+-]
floatsuf	[fFlL]
exp 		[eE]{sign}?{digit}+
bexp		[pP]{sign}?{digit}+
fract		({digit}*[.]{digit}+)|({digit}+[.])
hexfract	({hexdig}*[.]{hexdig}+)|({hexdig}+[.])
decfloat	({fract}{exp}?{floatsuf}?)|({digit}+{exp}{floatsuf}?)
hexfloat    ((0x)|(0X))(({hexfract}{bexp}{floatsuf}+)|({hexdig}+{bexp}{floatsuf}?))
filedir		[#][ ][0-9]+[ ]["].+["]
fallback	.

%%
<INITIAL>"\"" 		{BEGIN(STR); bptr=0;}
<INITIAL>"L\"" 		{BEGIN(STR); bptr=0;}
<INITIAL>"\'"		{BEGIN(CHL); bptr=0; overflow=0;}
<INITIAL>"L\'"		{BEGIN(CHL); bptr=0; overflow=0;}
<CHL>"\'"			{
						if (overflow)	
							fprintf(stderr, "%s:%d: warning: Unsupported multibyte character literal truncated to last byte\n", minibuf, line);
						BEGIN(INITIAL); 
						yylval.char_literal = buf[0];
						return CHARLIT;
					}
<STR>"\"" 			{
						BEGIN(INITIAL); 
						buf[bptr] = '\0';
						yylval.string_literal = buf;
						return STRING;
					}
<STR>\\{escape}		{
						switch (yytext[1])
						{
							case('a'):
								buf[bptr] = (int) '\a';	break;							
							case('b'):
								buf[bptr] = (int) '\b'; break;							
							case('f'):
								buf[bptr] = (int) '\f';	break;								
							case('n'):
								buf[bptr] = (int) '\n';	break;								
							case('r'):
								buf[bptr] = (int) '\r';	break;								
							case('t'):
								buf[bptr] = (int) '\t';	break;
							case('v'):
								buf[bptr] = (int) '\v';	break;								
							case('0'):
								buf[bptr] = (int) '\0';	break;
							default:
								buf[bptr] = (int) 'x'; // should not happen
						}
						bptr++;
					}
<STR>\\{special}	{
						buf[bptr] = (int) yytext[1];
						bptr++;
					}
<STR>\\{octseq}		{
						n = (int) strtol(yytext+1, &end, 8);
						buf[bptr] = n;
						bptr++;
					}
<STR>\\x{hexseq}	{
						n = (int) strtol(yytext+2, &end, 16);
						buf[bptr] = (n<256) ? n : 255;
						if (n > 255)
							fprintf(stderr, "%s:%d: warning: Hex escape sequence %s out of range\n", minibuf, line, yytext);
						bptr++;
					}
<STR>{snormal}+ 	{
						int i, chars= strlen(yytext);
						for (i=0; i<chars; i++)
						{
							buf[bptr] = (int) yytext[i];
							bptr++;
						}
					}
<STR>\n				{BEGIN(INITIAL); return ERRS;}

<CHL>\\{escape}     {
						if (bptr!=0)
							overflow = 1;
						bptr=0;
						switch (yytext[1])
						{
							case('a'):
								buf[bptr] = (int) '\a';	break;							
							case('b'):
								buf[bptr] = (int) '\b'; break;							
							case('f'):
								buf[bptr] = (int) '\f';	break;								
							case('n'):
								buf[bptr] = (int) '\n';	break;								
							case('r'):
								buf[bptr] = (int) '\r';	break;								
							case('t'):
								buf[bptr] = (int) '\t';	break;
							case('v'):
								buf[bptr] = (int) '\v';	break;								
							case('0'):
								buf[bptr] = (int) '\0';	break;
						}
					}
<CHL>\\{special}   	{
						if (bptr!=0)
							overflow = 1;
						bptr=0; 
						buf[bptr] = (int) yytext[1];
					}
<CHL>\\{octseq}		{
						if (bptr!=0)
							overflow = 1;
						bptr = 0;
						n = (int) strtol(yytext+1, &end, 8);
						buf[bptr] = n;
					}
<CHL>\\x{hexseq}	{
						if (bptr!=0)
							overflow = 1;
						bptr = 0;
						n = (int) strtol(yytext+2, &end, 16);
						buf[bptr] = (n<256) ? n : 255;
						if (n > 255)
							fprintf(stderr, "%s:%d: warning: Hex escape sequence %s out of range\n", minibuf, line, yytext);
					}
<CHL>{cnormal}+ 	{
						if (strlen(yytext) > 1)
							overflow = 1;
						int l = strlen(yytext);
						bptr = 0; 
						buf[bptr] = (int) yytext[l-1]; 
					}
<CHL>\n			{BEGIN(INITIAL); return ERRC;}

{decint}	{
				yylval.metadata.tokname = "NUMBER";
				yylval.metadata.num_class = INT_CLASS; 
				ll = strtoll(yytext, &end, 10);
				yylval.int_val = ll;
				yylval.has_val = 1;
				set_int_type(end, &yylval.metadata);
				return(NUMBER);
			}
{octint}	{
				yylval.metadata.tokname="NUMBER"; 
				yylval.metadata.num_class = INT_CLASS; 
				ll = strtoll(yytext, &end, 8);
				yylval.int_val = ll;
				yylval.has_val = 1;
				set_int_type(end, &yylval.metadata);
				return(NUMBER);
			}
{hexint}    {
				yylval.metadata.tokname="NUMBER"; 
				yylval.metadata.num_class = INT_CLASS; 
				ll = strtoll(yytext+2, &end, 16);
				yylval.int_val = ll;
				yylval.has_val = 1;
				set_int_type(end, &yylval.metadata);
				return(NUMBER);
			}
{decfloat}	{
				yylval.metadata.tokname="NUMBER";
				yylval.metadata.num_class = REAL_CLASS;
				ld = strtold(yytext, &end);
				yylval.double_val = ld;
				yylval.has_val = 1;
				set_double_type(end, &yylval.metadata);
				return(NUMBER);
			}

{hexfloat}	{
				yylval.metadata.tokname="NUMBER";
				yylval.metadata.num_class = REAL_CLASS;
				ld = strtold(yytext, &end);
				yylval.double_val = ld;
				yylval.has_val = 1;
				set_double_type(end, &yylval.metadata);
				return(NUMBER);
			}

\n			{line++;}
\040		{;}
\t			{;}

auto		{yylval.metadata.tokname="AUTO"; return(AUTO);}
break		{yylval.metadata.tokname="BREAK"; return(BREAK);}
case 		{yylval.metadata.tokname="CASE"; return(CASE);}
char 		{yylval.metadata.tokname="CHAR"; return(CHAR);}
const 		{yylval.metadata.tokname="CONST"; return(CONST);}
continue 	{yylval.metadata.tokname="CONTINUE"; return(CONTINUE);}
default 	{yylval.metadata.tokname="DEFAULT"; return(DEFAULT);}
do 			{yylval.metadata.tokname="DO"; return(DO);}
double 		{yylval.metadata.tokname="DOUBLE"; return(DOUBLE);}
else 		{yylval.metadata.tokname="ELSE"; return(ELSE);}
enum 		{yylval.metadata.tokname="ENUM"; return(ENUM);}
extern 		{yylval.metadata.tokname="EXTERN"; return(EXTERN);}
float 		{yylval.metadata.tokname="FLOAT"; return(FLOAT);}
for 		{yylval.metadata.tokname="FOR"; return(FOR);}
goto 		{yylval.metadata.tokname="GOTO"; return(GOTO);}
if 			{yylval.metadata.tokname="IF"; return(IF);}
inline 		{yylval.metadata.tokname="INLINE"; return(INLINE);}
int 		{yylval.metadata.tokname="INT"; return(INT);}
long 		{yylval.metadata.tokname="LONG"; return(LONG);}
register 	{yylval.metadata.tokname="REGISTER"; return(REGISTER);}
restrict 	{yylval.metadata.tokname="RESTRICT"; return(RESTRICT);}
return 		{yylval.metadata.tokname="RETURN"; return(RETURN);}
short 		{yylval.metadata.tokname="SHORT"; return(SHORT);}
signed 		{yylval.metadata.tokname="SIGNED"; return(SIGNED);}
sizeof 		{yylval.metadata.tokname="SIZEOF"; return(SIZEOF);}
static 		{yylval.metadata.tokname="STATIC"; return(STATIC);}
struct 		{yylval.metadata.tokname="STRUCT"; return(STRUCT);}
switch 		{yylval.metadata.tokname="SWITCH"; return(SWITCH);}
typedef 	{yylval.metadata.tokname="TYPEDEF"; return(TYPEDEF);}
union 		{yylval.metadata.tokname="UNION"; return(UNION);}
unsigned 	{yylval.metadata.tokname="UNSIGNED"; return(UNSIGNED);}
void 		{yylval.metadata.tokname="VOID"; return(VOID);}
volatile 	{yylval.metadata.tokname="VOLATILE"; return(VOLATILE);}
while 		{yylval.metadata.tokname="WHILE"; return(WHILE);}
_Bool 		{yylval.metadata.tokname="_BOOL"; return(_BOOL);}
_Complex 	{yylval.metadata.tokname="_COMPLEX"; return(_COMPLEX);}
_Imaginary 	{yylval.metadata.tokname="_IMAGINARY"; return(_IMAGINARY);}
"["			{yylval.metadata.tokname="["; return('[');}
"]"			{yylval.metadata.tokname="]"; return(']');}
"("			{yylval.metadata.tokname="("; return('(');}
")"			{yylval.metadata.tokname=")"; return(')');}
"{" 		{yylval.metadata.tokname="{"; return('{');}
"}"			{yylval.metadata.tokname="}"; return('}');}
"."			{yylval.metadata.tokname="."; return('.');}
"&"			{yylval.metadata.tokname="&"; return('&');}
"*"			{yylval.metadata.tokname="*"; return('*');}
"+"			{yylval.metadata.tokname="+"; return('+');}
"-"			{yylval.metadata.tokname="-"; return('-');}
"~"			{yylval.metadata.tokname="~"; return('~');}
"!"			{yylval.metadata.tokname="!"; return('!');}
"/"			{yylval.metadata.tokname="/"; return('/');}
"%"			{yylval.metadata.tokname="%"; return('%');}
"<"			{yylval.metadata.tokname="<"; return('<');}
">"			{yylval.metadata.tokname=">"; return('>');}
"^"			{yylval.metadata.tokname="^"; return('^');}
"|"			{yylval.metadata.tokname="|"; return('|');}
"?"			{yylval.metadata.tokname="?"; return('?');}
":"			{yylval.metadata.tokname=":"; return(':');}
";"			{yylval.metadata.tokname=";"; return(';');}
"="			{yylval.metadata.tokname="="; return('=');}
","			{yylval.metadata.tokname=","; return(',');}
"#"			{yylval.metadata.tokname="#"; return('#');}
"->"		{yylval.metadata.tokname="INDSEL"; return(INDSEL);}
"++"		{yylval.metadata.tokname="PLUSPLUS"; return(PLUSPLUS);}
"--"		{yylval.metadata.tokname="MINUSMINUS"; return(MINUSMINUS);}
"<<"		{yylval.metadata.tokname="SHL"; return(SHL);}
">>"		{yylval.metadata.tokname="SHR"; return(SHR);}
"<="		{yylval.metadata.tokname="LTEQ"; return(LTEQ);}
">="		{yylval.metadata.tokname="GTEQ"; return(GTEQ);}
"=="		{yylval.metadata.tokname="EQEQ"; return(EQEQ);}
"!="		{yylval.metadata.tokname="NOTEQ"; return(NOTEQ);}
"&&"		{yylval.metadata.tokname="LOGAND"; return(LOGAND);}
"||"		{yylval.metadata.tokname="LOGOR"; return(LOGOR);}
"..."		{yylval.metadata.tokname="ELLIPSES"; return(ELLIPSES);}
"*="    	{yylval.metadata.tokname="TIMESEQ"; return(TIMESEQ);}
"/="		{yylval.metadata.tokname="DIVEQ"; return(DIVEQ);}
"%="		{yylval.metadata.tokname="MODEQ"; return(MODEQ);}
"+="		{yylval.metadata.tokname="PLUSEQ"; return(PLUSEQ);}
"-="		{yylval.metadata.tokname="MINUSEQ"; return(MINUSEQ);}
"<<="		{yylval.metadata.tokname="SHLEQ"; return(SHLEQ);}
">>="		{yylval.metadata.tokname="SHREQ"; return(SHREQ);}
"&="		{yylval.metadata.tokname="ANDEQ"; return(ANDEQ);}
"|="		{yylval.metadata.tokname="OREQ"; return(OREQ);}
"^="		{yylval.metadata.tokname="XOREQ"; return(XOREQ);}

{ident}		{
				yylval.metadata.tokname = "IDENT";
				yylval.ident_val = malloc(sizeof(char) * (strlen(yytext)+1)); 
				strcpy(yylval.ident_val, yytext);
				//yylval.ident_val = yytext;
				return(IDENT);
			}
{filedir} 	{
				sscanf(yytext, "# %d \"%[^\"]", &line, minibuf);
				line = 0; //printf("RESET\n");
				yylval.ident_val = malloc(sizeof(char)*(strlen(yytext)+1));
				strcpy(yylval.ident_val, minibuf);
				return FILEDIR;
			}

%%
/*
int main(int argc, char *argv)
{
        int tok, i;
        line = 1;
        while (tok=yylex())
        {
            //printf("TOK: %d\n", tok);
            printf("%s\t%d\t", minibuf, line);
            // case of keyword or puctuator 
            if (tok < 500)
            {
                printf("%s\n", yylval.metadata.tokname);
                continue;
            }
            // case of a token that has an associated value
            switch(tok)
            {
                case IDENT: printf("IDENT\t%s\n", yylval.ident_val); break;
                case STRING:
                    printf("STRING\t");
                    for (i=0; i<bptr; i++)
                    {
                        printchar(stdout, (int) yylval.string_literal[i]);
                    }
                    printf("\n");
                    break;
                case CHARLIT:
                    printf("CHARLIT\t");
                    printchar(stdout, yylval.char_literal);
                    printf("\n");
                    break;
                case NUMBER:
                    if (yylval.metadata.num_class == INT_CLASS)
                    {
                        printf("NUMBER\tINTEGER\t%lld\t", yylval.int_val);
                        if (!yylval.metadata.is_signed)
                            printf("UNSIGNED,");
                        printf("%s\n", yylval.metadata.num_type);
                    }
                    else
                    {
                        printf("NUMBER\tREAL\t%Lg\t%s\n", yylval.double_val, yylval.metadata.num_type);
                    }
                    break;
                case ERRC: fprintf(stderr, "%s:%d: error: newline encountered in character literal\n", minibuf, line); break;
                case ERRS: fprintf(stderr, "%s:%d: error: newline encountered in string token\n", minibuf, line); break;
            }
            last_tok = tok;
        }
        return 0;
}
*/

int printable(int n)
{
	if (n > 32 && n < 127 && !(n==34||n==39||n==92))
		return 1;
	return 0; 
}

void set_int_type(char *suf, MTYPE *m)
{
	char *u = "uU";
	if (strpbrk(suf, u))
		m->is_signed = 0;
	else
		m->is_signed = 1;
	// we can only have L or LL (or l or ll) left...
	int lcount = strlen(suf) + (m->is_signed) - 1;
	if (lcount == 2)
		m->num_type = longlong_type;
	else if (lcount == 1)
		m->num_type = long_type;
	else if (lcount == 0)
		m->num_type = int_type;
	else
		m->num_type = "SHIT";
	return;
}

void set_double_type(char *suf, MTYPE *m)
{
	if (!strlen(suf))
	{
		m->num_type = double_type;
		return;
	}
	char s = suf[0];
	if (s == 'l' || s == 'L')
	{
		m->num_type = longdouble_type;
		return;
	}
	m->num_type = float_type;
	return;

}

void printchar(FILE *f, int charcode)
{ 
    if (printable(charcode)) 
    { 
        fprintf(f, "%c", charcode); 
		return;
    }    
    switch (charcode) 
    { 
        case 7: 
            fprintf(f, "\\a"); break;
        case 8: 
            fprintf(f, "\\b"); break;
        case 12: 
            fprintf(f, "\\f"); break;
        case 10: 
            fprintf(f, "\\n"); break;
        case 13: 
            fprintf(f, "\\r"); break;
        case 9: 
            fprintf(f, "\\t"); break;
        case 11: 
            fprintf(f, "\\v"); break;
        case 0: 
            fprintf(f, "\\0"); break;
        case 34: 
            fprintf(f, "\\\""); break;
        case 39: 
            fprintf(f, "\\\'"); break;
        case 92: 
            fprintf(f, "\\\\"); break;
        default: 
            fprintf(f, "\\%03o", charcode); 
    } 
    return; 
}

