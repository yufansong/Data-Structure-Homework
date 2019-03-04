#include<iostream>
using namespace std;
int n = 0;
const int MAX_NUM = 1000000;
int elem[MAX_NUM] = { 0 };
int elem_temp[MAX_NUM] = { 0 };
void Sort_Heap_Adjust(int h[], int s, int m)//堆里面关于elem*2是子树的运算是从1开始的，所以从0开始会有问题
{
	int temp = elem[s - 1];
	for (int j = 2 * s; j <= m; j = j * 2)
	{
		if ((j < m) && (elem[j - 1] < elem[j + 1 - 1]))
			j++;
		if (!(temp< elem[j - 1]))
			break;
		elem[s - 1] = elem[j - 1];
		s = j;
	}
	elem[s - 1] = temp;
}
void Sort_Heap()
{
	for (int i = n / 2; i >0; i--)
		Sort_Heap_Adjust(elem, i, n);
	for (int i = n; i >1; i--)
	{
		int temp = elem[0];
		elem[0] = elem[i - 1];
		elem[i - 1] = temp;
		Sort_Heap_Adjust(elem, 1, i - 1);
	}
}
int main()
{
	int k = 0;
	cin >> n>>k;
	for (int i = 0; i < n; i++)
		cin >> elem[i];
	Sort_Heap();
	for (int i = n-1; i>=n-k; i--)
		cout << elem[i] << " ";
	cout << endl;
}