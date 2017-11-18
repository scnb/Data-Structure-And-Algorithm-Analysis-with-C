// 插入排序.cpp : 定义控制台应用程序的入口点。
//把数组中的某一个位置的值与他前面的所有元素进行比较，当顺序不正确时，就交换顺序。
//其实真正的理解是类似于一群人按身高排队，如果某一个人的前面那个人比他高，则他就往前移动一位，
//对应的，前面那个人相当于往后移动了一位。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

typedef int ElementType;

void InsertionSort(ElementType A[],int N);
void Show_Arr(ElementType A[], int N);
void InsertSort(vector<ElementType>& A);
int majorityNumber(vector<int> nums);
int maxSubArray(vector<int> nums);
bool isUgly(int num);
int maxSubArray(vector<int> nums);
int Get10mi(int n);
vector<int> plusOne(vector<int>& digits);
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B);
void mergeSortedArray(int A[], int m, int B[], int n);

int main()
{
	//ElementType arr[7] = { 3,6,4,9,0,2,8 };
	//cout << "排序之前：";
	//Show_Arr(arr, 7);
	//InsertionSort(arr,7);
	//cout << "排序之后：";
	//Show_Arr(arr, 7);
	int A[6] = { 1,3,4,6 };
	int B[2] = { 2,5 };
	mergeSortedArray(A, 4, B, 2);
	for (int i = 0;i < 6;i++)
	{
		cout << A[i] << " ";
	}
	getchar();
    return 0;
}

void InsertionSort(ElementType A[],int N)
{
	int j, P;
	ElementType temp;
	for (P = 1;P < N;P++)	
	{
		temp = A[P];
		for (j = P;j > 0 && A[j - 1] > temp;j--)//把A[P]之前的元素挨个根A[P]比较，谁比A[P]大，就换位置
		{
			A[j] = A[j - 1];                    //注意应为上面一直都是和定值temp比较，所以其实就是看temp能往前走多远，
												//即它比前面的几个值小，直到遇到比temp小的，就停止前移，而是把temp放在这个位置
		}
		A[j] = temp;
	}
}

void InsertSort(vector<ElementType>& A)
{
	int j, P;
	ElementType temp;
	int N = A.size();
	for (P = 1;P < N;P++)
	{
		temp = A[P];
		for (j = P;j > 0 && A[j - 1] > temp;j--)//把A[P]之前的元素挨个根A[P]比较，谁比A[P]大，就换位置
		{
			A[j] = A[j - 1];                    //注意应为上面一直都是和定值temp比较，所以其实就是看temp能往前走多远，
												//即它比前面的几个值小，直到遇到比temp小的，就停止前移，而是把temp放在这个位置
		}
		A[j] = temp;
	}
}

void Show_Arr(ElementType A[], int N)
{
	for (int i = 0;i < N;i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

//取出数组中出现次数严格大于（数组元素个数的二分之一）
int majorityNumber(vector<int> nums) 
{
	// write your code here
	int N = nums.size();
	InsertSort(nums);
	for (int i = 0;i < 7;i++)
	{
		cout << nums[i] << " ";
	}
	int temp;
	for (int i = 0;i < N;)
	{
		int flag = 0;
		temp = nums[i];
		while (i < N && nums[i] == temp)
		{
			i++;
			flag++;
		}
		if (flag > N / 2)
		{
			return temp;
		}
	}
}



/*判断是否是丑数*/
bool isUgly(int num)
{
	// Write your code here
	if (num <= 0)
	{
		return false;
	}
	else
	{
		if (num == 1)
		{
			return true;
		}
		for (int i = 4;i <= num / 2;i++)
		{
			if (num % i == 0 && i != 5)//首先得是一个因子，并且这个因子不为2，3，5
			{
				int flag = 0;
				//再判断这个因子是不是质数
				for (int j = 2;j <= i / 2;j++)
				{
					if (i % j == 0)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					return false;
				}
			}
		}
		return true;
	}
}

/*九章算法给出的标准答案*/
int maxSubArray(vector<int> nums)
{
	int sum = 0, minSum = 0, maxSum = INT_MIN;
	for (int i = 0; i < nums.size(); i++) 
	{
		sum += nums[i];
		maxSum = max(maxSum, sum - minSum);
		minSum = min(minSum, sum);
	}
	return maxSum;
}


int Get10mi(int n)
{
	int mi = 1;
	for (int i = 0;i < n;i++)
	{
		mi = mi * 10;
	}
	return mi;
}

vector<int> plusOne(vector<int>& digits) 
{
	// Write your code here
	int N = digits.size();
	//先把数组转化成整数的形式
	unsigned int sum = 0;
	int mi = 0;
	int flag = 1;//用来判断是否每一位都是9，即加1之后是否有进位
	for (int i = 0;i < N;i++)
	{
		if (digits[i] != 9)
		{
			flag = 0;
		}
		mi = Get10mi(N - i - 1);
		sum += digits[i] * mi;
	}
	sum += 1;
	if (flag == 0)
	{
		//没有进位
		vector<int> nums(N);
		int i = 0;
		while (sum > 0)
		{
			nums[i++] = sum % 10;
			sum = sum / 10;
		}
		reverse(nums.begin(), nums.end());
		return nums;
	}
	else
	{
		//进了一位，数组元素个数加1
		vector<int> nums(N + 1);
		int i = 0;
		while (sum > 0)
		{
			nums[i++] = sum % 10;
			sum = sum / 10;
		}
		reverse(nums.begin(), nums.end());
		return nums;
	}
}

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B)
{
	// write your code here
	int NA = A.size();
	int NB = B.size();
	int N = NA + NB;
	int i, j, p;
	vector<int> nums(N);
	for (i = 0;i < NA;i++)
	{
		nums[i] = A[i];
	}
	for (j = i, p = 0;j < N;j++, p++)
	{
		nums[j] = B[p];
	}
	InsertSort(nums);
	return nums;
}

void mergeSortedArray(int A[], int m, int B[], int n) 
{
	// write your code here
	int i, j;
	for (i = m, j = 0;i < m + n;i++, j++)
	{
		A[i] = B[j];
	}
	InsertionSort(A, m + n);
};