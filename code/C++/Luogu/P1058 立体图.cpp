#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char pvc[6][8] = { "+---+"  ,
				   "/   /|" ,
				   "+---+ |",
				   "|   | +",
				   "|   |/" ,
				   "+---+"  };
int ht[6] = {2, 1}, th[6] = {-2, -1, 0, 0, -1, -2};
char ti[1005][1005];
int a[55][55], n, m, y, x, h;
void hui(int x1, int y1){
	for (int i = 5; i >= 0; i--)
		for (int j = 0; j <= 6 + th[i]; j++){
			ti[x1 + i - 5][y1 + j + ht[i]] = pvc[i][j];
		}
}
int main(){
	memset(ti, '.', sizeof ti);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		h = 0;
		for (int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			h = max(h, a[i][j]);
		}
		h = 3 * h + 2 * (n - i) + 3;
		x = max(x, h);
	}
	y = 4 * m + 2 * n + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= a[i][j]; k++)
				hui(x - 2 * (n - i) - 3 * (k - 1), 2 * (n - i) + 4 * (j - 1) + 1);
	for (int i = 1; i <= x; i++, printf("\n"))
		for (int j = 1; j <= y; j++)
			printf("%c", ti[i][j]);
	return 0;
}
