#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void drawTriangle(void)
{
	int i, j;
	for (i=1;i<=5;i++)
	{
		for (j = 0; j <=(5 - i); j++)
		{
			
			if ((i + j) == 5)
			{
				printf("%d", i);
				
			}
			printf(" ");
		}
		
		
		for (j = 1; j <=(5 + i); j++)
		{
			
			if ( abs(j-i)==5)
				printf("%d", i + 1);
			printf(" ");
		}
		printf("\n");
	}
}

int main(void)
{
	drawTriangle();
}