#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structStack.h"
#include"stackTypeQue.h"


void displayStack(stack_t stack)
{
	course_t info;
	while (!isEmptyS(&stack))
	{
		info = pop(&stack);
		printf("%d %d-->", info.id, info.credit);

	
	}
	printf("END");
}

void displayQue(queue_t que)
{
	int count = 0;
	printf("QUEUE CONTENT\n----------------\n");
	while (!isEmptyQ(&que))
	{
		displayStack(que.data[count]);
		printf("\n");
		count++;

	}
}
int main(void)
{

	FILE* courses;
	courses = fopen("courses.txt", "r");
	if (courses == NULL)
		printf("Error!");
	else {

		stack_t stack;
		initializeS(&stack);
		queue_t que;
		initializeQ(&que);
		char ch;
		course_t info;
		while (fscanf(courses, "%d %d", &info.id, &info.credit) != EOF)
		{
			push(&stack, info);
			fscanf(courses,"%c",&ch);
			if (ch == '\n')
			{
				insert(&que, stack);
				while (!isEmptyS(&stack))
					pop(&stack);
			}


		}
		displayQue(que);
	}

}
