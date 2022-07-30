#define _CRT_SECURE_NO_WARNINGS
#define SIZE 20
#include<stdio.h>

int main(void)
{
	FILE* sales;
	sales = fopen("sales.txt", "r");
	if (sales == NULL)
		printf("Eror");
	else {
		double Arr1[SIZE];
		double Arr2[SIZE];
		int i = 0;
		while (fscanf(sales, "%lf %lf", &Arr1[i], &Arr2[i]) != EOF)
		{
			i++;
		}
		int j;
		double sum = 0;

		printf("Purchase  Sale  Profit\n");
		printf("------  ------  ------\n");
		for (j = 0;j < i; j++)
		{
			printf("%.2f\t%.2f\t%.2f\n", Arr1[j], Arr2[j], Arr2[j] - Arr1[j]);
			sum += Arr2[j] - Arr1[j];

		}
		printf("Total profit is :%.2f", sum);
	}
}