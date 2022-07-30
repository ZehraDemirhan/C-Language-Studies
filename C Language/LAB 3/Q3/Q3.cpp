#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void input(int *aptr, int num)
{
	
	int i;
	
	printf("Enter %d grades:", num);
	for (i = 0; i < num; i++)
	{
		scanf("%d", aptr + i);
		
	}

}

double findGrade(int* aptr, int num)
{
	int i = 0;
	double sum = 0;
	for (i = 0; i < num; i++)
	{
		sum += *(aptr + i);

	}
	return(sum *40/100);

}

int main(void)
{
	int num;
	int* aptr;
	
	do
	{
		printf("How many grades?");
		scanf("%d", &num);
		aptr = (int*)malloc(sizeof(int) * num);
		
		if (num > 0)
		{
			input(aptr, num);
			double total;

			total = findGrade(aptr, num);

			printf("The %%40 of the total grade:%5.2f\n\n", total);
		}
	} while (num >= 0);
	
	free(aptr);
	aptr = NULL;





}