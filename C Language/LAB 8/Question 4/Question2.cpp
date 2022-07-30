#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>


int main(void)
{
	int i,sign=-1;
	double  fact = 1,y, result=0;

	printf("Enter the value of y :");
	scanf("%lf", &y);

	while (y==-1)
	{
		printf("Enter the value of y :");
		scanf("%lf", &y);
	}

	for (i = 0; i <= 12; i+=2)

	{	
	
		fact *=( (i + 1) * (i + 2));
		result += (sign * fact) / powf(y + 1, 1.0 / (15.0 - i));
		sign = sign*-1;
		
	}
		

	
	printf("\nThe result is %14.2f", result);
}
