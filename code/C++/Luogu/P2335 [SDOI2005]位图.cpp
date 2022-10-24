#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int mx[10] = {1, -1, 0, 0}, my[10] = {0, 0, 1, -1};
int qx[50000], qy[50000], a[200][200], ans[200][200], n, m, head, tail;
int main(){
	scanf("%d%d", &n, &m);
	memset(ans, 6, sizeof ans);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			if (a[i][j]){
				ans[i][j] = 0;
				qx[++tail] = i, qy[tail] = j;
			}
		}
	int x, y;
	while (head < tail){
		x = qx[++head];
		y = qy[head];
		for (int i = 0; i < 4; i++){
			if ((x + mx[i] > 0 && x+mx[i]<=n && y+my[i]>0 && y+my[i]<=m) && (ans[x+mx[i]][y+my[i]] > ans[x][y] + 1)){
				qx[++tail] = x + mx[i]; qy[tail] = y + my[i];
				ans[x + mx[i]][y+my[i]] = ans[x][y] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
