#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void drawTriangle(void)
{
	int i, j, k,l,m;
	for (i = 0; i < 5; i++)
	{
		for (j = 1; j < (5 - i); j++)
		{
			printf(" ");
		}

		printf("%d", i+1);
		if (i == 0)
			printf("\n");
		if (i != 0)
		{
			if (i != 4)
			{
				for (k = 1; k < 2 * i; k++)

				{
					printf(" ");
				}
				printf("%d", i + 1);
			    printf("\n");
			}
			
			if(i == 4)
			{
				for (l = 4; l >= 1; l--)
					printf("%d", l);
				for (m = 2; m <= 5; m++)
					printf("%d", m);

			}
				
		}

		

	}

}




int main(void)
{
	drawTriangle();
}