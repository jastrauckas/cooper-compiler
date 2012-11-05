bison -d -v hw3.y
flex lexer.l 
gcc -g -c -o lex.out lex.yy.c 
gcc -g -o p hw3.tab.c lex.out -lm

