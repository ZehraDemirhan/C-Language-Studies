#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int myStrlen(char* str)
{
	int count = 0;
	while (*(str + count) != '\0')
	{
		count++;

	}
	return(count);
}

int main(void)
{
	FILE* words;
	words = fopen("words.txt", "r");
	if (words == NULL)
		printf("Cannot open the file");
	else {
		FILE* result;
		result = fopen("result.txt", "w");
		char* str;
		str = (char*)malloc(sizeof(char) * 50);
		int i = 0;
		
		while (fscanf(words, "%s", str + i) != EOF)
		{
			 

			fprintf(result,"%s-%d\n",(str+i), myStrlen(str + i));
			i++;

		}
	}
}