#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "list.h"

int main(void)
{

	FILE* list;
	list = fopen("numList.txt", "r");
	node_t* hp;
	hp= createList(list);

	displayList(hp);
}