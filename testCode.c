// a program that reads an input pair from a file and outputs the pairs along with the maximum 
// cycle length for the integers between and including the two pairs. The cycle-length of the 
// integer is the number of numbers generated uo to and including the stopping condition, 1. 

#include <stdio.h>
#include <stdlib.h>

//a function to find the cycle-length given an integer, based on the collatz conjecture algorithm 
int numCycles (int num)
{
	int cycleCount = 1;
	while (num != 1)
	{
		if (num % 2 == 0)
		{
			num /= 2;
			cycleCount++;
		}
		else
		{
			num = num * 3 + 1;
			cycleCount++;
		}
	}
	return cycleCount;
}

//a function to find the maximum cycle length for two integers between and including the integers 
int maxCycles (int num1, int num2)
{
	int max = 1;
	
	if (num1 > num2)
	{
		for (int i = num1; i <= num2; i++)
		{
			if (max < numCycles (i))
			{
				max = numCycles (i);
			}
		}
	}
	else 
	{
		for (int i = num1; i <= num2; i++)
		{
			if (max < numCycles (i))
			{
				max = numCycles (i);
			}
		}
	}
	return max;
}

int main (int argc, char **argv)
{
	int firstNum, secondNum;

	FILE* inFile = NULL;

	inFile = fopen (argv[1], "r");

	if (NULL == inFile)
	{
		printf ("Could not open file.\n");
		exit (EXIT_FAILURE);
	}

	while (!feof (inFile))
	{
		fscanf (inFile, "%d %d", &firstNum, &secondNum);
		printf ("%d %d %d\n", firstNum, secondNum, maxCycles (firstNum, secondNum));
	}

	fclose (inFile);

	return 0;
}

// bin/testCode data/data.txt

