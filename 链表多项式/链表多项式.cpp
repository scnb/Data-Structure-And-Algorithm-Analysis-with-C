// �������ʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//���������洢����ʽ�������ÿһ�����洢һ��ߴ���洢�������ǰ����
//�������Ҫ��������ʽ���ݶ���
//�޸�����һ����bug�����������������ʽ�ݲ���ͬ������

#include "stdafx.h"
#include "polynomial.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Polynomial p1 = CreatePolynomial();
	Polynomial p2 = CreatePolynomial();
	Polynomial psum = CreatePolynomial();
	cout << "Ϊ����ʽ1��ϵ����";
	int co, exp;
	char ch;
	while (cin >> co)
	{
		cout << "Ϊ����ʽ1���ݣ�";
		cin >> exp;
		Append(co, exp, p1);
		cout << "Ҫ�˳���y or n����";
		cin >> ch;
		if (ch == 'y')
		{
			break;
		}
		cout << "Ϊ����ʽ1��ϵ����";
	}

	cout << endl;
	cout << "Ϊ����ʽ2��ϵ����";
	while (cin >> co)
	{
		cout << "Ϊ����ʽ2���ݣ�";
		cin >> exp;
		Append(co, exp, p2);
		cout << "Ҫ�˳���y or n����";
		cin >> ch;
		if (ch == 'y')
		{
			break;
		}
		cout << "Ϊ����ʽ2��ϵ����";
	}

	cout << endl;
	AddPolynomial(p1, p2, psum);
	cout << "����ʽ�ĺ�Ϊ��";
	psum = psum->Next->Next;
	while (psum != NULL)
	{
		if (psum->Coefficient >= 0)
		{
			cout << "+";
		}
		else
		{
			cout << "-";
		}
		cout<< abs(psum->Coefficient) << "X^" << psum->Exponent;
		psum = psum->Next;
	}
	getchar();
	getchar();
    return 0;
}

