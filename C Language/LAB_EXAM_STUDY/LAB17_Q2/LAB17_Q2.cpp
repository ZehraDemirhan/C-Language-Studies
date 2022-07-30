#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stringQue.h"

int main(void)
{

	queue_t PC1, PC2, PC3, buffer, printed;
	initializeQ(&PC1);
	initializeQ(&PC2);
	initializeQ(&PC3);
	initializeQ(&buffer);
	initializeQ(&printed);

	char document1[] = "Alumni Information Form";
	char document2[] = "Academic Phone Numbers";
	char document3[] = "Health Reports";
	char document4[] = "Advisor List";
	char document5[] = "New Course Add Form";
	char document6[] = "Course Outline";

	insert(&PC1, document1);
	insert(&PC1, document2);
	insert(&PC1, document3);
	insert(&PC2, document4);
	insert(&PC2, document5);
	insert(&PC3, document6);

	char command;
	int pc;
	FILE* printing;
	printing = fopen("printing.txt", "r");
	while (fscanf(printing, "%c", &command) != EOF)
	{
		if (command =='S')
		{
			fscanf(printing, "%d", &pc);
			switch (pc)
			{
			case 1:insert(&buffer, remove(&PC1));
				break;
			case 2:insert(&buffer, remove(&PC2));
				break;
			case 3:insert(&buffer, remove(&PC3));

			}


		}
		else if (command == 'P')
		      insert(&printed,remove(&buffer));

			
		
	}
	printf("Pending Jobs:\n");
	while (!isEmptyQ(&buffer))
	{
		printf("%s\n", remove(&buffer));

	}

	printf("\nPrinted Jobs:\n");
	while (!isEmptyQ(&printed))
	{
		printf("%s\n", remove(&printed));

	}

	fclose(printing);

}