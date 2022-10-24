#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 0x3f3f3f3f;
int f[100005][25], n, m, l, r, ans, t;
int main(){
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &f[i][0]);
	for (int j = 1; j <= 20; ++j){
	 	if ((1<<j) > m){
			t = j; break;
		}
		for (int i = 1; i <= m; ++i){
			if (i+(1<<j)-1 > m) break;
	  		f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
	 	}
	}
	for (int i = 1; i <= n; ++i){
		scanf("%d%d", &l, &r); ans = maxn;
	 	for (int j = t; j >= 0; --j){
		 	if ((1<<j) > r-l+1) continue;
	  		ans = min(ans, f[l][j]);
	  		l += (1<<j);
		}
	 	printf("%d ", ans);
	}
	return 0;
} 
