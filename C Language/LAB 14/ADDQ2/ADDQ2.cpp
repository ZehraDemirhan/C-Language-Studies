#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 50

int findMaxPrice(double Array[], int size)
{
	int i;
	int maxindex = 0;
	for (i = 1; i <= size; i++)
	{
		if (Array[i] > Array[maxindex])
			maxindex = i;
	}

	return(maxindex);
}

void displayAll(char codeArray[], double priceArray[], int codeSize, int priceSize)
{
	int i;

	printf("District   Price\n-------- ------- \n");
	for (i = 0; i < codeSize; i++)
	{
		if (codeArray[i] == 'a')
		{
			printf("Abroad  ");
			printf("%8.2f\n", priceArray[i]);
		}
		else if(codeArray[i]='d')
		{
			printf("Domestic");
			printf("%8.2f\n", priceArray[i]);
		}



	}
	
		
	printf("\n");

}
int main(void)
{
	FILE* inp;
	int i = 0;
	int size = 0;

	char CodeArr[SIZE],maxDistrict;
	int tmpCode;
	double PriceArr[SIZE], tmpWeight;
	double price;
	inp = fopen("cargo.txt", "r");
	if (inp == NULL)
		printf("Cannot be opened");
	else
	{
		double num;

		while (fscanf(inp, "%d %lf", &tmpCode, &tmpWeight) != EOF)
		{


			if (tmpCode <= 81)
				CodeArr[i] = 'd';
			else
				CodeArr[i] = 'a';



			switch (CodeArr[i])
			{
			case 'a': if (tmpWeight >= 10)
				price = 120 + (tmpWeight - 10) * 15;
					else
				price = 120;
				break;
			case 'd': if (tmpWeight >= 5)
				price = 75 + (tmpWeight - 5) * 10;
					else
				price = 75;


			}
			size++;
			PriceArr[i] = price;
			i++;


		}

		maxDistrict = CodeArr[findMaxPrice(PriceArr, size)];
		displayAll(CodeArr, PriceArr, size, size);
		printf("Max Price Delivery\nDistrict    Price\n---------   --------\n");
		if (maxDistrict == 'a')
		{
			printf("Abroad\t ");
			
		}
		else if (maxDistrict = 'd')
		{
			printf("Domestic");
			
		}


		printf( "  % 5.2f\t", PriceArr[findMaxPrice(PriceArr, size)]);
	}
}