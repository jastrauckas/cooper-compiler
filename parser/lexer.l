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
	extern MTYPE mval;
	int buf[2048]; 
	char minibuf[128];
	char *end; 
	int n, line, overflow, bptr=0;
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
				mval.tokname = "NUMBER";
				mval.num_class = INT_CLASS; 
				ll = strtoll(yytext, &end, 10);
				yylval.int_val = ll;
				set_int_type(end, &mval);
				return(NUMBER);
			}
{octint}	{
				mval.tokname="NUMBER"; 
				mval.num_class = INT_CLASS; 
				ll = strtoll(yytext, &end, 8);
				yylval.int_val = ll;
				set_int_type(end, &mval);
				return(NUMBER);
			}
{hexint}    {
				mval.tokname="NUMBER"; 
				mval.num_class = INT_CLASS; 
				ll = strtoll(yytext+2, &end, 16);
				yylval.int_val = ll;
				set_int_type(end, &mval);
				return(NUMBER);
			}
{decfloat}	{
				mval.tokname="NUMBER";
				mval.num_class = REAL_CLASS;
				ld = strtold(yytext, &end);
				yylval.double_val = ld;
				set_double_type(end, &mval);
				return(NUMBER);
			}

{hexfloat}	{
				mval.tokname="NUMBER";
				mval.num_class = REAL_CLASS;
				ld = strtold(yytext, &end);
				yylval.double_val = ld;
				set_double_type(end, &mval);
				return(NUMBER);
			}

