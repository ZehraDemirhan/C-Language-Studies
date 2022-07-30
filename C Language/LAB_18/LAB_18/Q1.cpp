#define _CRT_SECURE_NO_WARNINGS
#define COL 5
#include <stdio.h>

void negate(int Arr[][COL])
{
	int r, c;
	for (r = 0; r < COL; r+=2)
	{
		for (c = 0; c < COL; c++)
		{
			Arr[r][c] = -Arr[r][c];

		}
	}
}
void displayRowise(int Arr[][COL])
{
	int r, c;
	for (r = 0; r < COL; r++)
	{
		for (c = 0; c < COL; c++)
			printf("%3d  ",Arr[r][c]);
		printf("\n");

	}
}
void displayColumnwise(int Arr[][COL])
{
	int r, c;
	for (r = 0; r < COL; r++)
	{
		for (c = 0; c < COL; c++)
			printf("%3d  ", Arr[c][r]);
		printf("\n");

	}
}

int main(void)
{
	FILE* nums;
	nums = fopen("nums.txt", "r");
	if (nums == NULL)
		printf("Error");
	else
	{
		int Arr[COL][COL];
		int r = 0, c = 0;

		while (fscanf(nums, "%d", &Arr[r][c])!=EOF)
		{
			if (c != COL - 1)
				c++;
			else {
				r++;
				c = 0;
			}
		}
		printf("Original Array,row-wise format:\n");
		displayRowise(Arr);
		int i;
		for (i = 0; i < COL; i += 2)
		{
			printf("Negating the values on the row %d\n", i);
		}
		printf("Values on the even rows are negated!\n\n");
		printf("Your new Array,row-wise format:\n");
		negate(Arr);
		displayRowise(Arr);
		printf("Your new Array,Column-wise format:\n");
		displayColumnwise(Arr);


	}
}