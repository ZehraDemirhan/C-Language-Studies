#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int number,i,sum=0;

	do {
		printf("Enter a number:");
		scanf("%d", &number);


	} while (number <= 0);
	for (i = 1; i < number; i++)
	{
		if ( number % i== 0)
			sum += i;
	}

	if (sum == number)
	{
		printf("The number %d is a perfect number", number);

	}
	else if (sum != number)
		printf("The number %d is NOT a perfect number", number);
	
}