#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, tot, f[1005] = {0, 1};
int dfs(int x){
	if (f[x])
		return f[x];
	int ans = 1;
	for (int i = 1; i <= x / 2; i++){
		ans += dfs(i);
	}
	return f[x] = ans;
}
int main(){
	scanf("%d", &n);
	tot = dfs(n);
	printf("%d", tot);
	return 0;
}
