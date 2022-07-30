#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int encrypt(int num)
{
	int digit,i,temp1,temp2;
	int Arr[4];
	for (i = 0; i <4; i++)
	{
		digit = num % 10;
		num /= 10;
		Arr[3-i] =( digit + 7 )% 10;

	}
	temp1 = Arr[0];
	Arr[0] = Arr[2];
	Arr[2] = temp1;

	temp2 = Arr[1];
	Arr[1] = Arr[3];
	Arr[3] = temp2;

	num = Arr[0] * 1000 + Arr[1] * 100 + Arr[2] * 10 + Arr[3];
	return(num);

}
int main(void)
{
	FILE* inp;
	FILE* out;
	int num;
	inp = fopen("numbers.txt", "r");
	
	if (inp == NULL)
		printf("File cannot be opened");
	else {
		out = fopen("newnumbers.txt", "w");
		while (fscanf(inp, "%d", &num) != EOF)
		{
			fprintf(out, "%d", encrypt(num));
			fprintf(out,"%c", '\n');

		}


		fclose(inp);
		fclose(out);
	}

}