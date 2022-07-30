#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 50

int main(void)
{
	FILE* courses;
	FILE* gpa;
	courses = fopen("courses.txt", "r");
	if (courses == NULL)
		printf("Error!");
	else {
		gpa = fopen("gpa.txt", "w");
		double gpaArr[SIZE];
		int IDArr[SIZE];
		double sum = 0;
		double points;
		int creditArr[] = { 5,4,3,3,1,2 };
		int i = 0;
		char ch1,ch2;
		while (fscanf(courses, "%d", &IDArr[i]) != EOF)
		{
			int k;
			int count = 0;
			for (k = 0; k < 6; k++)
			{

				fscanf(courses, " %c%c", &ch1, &ch2);

				switch (ch1)
				{
				case 'A':
					if (ch2 == '-')
						points = 3.70;
					else points = 4.00;
					break;
				case 'B':
					if (ch2 == '+')
						points = 3.30;
					else if (ch2 == '-')
						points = 2.70;
					else points = 3.00;
					break;
				case 'C':
					if (ch2 == '+')
						points = 2.30;
					else if (ch2 == '-')
						points = 1.70;
					else points = 2.00;
					break;
				case 'D':
					if (ch2 == '+')
						points = 1.30;

					else points = 1.00;
					break;
				default:
					points = 0;


				}
				sum += points * creditArr[count];
				count++;

			}
			
			count = 0;
			gpaArr[i] = sum / 18;
			sum = 0;
			i++;
		}
		int j;
		for (j = 0; j < i; j++)
		{
			fprintf(gpa, "%d %4.2f\n", IDArr[j], gpaArr[j]);

		}

	}
}