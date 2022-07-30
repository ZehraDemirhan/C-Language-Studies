#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#include <stdio.h>

int acrostic(FILE* inp, char Arr[])
{
	if (inp == NULL)
		printf("Cannot open file ");

	else
	{
		char ch,status;
		int i = 1;
		status=fscanf(inp,"%c",&ch);
		Arr[0] = ch;
		while (status != EOF)
		{
			if (ch == '\n')
			{
				status =fscanf(inp, "%c", &ch);
				Arr[i] = ch;
				i++;
			}

			else {
				status= fscanf(inp, "%c", &ch);

			}

		}
		return(i);
	}

}

int main(void)
{
	
	FILE * inp;
	char Arr[SIZE];
	inp = fopen("acrostic.txt", "r");
	int size,i;
	size=acrostic(inp, Arr);
	for (i = 0; i < size; i++)
	{
		printf("%c\n", Arr[i]);
	}
	return(0);
}