# include<stdio.h>

int main(void)
{
	int sum = 0, number;
	for (number = 1; number <= 100; sum += (number++))
	printf("sum: %d\n", sum); 
	return 0;
}