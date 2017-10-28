#include <stdio.h>

int main()
{
	int n, i, flag = 0;
	
	printf("Enter a positive integer: \t");
	
	// Read an integer
	scanf("%d", &n);
	
	// Go through all possible factors
	for(i=2; i<=n/2; ++i)
	{
		// If the number is prime
		if(n%i==0)
		{
			flag = 1;
			break;
		}
	}
	
	// Else the number is prime i.e.  flag is still 0
	if (flag==0)
		
		printf("%d is a prime number\n", n);
	else
		
		printf("%d is not a prime number\n", n);

	return 0;
	
}
