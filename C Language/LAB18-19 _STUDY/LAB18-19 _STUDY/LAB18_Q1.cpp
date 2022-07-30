#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "linkedList.h"

int main(void)
{
	node_t* hp, * tp;
	int num;
	printf("Enter a number:");
	scanf("%d", &num);
	hp = NULL;
	hp=addBeginning(hp, num);
	tp = hp;
	while (num > 0)
	{
		printf("Enter a number:");
		scanf("%d", &num);
		addAfter(tp, num);
		tp = tp->next;
	}

	displayList(hp);

}