#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int num,i,j;
	srand(time(NULL));
		num = (rand() % 11)+5;

		printf("Randomly generated number is :%d\n", num);
		for (i = 1; i <= num; i++)
		{
			for (j = 1; j <= i; j++)
			{
				printf("*");
			}
			printf("\n");

		}

}
