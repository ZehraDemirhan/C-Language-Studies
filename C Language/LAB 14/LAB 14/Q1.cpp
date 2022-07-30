#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 50


int findMax( int Array[10])
{
	int max,i;
	max = Array[0];
	for (i = 1; i <= SIZE; i++)
	{
		if (Array[i] > max)
			max = Array[i];
	}
	return(max);
	
}

void display(int Array[10])
{
	int i;
	printf("Grade    Frequency\n-----     --------\n");

	for (i = 0; i < 10; i++)
	{
		if (i != 9)
			printf("   %d \t", i + 1);
		else
			printf("  %d", i + 1);
		if (i!=9)
		printf("         %d", Array[i]);
		else 
			printf("             %d", Array[i]);
		printf("\n");

	}
}
int main(void)
{
	int Arr[SIZE];
	int num, i = 0,linecount=1, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0, count10 = 0;
	FILE* inp;
	inp = fopen("grades.txt", "r");
	if (inp == NULL)
		printf("The file cannot be opened!");
	else {
		
		while (fscanf(inp, "%d", &num) != EOF)
		{
			if (num == 1)
			{
				count1++;
				Arr[0] = count1;
			}
			if (num == 2)
			{
				count2++;
				Arr[1] = count2;
			}
			if (num == 3)
			{
				count3++;
				Arr[2] = count3;
			}
			if (num == 4)
			{
				count4++;
				Arr[3] = count4;
			}
			if (num == 5)
			{
				count5++;
				Arr[4] = count5;
			}
			if (num == 6)
			{
				count6++;
				Arr[5] = count6;
			}
			if (num == 7)
			{
				count7++;
				Arr[6] = count7;
			}
			if (num == 8)
			{
				count8++;
				Arr[7] = count8;
			}if (num == 9)
			{
				count9++;
				Arr[8] = count9;
			}if (num == 10)
			{
				count10++;
				Arr[9] = count10;
			}

			

		}

		findMax(Arr);
		display(Arr);
		i = 0;
		while(Arr[i] != findMax(Arr))
		
		{
			
			if (Arr[i] != findMax(Arr))
				linecount++;
			i++;

		}
		printf("\nMost of the students (%d students) have got the grade %d", findMax(Arr),linecount);
		
		fclose(inp);

	}

	return(0);
}