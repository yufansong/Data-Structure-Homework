#include<iostream>  
#include<string>  
#include<cstring>  
using namespace std;
int map[6][6];
void makemap() {
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++) if (i != j) map[i][j] = 1;
	map[4][1] = map[1][4] = 0;
	map[4][2] = map[2][4] = 0;
}
void dfs(int x, int k, string s) { // x 为 出发点/经过点，k为边的条数，s记录路径  
	s += char(x + '0');
	if (k == 8) {
		cout << s << endl;
		return;
	}
	for (int y = 1; y <= 5; y++)
		if (map[x][y]) {
			map[x][y] = map[y][x] = 0;//画过的的边标记为 0  
			dfs(y, k + 1, s);
			map[x][y] = map[y][x] = 1;//递归完之后，返回原来未画的状态 1  
		}
}
int main() {
	makemap();
	dfs(1, 0, "");
	return 0;
}