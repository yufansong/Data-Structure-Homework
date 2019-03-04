#include<iostream>
using namespace std;
const int MAX_NUM =10000;
typedef  int Elemtype ;
typedef int KeyType;
typedef struct {
	Elemtype elem[MAX_NUM];
	int length;
}SSTable;
int Search_Bin(SSTable st, KeyType key)
{
	int low, high, mid;
	low = 0;
	high = st.length-1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (key == st.elem[mid])
		{
			int i = mid;
			while (true)
			{
				mid--;
				if (key > st.elem[mid])
					return i;
				i = mid;
			}
		}
		else if (key < st.elem[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int main()
{
	SSTable st;
	int key;
	cin >> st.length;
	for (int i = 0; i < st.length; i++)
		cin >> st.elem[i];
	cin >> key;
	cout << Search_Bin(st, key) << endl;

}