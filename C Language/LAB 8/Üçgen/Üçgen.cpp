#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main(void)
{
	int k, i, j, m, n;
	double x;
	k = 1;
	n = 10;
	i = 11;
	j = 2 * i / 4;
	x = i + j / 2.0 - 4;
	printf("%d %0.1f\n", j, x);
	do
	{
		if (x > j)
		{
			x -= 2.5;
			m = x / k++ + 1;
			printf("%0.1f %d\n", x, m);
		}
		else
		{
			j /= k;
			printf("%0.1f %d %d\n", x, k, j);
		}
		n -= 2;
	} while (n > 0);
	printf("%d\n", n);
}


