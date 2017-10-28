#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	// Print welcome message and initial prompt
	printf("TRIG: the trigonometric calculator\n\n");

	// Take input from the user
	INPUT:
    printf("Please input request (h-help, q-quit): ");
    char types[100];
    double start_value, final_value, intermediate_rows;

    //scanf("%s %lf %lf %lf", types, &start_value, &final_value, &intermediate_rows);
    scanf("%s ", types);
    scanf("%lf %lf %lf", &start_value, &final_value, &intermediate_rows);

    //printf("%d", strlen(types));
    //printf("%s", types);
    //printf("%s", letter);
	if(strcmp(types, "q") == 0 )/* If user wants to quit */
	{
		return 0;
	}
	else if( strcmp(types, "h") == 0) /* If user wants to see help options */
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

		goto INPUT;
	}
	else
        printf("error");
		goto INPUT;
}
