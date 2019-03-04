#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int Hash_function(string s,int p)
{
	int k = 1, sum = 0;
	for (int j = s.length() - 1; j >= 0; j--)
	{
		sum = (sum + int(s[j])*k) % p;
		k = ((k%p)*(37 % p)) % p;
	}
	return (int)(sum);
}
void Create_HashTable(string table[],string input[], int index[],int n,int p)
{
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		input[i] = s;
		int key = Hash_function(s,p)%p;
		int times = 1;
		while (index[key]!=0)
		{
			key = (key + 1) % p;
			times++;
		}
		index[key] = times;
		table[key] = s;
	}
}
int Search(string table[],string s,int p)
{
	int key = Hash_function(s,p) % p;
	int times = 1;
	int i = 0;
	while (s!=table[key])
	{
		key = (key + 1) % p;
	}
	return key;
}
int main()
{
	string table[100];
	string input[100];
	int index[250];
	int n = 0, p = 0;
	cin >> n >> p;
	for (int i = 0; i < p; i++)
		index[i] = 0;
	Create_HashTable(table,input, index, n, p);
	for (int i = 0; i < n; i++)
	{
		int a = Search(table, input[i], p);
		cout <<a<<" ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << index[Search(table, input[i], p)]<<" ";
	cout << endl;
}