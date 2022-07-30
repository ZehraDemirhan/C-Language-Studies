#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "structL.h"

void displayList(node_t* hp)
{
	printf("ID Name Price\n-------------------------\n ");
	while (hp != NULL)
	{
		printf("%d %s %.2f\n", hp->data.id, hp->data.name, hp->data.price);
		hp = hp->next;


	}

}

int menu()
{
	int choice;
	printf("MENU\n---------------\n1. Add Record\n2. Update Record\n3. Exit\n");
	printf("Enter your choice:");
	scanf("%d", &choice);

	return(choice);

}

node_t* searchNode(node_t* hp, int ID)
{
	while (hp != NULL && hp->data.id != ID)
		hp = hp -> next;

	return(hp);

}

node_t* addToEnd(node_t* hp, vegAndFruit_t info)
{

	node_t* tp;
	tp = hp;
	while (tp->next != NULL)
		tp = tp->next;
	addAfter(tp, info);
	return(hp);
}

node_t* createList(FILE* inp)
{
	node_t* hp, * tp;
	vegAndFruit_t info;
	hp = NULL;
	fscanf(inp, "%d %s %lf", &info.id, info.name, &info.price);
	hp = addBeginning(hp, info);
	tp = hp;
	while (fscanf(inp, "%d %s %lf", &info.id, info.name, &info.price) != EOF)
	{
		addAfter(tp, info);
		tp = tp->next;
		
	}
	return(hp);

}

void updateList(node_t* hp, node_t* p, int fieldNo)
{
	switch (fieldNo)
	{
	case 1:int id;
		printf("Enter the new Id:");
		scanf("%d", &id);
		p->data.id = id;
		break;
	case 2:char newName[20];
		printf("Enter the new name: ");
		scanf("%s", newName);
		strcpy(p->data.name, newName);
		break;
	case 3:double price;
		printf("Enter new price:");
		scanf("%lf", &price);
		p->data.price = price;


	
	}
}

void writeList(node_t* hp, char* name)
{
	FILE* output;
	output = fopen(name, "wb");
	while (hp != NULL)
	{
		fwrite(&(hp->data), sizeof(vegAndFruit_t), 1, output);
		hp = hp->next;
	}
}

int main(void)
{

	char textName[] = "veganfruit.txt";
	char inputName[50];
	char bin[] = ".bin";
	do {
		printf("Enter the text file name:");
		scanf("%s", inputName);

	} while (strcmp(textName, inputName) != 0);

	FILE* vegetables;
	vegetables = fopen(inputName, "r");
	node_t* hp;
	node_t* found;
	int choice;
	hp = createList(vegetables);
	displayList(hp);
	do {
		choice = menu();
		switch (choice)
		{
		case 1:vegAndFruit_t info;
			do {
				printf("\nEnter vegetable ID:");
				scanf("%d", &info.id);
				if (searchNode(hp, info.id) != NULL)
					printf("The ID:%d already exists", info.id);
			} while (searchNode(hp,info.id ) != NULL);
			printf("Enter vegetable name : ");
			scanf("%s", info.name);
			printf("Enter vegetable price : ");
			scanf("%lf", &info.price);
			addToEnd(hp, info);
			displayList(hp);

			break;

		case 2:int recordId;
			int updateChoice;
			node_t* whereTochange;
			printf("\nEnter vegetable ID:");
			scanf("%d", &recordId);
			whereTochange = searchNode(hp, recordId);
			printf("\n%d %s %.2f\n", whereTochange->data.id, whereTochange->data.name, whereTochange->data.price);

			printf("\n\nUpdate (1. ID, 2. Name, and 3. Price):");
			scanf("%d", &updateChoice);
			updateList(hp, whereTochange, updateChoice);
			displayList(hp);



		}

	} while (choice != 3);
	int i = 0;
	while (*(textName + i) != '.')
		i++;

	char tmp[20];
	strncpy(tmp, textName, i);
	tmp[i] = '\0';
	strcat(tmp, bin);


	printf("Writing linkedlist to binary file %s", tmp);
	writeList(hp, tmp);

}