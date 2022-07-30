#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int num, i, j, k;
	srand(time(NULL));
	num = (rand() % 11) + 5;

	printf("Randomly generated number is :%d\n", num);
	for (i = 1; i <= num; i++)
	{
		{
		for (j = 1; j <= (num - i); j++)
				printf(" ");
		}
		for (k = 1; k <= i; k++)
		{
			printf("*");
		}

		printf("\n");
	}
	
	return(0);
}
