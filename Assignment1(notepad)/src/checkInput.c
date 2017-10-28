#include "trig.h"

int checkInput(char *userInput)
{
	int primarySpaces = 3, secondarySpaces = 2; /* Defines a normal input with 3 spaces of an input without a string of 2 spaces */ 
	
	// Check the amount of spaces in the input
	int spaces = countSpaces(userInput);

	// Define strings for the input to be split in to
	char inputString[BUFFER_SIZE], startValueString[BUFFER_SIZE], finalValueString[BUFFER_SIZE], intermediateRowsString[BUFFER_SIZE];
	
	// If a normal (3 space input)
	if (spaces == primarySpaces)
	{
		// Split the input string into seperate strings to be processed differently
		sscanf(userInput, "%s %s %s %s", inputString, startValueString, finalValueString, intermediateRowsString);
		
		// If any of the checkInput<> sub functions return an error we want our entire checkInput function to return an error
		if ((checkInputString(inputString) || checkStartFinalValue(startValueString) || checkStartFinalValue(finalValueString) 
			 || checkIntermediateValue(intermediateRowsString)) == 1)
		{
			return 1; /* returning 1 causes an getInput() to run the error() function */
		}
	}
	
	// If a 2 space input
	else if (spaces == secondarySpaces)
	{
		// Split the input string into seperate strings to be processed differently
		sscanf(userInput, "%s %s %s", startValueString, finalValueString, intermediateRowsString);
		
		// If any of the checkInput<> sub functions return an error we want our entire checkInput function to return an error
		if ((checkStartFinalValue(startValueString) || checkStartFinalValue(finalValueString) || checkIntermediateValue(intermediateRowsString)) == 1)
		{
			return 1;
		}	
	}
	else /* If an abnormal number of spaces we must print an error */
	{
		return 1;
	}
	return 0;
}

// Function to check the first string, if it exists
int checkInputString(char *inputString)
{
	// Define valid characters
	char validCharacters[] = "stcdr";
	
	// Use a function to check if the characters are valid
	if (checkValidCharacters(validCharacters, inputString) == 1)
	{
		return 1;
	}
	
	// Define "boolean" checker for degrees and radians (to ensure both are not inputted)
	int isDegrees = 0, isRadians = 0;
	
	// Go through the string
	for (int i = 0; i < strlen(inputString); i++)
	{			
		// Check if radians or degrees are entered
		if (inputString[i] == 'r')
		{
			isRadians = 1;
		}
		else if (inputString[i] == 'd')
		{
			isDegrees = 1;
		}
		
		// If both are entered induce an error
		if (isRadians == 1 && isDegrees == 1)
		{
			return 1;
		}
	}
	
	// This block will check that no character are entered more than once
	for (int i = 0; i < strlen(validCharacters); i++) /* Go through valid characters */
	{
		int count = 0;
		
		// Go through characters in the string
		for (int j = 0; j < strlen(inputString); j++)
		{
			// If validCharacter is in the string increment the count
			if (validCharacters[i] == inputString [j])
			{
				count++;
			}
		}
		
		// Each input character should only be inputted once, otherwise 
		if (count > 1)
		{
			// Return an error
			return 1; 
		}
	}
	return 0;
}

// Function to check the startValue and finalValue inputs
int checkStartFinalValue(char *inputString)
{
	// Define the possible characters that can be in the string for it to be valid
	char validCharacters[] = "0123456789.-"; /* note: is a float so decimal point is legal */
	
	// Use a function to check if the characters are valid
	if (checkValidCharacters(validCharacters, inputString) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Function to check the string that defines how many intermediate rows there should be
int checkIntermediateValue(char *inputString)
{
	// The valid characters are all the integers
	char validCharacters[] = "0123456789"; /* only the integers are valid, we can not have a negative or decimal number of rows */
	
	// Use a function to check if the characters are valid
	if (checkValidCharacters(validCharacters, inputString) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int countSpaces(char string[])
{
	int length = strlen(string);
	int spaces = 0;
	
	// Go through the string and count the spaces
	for (int i = 0; i < length; i++)
	{
		if (string[i] == ' ')
		{
			spaces++;
		}
	}
	return spaces;
}

int checkValidCharacters(char *validCharacters, char *inputString)
{
	// Go through the string
	for (int i = 0; i < strlen(inputString); i++)
	{
		// Set boolean for to check if the character is valid
		int isValid = 0;
		
		// Go through valid characters
		for (int j = 0; j < strlen(validCharacters); j++)
		{
			// if the character is in the valid characters set isValid
			if (validCharacters[j] == inputString[i])
			{
				isValid = 1;
			}		
		}
		
		// Return an error if the character is not valid
		if (isValid == 0)
		{
			return 1;
		}
	}
	return 0;
}