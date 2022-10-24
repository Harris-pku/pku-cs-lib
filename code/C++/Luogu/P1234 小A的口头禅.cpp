#include <iostream>
#include <algorithm>

using namespace std;

char a[1005][1005], c[5] = "hehe";
int h[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m, ans;
inline int sou(int x, int y, int k){
	int f = 1;
	for (int i = 1; i < 4; i++)
		if (x + i * h[k][0] < 1 || x + i * h[k][0] > n || y + i * h[k][1] < 1 || y + i * h[k][1] > m || a[x + i * h[k][0]][y + i * h[k][1]] != c[i]){
			f = 0; break;
		}
	return f;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			if (a[i][j] == 'h')
				for (int k = 0; k < 4; k++)
					if (sou(i, j, k))
						ans++;
		}
	cout << ans;
	return 0;
}
