#include<stdio.h>

void addToArray(int *parray, int size)
{
	parray[0] = 45;
	printf("test%d\n", parray[0]);
}

int main(void)
{
	//int array[] = {1, 2, 3};
	//int *parray = array;
	//int size = sizeof(array)/sizeof(int);
	printf("HELLOO\n");
	//addToArray(parray, size);
	//printf("\n %d \n", array[0]);
	return 0;
}