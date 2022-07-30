#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"que.h"
#include"stack.h"

void displayQue(queue_t que)
{
	printf("Queue contents:\n");
	stock_t info;
	while (!isEmptyQ(&que))
	{
		info = remove(&que);
		printf("%d %.2f %d\n", info.id, info.price, info.amount);

	}
}
void displayStack(stack_t stack)
{
	stock_t info;
	printf("\nStack contents:\n");
	while (!isEmptyS(&stack))
	{
		info = pop(&stack);
		printf("%d %.2f %d\n", info.id, info.price, info.amount);


	}
}
int main(void)
{

	FILE* items;
	items = fopen("items.txt", "r");
	if (items == NULL)
		printf("Error!");
	else {
		stock_t info;
		stack_t myStack;
		queue_t myQue;
		stock_t info2;
		int addedAmount;
		initializeQ(&myQue);
		initializeS(&myStack);

		while (fscanf(items, "%d %lf %d", &info.id, &info.price, &info.amount) != EOF)
		{
			if (info.amount > 100)
				push(&myStack, info);
			else {
				insert(&myQue, info);
			}

		}
		displayQue(myQue);
		displayStack(myStack);

		while (!isEmptyQ(&myQue))
		{
			info2 = remove(&myQue);
			printf("Enter the purchase amount for the item %d (min %d)", info2.id, 100 - info2.amount);
			scanf("%d", &addedAmount);
			if (addedAmount < 100 - info2.amount)
			{
				do {
					printf("\nWrong Input!\n");
					printf("Enter the purchase amount for the item %d (min %d)", info2.id, 100 - info2.amount);
					scanf("%d", &addedAmount);
				} while (addedAmount < 100 - info2.amount);
				
			}

			else {
				info2.amount += addedAmount;
				push(&myStack, info2);
			}
		}

		printf("\nStack contents after purchases:\n");
		displayStack(myStack);

	}
}