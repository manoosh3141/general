#include "trig.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.1415926535897932384626433
#define BUFFER_SIZE 2048
#define MAX_STRING_LENGTH 100

int main(void)
{
	// Print welcome message and initial prompt
	printf("TRIG: the trigonometric calculator\n\n");

	// Take input from the user
	INPUT:
    printf("Please input request (h-help, q-quit): ");
	
    char userInput[BUFFER_SIZE];	
	fgets(userInput, BUFFER_SIZE, stdin);
	//char userInput[] = "asd 1234 45 6";	
	int inputLength = strlen(userInput);
	
	// Check for a valid input
	//int res = checkInput(userInput);
	
	// If the user requests help or quit command (only single input + null character)
	if( inputLength == 2 )
	{
		if( userInput[0] == 'q' )/* If user wants to quit */
		{
			return 0;
		}
		else if( userInput[0] == 'h' ) /* If user wants to see help options */
		{
			help();
			goto INPUT;
		}
	}
	
	char string[100];
	double lower, upper, intermediateRows;
	sscanf(userInput, "%s %lf %lf %lf", string, &lower, &upper, &intermediateRows);
		   
	// Send data to trig.c to be processed
	trig(string, lower, upper, intermediateRows);
	
	goto INPUT;
}
