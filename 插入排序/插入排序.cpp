// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//�������е�ĳһ��λ�õ�ֵ����ǰ�������Ԫ�ؽ��бȽϣ���˳����ȷʱ���ͽ���˳��
//��ʵ�����������������һȺ�˰�����Ŷӣ����ĳһ���˵�ǰ���Ǹ��˱����ߣ���������ǰ�ƶ�һλ��
//��Ӧ�ģ�ǰ���Ǹ����൱�������ƶ���һλ��

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
	//cout << "����֮ǰ��";
	//Show_Arr(arr, 7);
	//InsertionSort(arr,7);
	//cout << "����֮��";
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
		for (j = P;j > 0 && A[j - 1] > temp;j--)//��A[P]֮ǰ��Ԫ�ذ�����A[P]�Ƚϣ�˭��A[P]�󣬾ͻ�λ��
		{
			A[j] = A[j - 1];                    //ע��ӦΪ����һֱ���ǺͶ�ֵtemp�Ƚϣ�������ʵ���ǿ�temp����ǰ�߶�Զ��
												//������ǰ��ļ���ֵС��ֱ��������tempС�ģ���ֹͣǰ�ƣ����ǰ�temp�������λ��
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
		for (j = P;j > 0 && A[j - 1] > temp;j--)//��A[P]֮ǰ��Ԫ�ذ�����A[P]�Ƚϣ�˭��A[P]�󣬾ͻ�λ��
		{
			A[j] = A[j - 1];                    //ע��ӦΪ����һֱ���ǺͶ�ֵtemp�Ƚϣ�������ʵ���ǿ�temp����ǰ�߶�Զ��
												//������ǰ��ļ���ֵС��ֱ��������tempС�ģ���ֹͣǰ�ƣ����ǰ�temp�������λ��
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

//ȡ�������г��ִ����ϸ���ڣ�����Ԫ�ظ����Ķ���֮һ��
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



/*�ж��Ƿ��ǳ���*/
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
			if (num % i == 0 && i != 5)//���ȵ���һ�����ӣ�����������Ӳ�Ϊ2��3��5
			{
				int flag = 0;
				//���ж���������ǲ�������
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

/*�����㷨�����ı�׼��*/
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
	//�Ȱ�����ת������������ʽ
	unsigned int sum = 0;
	int mi = 0;
	int flag = 1;//�����ж��Ƿ�ÿһλ����9������1֮���Ƿ��н�λ
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
		//û�н�λ
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
		//����һλ������Ԫ�ظ�����1
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