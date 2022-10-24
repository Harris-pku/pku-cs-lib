#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100010;
long long sumv[maxn*5], addv[maxn*5], a[maxn];
int n, m;

void build(int o, int L, int R){
	int lc = o*2, rc = o*2+1;
	sumv[o] = 0;
	if (R==L) sumv[o] = addv[o] = a[L];
	else{
		int M = L + (R-L)/2;
		build(lc, L, M); build(rc, M+1, R);
		sumv[o] = sumv[lc] + sumv[rc];
	}
}

int y1, y2;//[y1,y2]
void maintain(int o, int L, int R){
	int lc = o*2, rc = o*2+1;
	sumv[o] = 0;
	if (R > L) {
		sumv[o] = sumv[lc] + sumv[rc];
	}
	sumv[o] += addv[o] * (R-L+1);
}

long long v = 0;
void update(int o, int L, int R){
	int lc = o*2, rc = o*2+1;
	if (y1 <= L && y2 >= R) {
		addv[o] += v;
	} else {
		int M = L + (R-L)/2;
		if (y1 <= M) update(lc, L, M);
		if (y2 > M) update(rc, M+1, R);
	}
	maintain(o, L, R);
}

long long _sum = 0;
void query(int o, int L, int R, long long add){
	if (y1<=L && y2>=R) {
		_sum += sumv[o] + add * (R-L+1);
	} else {
		int M = L + (R-L)/2;
		if (y1 <= M) query(o*2, L, M, add + addv[o]);
		if (y2 > M) query(o*2+1, M+1, R, add + addv[o]);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	build(1, 1, n); int f;
	for (int i = 1; i <= m; ++i){
		scanf("%d%d%d", &f, &y1, &y2);
		if (f==1){
			scanf("%lld", &v); update(1, 1, n);
		}else{
			_sum = 0;
			query(1, 1, n, 0); printf("%lld\n", _sum);
		}
	}
	return 0;
}