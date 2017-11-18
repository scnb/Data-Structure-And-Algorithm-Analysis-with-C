#include "stdafx.h"
#include "polynomial.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


void ZeroPolynomial(Polynomial Poly)
{
	for (int i = 0;i <= MaxDegree;i++)
	{
		Poly->CoeffArray[i] = 0;
	}
	Poly->HighPower = 0;
}

int Max(int a, int b)
{
	return (a > b) ? a : b;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
	ZeroPolynomial(PolySum);
	PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);//先确定最大的幂
																 //然后对应幂的系数相加
	for (int i = PolySum->HighPower;i >= 0;i--)//为了输出方便起见，将最高次幂的系数放在数组的最前面
	{
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];//即使有不同次幂也没关系，因为没有的项系数为0
	}
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
	ZeroPolynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
	if (PolyProd->HighPower > MaxDegree)
	{
		cout << "最高次超出数组范围！\n";
		exit(-1);
	}
	else
	{
		for (int i = 0;i <= Poly1->HighPower;i++)
		{
			for (int j = 0;j <= Poly2->HighPower;j++)
			{
				PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];//+=是关键，因为要合并同类项，即相等幂的系数相加
			}
		}
	}
}