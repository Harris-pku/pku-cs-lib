#include <cstdio>
#include <algorithm>

using namespace std;

int a[15] = {1}, n;
void dfs(int x, int re){
	if (re == 0){
		for (int i = 1; i < x - 1; i++)
			printf("%d+", a[i]);
		printf("%d\n", a[x - 1]);
		return;
	}
	for (int k = a[x-1]; k <= re; k++)
		if (k < n){
			a[x] = k;
			dfs(x+1, re-k;
		}
}
int main(){
	scanf("%d", &n);
	dfs(1, n);
	return 0;
}
