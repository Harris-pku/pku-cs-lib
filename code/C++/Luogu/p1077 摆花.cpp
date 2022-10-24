#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int f[105] = {1}, n, m, x;
int main(){
	scanf("%d%d", &n, &m);
	for (int k = 1; k <= n; ++k){
		scanf("%d", &x);
	 	for (int i = m; i >= 0; --i)
	  		for (int j = 1; j <= min(x, m-i); ++j)
	    		f[k][i+j] = (f[k][i+j] + f[k-1][i]) % 1000007;
	}
	printf("%d", f[m]);
	return 0;
}