\n			{line++;}
auto		{mval.tokname="AUTO"; return(AUTO);}
break		{mval.tokname="BREAK"; return(BREAK);}
case 		{mval.tokname="CASE"; return(CASE);}
char 		{mval.tokname="CHAR"; return(CHAR);}
const 		{mval.tokname="CONST"; return(CONST);}
continue 	{mval.tokname="CONTINUE"; return(CONTINUE);}
default 	{mval.tokname="DEFAULT"; return(DEFAULT);}
do 			{mval.tokname="DO"; return(DO);}
double 		{mval.tokname="DOUBLE"; return(DOUBLE);}
else 		{mval.tokname="ELSE"; return(ELSE);}
enum 		{mval.tokname="ENUM"; return(ENUM);}
extern 		{mval.tokname="EXTERN"; return(EXTERN);}
float 		{mval.tokname="FLOAT"; return(FLOAT);}
for 		{mval.tokname="FOR"; return(FOR);}
goto 		{mval.tokname="GOTO"; return(GOTO);}
if 			{mval.tokname="IF"; return(IF);}
inline 		{mval.tokname="INLINE"; return(INLINE);}
int 		{mval.tokname="INT"; return(INT);}
long 		{mval.tokname="LONG"; return(LONG);}
register 	{mval.tokname="REGISTER"; return(REGISTER);}
restrict 	{mval.tokname="RESTRICT"; return(RESTRICT);}
return 		{mval.tokname="RETURN"; return(RETURN);}
short 		{mval.tokname="SHORT"; return(SHORT);}
signed 		{mval.tokname="SIGNED"; return(SIGNED);}
sizeof 		{mval.tokname="SIZEOF"; return(SIZEOF);}
static 		{mval.tokname="STATIC"; return(STATIC);}
struct 		{mval.tokname="STRUCT"; return(STRUCT);}
switch 		{mval.tokname="SWITCH"; return(SWITCH);}
typedef 	{mval.tokname="TYPEDEF"; return(TYPEDEF);}
union 		{mval.tokname="UNION"; return(UNION);}
unsigned 	{mval.tokname="UNSIGNED"; return(UNSIGNED);}
void 		{mval.tokname="VOID"; return(VOID);}
volatile 	{mval.tokname="VOLATILE"; return(VOLATILE);}
while 		{mval.tokname="WHILE"; return(WHILE);}
_Bool 		{mval.tokname="_BOOL"; return(_BOOL);}
_Complex 	{mval.tokname="_COMPLEX"; return(_COMPLEX);}
_Imaginary 	{mval.tokname="_IMAGINARY"; return(_IMAGINARY);}
"["			{mval.tokname="["; return('[');}
"]"			{mval.tokname="]"; return(']');}
"("			{mval.tokname="("; return('(');}
")"			{mval.tokname=")"; return(')');}
"{" 		{mval.tokname="{"; return('{');}
"}"			{mval.tokname="}"; return('}');}
"."			{mval.tokname="."; return('.');}
"&"			{mval.tokname="&"; return('&');}
"*"			{mval.tokname="*"; return('*');}
"+"			{mval.tokname="+"; return('+');}
"-"			{mval.tokname="-"; return('-');}
"~"			{mval.tokname="~"; return('~');}
"!"			{mval.tokname="!"; return('!');}
"/"			{mval.tokname="/"; return('/');}
"%"			{mval.tokname="%"; return('%');}
"<"			{mval.tokname="<"; return('<');}
">"			{mval.tokname=">"; return('>');}
"^"			{mval.tokname="^"; return('^');}
"|"			{mval.tokname="|"; return('|');}
"?"			{mval.tokname="?"; return('?');}
":"			{mval.tokname=":"; return(':');}
";"			{mval.tokname=";"; return(';');}
"="			{mval.tokname="="; return('=');}
","			{mval.tokname=","; return(',');}
"#"			{mval.tokname="#"; return('#');}
"->"		{mval.tokname="INDSEL"; return(INDSEL);}
"++"		{mval.tokname="PLUSPLUS"; return(PLUSPLUS);}
"--"		{mval.tokname="MINUSMINUS"; return(MINUSMINUS);}
"<<"		{mval.tokname="SHL"; return(SHL);}
">>"		{mval.tokname="SHR"; return(SHR);}
"<="		{mval.tokname="LTEQ"; return(LTEQ);}
">="		{mval.tokname="GTEQ"; return(GTEQ);}
"=="		{mval.tokname="EQEQ"; return(EQEQ);}
"!="		{mval.tokname="NOTEQ"; return(NOTEQ);}
"&&"		{mval.tokname="LOGAND"; return(LOGAND);}
"||"		{mval.tokname="LOGOR"; return(LOGOR);}
"..."		{mval.tokname="ELLIPSES"; return(ELLIPSES);}
"*="    	{mval.tokname="TIMESEQ"; return(TIMESEQ);}
"/="		{mval.tokname="DIVEQ"; return(DIVEQ);}
"%="		{mval.tokname="MODEQ"; return(MODEQ);}
"+="		{mval.tokname="PLUSEQ"; return(PLUSEQ);}
"-="		{mval.tokname="MINUSEQ"; return(MINUSEQ);}
"<<="		{mval.tokname="SHLEQ"; return(SHLEQ);}
">>="		{mval.tokname="SHREQ"; return(SHREQ);}
"&="		{mval.tokname="ANDEQ"; return(ANDEQ);}
"|="		{mval.tokname="OREQ"; return(OREQ);}
"^="		{mval.tokname="XOREQ"; return(XOREQ);}

{ident}		{
				mval.tokname = "IDENT"; 
				yylval.ident_val = yytext;
				return(IDENT);
			}
{filedir} 	{
				sscanf(yytext, "# %d \"%[^\"]", &line, minibuf);
				line = 0; // reset following directive
			}

%%
/*
int main(int argc, char *argv)
{
        int tok, i;
        line = 0;
        while (tok=yylex())
        {
            //printf("TOK: %d\n", tok);
            printf("%s\t%d\t", minibuf, line);
            // case of keyword or puctuator 
            if (tok < 500)
            {
                printf("%s\n", mval.tokname);
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
                    if (mval.num_class == INT_CLASS)
                    {
                        printf("NUMBER\tINTEGER\t%lld\t", yylval.int_val);
                        if (!mval.is_signed)
                            printf("UNSIGNED,");
                        printf("%s\n", mval.num_type);
                    }
                    else
                    {
                        printf("NUMBER\tREAL\t%Lg\t%s\n", yylval.double_val, mval.num_type);
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

