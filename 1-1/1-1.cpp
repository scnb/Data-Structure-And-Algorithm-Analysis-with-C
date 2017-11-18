// 1-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

const int N = 10;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int temp;
	int arr[N] = { 1,3,4,5,8,9,2,6,7,0 };
	for (int i = 0;i < N;i++)
	{
		for (int j = i;j < N;j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0;i < N;i++)
	{ 
		cout << i << " ";
	}
	cout << "第 " << N / 2 << " 个元素为：";
	cout << arr[N / 2-1];
	getchar();
    return 0;
}

