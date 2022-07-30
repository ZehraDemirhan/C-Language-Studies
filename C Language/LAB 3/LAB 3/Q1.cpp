#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 

int main(void)
{
	double array[4][3] = { { 42.90, 60.71, 57.30 }, { 93.21, 82.97, 21.14 }, { 25.91, 92.2, 30.17 }, { 52.87, 75.84, 44.56 } };


	printf("%p\n", array);
	printf("%p\n", array + 1);
	printf("%p\n", *(array + 1));
	printf("%p\n", *(array) + 1);
	printf("%5.2f\n", *(*(array)+1));//60.71
	printf("%5.2f\n", *(*(array + 1)));//93.21
	printf("%5.2f\n", *(*(array)+1) + 2);//62.71
	printf("%p\n", (*(array + 1) + 2));
	printf("%5.2f", *(*(array + 1) + 2));//21.14
}