#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
/*
Dfs
列举所有的类型
每一个数组中，每一个元素，他后面所有比他小的元素，均需逆序输出，否则不满足
字典序输出
*/
#include <stdio.h>
//交换list[a],list[b] 
void Swap(char list[], int a, int b)
{
	int temp = 0;
	temp = list[a];
	list[a] = list[b];
	list[b] = temp;
	return;
}
//将list区间[a,n]之间的数据由小到大排序 
void Sort(char list[], int a, int n)
{
	char temp = 0;
	for (int i = 1; i < n - a; ++i)
		for (int j = a + 1; j < n - 1; ++j)
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
	return;
}
//全排列 
void Prim(char list[26], int n)
{
	char output[26];
	int a = 0, b = 0;
	double num = 1;
	for (int i = n; i > 0; --i)     //计算有多少种情况，就循环多少次 
		num *= i;
	for (double m = 0; m < num; m++)
	{
		for (int i = 0; i < n; ++i) //
		{
			//cout << list[i];
			output[i] = list[i];
		}
		bool flag = true;
		for (int j = 0; j < n; j++)//对这个输出中每一个火车之后的情况进行判断
		{
			int min=j;
			for (int k = j + 1; k < n; k++)
			{
				if (output[j] > output[k])
				{
					if (output[min] > output[k])
						min = k;
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)break;
			}
			if (flag == false)break;
		}
		if (flag == true)
		{
			for (int k = 0; k < n; k++)
			{
				cout << output[k];
			}
			cout << endl;
		}
		//cout << endl;
		for (int i = n - 1; i > 0; --i) //从右往左，找出第一个左边小于右边的数，设为list[a] 
			if (list[i - 1] < list[i])
			{
				a = i - 1;
				break;
			}
		for (int j = n - 1; j > a; --j) //从右往左，找出第一个大于list[a]的数，设为list[b] 
			if (list[j] > list[a])
			{
				b = j;
				break;
			}
		Swap(list, a, b);         //交换list[a],list[b] 
		Sort(list, a, n);         //将list[a]后面的数据，由小往大排列 
	}
	return;
}
/*
void judge(int n)
{
	int num = 1;
	for (int i = 1; i <=n; i++)
		num = num*i;
	for (int i = 0; i <num; i++)//选取一个输出
	{
		bool flag = true;
		for (int j = 0; j < n; j++)//对这个输出中每一个火车之后的情况进行判断
		{
			int min=j;
			for (int k = j + 1; k < n; k++)
			{
				if (output[i][j] > output[i][k])
				{
					if (output[i][min] > output[i][k])
						min = k;
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)break;
			}
			if (flag == false)break;
		}
		if (flag == true)
		{
			for (int k = 0; k < n; k++)
			{
				cout << output[i][k];
			}
			cout << endl;
		}
	}
}
*/
int main()
{
	char list[26];
	for(int i=0;i<26;i++)
	{
		list[i] = 'A' + i;
	}
	int n ;
	string input;
	cin >> list;
	n = strlen(list); //获取输入火车数量
	if (n > 26)n = 26;
	Prim(list, n);//获得火车出栈的全排列
	//cout << endl;
	//judge(n);//判断是否符合要求输出
	return 0;
}