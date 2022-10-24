#include <iostream>
#include <algorithm>

using namespace std;

int c[1005][1005], a, b, k, n, m;
long long ans;
int main(){
	cin >> a >> b >> k >> n >> m;
	ans = 1;
	for (int j = 1; j <= k; j++)
		c[1][j] = j;
	for (int i = 2; i <= m; i++)
		for (int j = i; j <= k; j++){
			if (i == j){
				c[i][j] = 1; continue;
			}
			c[i][j] = c[i - 1][j - 1] + c[i][j - 1];
			c[i][j] %= 10007;
		}
	ans = c[m][k];
	for (int i = 1; i <= m; i++){
		ans *= b;
		ans %= 10007;
	}
	for (int i = 1; i <= n; i++){
		ans *= a;
		ans %= 10007;
	}
	cout << ans;
	return 0;
}
