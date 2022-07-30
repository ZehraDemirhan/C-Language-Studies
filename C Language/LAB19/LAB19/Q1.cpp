#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include "charList.h"

node_t* createList()
{
	char ch;
	char stop = '!';
	node_t* tp, *hp;
	hp = NULL;
	printf("Enter a character (or ! to stop):");
	scanf(" %c", &ch);
	if(ch!='!')
	hp = addBeginning(hp, ch);
	tp = hp;
	while (ch != stop)
	{
		printf("Enter a character (or ! to stop):");
		scanf(" %c", &ch);
		if (ch != '!')
		{
			addAfter(tp, ch);
			tp = tp->next;
		}


	}

	return(hp);


}

node_t* removeChar(node_t* hp, char toDel, char* founded, int *isFounded)
{
	node_t* tp;
	tp = hp;
	if (tp->data == toDel)
	{
		deleteFirst(hp, founded);
		*isFounded = 1;
	}

	else {
		while (tp->next != NULL && tp->next->data != toDel)
		{
			tp = tp->next;

		}
		if (tp ->next!= NULL)
		{
			deleteAfter(tp, founded);
			*isFounded = 1;
		}
		else
		{
			*isFounded = 0;
		}
	}
	
	return(hp);

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
	int isfounded;
	char deleted;
	char ch;
	hp = createList();
	displayRec(hp);
	printf("Enter a char to delete:");
	scanf(" %c", &ch);
	removeChar(hp, ch, &deleted, &isfounded);
	if (!isfounded)
		printf("The charachter %c is NOT founded in the list", ch);
	else {
		displayRec(hp);
	}


}