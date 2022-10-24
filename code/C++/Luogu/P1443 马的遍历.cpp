#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct point{int x, y;} q[400010];
int h[8][2] = {{2,1}, {1,2}, {2,-1}, {-2,-1}, {-2,1}, {1,-2}, {-1,2}, {-1,-2}};
int a[410][410], vis[410][410], n, m, x0, y0, x1, y1, xx, yy, head, tail;
int main(){
	scanf("%d%d%d%d", &n, &m, &x0, &y0);
	memset(a, 6, sizeof(a));
	a[x0][y0] = 0; q[0].x = x0; q[0].y = y0;
	tail = 1; vis[x0][y0] = 1;
	while (head < tail){
		x1 = q[head].x; y1 = q[head++].y;
	 	vis[x1][y1] = 0;
	 	for (int k = 0; k < 8; k++){
			xx = x1 + h[k][0]; yy = y1 + h[k][1];
	  		if (xx<1 || xx>n || yy<1 || yy>m) continue;
	  		if (a[x1][y1] + 1 < a[xx][yy]){
				a[xx][yy] = a[x1][y1] + 1;
	   			if (!vis[xx][yy]){
					vis[xx][yy] = 1; q[tail].x = xx;
					q[tail++].y = yy;
				}
	  		}
	 	}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if (a[i][j] == 101058054) a[i][j] = -1;
	  		printf("%-5d", a[i][j]);
	 	}
	 	printf("\n");
	}
	return 0;
}
