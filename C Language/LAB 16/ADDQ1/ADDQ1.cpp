#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#include <stdio.h>

int maxPos(double GPAArr[], int size)
{
	int max = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		if (GPAArr[i] > GPAArr[max])
			max = i;

	}
	return(max);

}

int main(void)
{
	FILE* inp;
	FILE* out;
	int id;
	double sum=0,avg;

	char ch;
	int CreditArr[] = { 5,4,3,3,1,2 };
	int IDArr[SIZE];
	int GPArr[SIZE];
	char letterArr[2];
	inp = fopen("courses.txt", "r");
	if (inp == NULL)
		printf("Cannot open");
	else
	{
		int i = 0, j = 0,status;
		double point;
		out = fopen("gpa.txt", "w");
		fscanf(inp, "%d", &id);
		fprintf(out, "%d", id);
		status=fscanf(inp, "%c", &ch);
		while (status!= EOF)
		{
			while (ch != '\n')
			{
				fscanf(inp, "%c", &ch);
				while (ch != ' ' && ch != '\n')
				{
					letterArr[i] = ch;
					i++;
					fscanf(inp, "%c", &ch);
				}


				switch (letterArr[0])
				{
				case'A':
					if (letterArr[1] == '-')
						point = 3.70;
					else point = 4.00;
					break;

				case'B':
					if (letterArr[1] == '-')
						point = 2.70;
					else if (letterArr[1] == '+')
						point = 3.30;
					else point = 3.00;
					break;
				case'C':
					if (letterArr[1] == '-')
						point = 1.70;
					else if (letterArr[1] == '+')
						point = 2.30;
					else point = 2.00;
					break;
				case'D':

					if (letterArr[1] == '+')
						point = 1.30;
					else point = 1.00;
					break;
				case 'F':
					point = 0.00;

				}
				sum += CreditArr[j] * point;
				j++;
				i = 0;
				letterArr[1] = { 'a' };


			}

			avg = sum / 18;
			fprintf(out, "  %4.2f\n", avg);
			sum = 0;

			j = 0;
			status = fscanf(inp, "%d", &id);
			if (status != EOF) {
				fprintf(out, "%d", id);
				status = fscanf(inp, "%c", &ch);
			}
			
		}
	}


	



}
