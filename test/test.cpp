// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

typedef struct TreeNode * SearchTree;
typedef int ElementType;

struct TreeNode
{
	ElementType val;
	SearchTree left;
	SearchTree right;
};

struct ListNode
{
	int val;
	ListNode * next;
};

typedef struct
{
	int start;
	int end;
}Interval;




void sortIntegers(int A[], int N);
int fibonacci(int n);
int strStr(const char *source, const char *target);
int FindPos(int N, int flag, vector<int>A,int sum);
int singleNumber(vector<int> &A);
void PreOrderTraverse(TreeNode * root, int  pos, vector<int> A);
vector<int> preorderTraversal(TreeNode *root);
bool isUnique(string &str);
int removeDuplicates(vector<int> &nums);
string addBinary(string& a, string& b);
int bin2dec(string & str, int len);
vector<Interval> merge(vector<Interval> &intervals);

int main()
{
	vector<Interval> intervals(5);
	intervals[0].start = 1;
	intervals[0].end = 3;
	intervals[1].start = 2;
	intervals[1].end = 6;
	intervals[2].start = 4;
	intervals[2].end = 7;
	intervals[3].start = 8;
	intervals[3].end = 10;
	intervals[4].start = 15;
	intervals[4].end = 18;
	vector<Interval> res = merge(intervals);
	for (int i = 0;i < res.size();i++)
	{
		cout << res[i].start << " " << res[i].end << endl;
	}
	getchar();
    return 0;
}





bool isUnique(string &str)
{
	// write your code here
	int N = str.length();
	for (int i = 0;i<N - 1;i++)
	{
		for (int j = i + 1;j<N;j++)
		{
			if (str[i] == str[j])
			{
				return false;
			}
		}
	}
	return true;
}



void PreOrderTraverse(TreeNode * root, int  pos, vector<int> A)
{
	if (root == NULL)
	{
		return;
	}
	A[pos++] = root->val;
	PreOrderTraverse(root->left, pos, A);
	PreOrderTraverse(root->right, pos, A);
}

vector<int> preorderTraversal(TreeNode *root) 
{
	// write your code here
	vector<int> A(3);
	int a = 0;
	PreOrderTraverse(root, a, A);
	return A;
}

int FindPos(int N, int flag, vector<int>A,int sum)
{
	if (A[flag]!=A[flag-1] && A[flag]!=A[flag+1])//���������������������������м�
	{
		return flag;
	}
	else if (N == 3)
	{
		if (A[flag] == A[flag + 1])
		{
			return flag - 1;
		}
		else
		{
			return flag + 1;
		}
	}
	else if (N>3)
	{
		if (A[flag] == A[flag + 1])
		{
			if ((sum - flag - 2) % 2 == 0)
			{
				N = N - N / 2 - 1;
				flag = flag - N / 2 - 1;
				return FindPos(N, flag, A, sum);
			}
			else
			{
				N = N - N / 2 - 2;
				flag = flag + N / 2 + 2;
				return FindPos(N, flag, A, sum);
			}
		}
		if (A[flag] == A[flag - 1])
		{
			if ((sum - flag - 1) % 2 == 0)
			{
				N = N - N / 2 - 2;
				flag = flag - N / 2 - 2;
				return FindPos(N, flag, A, sum);
			}
			else
			{
				N = N - N / 2 - 1;
				flag = flag + N / 2 + 1;
				return FindPos(N, flag, A, sum);
			}
		}
	}
}

int singleNumber(vector<int> &A) 
{
	// write your code here
	/*   2*n+1�����֣���һ����n+1����  */
	int N = A.size();
	int j, P;
	int temp;
	for (P = 1;P < N;P++)
	{
		temp = A[P];
		for (j = P;j > 0 && A[j - 1] > temp;j--)//��A[P]֮ǰ��Ԫ�ذ�����A[P]�Ƚϣ�˭��A[P]�󣬾ͻ�λ��
		{
			A[j] = A[j - 1];                    //ע��ӦΪ����һֱ���Ǹ���ֵtemp�Ƚϣ�������ʵ���ǿ�temp����ǰ�߶�Զ��������ǰ��ļ���ֵС��ֱ��������tempС�ģ���ֹͣǰ�ƣ����ǰ�temp�������λ��
		}
		A[j] = temp;
	}
	if (N == 0)
	{
		return 0;
	}
	if (N == 1)
	{
		return A[0];
	}
	int pos;
	pos = FindPos(N, N / 2, A,N);
	return A[pos];
}

