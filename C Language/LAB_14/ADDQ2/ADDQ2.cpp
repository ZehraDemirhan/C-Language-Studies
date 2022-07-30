#define _CRT_SECURE_NO_WARNINGS
#define SIZE 15
#include<stdio.h>

int findMaxPrice(double Arr[], int size)
{
	int maxI = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		if (Arr[i] > Arr[maxI])
			maxI = i;
	}
	return(maxI);


}

void displayAll(char CodeArr[], double PriceArr[], int size)
{
	printf("District\t  Price\n");
	printf("--------\t  --------\n");
	int i;
	for (i = 0; i < size; i++)
	{
		if (CodeArr[i] =='d')
			printf("Domestic");
		else
			printf("Abroad\t");
		printf("\t  %6.2f\n", PriceArr[i]);

	}
	printf("Max Price Delivery\n");

	printf("District\t  Price\n");
	printf("--------\t  --------\n");
	int index;
	index = findMaxPrice(PriceArr,size);
	if (CodeArr[index] == 'd')
		printf("Domestic");
	else {
		printf("Abroad");

	}
	printf("\t          %6.2f", PriceArr[index]);

}

int main(void)
{
	FILE* cargo;
	cargo = fopen("cargo.txt", "r");
	if (cargo == NULL)
		printf("Error");
	else 
	{
		char CodeArr[SIZE];
		double Price[SIZE];
		int code;
		double weight,price;
		int status;
		int i = 0;
		status = fscanf(cargo, "%d %lf", &code, &weight);
		while (status != EOF)
		{
			if (code <= 81)
			{
				CodeArr[i] = 'd';
				if (weight >= 5)
				{
					price = 75 + (weight - 5) * 10;
					Price[i] = price;
					i++;
				}
				else 
				{ price = 75; 
				  Price[i] = price;
				  i++;
				}
			}

			else 
			
			{ 
				CodeArr[i] = 'a';
				if (weight >= 10)
				{
					price = 120 + (weight - 10) * 15;
					Price[i] = price;
					i++;
				}
				else {
					price = 120;
					Price[i] = price;
					i++;
				}
			
			}
			status = fscanf(cargo, "%d %lf", &code, &weight);


		}

		displayAll(CodeArr, Price, i);
	

		fclose(cargo);
	
	}
	return(0);
}