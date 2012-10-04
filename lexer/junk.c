#include <stdio.h>
#include <stdlib.h>

enum
{
	one = 1, two, three, four
};

int n;
double dec = .98;
char *ostr = "0124";
char *dstr = "124";
char c = 'abcdef';
int main()
{
	printf("The number two is %d\n", two);
	printf("Decimal value is: %f\n", dec);	
	printf("atoi(ostr): %d\n", atoi(ostr));
	printf("atoi(dstr): %d\n", atoi(dstr));
	printf("0124 const: %d\n", 0124);
	printf("'abc' is %c\n", c);

	char *end;
	char *intstr = "234uL";
	long lnum = strtol(intstr, &end, 10);
	printf("part of intstr that was not parsed: %s\n", end);

	char *s1 = "ul";
	char *s2 = "lu";
	n = strcmp(s1, s2);
	printf("strcmp of %s and %s = %d\n", s1, s2, n);

	char *c1 = "\a\b\f\n\r\t\v\0";
	int i;
	for (i=0; i<8; i++)
	{
		printf("%d\n", (int)(c1[i]));
	}
}
