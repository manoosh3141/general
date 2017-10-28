#include <stdio.h>

int main(void)
{
	char yourname[100];
	printf("What’s your name?\t");
	scanf("%s",yourname);
	printf("Greetings, %s\n", yourname);
	return 0;
}