#define _CRT_SECURE_NO_WARNINGS
#define COL 9
#include <stdio.h>

void readFromFile(FILE* inp, char Arr[][COL])
{
	if (inp == NULL)
		printf("Error!");
	else {
		char ch;
		int status;
		int r = 0, c = 0;

		status = fscanf(inp, "%c", &ch);
		while (status != EOF)
		{
			if (ch != '\n')
			{
				Arr[c][r] = ch;
				r++;
				status = fscanf(inp, "%c", &ch);
			}

			else
			{
				
				c++;
				r = 0;
				status = fscanf(inp, "%c", &ch);
			}
		}
	}
}

void displayTwoDÝmension(char Arr[][COL])
{
	int r, c;
	for (r = 0; r < COL; r++)
	{
		for (c = 0; c < COL; c++)
		{
			printf("%c", Arr[r][c]);
		}
		printf("\n");
	}
}

void DisplayDimension(char Arr[][COL], int dim)
{
	int r, c;
	printf("Dimension for %d,MAJOR element of the file is:", dim);
	for (r = 0; r < dim; r++)
	{
		printf("%c", Arr[r][r]);

	}
	printf("\n");
	printf("\nDimension for %d,MINOR element of the file is:", dim);
	for (r = 0; r < dim; r++)
	{
		printf("%c", Arr[r][dim - 1 - r]);
	}

}
int main(void)
{
	FILE* words;
	words = fopen("words.txt", "r");
	char ARR[COL][COL];
	readFromFile(words, ARR);
	displayTwoDÝmension(ARR);
	int dimension;
	do {
		do {
			printf("Enter the dimension [1-9] ");
			scanf("%d", &dimension);

		} while (dimension>9);


	    
		DisplayDimension(ARR, dimension);
		printf("\n\n");
	} while (dimension >0);



}