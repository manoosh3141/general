#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define BUF_SIZE 2048

void printNumber(char *);

int main(int command, char *input[]) {
	
	// TO DO CHECK FOR NULL INPUT
	

	char *power3[] = {"invalidZeros", "thousand", "million", "billion"};
	
	//printf("input: %s\n", input[1]);
	int length = strlen(input[1]);
	//printf("length: %d\n", length);
	
	// Create a buffer string of zeros so that our string is always 12 digits long
	int remainder = 12-length;
	char zeroBuffer[BUF_SIZE];	
	//printf("remainder: %d\n", remainder);
	for (int i = 0; i < remainder; i++) {
		zeroBuffer[i] = '0';
	}
	
	// Concatenate the two strings
	char string[BUF_SIZE];
	strcpy(string, input[1]);
	char processedInput[BUF_SIZE];
	strcpy(processedInput, zeroBuffer);	
	strcat(processedInput, string);
	
	
	//printf("%s\n", processedInput);
	
	// Split strings into integer blocks of 3 - billions, millions etc
	char trillionString[3];
	char billionString[3];
	char thousandString[3];
	char hundredString[3];
	
	char * processedInputp = &processedInput[0];
	for (int i = 0; i < 12; i++) {
		//printf("\n%c\n", *(processedInputp + i));
		
		
		if (i < 3)
			trillionString[i] = *(processedInputp + i);
		else if (i < 6)
			billionString[i-3] = *(processedInputp + i);
		else if (i < 9)
			thousandString[i-6] = *(processedInput + i);
		else if (i < 12)
			hundredString[i-9] = *(processedInput + i);
		
	}
	
	// Convert to integers
	/*
	int trillion = atoi(trillionString);
	int billion = atoi(billionString);
	int thousand = atoi(thousandString);
	int hundred = atoi(hundredString);
	*/
	
	//printf("string %s\n", hundredString);
	if (atoi(trillionString) > 0) {
		printNumber(trillionString);
		printf("billion ");
	}
	
	if (atoi(billionString) > 0) {
		printNumber(billionString);
		printf("million ");
	}
	
	if (atoi(thousandString) > 0) {
		printNumber(thousandString);
		printf("thousand ");
	}
	
	if (atoi(hundredString) > 0) {
		printNumber(hundredString);
		//printf("");
	}
	
	
	
	//printNumber(hundredString);
	
	return 0;
}

void printNumber(char *string) {
	
	char *units[] = {"invalidZero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *tens[] = {"invalidZeros", "invalidTens", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	//char *hundredText[] = {"hundred"};
	
	int integer = atoi(string);
	//printf("%d\n", integer);
	
	char ** stringp = &string;
	
	// Print Hundreds
	if ((*string - '0') > 0) {
		printf("%s hundred ", units[*string- '0']);
	}
	
	if ((*string - '0') > 0 && (*(string + 1) - '0') > 0 )
		printf("and ");
	
	// Print tens
	if ((*(string + 1) - '0') > 1 ) {
		printf("%s ", tens[*(string + 1) - '0']);
	}
	else if ((*(string + 1) - '0') > 0 ) {
		printf("%s ", units[10 + *(string + 2) - '0']);
		return;
	}
	
	if (((*(string + 1) - '0') == 0) && ((*(string + 2) - '0') > 0) && ((*(string) - '0') > 0))
		printf("and ");
	
	if (*(string + 2) - '0' > 0) {
		printf("%s ", units[*(string + 2) - '0']);
	}
	return;
}