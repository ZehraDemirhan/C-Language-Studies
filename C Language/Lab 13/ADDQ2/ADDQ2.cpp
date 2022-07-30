#define _CRT_SECURE_NO_WARNINGS
#define SIZE 15
#include<stdio.h>

int main(void)
{
	char Arr[SIZE];
	char ch, last = 'a';
	int i = 0, j, player = 1;
	int finished = 0;


	do
	{
		printf("Player-%d, enter a word:", player);
		i = 0;
		scanf(" %c", &ch);
		while (ch != '.')
		{

			Arr[i] = ch;
			i++;
			scanf(" %c", &ch);


		}

		if (Arr[0] != last) {
			for (j = 0; j < i; j++)
				printf("%c", Arr[j]);
			printf(" does not start with %c !\n", last);
			printf("Game over! Player %d wins.\n\n", player == 1 ? 2 : 1);
			finished = 1;
		}
		else {
			last = Arr[i - 1];
			player = player == 1 ? 2 : 1;
			//printf("%c", last);
		}




	} while (!finished);




	/*for (j = 0; j < i; j++)
		printf("%c", Arr[i]);

	printf("does not start with %d !", Arr[0]);
	printf("Game over!");*/






}