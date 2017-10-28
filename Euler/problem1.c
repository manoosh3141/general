#include<stdio.h>

int main(void)
{
	int sum = 0, number;
	
	for (number = 0; number < 10; number++)
	{
		if ((number%3 == 0) || (number%5 == 0))
			sum += number;
	}
	
	printf("%d\n", sum);
	return 0;
}