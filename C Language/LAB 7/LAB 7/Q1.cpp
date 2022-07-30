#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	char string[100];
	printf("Enter a sentence:");
	//scanf("%s", string);
	//scanf("%[^\n]", string);
	scanf("%[^0-9]", string);
	printf("The sentence is :%s", string);


}
