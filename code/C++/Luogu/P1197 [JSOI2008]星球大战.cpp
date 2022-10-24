/*  Coder: Harris
    Time: 2020.1.30
    Website: https://www.luogu.com.cn/problem/P1197
    Description: n points and m edges, given the information of every
                 edge of u and v. given k points will be crashed in
                 order, how many connected sections in the graph after
                 every crash?
                 给定 n 点 m 边, k 个点被摧毁的次序, 求每次摧毁后联通块的个数
    
    Algorithm: use Union-Find to record the number of connected section
               in reverse order
               逆序建点, 使用并查集记录联通块个数
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 500005;
int h[maxn], to[maxn], nex[maxn], c[maxn];
int f[maxn], fa[maxn], ans[maxn], n, m, k, tot;
int found(int x){
	if (fa[x] == x) return x;
	return fa[x] = found(fa[x]);
}
void unify(int x, int y){
	int fx = found(x), fy = found(y);
	if (fx != fy){
		fa[fx] = fy; tot--;
	}
}
int x, y;
int main(){
	scanf("%d%d", &n, &m); tot = n;
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &x, &y);
		nex[i] = h[x]; to[i] = y; h[x] = i;
		nex[m+i] = h[y]; to[m+i] = x; h[y] = m+i;
	}
	for (int i = 0; i <= n; i++){
		f[i] = 1; fa[i] = i;
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++){
		scanf("%d", &x); c[i] = x; f[x] = 0;
	}
	for (int i = 0; i < n; i++){
		if (!f[i]) continue;
		int p = h[i];
		while (p){
			if (f[to[p]]) unify(i, to[p]);
			p = nex[p];
		}
	}
	for (int i = k; i >= 1; i--){
		x = c[i]; f[x] = 1; ans[i] = tot - i;
		int p = h[x];
		while (p){
			if (f[to[p]]) unify(x, to[p]);
			p = nex[p];
		}
	}
	ans[0] = tot;
	for (int i = 0; i <= k; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
/*
input:
8 13
0 1
1 6
6 5
5 0
0 6
1 2
2 3
3 4
4 5
7 1
7 2
7 6
3 6
5
1
6
3
5
7

output:
1
1
1
2
3
3
*/