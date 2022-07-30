#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "structQue.h"


int removeFromQue(queue_t *que, char* name ,package_t *holderInfo)
{
	package_t info;
	queue_t temp;
	int count = 0;
	initializeQ(&temp);
	while (!isEmptyQ(que))
	{
		info = remove(que);
		if (strcmp(info.hauseHolder, name) != 0)
			insert(&temp, info);
		else {
			*holderInfo = info;
			count++;
			
		}

			
	}

	while (!isEmptyQ(&temp))
	{
		insert(que, remove(&temp));

	}
	if (count != 0)
		return(1);
	else
		
	return(0);


}


void fillQue(FILE* inp, queue_t* que)
{
	package_t info;
	while (fscanf(inp, " %[^:]: %d %lf", info.hauseHolder, &info.distance, &info.noOfPeople) != EOF)
	{
		info.noOfPackage = ceil(info.noOfPeople / 2);
		insert(que, info);


	}

}

void displayQue(queue_t que)
{
	package_t info;
	while (!isEmptyQ(&que))
	{
		info = remove(&que);
		printf("%-20s %d %.f %.f\n", info.hauseHolder, info.distance, info.noOfPeople, info.noOfPackage);


	}
}

int main(void)
{

	FILE* village;
	village = fopen("village.txt", "r");
	if (village == NULL)
		printf("Eror!");
	else {
		char damaged;
		char searchHouse[20];
		queue_t que;
		initializeQ(&que);
		fillQue(village, &que);
		do {

		
		printf("The list of people;\n");
		displayQue(que);
		printf("All of the package were distubuted\n");

		printf("Do we have damaged package? ( Y / N ): ");
		scanf(" %c", &damaged);
		switch (damaged)
		{

		case 'Y':printf("Enter household:");
			scanf(" %[^\n]", searchHouse);
			package_t deleteInfo;
			int isDeleted;
			int damagedNo;
			isDeleted = removeFromQue(&que, searchHouse, &deleteInfo);
			if (!isDeleted)
			{
				printf("\nThere is no householder with the specified name!");
			}
			else {
				printf("\nEnter how many was damaged?:");
				scanf("%d", &damagedNo);
				deleteInfo.noOfPackage -= damagedNo;
				insert(&que, deleteInfo);


			}
			break;

		case 'N':printf("Thank you for your help :)");

		}

		} while (damaged != 'N');
		
		fclose(village);

	}
}