#include <cstdio>
#include <algorithm>

using namespace std;

int h[10005], v[10005], nex[10005], f[10005];
int n, k, x, y, p;
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++i){
		scanf("%d%d", &x, &y);
	 	v[i] = x+y-1; nex[i] = h[x]; h[x] = i;
	}
	for (int i = n; i >= 1; --i){
		if (!h[i]){
			f[i] = f[i+1] + 1; continue;
		}
		p = h[i];
		while (p){
			f[i] = max(f[i], f[v[p]]);
	  		p = nex[p];
		}
	}
	for (int i = 1; i <= n; ++i)
	 	printf("%d ",f[i]);
	return 0;
}
