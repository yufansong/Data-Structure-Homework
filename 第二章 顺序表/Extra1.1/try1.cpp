#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
/*
Dfs
�о����е�����
ÿһ�������У�ÿһ��Ԫ�أ����������б���С��Ԫ�أ����������������������
�ֵ������
*/
#include <stdio.h>
//����list[a],list[b] 
void Swap(char list[], int a, int b)
{
	int temp = 0;
	temp = list[a];
	list[a] = list[b];
	list[b] = temp;
	return;
}
//��list����[a,n]֮���������С�������� 
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
//ȫ���� 
void Prim(char list[26], int n)
{
	char output[26];
	int a = 0, b = 0;
	double num = 1;
	for (int i = n; i > 0; --i)     //�����ж������������ѭ�����ٴ� 
		num *= i;
	for (double m = 0; m < num; m++)
	{
		for (int i = 0; i < n; ++i) //
		{
			//cout << list[i];
			output[i] = list[i];
		}
		bool flag = true;
		for (int j = 0; j < n; j++)//����������ÿһ����֮�����������ж�
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
		for (int i = n - 1; i > 0; --i) //���������ҳ���һ�����С���ұߵ�������Ϊlist[a] 
			if (list[i - 1] < list[i])
			{
				a = i - 1;
				break;
			}
		for (int j = n - 1; j > a; --j) //���������ҳ���һ������list[a]��������Ϊlist[b] 
			if (list[j] > list[a])
			{
				b = j;
				break;
			}
		Swap(list, a, b);         //����list[a],list[b] 
		Sort(list, a, n);         //��list[a]��������ݣ���С�������� 
	}
	return;
}
/*
void judge(int n)
{
	int num = 1;
	for (int i = 1; i <=n; i++)
		num = num*i;
	for (int i = 0; i <num; i++)//ѡȡһ�����
	{
		bool flag = true;
		for (int j = 0; j < n; j++)//����������ÿһ����֮�����������ж�
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
	n = strlen(list); //��ȡ���������
	if (n > 26)n = 26;
	Prim(list, n);//��û𳵳�ջ��ȫ����
	//cout << endl;
	//judge(n);//�ж��Ƿ����Ҫ�����
	return 0;
}