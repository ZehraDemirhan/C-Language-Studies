#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct {
	char docName[20];
	char patientName[20];
	char operation[25];
	int time;
	char status[15];

}surgeries_t;

int main(void)
{

	FILE* surgery;
	FILE* output;
	int size;
	int random;
	int i;
	surgeries_t *arr,*arr2;
	char finished[] = "Finished";

	surgery = fopen("surgery.bin", "rb");
	output = fopen("output.bin", "wb");

	
	fseek(surgery,0,SEEK_END);
	size = ftell(surgery) / sizeof(surgeries_t);
	arr = (surgeries_t*)malloc(sizeof(surgeries_t) * size);



	rewind(surgery);

	printf("There are %d surgery in the file", size);
	srand(time(NULL));

	//random = 1 + rand() % size;
	int count = 0;
	fread(arr, sizeof(surgeries_t), size, surgery);
	for (i = 0; i < size; i++)
	{
		if (strcmp(arr[i].status, finished) == 0)
		{
			fwrite(arr + i, sizeof(surgeries_t), 1, output);
			count++;
		}


	}
	fclose(output);
	fclose(surgery);
	output = fopen("output.bin", "rb");
	arr2 = (surgeries_t*)malloc(sizeof(surgeries_t) * count);

	fread(arr2, sizeof(surgeries_t), count, output);
	for (i = 0; i < count; i++)
	{
		printf("\n%-15s %-15s %-15s %d %-15s\n", arr2[i].docName, arr2[i].patientName, arr2[i].operation, arr2[i].time, arr2[i].status);
	}


	fclose(output);
	free(arr2);



	//printf("\n\n%d surgery will be displayed\n", random);
	//printf("Doctor Patient Operation Time Status\n----------------------------------------------------------------------------------------\n");
	/*for (i = 0; i < random; i++)
	{
		
		printf("%-15s %-15s %-15s %d %-15s\n", arr[i].docName, arr[i].patientName, arr[i].operation, arr[i].time, arr[i].status);
	}
	*/


	free(arr);




}