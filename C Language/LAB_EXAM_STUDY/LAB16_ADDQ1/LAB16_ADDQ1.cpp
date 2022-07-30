#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structQue.h"


void displayQue(queue_t que)
{
	printf("Topic Level\n* ******************************\n");
	question_t info;
	while (!isEmptyQ(&que))
	{
		info = remove(&que);
		printf("%-15s %-10s", info.topic, info.level);
	}
}

int main(void)
{

	FILE* math;
	math = fopen("math.txt", "r");
	if (math == NULL)
		printf("Error!");
	else {

		queue_t arr[3];
		question_t info;
		char easy[] = "Easy";
		char medium[] = "Medium";
		char hard[] = "Hard";

		initializeQ(&arr[0]);
		initializeQ(&arr[1]);
		initializeQ(&arr[2]);
		while (fscanf(math, "%[^:]:  %[^\n]", info.topic, info.level) != EOF)
		{
			if (strcmp(info.level, easy) == 0)
			{
				insert(&arr[0], info);

			}
			else if (strcmp(info.level, medium) == 0)
				insert(&arr[1], info);
			else
				insert(&arr[2], info);


		}

		printf("Easy Topics;\n");
		displayQue(arr[0]);

		printf("\nMedium Topics;\n");
		displayQue(arr[1]);

		printf("\nHard Topics;\n");
		displayQue(arr[2]);
		char YesNo;

		question_t newInfo;
		
		do {

			printf("\nDo you want to add any topic?:");
			scanf("%c", &YesNo);
			switch (YesNo)
			{
			case 'Y':printf("Enter the topic:");
				scanf("%s", newInfo.topic);
				printf("Enter level:");
				scanf("%s", newInfo.level);
				if (strcmp(newInfo.level, easy) == 0)
				{
					insert(&arr[0], newInfo);
					displayQue(arr[0]);

				}
				else if (strcmp(newInfo.level, medium) == 0)
				{

					insert(&arr[1], newInfo);
					displayQue(arr[1]);

				}

				else
				{
					insert(&arr[2], newInfo);
					displayQue(arr[2]);
				}

				break;
			case 'N':char levelnew[20];
				char questionNew[20];
				
				printf("\nWhich level do you prefer to solve questions ? : ");
				scanf("%s", levelnew);

				if (strcmp(levelnew, easy) == 0)
				{
					
					strcpy(questionNew, remove(&arr[0]).topic);
					printf("\nYou should solve the %s question",questionNew );


				}
				else if (strcmp(levelnew, medium) == 0)
				{
					strcpy(questionNew, remove(&arr[1]).topic);
					printf("\nYou should solve the %s question", questionNew);

				}

				else
				{
					strcpy(questionNew, remove(&arr[2]).topic);
					printf("\nYou should solve the %s question", questionNew);
				}
				printf("\nGood Luck :)");

				



			}

		} while (YesNo != 'N');

	}





	
}