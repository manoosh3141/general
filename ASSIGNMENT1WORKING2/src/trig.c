#include "trig.h"

int trig(char string[], double startValue, double finalValue, double intermediateRows)	
{
	// Default our logical operators to false (zero)
	int isSin = 0, isCos = 0, isTan = 0, isRadians = 0, isDegrees = 0;
	
	// Check the input string and assign boolean values to terms
	for (int i = 0; i < strlen(string); i++)
	{
		switch (string[i])
		{
			case 's':
				isSin = 1;
				break;
			case 'c':
				isCos = 1;
				break;
			case 't':
				isTan = 1;
				break;
			case 'r':
				isRadians = 1;
				break;
			case 'd':
				isDegrees = 1;
				break;
			default:
				break;
		}
	}
	
	// If neither radians or degrees are inputted we want to default to degrees
	if (isRadians == 0 && isDegrees == 0)
	{
		isDegrees = 1;
	}
	
	// If none of sin, cos and tan are selected we default to print all of them
	if (isSin == 0 && isCos == 0 && isTan == 0)
	{
		isSin = 1;
		isCos = 1;
		isTan = 1;
	}	
	
	// Print the appropriate header
	printHeader(isSin, isCos, isTan);
	
	// Define our intervals
	double radianInterval, degreeInterval;
	
	// Define our degrees and radians arrays
	int terms = intermediateRows + 2; /* The number of elements in each array, or the number of rows of numbers in our final output */
	double degrees[terms], radians[terms];
	
	// Define our angle arrays
	if (isRadians == 1)  /* If radians are inputted */
	{
		// Define the increment that radians or degrees increases by
		radianInterval = (finalValue - startValue) / (intermediateRows + 1);
		degreeInterval = rad2deg(radianInterval);
		
		// Define first and last terms
		radians[0] = startValue;
		radians[terms - 1] = finalValue;		
		degrees[0] = rad2deg(startValue);
		degrees[terms - 1] = rad2deg(finalValue);		 
	}
	else if (isDegrees == 1) /* If degrees are inputted */
	{
		// Define the increment that radians or degrees increases by
		degreeInterval = (finalValue - startValue) / (intermediateRows + 1);
		radianInterval = deg2rad(degreeInterval);
		
		// Define first and last term
		degrees[0] = startValue;
		degrees[terms - 1] = finalValue;
		radians[0] = deg2rad(startValue);
		radians[terms - 1] = deg2rad(finalValue);		
	}
	
	// Define the inner terms of our degrees and radians arrays
	for (int i = 1; i < terms - 1; i++)
	{
		degrees[i] = degrees[i-1] + degreeInterval;
		radians[i] = radians[i-1] + radianInterval;
	}
	
	//Calculate sine cosine and tan arrays
	double sinArray[terms], cosArray[terms], tanArray[terms];
	for (int i = 0; i < terms; i ++)
	{
		sinArray[i] = sin(radians[i]);
		cosArray[i] = cos(radians[i]);
		tanArray[i] = tan(radians[i]);
	}
	
	// Go through all the arrays
	for (int i = 0; i < terms; i++)
	{
		// Print degrees and radians
		printf("\n%10.3lf%10.3lf", degrees[i], radians[i]);
		
		// Print sin, cos and tan arrays where appropriate
		if(isSin)
		{
			printf("%10.3lf", sinArray[i]);
		}
		if(isCos)
		{
			printf("%10.3lf", cosArray[i]);
		}
		if(isTan)
		{
			// We need to print "N/A" when tan is undefined.  This occurs at 90 +- 180n.
			// Subsequently it will be undefined when Angle%90 == 0 and Angle%180 != 0
			double undefinedTan = 90, definedTan = 180, ZERO = 0;
			if(fmod(degrees[i], undefinedTan) == 0 && fmod(degrees[i], definedTan) != ZERO) /* We us fmod as '%' does not work for double types */
			{
				printf("%10s", "N/A");
			}
			else
			{
				printf("%10.3lf", tanArray[i]);
			}
		}	
	}
	printf("\n\n");
	
	return 0;
}

void help(void)
{
	// Define a integer to store the ASCII of a character
	int character;
	
	// Assign file a pointer
	FILE *fpointer;
	
	// Opens the help file assigning it to a pointer, (read only)
	fpointer = fopen("src/help.txt", "r");
	
	// Go through the file character by character until the end of file (EOF) character
	while ((character = getc(fpointer)) != EOF)
	{
		// Print the character
        printf("%c",character);
	}
	
	// Close the file
	fclose(fpointer);
}

void printHeader(int isSin, int isCos, int isTan)
{
	printf("\n");
	printf("%10s", "Degrees");  /* 10 space columns */
	printf("%10s", "Radians");
	if (isSin == 1)
	{
		printf("%10s", "Sin");
	}
	if (isCos == 1)
	{
		printf("%10s", "Cos");
	}
	if (isTan == 1)
	{
		printf("%10s", "Tan");
	}
	printf("\n");
}

// Function to calculate radians from degrees
double rad2deg(double rad)
{
	double deg = rad*180/PI;
	return deg;
}

// Function to calculate degrees from radians
double deg2rad(double deg)
{
	double rad = deg*PI/180;
	return rad;
}

// Our error function
int error(void)
{
	printf("\nError: Illegal input!\n\n");
	return 0;
}