#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 2048

int printArray(int *array, int size);

int getFuzzyMinute(int);

int main(void)
{
	while (1)
	{
	printf("Input a time in the format HH:MM - ");
	//int hour = 1, minute = 20;
	int hour, minute;
	scanf("%d:%d", &hour, &minute);
	//printf("\nminute %d\n", minute);
	
	
	// Define minute
	char *minuteString[] = {"o'clock", "five", "ten", "quater", "twenty", "twenty five", "half"};
	char *directionString[] = {"past", "to"};
	char *hourString[] = {"twelve", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};
	//char *
	char *fuzzyHour = hourString[hour];
	//printf("%s\n", fuzzyHour);
	
	int position = getFuzzyMinute(minute);
	int direction;
	if (position > 6)
	{
		position = 6 - (position - 6);
		direction = 1;
		if (hour == 0 || hour == 12)
			hour = 1;
		else
			hour = hour + 1;
	}
	else
	{
		direction = 0;
	}
		

	
	printf("It is %s %s %s\n", minuteString[position], directionString[direction], hourString[hour]);
}
}


int getFuzzyMinute(int minute)
{
	int minutesByFive[13];
	// Create minutesByFive array [0, 5, 10, ... , 55] 
	for (int i = 0; i <= 12; i++)
	{
		minutesByFive[i] = i * 5;
	}
	
	int size = sizeof(minutesByFive)/sizeof(minutesByFive[0]);
	printArray(&minutesByFive[0], size);
	
	
	// Calculate remainder
	int remainder;
	for (int i = 11; i >= 0; i--)
	{
		if (i == 0)
			remainder = minute;
		else
			remainder = minute%(minutesByFive[i]);
		
		// Get position of fuzzy number
		int position;
		if ((remainder < 5) && (remainder > 2))
		{
			//printf("i: %d\n", i);
			position = (i + 1);
			//printf("2 < rem < 5");
			//printf("..1.. by 5: %d\n", minutesByFive[position]);
			return position;
		}
		else if (remainder < 3)
		{
			//printf("rem < 3");
			position = i;
			printf("\n..2.. by 5: %d  pos: %d\n", minutesByFive[position], position);
			return position;
		}
		
		//printf("pos: %d, rem: %d, by 5: %d\n", position, remainder, minutesByFive[position]);			
	}
}

int printArray(int *array, int size)
{
	for (int i = 0; i < size; i ++)
	{
		//printf("-%d-", *(array + i));
	}
	//printf("\n");
	return 0;
}