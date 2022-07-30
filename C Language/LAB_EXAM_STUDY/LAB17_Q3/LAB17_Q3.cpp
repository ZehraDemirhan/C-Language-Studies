#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "que.h"
#include "stack.h"

void carWash(stack_t* stack, queue_t* que, char code, int id)
{
	stack_t temp;
	initializeS(&temp);
	


	switch (code)
	{
	case 'A':if (!isFullQ(que))
	{
		insert(que, id);
	}
			break;
	case 'D':
		while (!isEmptyS(stack))
		{
			push(&temp, pop(stack));
		}
		int num;
		while (!isEmptyS(&temp))
		{
			num = pop(&temp);
			if (num != id)
			{
				push(stack, num);
			}
			

		}
		push(stack, remove(que));

		break;

	}
}

void displayStack(stack_t stack)
{
	printf("The washing lanes:\n");
		while (!isEmptyS(&stack))
		{
			printf("%d\n", pop(&stack));
				
		}
}

void displayQue(queue_t que)
{
	printf("\nThe car Queue:");

	while (!isEmptyQ(&que))
	{
		printf("%d ", remove(&que));

	}
	printf("\n");

}

int main(void)
{
	FILE* carwash;
	carwash = fopen("carWash.txt", "r");
	if (carWash == NULL)
		printf("Error!");
	else {

		char code;
		int id;
		queue_t que;
		stack_t stack;
		initializeQ(&que);
		initializeS(&stack);
		push(&stack, 1);
		push(&stack, 2);
		push(&stack, 3);

		while (fscanf(carwash, " %c %d", &code, &id) != EOF)
		{
			carWash(&stack, &que, code, id);
			displayStack(stack);
			displayQue(que);
		}
		fclose(carwash);
	}
}