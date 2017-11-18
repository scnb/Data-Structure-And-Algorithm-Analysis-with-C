#include "stdafx.h"
#include "quick_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Swap( ElementType * a, ElementType * b)
{
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


/*使用3数值中值法决定枢纽元，枢纽元取3数值的中间值*/
ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;//3数值中值法分别是数组左端元素、右端元素和中间元素
	/*下面三个if-else将3个数值进行了排序，即A[Left]<=A[Center]<=A[Right]*/
	if (A[Left] > A[Center])
	{
		Swap(&A[Left], &A[Center]);
	}
	if (A[Left] > A[Right])
	{
		Swap(&A[Left], &A[Right]);
	}
	if (A[Center] > A[Right])
	{
		Swap(&A[Center], &A[Right]);
	}
	/*将枢纽元和数组倒数第二个元素交换位置，之所以是与倒数第二个元素交换，是因为前面的排序已经保证了首元素小于枢纽元，尾元素大于枢纽元*/
	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];//返回枢纽元的值
}

/*插入排序例程，适用于小数组*/
void InsertionSort(ElementType A[], int N)
{
	int j, P;
	ElementType temp;
	for (P = 1;P < N;P++)
	{
		temp = A[P];
		for (j = P;j > 0 && A[j - 1] > temp;j--)//把A[P]之前的元素挨个根A[P]比较，谁比A[P]大，就换位置
		{
			A[j] = A[j - 1];                    //注意应为上面一直都是跟定值temp比较，所以其实就是看temp能往前走多远，即它比前面的几个值小，直到遇到比temp小的，就停止前移，而是把temp放在这个位置
		}
		A[j] = temp;
	}
}

void QSort(ElementType A[], int Left, int Right)
{
	int i, j;
	ElementType Pivot;
	if (Left + Cutoff <= Right)//先判断该数组是不是小数组，如果数组元素超过Cutoff的话，则执行快速排序
	{
		Pivot = Median3(A, Left, Right);//得到枢纽元的值，将用来比较
		i = Left;//奇怪的是，在Median3函数中已经对3数值排过序了，在这里，i还是从左端开始
		j = Right - 1;
		for (;;)//该for循环的退出条件实际是在if-else判断中，即当i与j交错后，退出循环
		{
			while (A[++i] < Pivot) {}//这两个while循环完成的操作是，i越过那些比枢纽元小的元素，
			while (A[--j] > Pivot) {}//而j越过那些比枢纽元大的元素
			/*如果上边while条件不成立，i和j停止移动，下边判断i是否小于j，若小于，则交换元素*/
			if (i < j)
			{
				Swap(&A[i], &A[j]);
			}
			else
			{
				break;
			}
		}
		Swap(&A[i], &A[Right - 1]);

		/*上述for循环使i和j正好将整个数组以枢纽元为基准，分成左右一大一小两半*/
		QSort(A, Left, i - 1);/*递归地将枢纽元左侧的元素进行排序*/
		QSort(A, i + 1, Right);/*递归地将枢纽元右侧的元素进行排序*/
	}
	else//如果该数组是小数组，即数组元素小于Cutoff个，则执行插入排序
	{
		InsertionSort(A + Left, Right - Left + 1);
	}
}

void QuickSort(ElementType A[], int N)
{
	QSort(A, 0, N - 1);
}

void Show(ElementType A[], int N)
{
	if (N == 0)
	{
		cout << "数组为空！\n";
		return;
	}
	for (int i = 0;i < N;i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
