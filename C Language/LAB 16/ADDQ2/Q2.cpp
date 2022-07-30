#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>
#include<math.h>

void sumBin(int Arr1[], int Arr2[], int SumArr[],int size1,int size2)
{
	int i = 0;
	int newnum = 0;
	int newnum2 = 0;
	int sum = 0;
	for (i = 0; i < size1; i++)
	{
		newnum += Arr1[i] * pow(2, size1 - i);
	}
	for (i = 0; i < size2; i++)
	{
		newnum2 += Arr2[i] * pow(2, size2 - i);

	}

	sum = newnum + newnum2;
	int j;
	while (sum != 0)
	{
		SumArr[j] = sum % 2;
		sum /= 2;
		j++;
	}
}


int main(void)
{
	FILE* inp;
	int Arr1[SIZE];
	int Arr2[SIZE];
	int sums[SIZE];

	inp = fopen("numbers.txt", "r");
	if (inp == NULL)
		printf("Cannot open the file!");
	else 
	{
		int i = 0;
		while (fscanf(inp, "%d %d", &)
	}
}
