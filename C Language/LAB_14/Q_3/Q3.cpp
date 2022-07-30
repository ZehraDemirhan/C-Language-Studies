#define _CRT_SECURE_NO_WARNINGS
#define SIZE 20
#include<stdio.h>

void display(int Arr[], int size)
{
	int i;
	printf("There are %d numbers in the array!\n\n", size);

	for (i = 0; i < size; i++)
	{
		printf("[%2d] %4d\n", i, Arr[i]);

	}

}
int main(void)
{
	FILE* numbers;
	numbers = fopen("numbers.txt", "r");
	if (numbers == NULL)
		printf("Eror");
	else 
	{
		int Arr[SIZE];
		int index;
		int i = 0;
		while (fscanf(numbers, "%d", &Arr[i]) != EOF)
		{
			i++;

		}

		printf("Array contents BEFORE delete operation:\n");
		display(Arr, i);
		do {
			printf("Enter the index of the element to be deleted(0-11):");
			scanf("%d", &index);

		} while (index > 11 || index < 0);
		printf("The value %d which is on the index %d will be deleted\n", Arr[index], index);
		int j;
		for (j=index  ; j< i; j++)
		{
			Arr[j] = Arr[j + 1];

		}
		printf("Array contents After delete operation:\n");
		display(Arr,i-1);


	}
}