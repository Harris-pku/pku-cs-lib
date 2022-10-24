#include <iostream>
#include <algorithm>

using namespace std;

int a[10][10], f[10][10];
int h[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int sx, sy, fx, fy, n, m, t, b, c, ans;
void dfs(int x, int y){
	if (x == fx && y == fy){
		ans++; return;
	}
	for (int k = 0; k < 4; k++){
		int xx = x + h[k][0], yy = y + h[k][1];
		if (xx<1 || xx>n || yy<1 || yy>n) continue;
		if (!f[xx][yy] && !a[xx][yy]){
			f[xx][yy] = 1;
	  		dfs(xx, yy);
			f[xx][yy] = 0;
		}   	
	}
}
int main(){
	cin >> n >> m >> t >> sx >> sy >> fx >> fy;
	for (int i = 1; i <= t; i++){
		cin >> b >> c; a[b][c] = 1;
	}
	f[sx][sy] = 1;
	dfs(sx, sy);
	printf("%d", ans);
	return 0;
}
