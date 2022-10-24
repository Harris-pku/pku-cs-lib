#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int num[35][35], n;
long long f[35][35], w[35], t;
void front(int x, int y){
    if (x > y) return;
	printf("%d ", num[x][y]);
	if (x == y) return;
	front(x, num[x][y]-1);
	front(num[x][y]+1, y);
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
	 	for (int j = 0; j <= n; ++j)
	  		f[i][j] = 1;
	for (int i = 1; i <= n; ++i){
	 	cin >> f[i][i]; num[i][i] = i;
	}
	for (int i = n; i >= 1; --i)
	 	for (int j = i+1; j <= n; ++j)
	  		for (int k = i; k <= j; ++k){
				t = f[i][k-1]*f[k+1][j] + f[k][k];
	   			if (t > f[i][j]){
					f[i][j] = t; num[i][j] = k;
				}
	  		}
	cout << f[1][n] << endl;
	front(1, n);
	return 0;
}

