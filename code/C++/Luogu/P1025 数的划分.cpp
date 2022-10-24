#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, ans;
void dfs(int x, int m, int t){
	if (m==0 && t==0) ans++;
	if (m<=0 || t<=0) return;
	if (m>=x && t==1){
		ans++; return;
	}
	for (int i = x; i <= m/2; i++){
		dfs(i, m-i, t-1);
	}
}
int main(){
	scanf("%d%d", &n, &k);
	dfs(1, n, k);
	printf("%d", ans);
	return 0;
} 
