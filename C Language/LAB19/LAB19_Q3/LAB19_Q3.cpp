#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "structL.h"

node_t* createList(FILE* inp)
{
	node_t* hp, *tp;
	hp = NULL;
	alert_t info;
	fscanf(inp, "%[^\,] ,%[^\,] , %[^\n] ", info.username, info.city, info.login);
	hp = addBeginning(hp, info);
	tp = hp;
	while (fscanf(inp,"%[^\,] ,%[^\,] , %[^\n] " , info.username, info.city, info.login) != EOF)
	{
		addAfter(tp, info);
		tp = tp -> next;
	}

	return(hp);
}

void searchForAUser(node_t* hp, char* susername,int* isfound)
{
	*isfound = 0;
	while (hp!= NULL)
	{
		if (strcmp(hp->data.username, susername) == 0)
		{
			printf("%-15s %-30s %-30s->\n", hp->data.username, hp->data.city, hp->data.login);
			*isfound = 1;
			

		}
		hp = hp->next;
	}


}

node_t* deleteUserLogins(node_t* hp, char* susername)
{
	alert_t deleted;
	node_t* tp;
	tp = hp;
	while (tp->next != NULL)
	{
		if (strcmp(hp->data.username, susername) == 0)
		{
			hp = deleteFirst(hp, &deleted);
			tp = hp;
		}
		else if (strcmp(tp->next->data.username, susername) == 0)
			deleteAfter(tp, &deleted);
		else tp = tp->next;
	}
	return(hp);
}

int main(void)
{
	FILE* alert;
	alert = fopen("alert.txt", "r");
	if (alert == NULL)
		printf("Error!");
	else {
		node_t* hp;
		char search[20];
		int isfound;
		char yesNo;
		hp = createList(alert);
		displayList(hp);

		printf("\nPlease enter your account name to see the login history:");
		scanf("%s", search);
		searchForAUser(hp, search, &isfound);
		if (!isfound)
			printf("\nThere is no account with the name %s!\n", search);
		else {
			printf("Is there any suspicious account activity? (y/n):");
			scanf(" %c", &yesNo);
			if (yesNo == 'n')
				printf("\n\n** All the login info will be deleted ***\n\n");
			printf("Login history updated!\n\n");
			hp=deleteUserLogins(hp, search);
			displayList(hp);

		}



	}
}