#include <stdio.h>

int main(void)
{
	char name[100];
	
	printf("Insert name:\t");
	scanf("%s", name);
	printf("Your name: %s\n", name);
	return 0;
}