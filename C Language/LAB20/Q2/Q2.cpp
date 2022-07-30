#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "structL.h"

void createList(FILE* inp, node_t* arr[])
{
	node_t* hp;
	hp = NULL;
	user_t info;
	int index;
	while (fscanf(inp, "%d %[^:] : %[^\n] ", &info.id, info.username, &info.time) != EOF)
	{
	    index = info.id - 1;
		
	
       arr[index] = addBeginning(arr[index], info);
		
		
	}


}

void display(node_t* hp)
{

	while (hp != NULL)
	{
		printf("%d %-20s %-20s\n", hp->data.id, hp->data.username, hp->data.time);
		hp = hp->next;

	}
}

int main(void)
{

	FILE* courses;
	courses = fopen("courses.txt", "r");
	if (courses == NULL)
		printf("Error!");
	else {

		node_t* arr[3];
		int i;
		for (i = 0; i < 3; i++)
			arr[i] = NULL;
		createList(courses, arr);

		printf("Aerobics\n ***************************************\n");
		display(arr[0]);
		printf("Zumba\n ***************************************\n");
		display(arr[1]);

		printf("Pilates\n* **************************************\n");
		display(arr[2]);



	}
}