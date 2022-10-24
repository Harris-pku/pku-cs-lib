#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int hx[4] = {0, 1, 0, -1};
const int hy[4] = {1, 0, -1, 0};
char s[1010][1010];
int f[1010][1010], ans[100010], n, m, x, y, k;
void dfs(int x, int y){
	for (int i = 0; i < 4; i++){
		int xx = x + hx[i];
		int yy = y + hy[i];
		if (xx>n || xx<1 || yy>n || yy<1 || s[x][y]==s[xx][yy] || f[xx][yy]!=-1) continue;
		f[xx][yy] = k; ans[k]++;
		dfs(xx, yy);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	 	scanf("%s", s[i]+1);
	memset(f, -1, sizeof(f));
	for (k = 0; k < m; k++){
		scanf("%d%d", &x, &y);
	 	if (f[x][y] != -1) ans[k] = ans[f[x][y]];
	 	else{
	 		f[x][y] = k; ans[k] = 1; dfs(x, y);
	 	}
		printf("%d\n", ans[k]);
	}
	return 0;
}
