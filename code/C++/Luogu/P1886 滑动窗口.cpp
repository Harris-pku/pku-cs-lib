#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1000000;
struct Node{int val, pos;} qa[maxn], qi[maxn];
int ansi[maxn], ansa[maxn], n, k, num, cur, xi, yi, xa, ya;

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++i){
		scanf("%d", &num);
		while (xi<yi && qi[yi-1].val>=num) --yi;
		qi[yi].val = num; qi[yi++].pos = i;
		
		while (xa<ya && qa[ya-1].val<=num) --ya;
		qa[ya].val = num; qa[ya++].pos = i;
	}
	for (int i = k+1; i <= n; ++i){
		ansi[++cur] = qi[xi].val;
		ansa[cur] = qa[xa].val;
		scanf("%d", &num);
	
		while (xi<yi && i-qi[xi].pos>=k) ++xi;
		while (xi<yi && qi[yi-1].val>=num) --yi;
		qi[yi].val = num; qi[yi++].pos = i;
		
		while (xa<ya && i-qa[xa].pos>=k) ++xa;
		while (xa<ya && qa[ya-1].val<=num) --ya;
		qa[ya].val = num; qa[ya++].pos = i;
	}
	ansi[++cur] = qi[xi].val; ansa[cur] = qa[xa].val;
	
	for (int i = 1; i <= n-k+1; ++i)
		 printf("%d ", ansi[i]);
	printf("\n");
	for (int i = 1; i <= n-k+1; ++i)
		 printf("%d ", ansa[i]);
	return 0;
}
