#include "trig.h"
#include<stdio.h>
#include<math.h>
#include<string.h>

#define PI 3.1415926535897932384626433

// double process()
int trig(char string[], double lower, double upper, double intermediateRows)	
{
	int isSin = 0, isCos = 0, isTan = 0, isRadians = 0, isDegrees = 0;
	
	// Check the input string and assign boolean values to terms
	for( int i = 0; i < strlen(string); i++)
	{
		switch(string[i])
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
				printf("\nInvlavid Input, press 'h' for help.\n");
				return 0;
				break;
		}
	}
	
	// Check if user has inputted both radians AND degrees or neither
	if( (isRadians == 0 && isDegrees == 0) || (isRadians == 1 && isDegrees == 1) )
	{
		printf("\nInvlavid Input, press 'h' for help.\n");
		return 0;
	}
	
	// Print the appropriate header
	printHeader(isSin, isCos, isTan);
	
	// Define our intervals
	double interval, radianInterval, degreeInterval;
	
	// Define our degrees and radians arrays
	int terms = intermediateRows + 2; /* The number of elements in each array, or the number of rows of numbers in our final output */
	double degrees[terms], radians[terms];
	
	// Calculate the interval we increase by	
	interval = (upper - lower) / (intermediateRows + 1);
	
	// Define our angle arrays
	if( isRadians == 1 )  /* If radians are inputted */
	{
		radianInterval = interval;
		degreeInterval = rad2deg(radianInterval);
		
		// Define first and last terms
		radians[0] = lower;
		radians[terms - 1] = upper;		
		degrees[0] = rad2deg(lower);
		degrees[terms - 1] = rad2deg(upper);
			 
	}
	else if( isDegrees == 1 ) /* If degrees are inputted */
	{
		degreeInterval = interval;
		radianInterval = deg2rad(degreeInterval);
		
		// Define first and last term
		degrees[0] = lower;
		degrees[terms - 1] = upper;
		radians[0] = deg2rad(lower);
		radians[terms - 1] = deg2rad(upper);
		
	}
	
	// Define the inner terms of our degrees and radians arrays
	for(int i = 1; i < terms - 1; i++)
	{
		degrees[i] = degrees[i-1] + degreeInterval;
		radians[i] = radians[i-1] + radianInterval;
	}
	
	//Calculate sine cosine and tan arrays
	double sinArray[terms], cosArray[terms], tanArray[terms];
	for(int i = 0; i < terms; i ++)
	{
		sinArray[i] = sin(radians[i]);
		cosArray[i] = cos(radians[i]);
		tanArray[i] = tan(radians[i]);
	}
	
	
	for(int i = 0; i < terms; i++)
	{
		printf("\n%10.3lf%10.3lf", degrees[i], radians[i]);
		if( isSin )
		{
			printf("%10.3lf", sinArray[i]);
		}
		if( isCos )
		{
			printf("%10.3lf", cosArray[i]);
		}
		if( isTan )
		{
			double undefinedTan = 90, definedTan = 180, ZERO = 0;
			if( fmod(degrees[i], undefinedTan) == ZERO && fmod(degrees[i], definedTan) != ZERO)
			{
				printf("       N/A");
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

double sine(double angle)
{
	double ret = sin(angle);
	return ret;
}


void help(void)
{
	printf("\nThe input format is a single line of letters and numbers comprising the following fields:\n\n");
	printf(" <types> <start-value> <final-value> <intermediate-rows>\n\n");
	printf("These fields must be input in the order shown above, where <types> \n");
	printf("is a set of letters, and the others are single numbers defining\n");
	printf(" the range of computation.\n\n");
	printf("The <types> field consists of zero or more of the letters from the set \n");
	printf("<stcdr>, https://stackoverflow.com/questions/1252132/difference-between-scanf-and-fgetswhich indicate respectively, \n\n");
	printf(" (1) The desired trig functions: sin, tan, cos.\n");
	printf(" (2) Whether to use degrees or radians for input parameters.\n");
	printf(" (3) Whether to quit the program.\n\n");
	printf("Example input: scr 0 2.3 3\n");
}

void printHeader(int isSin, int isCos, int isTan)
{
	printf("\n");
	printf("   Degrees");
	printf("   Radians");
	if (isSin == 1)
	{
		printf("       Sin");
	}
	if (isCos == 1)
	{
		printf("       Cos");
	}
	if (isTan == 1)
	{
		printf("       Tan");
	}
	printf("\n\n");
}

double rad2deg(double rad)
{
	double deg = rad*180/PI;
	return deg;
}

double deg2rad(double deg)
{
	double rad = deg*PI/180;
	return rad;
}

/*
int checkInput(char userInput)
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
*/