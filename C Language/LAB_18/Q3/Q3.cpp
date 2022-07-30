#define _CRT_SECURE_NO_WARNINGS
#define COL 4
#define ROW 7
#include <stdio.h>


void readFromFile(FILE* matrix, double Arr[][COL])
{

	if (matrix == NULL)
		printf("Error");
	else
	{

		int r = 0, c = 0;

		while (fscanf(matrix, "%lf", &Arr[r][c]) != EOF)
		{
			if (c != COL - 1)
				c++;
			else {
				r++;
				c = 0;
			}
		}
	}
}

void displayArr(double Arr[][COL])
{
	int r, c;
	for (r = 0; r < ROW; r++)
	{
		for (c = 0; c < COL; c++)
		{
			printf("%4.1f  ", Arr[r][c]);
		}
		printf("\n");
	}
}

void swapRows(double ROW1[], double ROW2[])
{
	int c;
	double temp;
	for (c = 0; c < COL; c++)
	{
		temp = ROW1[c];
		ROW1[c] = ROW2[c];
		ROW2[c] = temp;
	}

}
int main(void)
{
	FILE* matrix;
	matrix = fopen("matrix.txt", "r");
	double Arr[ROW][COL];
	double swap1Arr[COL];
	double swap2Arr[COL];
	readFromFile(matrix, Arr);
	printf("The contents of the array is:");
	displayArr(Arr);
	int swap1, swap2;
	do {
		printf("Enter two row indices to swap:");
		scanf("%d %d",&swap1, &swap2);
			
	} while (swap1<0 || swap1> (ROW - 1)|| swap2<0 || swap2>(ROW - 1));
	int c;
	for (c = 0; c < COL;c++)
	{
		swap1Arr[c] = Arr[swap1][c];
		swap2Arr[c] = Arr[swap2][c];

	}
	swapRows(swap1Arr, swap2Arr);

	for (c = 0; c < COL; c++)
	{
		Arr[swap1][c] = swap1Arr[c];
		Arr[swap2][c] = swap2Arr[c];
	}
	displayArr(Arr);

}