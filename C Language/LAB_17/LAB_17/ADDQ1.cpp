#define _CRT_SECURE_NO_WARNINGS
#define COL 5
#define ROW 5
#include<stdio.h>

int main(void)
{
	FILE* calories;
	calories = fopen("calories.txt", "r");
	if (calories == NULL)
		printf("Error!");
	else 
	{
		FILE* output;
		output = fopen("output.txt", "w");
		int idArr[ROW];
		double CArr[ROW][COL];
		double AvgArr[ROW];
		int i = 0, status;
		status = fscanf(calories, "%d", &idArr[i]);
		int r = 0, c = 0;
		while (status != EOF)
		{
			fscanf(calories, "%lf", &CArr[r][c]);
			if (c != COL - 1)
				c++;
			else
			{
				r++;
				c = 0;
				i++;
				status = fscanf(calories, "%d", &idArr[i]);
				
			}

		}

		double sum = 0;
		for (r = 0; r < ROW; r++)
		{
			for (c = 0; c < COL; c++)
			{
				sum += CArr[r][c];

			}
			AvgArr[r] = sum / COL;
			sum = 0;
		}

		fprintf(output, "ID\tAVERAGE\tLOSE\tWEIGHT\n");
		fprintf(output, "***************************\n");
		for (r = 0; r < ROW; r++)
		{
			fprintf(output, "%d\t%6.1f\t", idArr[r], AvgArr[r]);
			if (AvgArr[r] > 2200)
				fprintf(output, "\tY\n");
			else fprintf(output, "\tN\n");

		}

		fclose(calories);
		fclose(output);
	}
	return(0);

}