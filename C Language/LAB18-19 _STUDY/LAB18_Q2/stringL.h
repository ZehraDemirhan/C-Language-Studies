#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRSIZE 100
typedef char LType;

typedef struct node_s {
	LType data[STRSIZE];
	node_s* next;
}node_t;

node_t* getNode(void)
{
	node_t* newp;
	newp = (node_t*)malloc(sizeof(node_t));
	newp->next = NULL;
	return(newp);

}

void addAfter(node_t* p, LType* item)
{
	node_t* newp;
	newp = getNode();
	strcpy(newp->data, item);
	newp->next = p->next;
	p->next = newp;

}

node_t* addBeginning(node_t* hp, LType* item)
{

	node_t* newp;
	newp = getNode();
	strcpy(newp->data, item);
	newp->next = hp;
	return(newp);
}

void displayList(node_t* hp)
{
	node_t* tp;
	tp = hp;
	while (tp != NULL)
	{
		printf("%s->", tp->data);
		tp = tp->next;

	}
	printf("NULL");


}
