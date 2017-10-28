#include "trig.h"

int getInput(void)
{
	while (1)
	{
		printf("Please input request (h-help, q-quit): ");

		// Take input from the user	
		char userInput[BUFFER_SIZE];	
		fgets(userInput, BUFFER_SIZE, stdin);
		
		// Get input length
		int inputLength = strlen(userInput);
		
		// make lower case
		for (int i = 0; i < inputLength; i++)
		{
			userInput[i] = tolower(userInput[i]);
		}

		// If the user requests help or quit command (only single input + null character)
		if (inputLength == 2)
		{
			if( userInput[0] == 'q' ) /* If user wants to quit */
			{
				return 0;
			}
			else if (userInput[0] == 'h') /* If user wants to see help options */
			{
				// Print help statemet
				help();

				// go to the start of the loop
				continue;

			}
		}

		// Check for a valid input
		if (checkInput(userInput) == 1)
		{
			error();
			continue;
		}

		// Define our variables to write to
		char string[] = ""; /* Define as empty string so when trig is run again we overwrite the previous string */
		double startValue, finalValue, intermediateRows;

		// If the user inputs a string first
		if (isalpha(userInput[0]))
		{
			sscanf(userInput, "%s %lf %lf %lf", string, &startValue, &finalValue, &intermediateRows);
		}
		// Otherwise the user has just inputted 3 numbers
		else
		{
			sscanf(userInput, "%lf %lf %lf", &startValue, &finalValue, &intermediateRows);
		}

		// Send data to trig.c to be processed
		trig(string, startValue, finalValue, intermediateRows);
	}
	return 0;
}