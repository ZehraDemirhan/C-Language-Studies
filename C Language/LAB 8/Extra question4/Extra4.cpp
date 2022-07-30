#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void drawTriangle(void)
{
	int i, j,l,m;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (i != 4)
			{
				if (i + j == 4)
					printf("%d", i + 1);
				else if (j - i == 4)
					printf("%d", i + 1);
				else printf(" ");

			}


		}
		if (i!=4)
		printf("\n");
		if (i == 4)
		{
			printf("543212345");
		}
	}
}

void drawRhombus(void)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (i + j == 4)
				printf("%d", i + 1);
			else if (abs(i - j) == 4)
				printf("%d", i + 1);
			else if (i + j == 12)
				printf("%d", i + 1);
			else
				printf(" ");
		}
		printf("\n");
	}
}


void menu(void)
{
	printf("1. Draw a triangle\n2. Draw a rhombus\n3. Exit");
}

int main(void)
{	
	int choice;
	menu();

	
	
	do {
		printf("Enter your choice: ");
		scanf("%d", &choice);;
	} while (choice != 1 && choice != 2);

	switch (choice)

	{
		case 1:
			drawTriangle();
			break;
		case 2: 
			drawRhombus();


	}

	return(0);
}
