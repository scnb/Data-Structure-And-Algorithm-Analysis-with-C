// ����ʽADT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "polynomial.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	Polynomial p1;
	p1 = new poly;
	cout << "Ϊ����ʽ1��ֵ��" << endl;
	cout << "�������ʽ1�м��";
	int n1;
	cin >> n1;
	p1->HighPower = n1 - 1;
	for (int i = 0;i <n1;i++)
	{
		cout << "Ϊ��Ϊ" << i << "�����ϵ����ֵ��";
		cin >> p1->CoeffArray[i];
	}
	for (int i = n1;i <= MaxDegree;i++)
	{
		p1->CoeffArray[i] = 0;
	}
	cout << endl;
	Polynomial p2 = new poly;
	cout << "Ϊ����ʽ2��ֵ��" << endl;
	int n2;
	cout << "�������ʽ2�м��";
	cin >> n2;
	p2->HighPower = n2 - 1;
	for (int i = 0;i <n2;i++)
	{
		cout << "Ϊ��Ϊ" << i << "�����ϵ����ֵ��";
		cin >> p2->CoeffArray[i];
	}
	for (int i = n2;i <= MaxDegree;i++)
	{
		p2->CoeffArray[i] = 0;
	}

	Polynomial psum = new poly;

	AddPolynomial(p1, p2, psum);
	cout << "����ʽ�ĺ�Ϊ��";
	for (int i = psum->HighPower;i >= 0;i--)
	{
		if (psum->CoeffArray[i] == 0)
		{
			continue;
		}
		cout <<"+"<< psum->CoeffArray[i] << "X^"<<i;
	}
	cout << endl;

	Polynomial pprod = new poly;

	MultPolynomial(p1, p2, pprod);
	cout << "����ʽ�Ļ�Ϊ��";
	for (int i = pprod->HighPower;i >= 0;i--)
	{
		if (pprod->CoeffArray[i] == 0)
		{
			continue;
		}
		cout << pprod->CoeffArray[i] << "X^" <<i<< "+";
	}
	getchar();
	getchar();
    return 0;
}

