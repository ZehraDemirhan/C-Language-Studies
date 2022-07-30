#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define SIZE 20

int main(void)
{
	FILE* inp;
	int i = 0;
	inp = fopen("sales.txt", "r");
	double num,profit,total=0;
	double Arr[SIZE];
	double ARR[SIZE];
	double ProfitArr[SIZE];

	while (fscanf(inp, "%lf", &num) != EOF)
	{
		Arr[i] = num;
		fscanf(inp, "%lf", &num);
		ARR[i] = num;

		profit =  ARR[i]-Arr[i];
		ProfitArr[i] = profit;
		total += profit;

	    i++;

	}

	printf("Purchase   Sale     Profit\n--------   ------   ------\n");
	for (i = 0; i < 10; i++)
	{
		printf("%8.2f   ", Arr[i]);
		printf("%6.2f   ", ARR[i]);
		printf("%6.2f",ProfitArr[i]);
		printf("\n");
	}
	printf("Total profit is : %5.2f", total);

}