#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#include <stdio.h>

int dispMenu(void)
{
	int request;

	printf("                MENU \n---------------------------------------\n1 - List the accounts with zero balances\n2 - Display the account which has the maximum balance\n3 - Exit\n\n");

	do {
		printf("Enter your request:");
		scanf("%d", &request);
		

	} while (request != 1 && request != 2 && request != 3);

	return(request);

}

int  readFile(FILE* inp, int Arr1[], double Arr2[])
{
	if (inp ==NULL)
		printf("Cannot open the file!");
	else 
	{
		int i = 0;
		while (fscanf(inp, "%d %lf", &Arr1[i], &Arr2[i]) != EOF)
		{
			i++;

		}
		return(i);
	}
}

void displayZeroBalances(double BArr[], int size, int IndexArr[], int *sizeIndex)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (BArr[i] == 0)
		{
			IndexArr[*sizeIndex] = i;
			*sizeIndex = *sizeIndex + 1;

		}

	}
}

int findMaxBalance(double BArr[], int size)
{
	int max = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		if (BArr[i] > BArr[max])
			max = i;

	}
	return(max);

}

int main(void)
{
	FILE* inp;
	int size,request,sizeIndex=0,i,max;
	int Array1[SIZE];
	double Array2[SIZE];
	int IndexArr[SIZE];
	inp = fopen("customers.txt", "r");
	size = readFile(inp, Array1, Array2);

	
	do {
		request = dispMenu();
		if (request == 1)
		{
			displayZeroBalances(Array2, size, IndexArr, &sizeIndex);
			printf("\nAccounts with zero balances:\n");
			for (i = 0; i < sizeIndex; i++)
			{
				printf("%d\n", Array1[IndexArr[i]]);
			}
			printf("\n");
		}

		else if (request == 2)
		{
			max = findMaxBalance(Array2, size);
			printf("\nAccount Info which has the maximum balance:\n");
			printf("%d  %7.2f\n\n", Array1[max], Array2[max]);
		}
	} while (request != 3);

}