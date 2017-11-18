#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void PrintOut(int N);
void PrintDigit(int N);

int main()
{
	int n;
	printf("输入任意实数：");
	scanf_s("%d", &n);
	PrintOut(n);
	getchar();
	getchar();
    return 0;
}

void PrintDigit(int N)
{
	printf("%d", N);
}

void PrintOut(int N)
{
	if (N < 0)
	{
		printf("-");
		if (abs(N) >= 10)
		{
			PrintOut(abs(N) / 10);
		}
	}
	if (N >= 10)
	{
		PrintOut(N/10);
	}
	PrintDigit(abs(N)%10);
}