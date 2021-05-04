#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* This method sorts the string array using the normal bubble sort algorithm
*
* routine: BubbleSort
*
* return type: void
*
* parameters:
*	stringArray[]	[char]		The array of strings to be sorted.
*
*	arraySize		[int]		Size of the array of strings to be sorted.
*
* @author	Abdel Rahman Mansour
* @since	02/06/2021
*/
void BubbleSort(char** stringArray, int arraySize)
{
	char* temp;
	temp = (char*)calloc(100, sizeof(char));

	for (int i = 0; i < arraySize - 1; i++)
	{
		for (int j = 0; j < arraySize - i - 1; j++)
		{
			if (strcmp(stringArray[j], stringArray[j + 1]) > 0)
			{
				strcpy(temp, stringArray[j]);
				strcpy(stringArray[j], stringArray[j + 1]);
				strcpy(stringArray[j + 1], temp);
			}
		}
	}

	free(temp);
}

/**
* This program inputs a list of string values from a text file, stores
* those values in an array of strings, sorts the array, and prints the final contents of the array
* to a separate text file
*
* CSC 3304 Programming project No. 1
*
* @author	Abdel Rahman Mansour
* @since	02/02/2021
*
*/
int main()
{
	FILE* input = fopen("./TestInput.txt", "r");
	FILE* output = fopen("./out.txt", "w");

	int numRows = 500;
	int numColumns = 100;
	int EOFcheck = 0;
	int i = 0;
	int j = 0;
	int arraySize = 0;
	
	char** stringArray = malloc(numRows * sizeof(char*));

	if (stringArray == NULL)
	{
		printf("Couldn't allocate memory");
	}
	else
	{
		for (i = 0; i < numRows; i++)
		{
			stringArray[i] = malloc(numColumns * sizeof(char));
		}
	}

	while ((EOFcheck = getc(input)) != EOF && j < 500)
	{
		ungetc(EOFcheck, input);
		fgets(stringArray[j], 100, input);
		arraySize = arraySize + 1;
		j = j + 1;
	}
		
	BubbleSort(stringArray, arraySize);

	for (int i = 0; i < arraySize; i++)
	{
		fputs(stringArray[i], output);
	}

	fclose(input);
	fclose(output);

	for (int i = 0 ; i < arraySize ; i++)
	{
		free(stringArray[i]);
	}
	free(stringArray);

	return 0;
}