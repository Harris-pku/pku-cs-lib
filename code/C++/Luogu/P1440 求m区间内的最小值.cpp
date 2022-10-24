#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 2000005;
struct Node{
    int val, pos;
}qi[maxn];
int ansi[maxn], n, k, num, cur, xi, yi;

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 2; i <= n; ++i){
		scanf("%d", &num); ansi[++cur] = qi[xi].val;
		while (xi<yi && i-qi[xi].pos>=k) ++xi;
		while (xi<yi && qi[yi-1].val>=num) --yi;
		qi[yi].val = num; qi[yi++].pos = i;
	}
	ansi[++cur] = qi[xi].val;
	for (int i = 1; i <= n; ++i)
		 printf("%d\n", ansi[i]);
	return 0;
}
