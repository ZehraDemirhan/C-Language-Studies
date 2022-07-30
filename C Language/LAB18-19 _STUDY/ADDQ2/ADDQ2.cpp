#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "structQue.h"

int readTruckInfo(FILE* inp, queue_t *que, int minWeight)
{
	int count = 0;
	truck_t info;
	while (fscanf(inp, "%s %d", info.licenceID, &info.capacity) != EOF)
	{
		if (info.capacity >= minWeight)
		{
			insert(que, info);
			count++;
		}

	}
	return(count);

}

truck_t displayTrucks(queue_t que,int weight)
{
	truck_t info;
	info = remove(&que);

	printf("%s %d\n", info.licenceID, info.capacity);
	truck_t min = info;
	while (!isEmptyQ(&que))
	{
		info = remove(&que);

		printf("%s %d\n", info.licenceID, info.capacity);
		if (info.capacity - weight < min.capacity-weight)
			min = info;
	}
	return(min);
}

int main(void)
{

	FILE* truck;
	truck = fopen("truck.txt", "r");
	if (truck == NULL)
		printf("Cannot open file!");
	else {
		int minWeight;
		int size;
		int truckCount;
		int i;
		queue_t que;
		truck_t minWasted;
		truck_t info;
		initializeQ(&que);
		printf("Enter mim weight:");
		scanf("%d", &minWeight);
		size = readTruckInfo(truck, &que, minWeight);
		printf("There are %d trucks\n", size);
		minWasted=displayTrucks(que, minWeight);
		printf("\nThe truck %s  will have the minimum wasted capacity with %d\n", minWasted.licenceID, minWasted.capacity);
		printf("How many trucks do you need?:");
		scanf("%d", &truckCount);
		for (i = 0; i < truckCount; i++)
		{
			info = remove(&que);
			printf("%d. truck %s %d\n", i + 1, info.licenceID, info.capacity);


		}
		printf("There are %d trucks\n***************\n",size-truckCount);
		displayTrucks(que, minWeight);





	}
}