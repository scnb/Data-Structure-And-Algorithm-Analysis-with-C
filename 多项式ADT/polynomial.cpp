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
	PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);//��ȷ��������
																 //Ȼ���Ӧ�ݵ�ϵ�����
	for (int i = PolySum->HighPower;i >= 0;i--)//Ϊ������������������ߴ��ݵ�ϵ�������������ǰ��
	{
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];//��ʹ�в�ͬ����Ҳû��ϵ����Ϊû�е���ϵ��Ϊ0
	}
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
	ZeroPolynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
	if (PolyProd->HighPower > MaxDegree)
	{
		cout << "��ߴγ������鷶Χ��\n";
		exit(-1);
	}
	else
	{
		for (int i = 0;i <= Poly1->HighPower;i++)
		{
			for (int j = 0;j <= Poly2->HighPower;j++)
			{
				PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];//+=�ǹؼ�����ΪҪ�ϲ�ͬ���������ݵ�ϵ�����
			}
		}
	}
}