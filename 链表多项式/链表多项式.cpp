// 链表多项式.cpp : 定义控制台应用程序的入口点。
//用链表来存储多项式，链表的每一个结点存储一项，高次项存储在链表的前面结点
//输入必须要两个多项式的幂都有
//修改了上一条的bug，完美解决两个多项式幂不相同的问题

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
	cout << "为多项式1赋系数：";
	int co, exp;
	char ch;
	while (cin >> co)
	{
		cout << "为多项式1赋幂：";
		cin >> exp;
		Append(co, exp, p1);
		cout << "要退出吗（y or n）：";
		cin >> ch;
		if (ch == 'y')
		{
			break;
		}
		cout << "为多项式1赋系数：";
	}

	cout << endl;
	cout << "为多项式2赋系数：";
	while (cin >> co)
	{
		cout << "为多项式2赋幂：";
		cin >> exp;
		Append(co, exp, p2);
		cout << "要退出吗（y or n）：";
		cin >> ch;
		if (ch == 'y')
		{
			break;
		}
		cout << "为多项式2赋系数：";
	}

	cout << endl;
	AddPolynomial(p1, p2, psum);
	cout << "多项式的和为：";
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

