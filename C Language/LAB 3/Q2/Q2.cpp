#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#define ROWSIZE 3
#define COLSIZE 3

int main(void)
{
	int Arr[ROWSIZE][COLSIZE];
	FILE* out;
	out = fopen("result.txt", "w");
	int r, c;
	int i = 1;
	printf("Successful! Please see the result.txt file for the output.");
	fprintf(out, "Element Name \t Value\t Adress\n");
	fprintf(out, "------------\t------\t-------\n");

	for (r = 0; r < ROWSIZE; r++)
	{
		for (c = 0; c < COLSIZE; c++)
		{
			*(*(Arr + r) + c) = pow(2,i);
			i++;

		}
	}
	for (r = 0; r < ROWSIZE; r++)
	{
		for (c = 0; c < COLSIZE; c++)
		{
			fprintf(out,"*(*(arr+%d)+%d)", r, c);
			fprintf(out,"\t%d ", *(*(Arr + r) + c));
			fprintf(out," %p\n", *(Arr + r) + c);

		}
	
	}

}
