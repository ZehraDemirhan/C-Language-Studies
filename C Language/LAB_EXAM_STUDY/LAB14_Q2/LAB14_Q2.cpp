#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char docName[20];
	char patientName[20];
	char operation[25];
	int time;
	char status[15];

}surgeries_t;

/*int binSearch(FILE* inp, char* arr)
{
	surgeries_t info;
	fread(&info, sizeof(surgeries_t), 1, inp);
	if (strcmp(info.patientName, arr) == 0)
		return(0);
	else {
		fseek(inp, sizeof(surgeries_t), SEEK_SET);
		return(1 + binSearch(inp, arr));
	}

}*/

int binSearch(FILE* inp, char* arr, int top, int bottom)
{

	int middle;
	surgeries_t info;
	if (top <= bottom)
	{
		middle = (top + bottom) / 2;
		fseek(inp, sizeof(surgeries_t) * middle, SEEK_SET);
		fread(&info, sizeof(surgeries_t), 1, inp);
		if (strcmp(info.patientName, arr) == 0)
			return(middle);
		else if (strcmp(info.patientName, arr) > 0)
			return(binSearch(inp, arr, top, middle - 1));
		else return(binSearch(inp, arr, middle + 1, bottom));
	}
	else return(-1);


}

int main(void)
{

	FILE* surgery;
	surgeries_t* arr;
	surgeries_t info;
	surgery = fopen("surgery.bin", "rb");
	int size;
	char name[20];
	printf("Enter a name to search:");
	scanf(" %[^\n]", name);

	int index;
	
	fseek(surgery, 0, SEEK_END);
	size = ftell(surgery) / sizeof(surgeries_t);
	index = binSearch(surgery, name, 0, size);
	rewind(surgery);

	fseek(surgery, sizeof(surgeries_t) * index, SEEK_SET);
	fread(&info, sizeof(surgeries_t), 1, surgery);
	printf("%-15s %-15s %-15s %d %-15s", info.docName, info.patientName, info.operation, info.time, info.status);



}
