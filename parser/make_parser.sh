bison -d -v parser.y
flex lexer.l 
gcc -g -c -o lex.out lex.yy.c 
gcc -g -o p parser.tab.c lex.out -lm

