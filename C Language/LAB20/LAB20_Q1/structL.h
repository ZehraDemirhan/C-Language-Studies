#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct {
	char username[20];
	char password[20];
}user_t;

typedef user_t LType;

typedef struct node_s {
	LType data;
	node_s* next;
}node_t;

node_t* getNode(void)
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

node_t* deleteFirst(node_t* hp, LType* item)
{
	node_t* del;
	del = hp;
	*item = del->data;
	hp = del->next;
	free(del);
	return(hp);


}

void deleteAfter(node_t* hp, LType* item)
{
	node_t* del;
	del = hp->next;
	*item = del->data;
	hp->next = del->next;
	free(del);

}

void displayList(node_t* hp)
{
	node_t* tp;
	tp = hp;
	while (tp != NULL)
	{
		printf("%d->", tp->data);
		tp = tp->next;

	}
	printf("NULL");


}

