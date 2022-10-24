#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 105; 
const int maxv = 1005;
int f[maxv], v, w, n, t;
int main(){
	scanf("%d%d", &t, &n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &v, &w);
	 	for(int j = t; j >= v; j--)
	 		f[j] = max(f[j], f[j-v] + w);
	}
	printf("%d", f[t]);
	return 0;
} 
