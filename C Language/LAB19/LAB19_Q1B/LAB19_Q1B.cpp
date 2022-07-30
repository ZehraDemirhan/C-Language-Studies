#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include "charList.h"

node_t* createList(int num)
{
	char ch;
	int i;
	node_t* tp, * hp;
	hp = NULL;
	ch = char('a' + rand() % 26);
	hp = addBeginning(hp, ch);
	tp = hp;
	for (i = 0; i < num - 1; i++)
	{
		ch = char('a' + rand() % 26);
		addAfter(tp, ch);

	}
	

	return(hp);


}

node_t* removeChar(node_t* hp, char toDel, char* founded)
{
	node_t* tp;
	tp = hp;
	if (tp->data == toDel)
	{
		hp=deleteFirst(hp, founded);
		if (hp->next != NULL)
			return(removeChar(hp, toDel, founded));
		
	}

	else {


		while (tp->next != NULL && tp->next->data != toDel)
		{
			tp = tp->next;

		}
		if (tp->next != NULL)
		{
			deleteAfter(tp, founded);
			
		}
		if (hp->next != NULL)
			return(removeChar(hp->next, toDel, founded));
	}
	
	

}

void displayRec(node_t* hp)
{
	if (hp != NULL)
	{
		printf("%c->", hp->data);
		displayRec(hp->next);
	}
	else {
		printf("NULL");
	}
}

int main(void)
{
	node_t* hp;
	
	char deleted;
	char ch;
	int num;
	printf("How many chars:");
	scanf("%d", &num);
	hp = createList(num);
	displayRec(hp);
	printf("\nEnter a char to delete:");
	scanf(" %c", &ch);
	removeChar(hp, ch, &deleted);
	
	
	displayRec(hp);
	


}