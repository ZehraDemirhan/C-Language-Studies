#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SPEED 598
#define LIGHT 314
#define PARK 144
int main(void)
{
	int i, penaltyA, deadlineCount=0;
	char deadline;
	double payment,sum=0;



	printf("\nTRAFFIC PENALTY PAYMENTS\n");
	for (i = 1; i <= 22; i++)
	{
		printf("-");
	}
	printf("\n1. Speed Limit Violation\n2. Red Light Violation\n3. Parking Violation\n4. EXIT");


	printf("\nEnter the penalty article no:");
	scanf("%d", &penaltyA);

	


	while (penaltyA != 4)
	{
		printf("payment before deadline (y/n)?");
		scanf(" %c", &deadline);
		switch (penaltyA)
		{
		case 1:
			if (deadline == 'y' || deadline == 'Y')
			{
				printf("25%% discount applied for the early payment!!\n");
				payment = SPEED - SPEED * 0.25;
				sum += payment;
				deadlineCount += 1;
			}
			else
			{
				payment = SPEED;
				sum += payment;
			}

			printf("Payment Amount:%6.2f\n", payment);
			break;

		case 2:
			if (deadline == 'y' || deadline == 'Y')
			{
				printf("25%% discount applied for the early payment!!\n");
				payment = LIGHT - LIGHT * 0.25;
				sum += payment;
				deadlineCount += 1; 
			}
			else
			{
				payment = LIGHT;
				sum += payment;
			}

			printf("Payment Amount:%6.2f\n", payment);
			break;



		case 3:
			if (deadline == 'y' || deadline == 'Y')
			{
				printf("25%% discount applied for the early payment!!\n");
				payment = PARK - PARK * 0.25;
				sum += payment;
				deadlineCount += 1;
			}
			else
			{
				payment = PARK;
				sum += payment;
			}
			printf("Payment Amount:%6.2f\n", payment);
		}
		printf("\nTRAFFIC PENALTY PAYMENTS\n");
		for (i = 1; i <= 18; i++)
		{
			printf("-");
		}
		printf("\n1. Speed Limit Violation\n2. Red Light Violation\n3. Parking Violation\n4. EXIT");


		printf("\nEnter the penalty article no:");
		scanf("%d", &penaltyA);




	}
	for (i = 1; i <= 22; i++)
	{
		printf("-");
	}
	printf("\nPenalty totals: %7.2f TL", sum);
	printf("\n%d people paid the penalty before the dealine", deadlineCount);
	return(0);
}