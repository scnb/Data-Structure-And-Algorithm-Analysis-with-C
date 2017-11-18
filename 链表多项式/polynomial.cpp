#include "stdafx.h"
#include <iostream>
#include "polynomial.h"

using std::cout;
using std::endl;
using std::cin;

Polynomial CreatePolynomial()
{
	Polynomial p;
	p = new (struct Node);
	if (p == NULL)
	{
		cout << "内存分配失败！\n";
		exit(-1);
	}
	p->Coefficient = 0;
	p->Exponent = 0;
	p->Next = NULL;
	return p;
}

void Append(int co, int exp, Polynomial p)//参考一下郝斌的链表是怎么写的
{
	Polynomial temp;
	temp = new (struct Node);
	temp->Coefficient = co;
	temp->Exponent = exp;
	temp->Next = NULL;
	while (p->Next != NULL)
	{
		p = p->Next;
	}
	p->Next = temp;
}

int Max(int a, int b)
{
	return (a > b) ? a : b;
}


void AddPolynomial(Polynomial Poly1,Polynomial Poly2, Polynomial PolySum)
{
	while (Poly1 != NULL || Poly2 != NULL)
	{
		if (Poly1 == NULL)
		{
			Append(Poly2->Coefficient, Poly2->Exponent, PolySum);
			Poly2 = Poly2->Next;
		}
		else if(Poly2==NULL)
		{
			Append(Poly1->Coefficient, Poly1->Exponent, PolySum);
			Poly1 = Poly1->Next;
		}
		else if (Poly1->Exponent > Poly2->Exponent)
		{
			Append(Poly1->Coefficient, Poly1->Exponent, PolySum);
			Poly1 = Poly1->Next;
		}
		else if (Poly1->Exponent < Poly2->Exponent)
		{
			Append(Poly2->Coefficient, Poly2->Exponent, PolySum);
			Poly2 = Poly2->Next;
		}
		else
		{
			Append(Poly1->Coefficient + Poly2->Coefficient, Poly1->Exponent, PolySum);
			Poly1 = Poly1->Next;
			Poly2 = Poly2->Next;
		}

	}
	
}

//void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);