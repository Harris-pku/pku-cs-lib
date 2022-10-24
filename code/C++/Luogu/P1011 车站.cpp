#include <cstdio>
#include <algorithm>

using namespace std;

int f[25][3], n, m, x, a, t;
int main(){
	scanf("%d%d%d%d", &a, &n, &m, &t);
	f[2][0] = x = 1;
	f[1][1] = a;
	m -= 2 * a;
	for (int i = 3; i < n; i++){
		f[i][0] = f[i - 1][0] + f[i - 2][0];
		f[i][1] = f[i - 1][1] + f[i - 2][1];
		if (i <= n - 3){
			x += f[i][0]; m -= f[i][1];
		}
	}
	x = m / x;
	f[2][2] = f[1][2] = a;
	for (int i = 3; i <= t; i++){
		f[i][2] = f[i - 1][2];
		f[i][2] += f[i - 2][1] + f[i - 2][0] * x;
	}
	printf("%d", f[t][2]);
	return 0;
}
