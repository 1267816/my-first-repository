#include <stdio.h>
int main(void)
{
	char *s="Hello World";
	char *s2="Hello World";
	//s[0]='B';
	printf("s=%p\n",s);
	printf("s2=%p\n",s2);
	printf("Here!s[0]=%c\n",s[0]);
	
	return 0;
}