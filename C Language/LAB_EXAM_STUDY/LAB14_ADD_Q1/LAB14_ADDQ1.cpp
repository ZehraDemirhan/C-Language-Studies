#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {

	char name[25];
	int stock;
	int stockarrive;
}item_t;

int recBinarySearch(FILE* inp, char* arr, int top, int bottom)
{
	int middle;
	item_t info;
	if (top < bottom)
	{

		middle = (top + bottom) / 2;
		fseek(inp, sizeof(item_t) * middle, SEEK_SET);
		fread(&info, sizeof(item_t), 1, inp);
		if (strcmp(info.name, arr) == 0)
		{
			printf("top: %d, bottom: %d,middle: %d, %s\n", top, bottom, middle, info.name);
			return(middle);
		}
		else if (strcmp(info.name, arr) > 0)
		{
			printf("top: %d, bottom: %d,middle: %d, %s\n", top, bottom, middle, info.name);
			return(recBinarySearch(inp, arr, top, middle - 1));
		}
		else {
			printf("top: %d, bottom: %d,middle: %d, %s\n", top, bottom, middle, info.name);
			return(recBinarySearch(inp, arr, middle + 1, bottom)); }
	}
	else return(-1);

}

int main(void)
{
	FILE* items;
	items = fopen("items.bin", "rb");
	if (items == NULL)
		printf("Error!");
	else {

		int size;
		char search[20];
		int index;
		item_t info;

		fseek(items, 0, SEEK_END);
		size = ftell(items) / sizeof(item_t);
		rewind(items);
		printf("There are %d items in the list\n", size);

		printf("Enter an item to search:");
		scanf("%s", search);
		index = recBinarySearch(items, search, 0, size-1);
		fseek(items, sizeof(item_t) * index, SEEK_SET);
		fread(&info, sizeof(item_t), 1, items);
		printf("%s found with %d  stock and %d stock will arrive", search, info.stock, info.stockarrive);
	
		fclose(items);


	}

}
