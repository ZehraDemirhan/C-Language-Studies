#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define RESIDENTIAL 6
#define COMMERCIAL 60
#define INDUSTRIALPEAK 76
#define INDUSTRIALOFF 40



int main(void)
{
	char Atype;
	double kwh=0,pay,Pkwh,Okwh,payW,payR=0,payC=0,payI=0;
	int Pcount=0, Ccount=0, Icount=0, no, i;

	printf("Enter Customer NO:");
	scanf("%d", &no);

	for (i=1;i<=no;i++)
	{ do {
			printf("Enter the usage type(R/r-Residental, C/c-Commercial, I/i-Industrial):");
			scanf(" %c", &Atype);
			if (Atype != 'r' && Atype != 'R' && Atype != 'c' && Atype != 'C' && Atype != 'I' && Atype != 'i')
				printf("\NInvalid Usage Type!!!");
	    } while (Atype != 'r' && Atype != 'R' && Atype != 'c' && Atype != 'C' && Atype != 'I' && Atype != 'i');

	
		switch (Atype)
		{
		case 'R':
		case 'r':printf("Enter the kwh: ");
			scanf("%lf", &kwh);
			pay = RESIDENTIAL + (0.052 * kwh);
			payR += pay;
			Pcount++;
			break;

		case 'C':
		case 'c':printf("Enter the kwh: ");
			scanf("%lf", &kwh);
			if (kwh > 1000)
			{
				pay = COMMERCIAL + (kwh - 1000) * 0.045;
				payC += pay;
				Ccount++;
			}
			else
			{
				pay = COMMERCIAL;
				payC += pay;
				Ccount++;
			}
			break;

		case 'I':
		case 'i':printf("Please enter the kwh for PEAK hours : ");
			scanf("%lf", &Pkwh);

			printf("Please enter the kwh for OFFPEAK hours : ");
			scanf("%lf", &Okwh);

			if (Pkwh > 1000)

			{
				payW = INDUSTRIALPEAK + (Pkwh - 1000) * 0.065;



			}
			else if (Pkwh <= 1000)
			{
				payW = INDUSTRIALPEAK;


			}


			if (Okwh > 1000)
			{
				pay = INDUSTRIALOFF + (Okwh - 1000) * 0.028;
				pay = pay + payW;
				payI+= pay;
				Icount++;
			}
			else if (Okwh <= 1000)
			{
				pay = INDUSTRIALOFF;
				pay = pay + payW;
				payI+= pay;
				Icount++;

			}
		}

		printf("Please pay %6.2f TL\n", pay);
	  
	}

	printf("\nThe average price of the residental usage is: %5.2f TL ", payR / Pcount);
	printf("\nThe average price of the commercial usage is: %5.2f TL ", payC / Ccount);
	printf("\nThe average price of the industrial usage is: %5.2f TL ", payI / Icount);
	return(0);

}