#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "structL.h"
#define SIZE 10

int hasCode(char *key)
{
	int sum = 0;
	int i = 0;
	while (*(key + i) != '\0')
	{
		sum += *(key + i);
		i++;
	}

	return(sum );

}

void initArray(node_t* Ht[])
{
	int i;
	for (i = 0; i < SIZE; i++)
		Ht[i] = NULL;


}
int menu()
{
	int choice;
	printf("MENU\n* ************************************\n1. Insert a user into the Hash Table\n2. Remove a user from the Hash Table\n3. Display a Hash Table\n4. Exit\n");
	printf("Please enter your choice :");
	scanf("%d", &choice);
	return(choice);
}

node_t* seacrhUser(node_t* Ht[], char* username)
{
	int index;
	index = hasCode(username);
	while (Ht[index] != NULL && strcmp(Ht[index]->data.username,username)!=0)
	{
		Ht[index] = Ht[index]->next;


	}
	return(Ht[index]);


}

void inserUser(node_t* Ht[], user_t info)
{
	int index;
	index = hasCode(info.username)%10;

	node_t* p, * tp;
	if (Ht[index] == NULL)
		Ht[index] = addBeginning(Ht[index], info);
	else {
		p = seacrhUser(Ht, info.username);
		if (p != NULL)
		{
			p->data = info;
		}
		else {
			tp = Ht[index];
			while (tp->next != NULL)
				tp = tp->next;
			addAfter(tp, info);


		}
	}

}

void removeUser(node_t* Ht[], char* username)
{

	int index = hasCode(username)%10;
	if (Ht[index] == NULL)
		printf("Cannot remove");
	else {
		user_t info;
		if (strcmp(Ht[index]->data.username, username) == 0)
			Ht[index] = deleteFirst(Ht[index], &info);
		else {
			node_t* tp;
			tp = Ht[index];
			while(tp->next!=NULL && strcmp(tp->next->data.username,username)!=0)
			{
				tp = tp->next;

			}

			deleteAfter(tp, &info);
		}



	}
}

void display(node_t* Ht[])
{
	int i;
	node_t* tp;
	

	for (i = 0; i < SIZE; i++)
	{
		printf("Head [%d] has",i);
		if (Ht[i] == NULL)
			printf("no elements\n");
		else {
			tp = Ht[i];
			while (tp != NULL)
			{
				printf("%s %s ->", tp->data.username, tp->data.password);
				tp = tp->next;
			}

			printf("NULL\n");
		}

	}

}

int main(void)
{
	int choice;
	node_t* Ht[SIZE];
	initArray(Ht);
	do {
		choice = menu();

		switch (choice)
		{

		case 1:user_t info;
			printf("Enter username and password :");
			scanf("%s %s", info.username, info.password);
			printf("Total of ASCII codes:%d", hasCode(info.username));
			inserUser(Ht, info);
			printf("\nInserted User:%s(username) and %s (password)\n\n", info.username, info.password);
			break;

		case 2:char name[20];
			printf("Enter the username to delete : ");
			scanf("%s", name);
			printf("\nTotal of ASCII codes:%d", hasCode(name));
			removeUser(Ht, name);
			printf("\nUser which has the username %s has removed\n\n", name);

			break;
		case 3: display(Ht);
			break;




		}
	} while (choice != 4);

}