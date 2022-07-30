#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 50

int readFromFile(FILE* inp, int IDArr[], int ByearArr[])
{
	if (inp == NULL)
		printf("Cannot open the file!");
	else
	{
		int i = 0;
		while (fscanf(inp, "%d %d ", &IDArr[i], &ByearArr[i]) != EOF)
		{
			i++;
		}

		return(i);
	}
}

int oldAgeSalary(int ByearArr[], int size, int indexArr[])
{
	int YearLimit = 2021 - 65;
	int i;
	int j=0;

	for (i = 0; i < size; i++)
	{
		if (ByearArr[i] < YearLimit)
		{
			indexArr[j] = i;
			j++;
		}
	}
	return(j);

}

int main(void)
{
	FILE* inp;
	int YArray[SIZE];
	int IDArray[SIZE];
	int IndexArr[SIZE];
	int size,i;
	int people;
	inp = fopen("people.txt", "r");

	size= readFromFile(inp, IDArray, YArray);
	
	
	people = oldAgeSalary(YArray, size, IndexArr);

	printf("The List of people who are >= 65 and got the old-age salary\n");

	for (i = 0; i < people; i++)
	{
		printf("%d  %d\n", IDArray[IndexArr[i]], YArray[IndexArr[i]]);
	}
	printf("There are %d people.", people);
	return(0);

}