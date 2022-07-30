#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 7 


void readFile(FILE* inp, char** arr,int num)
{
	
	int r = 0, c = 0;
	while (fscanf(inp, "%s", *(arr + r)) !=EOF)
	{
		if (r != num- 1)
		{
			r++;

		}
		
	}
	

}

void displayrows(char *arr)
{
	printf("%s", *(arr));

	
}

void displayWordSpecCol(char** arr)
{
	int num;
	printf("Enter the column:");
	scanf("%d", &num);
	printf("%s", *(*(arr)+num));

}

int main(void)
{
	FILE* words;
	words = fopen("words.txt", "w");
	if (words = NULL)
		printf("Cannot open the file!");
	else
	{
		int num;

		fscanf(words, "%d", &num);
		char** arr = malloc(sizeof(char*) * 10);
		int i;
		for (i = 0; i < SIZE; i++)
		{
			arr[i] = malloc(sizeof(char) * num);
		}
		readFile(words, arr, num);
		int i;
		printf("WORDS\n");
		printf("------\n");

		for (i = 0; i < num; i++)
		{
			displayrows(*(arr + i));
			printf("\n");


		}
		displayWordSpecCol(arr);

	}
}