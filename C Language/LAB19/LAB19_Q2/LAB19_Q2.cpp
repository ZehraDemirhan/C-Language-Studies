#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include "structL.h"

node_t* createList(FILE* inp)
{
	node_t* hp, * tp;
	customer_t info;
	hp = NULL;
	fscanf(inp, "%d %s %d", &info.id, info.name, &info.year);
	hp = addBeginning(hp, info);
	tp = hp;
	while (fscanf(inp, "%d %s %d", &info.id, info.name, &info.year) != EOF)
	{
		addAfter(tp, info);
		tp = tp->next;
	}


	return(hp);

}

node_t* deletePolicy(node_t* hp)
{
	node_t* tp;
	customer_t deleted;
	tp = hp;
	while (tp->next != NULL)
	{
		if (hp->data.year < 2020)
		{
			hp = deleteFirst(hp, &deleted);
			tp = hp;
		}


		else if (tp->next->data.year < 2020)
		{

			deleteAfter(tp, &deleted);

		}
		else {
			tp = tp->next;
		}
	}
	return(hp);

}

int main(void)
{
	FILE *policies;
	policies = fopen("policies.txt", "r");
	if (policies == NULL)
		printf("Error!");
	else {

		node_t* hp,*tp;
		hp = createList(policies);
		printf("Original List :\n");
		tp = hp;
		while (tp != NULL)
		{
			printf("%d %s %d->", tp->data.id, tp->data.name, tp->data.year);
			tp = tp->next;

		}

		printf("\n\n*** Policies before year 2020 will be deleted ***\n");
		hp = deletePolicy(hp);
		tp = hp;

		while (tp != NULL)
		{
			printf("%d %s %d->", tp->data.id, tp->data.name, tp->data.year);
			tp = tp->next;

		}



	}


}