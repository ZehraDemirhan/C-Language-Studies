#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char LType;

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

void deleteAfter(node_t* p, LType* item)
{
	node_t* del;
	del = p->next;
	*item = del->data;
	p->next = del->next;
	free(del);

}