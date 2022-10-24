#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[50005], len, n, m, l, mid, r;
bool can(int x){
	int p = 0, cnt = 0;
	for (int i = 1; i <= n+1; ++i)
	 	if (a[i]-a[p] < x) cnt++;
	 	else p = i;
	return (cnt <= m);
}
int main(){
	scanf("%d%d%d", &len, &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	a[n+1] = len; l = 0; r = len;
	while (l < r){
		mid = (l+r+1) >> 1;
	 	if (can(mid)) l = mid;
	 	else r = mid - 1;
	}
	printf("%d", l);
	return 0;
}
