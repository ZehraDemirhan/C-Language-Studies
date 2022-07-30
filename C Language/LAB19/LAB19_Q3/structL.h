#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char username[100];
	char city[100];
	char login[100];

}alert_t;

typedef alert_t LType;

typedef struct node_s {

	LType data;
	node_s* next;
}node_t;

node_t* getNode()
{
	node_t* newp;
	newp = (node_t*)malloc(sizeof(node_t));
	newp->next = NULL;
	return(newp);
}
void addAfter(node_t* p, LType item)
{
	node_t* newp;
	newp = getNode();
	newp->data = item;
	newp->next = p->next;
	p->next = newp;


}

node_t* addBeginning(node_t* hp, LType item)
{
	node_t* newp;
	newp = getNode();
	newp->data = item;
	newp->next = hp;
	return(newp);

}
void displayList(node_t* hp)
{
	printf("Login information for the users who may have suspicious activites:\n");
	printf("User Name City Last Login\n***********************************\n");
	while (hp != NULL)
	{
		printf("%-15s %-25s %-30s->\n", hp->data.username, hp->data.city, hp->data.login);
		hp = hp->next;

	}

}

void deleteAfter(node_t *p,LType *deleted)
{
	node_t* del;
	del = p->next;
	*deleted = del->data;
	p->next = del->next;
	free(del);


}

node_t* deleteFirst(node_t* hp, LType* deleted)
{
	node_t* del;
	del = hp;
	*deleted = del->data;
	hp = del->next;
	free(del);
	return(hp);

}

