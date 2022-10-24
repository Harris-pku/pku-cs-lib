#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100010;

int maxv[maxn*5],minv[maxn*5],sumv[maxn*5],addv[maxn*5],a[maxn];

void build(int o, int L, int R){
	int lc = o*2, rc = o*2+1;
	sumv[o] = 0;
	if (R==L) sumv[o] = addv[o] = a[L];
	else {
		int M = L + (R-L)/2;
		build(lc, L, M);build(rc, M+1, R);
		sumv[o] = sumv[lc] + sumv[rc];
	}
}

int y1,y2;//[y1,y2]
void maintain(int o, int L, int R){
	int lc = o*2, rc = o*2+1;
	maxv[o] = minv[o] = sumv[o] = 0;
	if (R > L) {
		maxv[o] = max(maxv[lc], maxv[rc]);
		minv[o] = min(minv[lc], minv[rc]);
		sumv[o] = sumv[lc] + sumv[rc];
	}
	minv[o] += addv[o]; maxv[o] += addv[o]; sumv[o] += addv[o] * (R-L+1);
	//add
}

int v;
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

int _min, _max, _sum;
void query(int o, int L, int R, int add){
	if (y1 <= L && y2 >= R) {
		_sum += sumv[o] + add * (R-L+1);
		_max = max(_max, maxv[o] + add);
		_min = min(_min, minv[o] + add);
	} else {
		int M = L + (R-L)/2;
		if (y1 <= M) query(o*2, L, M, add + addv[o]);
		if (y2 > M) query(o*2+1, M+1, R, add + addv[o]);
	}
}

int main(){
	
}



