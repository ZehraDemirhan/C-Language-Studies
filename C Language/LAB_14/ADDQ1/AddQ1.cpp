#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 25


int findMax(int Arr[], int size)
{
	int maxIndex = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		if (Arr[i] > Arr[maxIndex])
		{
			maxIndex = i;

		}
	}
	return(maxIndex);

}

void display(int Arr[], int size)
{
	int i;
	int j;
	printf("GRADE\tFREQUENCY\tHISTOGRAM\n");
	printf("------\t---------\t---------\n");
	for (i = 0; i < size; i++)
	{
		printf("%d\t   %d\t\t", i + 1, Arr[i]);
		for (j = 0; j < Arr[i]; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}

int main(void)
{
	FILE* Grades;
	Grades = fopen("grades.txt", "r");
	if (Grades == NULL)
		printf("Error");
	else {
		int Arr[SIZE] = { 0 };
		int i = 0;
		int num;
		int status;
		status = fscanf(Grades, "%d", &num);
		while (status != EOF)
		{
			Arr[num - 1] += 1;
			i++;
			status = fscanf(Grades, "%d", &num);
		}

		display(Arr, 10);
		
	}
}