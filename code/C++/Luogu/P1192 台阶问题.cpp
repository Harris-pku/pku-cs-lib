#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int f[100005], n, k, m;
int main(){
	scanf("%d%d", &n, &m);
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; ++i){
		for (int k = max(1, i); k <= m; ++k){
			if (i < k) continue;
	 		f[i] = (f[i] + f[i-k]) % 100003;
		}
	}
	printf("%d", f[n]);
	return 0;
}
