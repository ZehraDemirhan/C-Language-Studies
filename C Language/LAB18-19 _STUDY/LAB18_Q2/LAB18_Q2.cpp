#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "stringL.h"

node_t* crateList()
{
	char end[] = "END";
	char name[20];
	node_t* hp, * tp;
	hp = NULL;
	printf("Enter a player name:");
	scanf("%s", name);

	hp = addBeginning(hp, name);
	tp = hp;
	while (strcmp(name, end) != 0)
	{
		printf("Enter a player name:");
		scanf("%s", name);
		addAfter(tp, name);
		tp = tp->next;
	}
	return(hp);

}

node_t* findShortest(node_t* hp)
{
	node_t* shortest;
	shortest = hp;
	while (hp != NULL)
	{
		if (strlen(hp->data) < strlen(shortest->data))
		{
			shortest = hp;
		}
		hp = hp->next;
	}

	return(shortest);

}

int main(void)
{
	node_t* hp,*shortest;
	hp=crateList();
	displayList(hp);
	shortest = findShortest(hp);
	char name[20];

	printf("\nEnter a name to insert after the shortest name:");
	scanf("%s", name);
	printf("The shortest name is %s", shortest->data);

	addAfter(shortest, name);
	displayList(hp);



}