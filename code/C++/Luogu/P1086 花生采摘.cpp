/*  Coder: Harris
	Time: 2019.2.26
	Website: https://www.luogu.com.cn/problem/P1086
	Algorithm: enumeration
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node{
	int x, y, w;
}nut[405];
int n, m, k, tot, cur, xx, yy, ans;
int cmp(Node a, Node b){
	return a.w > b.w;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			scanf("%d", &cur);
			if (cur){
				nut[++tot].x = i;
				nut[tot].y = j; nut[tot].w = cur;
			}
		}
	}
	sort(nut+1, nut+tot+1, cmp);
	if (k < nut[1].x*2+1){
		printf("0"); return 0;
	}
	k -= nut[1].x + 1; xx = nut[1].x;
	yy = nut[1].y; ans += nut[1].w;
	for (int i = 2; i <= tot; i++){
		k -= abs(nut[i].x-xx) + abs(nut[i].y-yy) + 1;
		if (nut[i].x > k) break;
		xx = nut[i].x; yy = nut[i].y; ans += nut[i].w;
	}
	printf("%d", ans);
	return 0;
}
