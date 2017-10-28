#include <stdio.h>
#include <string.h>

int main()
{
  FILE *file;


  // Open the file for writing
  file = fopen("records.txt", "wt");
  if (!file)
  {
    printf("File could not be opened\n\a\a");
    getchar();
    return -1;
  }


	// Save data
	fprintf(file, "%s\n", firstName);


  // Close the file
  fclose(file);

  return 0;
}