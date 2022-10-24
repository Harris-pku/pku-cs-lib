#include <cstdio>
#include <algorithm>

using namespace std;

int h[5][2] = {0, 0, -1, 0, 1, 0, 0, -1, 0, 1};
int a[5][5], ans = 10000, f, t;
void ding(int x, int y){
	for (int k = 0; k < 5; k++)
		a[x + h[k][0]][y + h[k][1]] = (a[x + h[k][0]][y + h[k][1]] + 1) & 1;
}
void dfs(int e){
	if (t > ans || e == 15)
		return;
	f = 0;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			f += a[i][j];
	if (f == 9){
		ans = min(ans, t);
		return;
	}
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++){
			t++; ding(i, j);
			dfs(e + 1);
			ding(i, j); t--;
		}
}
int main(){			
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%d", &a[i][j]);
	dfs(1);
	printf("%d", ans);
	return 0;
}
