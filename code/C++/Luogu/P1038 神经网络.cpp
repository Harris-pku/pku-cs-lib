#include <cstdio>
#include <algorithm>

using namespace std;

int c[105], u[105], f[105], x[10005], y[10005], w[10005];
int n, p, maxp, ans;
int main(){
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &c[i], &u[i]);
	for (int i = 1; i <= p; ++i){
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		f[y[i]] = f[x[i]] + 1;
	 	maxp = max(maxp, f[y[i]]);
	} 
	for (int i = 1; i <= n; ++i){
		if (f[i]){
			for (int j = 1; j <= p; ++j)
	            if (c[x[j]]>0 && y[j]==i)
					c[i]+=w[j]*c[x[j]];
	        c[i]-=u[i];
	    }
		if (f[i]==maxp && c[i]>0){
			printf("%d %d\n", i, c[i]); ans++;
		}
	}
	if (!ans) printf("NULL");
	return 0;
}
