#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int a[105], n, sum, cur, ans;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	cur = sum/n;
	for (int i = 1; i <= n; ++i){
		if (a[i] == cur) continue;
		a[i+1] -= cur-a[i]; ans++;
	}
	printf("%d", ans);
	return 0;
}
