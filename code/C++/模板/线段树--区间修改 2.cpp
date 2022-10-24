#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int y1,y2;
void maintain(int o, int L, int R){
	int lc = o*2, rc = o*2+1;
	minv[o] = maxv[o] = sumv[o]=0;
	if (R > L){
		minv[o] = min(minv[lc], minv[rc]);
		maxv[o] = max(maxv[lc], maxv[rc]);
		sumv[o] = sumv[lc] + sumv[rc];
	}
	minv[o]=min(minv[o], setv[o]);maxv[o]=max(maxv[o], setv[o]);
	//sumv[o] = addv[o] * (R-L+1);
}

void pushdown(int o){
	if (setv[o]>=0){
		setv[o*2] = setv[o*2+1] =setv[o];
		setv[o] = -1;
	}
}

void update(int o, int L, int R){
	int lc = o*2, rc = o*2+1;
	if (y1<=L && y2>=R) setv[o] = v;
	else {
		pushdown(o);
		int M = L + (R-L)/2;
		if (y1 <= M) update(lc, L, M);else maintain(lc, L, M);
		if (y2 > M) update(rc, M+1, R);else maintain(rc, M+1, R);
 	}
 	maintain(o, L, R);
}

void query(int o, int L, int R){
	if (setv[o] >= 0) {
		_sum += setv[o] * (min(y2,R)-max(y1,L)+1);
		_min = min(_min, setv[o]);
		_max = max(_max, setv[o]);
	} else if (y1<=L && y2>=R) {
		_sum += sumv[o];
		_min = min(_min, minv[o]);
		_max = max(_max, maxv[o]);
	} else {
		int M = L + (R-L)/2;
		if (y1 <= M) query(o*2, L, M);
		if (y2 > M) query(o*2+1, M+1, R);
	}
}



