#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define RESIDENTIAL 6
#define COMMERCIAL 60
#define INDUSTRIALPEAK 76
#define INDUSTRIALOFF 40



int main(void)
{
	int count,i=1;
	char Atype;
	double kwh = 0, pay, Pkwh, Okwh, payI;
	double ressum=0, commsum=0, indsum=0;
	int rescount=0, commcount=0, indcount=0;
	double resavg, comavg, indavg;

	printf("Please enter the number of customers:");
	scanf(" %d", &count);

	while (i<=count)
	{ 
		
	printf("\nEnter the usage type(R/r-Residental, C/c-Commercial, I/i-Industrial):");
	scanf(" %c", &Atype);
	if (Atype != 'r' && Atype != 'R' && Atype != 'c' && Atype != 'C' && Atype != 'I' && Atype != 'i')
		printf("\nInvalid Usage Type!!!");


	switch (Atype)
	{
	case 'R':
	case 'r':

		printf("Enter the kwh: ");
		scanf("%lf", &kwh);
		rescount += 1;
		if (kwh <= 0)
		{
			pay = 0;
			printf("Please pay %6.2f TL\n", pay);
		}
			
		pay = RESIDENTIAL + (0.052 * kwh);
		printf("Please pay %6.2f TL\n", pay);
	
		ressum += pay;

		break;

	case 'C':
	case 'c':printf("Enter the kwh: ");
		scanf("%lf", &kwh);
		commcount += 1;
		if (kwh > 1000)
		{
			pay = COMMERCIAL + (kwh - 1000) * 0.045;
			printf("Please pay %6.2f TL\n", pay);

			commsum += pay;
		}
		else if (kwh > 0)
		{
			pay = COMMERCIAL;
			printf("Please pay %6.2f TL\n", pay);

			commsum += pay;
		}

		else
		{
			pay = 0;
			printf("Please pay %6.2f TL\n", pay);
		}

		break;

	case 'I':
	case 'i':printf("Please enter the kwh for PEAK hours : ");
		scanf("%lf", &Pkwh);

		printf("Please enter the kwh for OFFPEAK hours : ");
		scanf("%lf", &Okwh);
		indcount += 1;
		if (Pkwh > 1000)

		{
			payI = INDUSTRIALPEAK + (Pkwh - 1000) * 0.065;



		}
		else if (Pkwh <= 1000 && Pkwh>0)
		{
			payI = INDUSTRIALPEAK;


		}
		else payI= 0;


		if (Okwh > 1000)
		{
			pay = INDUSTRIALOFF + (Okwh - 1000) * 0.028;
			pay = pay + payI;
			printf("Please pay %6.2f TL\n", pay);
			indsum += pay;
		}
		else if (Okwh <= 1000 && Okwh > 0)
		{
			pay = INDUSTRIALOFF;
			pay = pay + payI;
			printf("Please pay %6.2f TL\n", pay);
			indsum += pay;
		}
		else {
			pay = 0;
			printf("Please pay %6.2f TL\n", pay);
		}

		

	}
	resavg = ressum / rescount;
	comavg = commsum / commcount;
	indavg = indsum / indcount;
	i++;
	}
	printf("\nThe average price of the residental usage is: %5.2f TL\n", resavg);
	printf("The average price of the commercial usage is: %5.2f TL \n", comavg);
	printf("The average price of the industrial usage is: %5.2f TL \n", indavg);
	return(0);

}