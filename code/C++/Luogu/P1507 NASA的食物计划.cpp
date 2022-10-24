#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 55; 
const int maxv = 405;
int f[maxv][maxv], v[maxn], w[maxn], ka[maxn], n, vm, mm;
int main(){
	scanf("%d%d%d", &vm, &mm, &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d%d%d", &v[i], &w[i], &ka[i]);
	 	for (int j = vm; j >= v[i]; --j)
	  		for (int k = mm; k >= w[i]; --k)
	   			f[j][k] = max(f[j][k], f[j-v[i]][k-w[i]] + ka[i]);
	}
	printf("%d", f[vm][mm]);
	return 0;
} 
