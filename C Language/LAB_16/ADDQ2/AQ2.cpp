#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 11

void sumBin(int Arr[], int Arr2[],int size1,int sumArr[])
{
		int i;
		int elde=0, taban;
		for (i = 0; i < size1; i++)
		{
			if ((Arr[(size1-1)-i] + Arr2[(size1 - 1) - i]+elde) == 2)
			{
				taban = 0;
				sumArr[(size1 - 1) - i] = taban ;
				elde = 1;
				
				
			}
			else if ((Arr[(size1 - 1) - i] + Arr2[(size1 - 1) - i]+elde) == 3)
			{
			    taban = 1;
				sumArr[(size1 - 1) - i] = taban ;
				elde = 1;
				
				
			}
			else {
				sumArr[(size1 - 1) - i] = Arr[(size1 - 1) - i] + Arr2[(size1 - 1) - i] + elde;;
				elde = 0;
			}
		
	    }
}

int main(void)
{
	FILE* numbers;
	numbers = fopen("numbers.txt", "r");
	if (numbers == NULL)
		printf("Error");
	else {
		int num1, num2;
		int i = 0, k= 0;
		

		while (fscanf(numbers, "%d %d", &num1, &num2) != EOF)
		{
			int Arr1[SIZE] = { 0 };
			int Arr2[SIZE] = { 0 };
			int sumArr[SIZE] = { 0 };
			while (num1 != 0)
			{
				Arr1[(SIZE-1)-i] = num1 % 10;
				num1=num1 / 10;
				i++;
			}
			i = 0;
			while (num2 != 0)
			{
				Arr2[(SIZE-1)-i] = num2 % 10;
				num2=num2/ 10;
				i++;
			}
			i = 0;
			k++;
			printf("%d. sum is ", k);
			sumBin(Arr1, Arr2, SIZE,sumArr);
			int j;
			for (j = 0; j < SIZE; j++)
			{
				printf("%d ", sumArr[j]);
			}
			printf("\n");

			
		}
		fclose(numbers);

	}
	return(0);
}