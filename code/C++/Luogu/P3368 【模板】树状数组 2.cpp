#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int c[500010], a[500010], k, l, r, w, n, m;
int lowbit(int x){
	return x & (-x);
}
void add(int x, int y){
	while (x <= n){
		c[x] += y;
	 	x += lowbit(x);
	}
}
int sum(int x){
	int tot = 0;
	while (x > 0){
		tot += c[x];
	 	x -= lowbit(x);
	}
	return tot;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	 	add(i, a[i] - a[i-1]);
	}
	for (int i = 1; i <= m; ++i){
		scanf("%d%d", &k, &l);
	 	if (k == 1){
			scanf("%d%d", &r, &w);
			add(l, w); add(r+1, -w);
		}
	 	else printf("%d\n", sum(l));
	}
	return 0;
}