void sortIntegers(int A[],int N) 
{
	// Write your code here
	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (A[i] > A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

int fibonacci(int n)
{
	/*ע��һ��Ҫ�����������������nΪ1��2�����*/
	int f1 = 0;
	int f2 = 1;
	int f3;
	if (n == 1)
	{
		return f1;
	}
	else if (n == 2)
	{
		return f2;
	}
	else
	{
		for (int i = 3;i <= n;i++)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
}


int strStr(const char *source, const char *target)
{
	// write your code here
	int m = 0, n = 0;//�ֱ���source��target���ַ�������
	const char * p1 = source;
	const char * p2 = target;
	while (*p1 != '\0')
	{
		m++;
		p1++;
	}
	while (*p2 != '\0')
	{
		n++;
		p2++;
	}
	cout << m << " " << n << endl;
	int pos;
	int flag = 0;
	for (int i = 0;i < m;i++)
	{
		pos = i;
		flag = 0;
		for (int j = 0;j < n;j++)
		{
			if (*(source + pos + j) == *(target + j))
			{
				flag++;
				continue;
			}
			else
			{
				break;
			}
		}
		if (flag == n)
		{
			break;
		}
	}
	cout << "flag = " << flag << endl;
	if (flag == n)
	{
		return pos;
	}
	else
	{
		return -1;
	}
}


int removeDuplicates(vector<int> &nums) 
{
	// write your code here
	int i, j;
	int h = 0;
	int occurence = 0;//��¼�ظ�����
	if (nums.size()<3)
	{
		return nums.size();
	}
	else
	{
		for (i = 0;i<nums.size();i = j)//�ص���i=j���j���൱��ÿһ�����ظ�Ԫ�صı��
		{
			if (occurence >= 1)
			{
				nums[h++] = nums[i - 1];
				nums[h++] = nums[i];
			}
			else if (i == 0)
			{
				nums[h++] = nums[0];
			}
			else if (occurence == 0)
			{
				nums[h++] = nums[i];
			}
			occurence = 0;
			for (j = i + 1;j<nums.size();j++)
			{
				if (nums[i] != nums[j])
				{
					break;
				}
				else
				{
					++occurence;
				}
			}
		}
		return h;
	}
}

/*������Ƶ�ʮ������*/
int bin2dec(string & str, int len)
{
	int sum = 0;
	int i, j;
	for (i = 0;i < len;i++)
	{
		if (str[i] == 0)
		{
			sum += 0;
		}
		else
		{
			int mi = 1;//2�ļ�����
			for (j = 0;j < len - i - 1;j++)
			{
				mi *= 2;
			}
			sum += (str[i] - 48) * mi;
		}
	}
	return sum;
}

string addBinary(string& a, string& b) {
	// Write your code here
	int a_len = a.length();
	int b_len = b.length();
	int a_num = bin2dec(a, a_len);
	int b_num = bin2dec(b, b_len);
	int sum = a_num + b_num;
	string add;
	string str;
	int i = 0;
	if (sum == 0)
	{
		add += '0';
		return add;
	}
	while (sum != 0)
	{
		int val = sum & 0x01;
		if (val)
		{
			str += '1';
		}
		else
		{
			str += '0';
		}
		sum = sum >> 1;
	}
	reverse(str.begin(), str.end());//һ��reverse()�������ɽ������
	return str;
}

vector<Interval> merge(vector<Interval> &intervals)
{
	// write your code here
	int N = intervals.size();
	vector<Interval> res(N);
	int i,j;
	Interval temp;
	for (i = 0,j = 0;i < N;i++)
	{
		if ((i + 1 < N) && (intervals[i].end > intervals[i + 1].start))
		{
			while ((i + 1 < N) && (intervals[i].end > intervals[i + 1].start))
			{
				temp.start = intervals[i].start;
				temp.end = intervals[i + 1].end;
				intervals[i + 1] = temp;
				i++;
			}
			res[j++] = temp;
		}
		else
		{
			res[j++] = intervals[i];
		}
	}
	vector<Interval> fuck(j);
	for (int i = 0;i < j;i++)
	{
		fuck[i] = res[i];
	}
	return fuck;
}