#pragma once
#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
const int MaxDegree = 10;

typedef struct poly
{
	int CoeffArray[MaxDegree + 1];//����ʽ��ϵ������
	int HighPower;//��ߴ���
} *Polynomial;


int Max(int a, int b);
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum);
void ZeroPolynomial(Polynomial Poly);
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);


#endif // !POLYNOMIAL_H_
