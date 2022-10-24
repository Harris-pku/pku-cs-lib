#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[500010], c[500010], n, m, t, x, y;
int lowbit(int x){
	return x & (-x);
}
void add(int p, int w){
	while (p <= n){
		c[p] += w;
	 	p += lowbit(p);
	}
}
int getsum(int x){
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
	 	add(i, a[i]);
	}
	for (int i = 1; i <= m; ++i){
		scanf("%d%d%d", &t, &x, &y);
	 	if (t == 1) add(x, y);
	 	else printf("%d\n", getsum(y) - getsum(x-1));
	}
	return 0;
}
