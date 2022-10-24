#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10005; 
const int maxv = 100005;
int f[maxv], v[maxn], w[maxn], n,t;
int main(){
	scanf("%d%d", &t, &n);
	for (int i = 1; i <= n; i++)
	 	scanf("%d%d", &v[i], &w[i]);
	for (int i = 1; i <= n; i++)
	  	for (int j = v[i]; j <= t; j++)
	  		f[j] = max(f[j], f[j-v[i]] + w[i]);
	printf("%d", f[t]);
	return 0;
}
