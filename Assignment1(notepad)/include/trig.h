// Constant definitions
#define PI 3.1415926535897932384626433
#define BUFFER_SIZE 2048

// Libraries
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

// trig.c headers
void help(void);
int trig(char [], double, double, double);
void printHeader(int, int, int);
double rad2deg(double);
double deg2rad(double);
int error(void);

// checkInput.c headers
int checkInput(char *);
int checkInputString(char *);
int checkStartFinalValue(char *);
int checkIntermediateValue(char *);
int countSpaces(char []);
int checkValidCharacters(char *, char *);

// getInput.c headers
int getInput(void);
