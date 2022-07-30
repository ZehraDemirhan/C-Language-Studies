#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "structL.h"

node_t* createList(FILE* inp)
{
	node_t* hp, * tp;
	hp = NULL;
	student_t info;
	fscanf(inp, "%s %s %s %d", info.name, info.surname, info.country, &info.lines);
	hp = addBeginning(hp, info);
	tp = hp;
	while (fscanf(inp, "%s %s %s %d", info.name, info.surname, info.country, &info.lines) != EOF)
	{
		addAfter(tp, info);
		tp = tp->next;
	}
	return(hp);
}

void displayListH(node_t* hp)
{
	while (hp != NULL)
	{
		printf("%-15s %-15s %-15s %d\n", hp->data.name, hp->data.surname, hp->data.country, hp->data.lines);
		hp = hp->next;

	}

}
node_t* searchCountry(node_t* hp,char *country)
{
	
	while (hp != NULL && strcmp(hp->data.country, country) != 0)
	{
		hp = hp->next;
	}
	if (hp == NULL)
		return(NULL);
	else
	return(hp);
}

node_t* findWinner(node_t* hp)
{
	node_t* winner;
	winner = hp;
	while (hp != NULL)
	{
		if (winner->data.lines < hp->data.lines)
		{
			winner = hp;
		}
		hp = hp->next;
	}
	return(winner);
}

int main(void)
{
	FILE* student;
	student = fopen("students.txt", "r");
	if (student == NULL)
		printf("Error!");
	else {
		node_t* hp;
		node_t* winner;
		node_t* find;
		char search[20];
		hp = createList(student);
		printf("List of ALL Student\n");
		displayListH(hp);

		winner = findWinner(hp);
		printf("\n\nThe winner is: %s %s,%s,%d", winner->data.name, winner->data.surname, winner->data.country, winner->data.lines);
		
		printf("\n\nEnter a country to search:");
		scanf("%s", search);

		find = searchCountry(hp, search);
		if (find == NULL)
			printf("\n\nThere is no student from %s", search);
		else {
			printf(" \n\n%s %s,%s,%d", find->data.name, find->data.surname, find->data.country, find->data.lines);
		}
		fclose(student);



	}

}