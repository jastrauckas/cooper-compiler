bison -d hw2.y
flex lexer.l 
gcc -c -o lex.out lex.yy.c 
gcc -o p hw2.tab.c lex.out

