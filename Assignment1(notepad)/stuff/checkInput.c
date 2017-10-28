//Check input
#include<stdio.h>
#include<string.h>

int checkInput(char userInput[100])
{
	int inputLength = strlen(userInput);
	for( int i = 0; i < inputLength; i++ )
	{
		if( userInput[i] == ' ' )
		{
			//delimeterPositions[delimeterIndex++] = i;
			counter++;
		}
	}
	
	
	// ERROR CASE
	if( counter == 3 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}