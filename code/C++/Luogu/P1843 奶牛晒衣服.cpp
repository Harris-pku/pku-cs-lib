#include <cstdio>
#include <algorithm>

using namespace std;
int a[500005], n, k, h, t, x, maxn;
int main(){
	scanf("%d%d%d", &n, &h, &t);
	for (int i = 1; i <= n; i++){
		scanf("%d", &x);
		a[x]++; maxn = max(maxn, x);
	}
	while (k * h < maxn){
		k++; a[maxn]--;
		a[maxn-t]++;
		while (!a[maxn]){
			maxn--;
		}
	}
	printf("%d", k);
	return 0;
}
