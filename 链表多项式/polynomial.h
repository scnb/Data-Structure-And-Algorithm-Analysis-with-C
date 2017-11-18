#pragma once
#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

const int MaxDegree = 10;
typedef struct Node * PtrToNode;

struct Node
{
	int Coefficient;
	int Exponent;
	PtrToNode Next;
};

typedef PtrToNode Polynomial;

Polynomial CreatePolynomial();
void Append(int co,int exp,Polynomial p);
int Max(int a, int b);
void AddPolynomial(Polynomial Poly1, Polynomial Poly2, Polynomial PolySum);
//void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);

#endif // !POLYNOMIAL_H_
