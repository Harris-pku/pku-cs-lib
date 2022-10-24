/*  Coder: Harris
    Time: 2016.8.24
    Website: https://www.luogu.com.cn/problem/P2670
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, m, ans, a[105][105];
char x[105][105];
int h[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> x[i][j];
			if (x[i][j] == '*')
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			ans = 0;
			if (a[i][j])
				cout << "*";
			else{
				for (int k = 0; k < 8; k++)
					ans += a[i + h[k][0]][j + h[k][1]];
				cout << ans;
			}
		}
		cout << endl;
	}
	return 0;
}
/*
input:
3 3
*??
???
?*?

output:
*10
221
1*1
*/