#include<iostream>
using namespace std;
int n = 0;
const int MAX_NUM = 1000000;
int elem[MAX_NUM] = { 0 };
int elem_temp[MAX_NUM] = { 0 };
void Sort_Select()
{
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
			if (elem[k] > elem[j])
				k = j;
		if (i!= k)
		{
			int temp = elem[i];
			elem[i] = elem[k];
			elem[k] = temp;
		}
	}
}
void Sort_Bubble()
{
	bool  flag = true;
	for (int i = n; i > 1; i--)
	{
		flag = true;
		for (int j = 0; j < i-1; j++)
		{
			if (elem[j + 1] < elem[j])
			{
				int temp = elem[j + 1];
				elem[j + 1] = elem[j];
				elem[j] = temp;
				flag = false;
			}
		}
		if (flag == true)
			break;
	}
}
void Sort_Insert()
{
	for (int i=1;i<n;i++)
		if (elem[i] < elem[i - 1])
		{
			int temp = elem[i];
			for (int j = i - 1; j >= 0, temp < elem[j]; j--)
			{
				elem[j + 1] = elem[j];
				elem[j ] = temp;
			}
		}
}
void Sort_Shell()
{
	int dlta[6] = { 364,121,40,13,4,1 };
	for (int k = 0; k < 6; k++)
	{
		int gap = dlta[k];
		for (int i = gap; i < n; i++)
			if (elem[i] < elem[i - gap])
			{
				int temp = elem[i];
				int j = 0;
				for (j = i - gap; j >= 0 && temp < elem[j]; j -= gap)
					elem[j + gap] = elem[j];
				elem[j+gap] = temp;
			}
	}
}
void Sort_Qsort(int low,int high)
{
	if (low < high)
	{
		int pivotloc = 0;
		int temp = elem[low];
		pivotloc = elem[low];
		int low_temp = low, high_temp = high;
		while (low < high)
		{
			while (low < high&&elem[high] >= pivotloc)
				high--;
			elem[low] = elem[high];
			while (low < high&&elem[low] < pivotloc)
				low++;
			elem[high] = elem[low];
		}
		elem[low] = temp;
		pivotloc = low;
		low = low_temp;
		high = high_temp;
		Sort_Qsort(low, pivotloc - 1);
		Sort_Qsort(pivotloc + 1, high);
	}
}
void Sort_merge_array(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void Sort_merge(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		Sort_merge(a, first, mid, temp);    //左边有序  
		Sort_merge(a, mid + 1, last, temp); //右边有序  
		Sort_merge_array(a, first, mid, last, temp); //再将二个有序数列合并  
	}
}
void Sort_Heap_Adjust(int h[],int s,int m)//堆里面关于elem*2是子树的运算是从1开始的，所以从0开始会有问题
{
	int temp =elem [s-1];
	for (int j = 2 * s; j <= m; j =j* 2)
	{
		if ((j < m) && (elem[j-1] < elem[j + 1-1]))
			j++;
		if (!(	temp< elem[j-1]))
			break;
		elem[s-1] = elem[j-1];
		s = j;
	}
	elem[s-1] = temp;
}
void Sort_Heap()
{
	for (int i = n / 2; i >0; i--)
		Sort_Heap_Adjust(elem, i, n);
	for (int i = n; i >1; i--)
	{
		int temp=elem[0];
		elem[0] = elem[i-1];
		elem[i-1] = temp;
		Sort_Heap_Adjust(elem, 1, i - 1);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> elem[i];
	Sort_Heap();
	for (int i = 0; i < n; i++)
		cout << elem[i] << " ";
	cout << endl;
}