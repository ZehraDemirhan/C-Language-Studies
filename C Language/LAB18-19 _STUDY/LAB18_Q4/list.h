#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int LType;

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

node_t* searchToInsert(node_t* hp,LType item)
{
	node_t* p;
	p = hp;
	while (p->next != NULL)
	{
		if (p->next->data == item)
			return(NULL);
		else if (p->next->data < item)
			p = p->next;
		else
			return p;

			


	}
	return p;
	
	
}

node_t* createList(FILE* inp)
{
	node_t* hp, * tp;
	int num;
	
	hp = NULL;
	fscanf(inp,"%d", &num);
	hp = addBeginning(hp, num);
	tp = hp;
	while (fscanf(inp, "%d", &num) != EOF)
	{

		
		if (num<hp->data )
			hp= addBeginning(hp, num);

		
			
		else {
			tp = searchToInsert(hp, num);
			addAfter(tp, num);
		}
	}

	return(hp);
}

