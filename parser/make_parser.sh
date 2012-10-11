bison -v -d hw2.y
flex lexer.l 
gcc -g -c -o lex.out lex.yy.c 
gcc -g -o p hw2.tab.c lex.out -lm

