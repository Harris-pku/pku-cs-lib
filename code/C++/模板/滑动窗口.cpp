#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
	int val, pos;
};
const int maxn = 1000000;
Node maxqueue[maxn], minqueue[maxn];
int n, k, num, cur; int minhead, mintail, maxhead, maxtail;
int mincur[maxn], maxcur[maxn];

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++i){
		scanf("%d", &num);
		
		while (minhead < mintail && minqueue[mintail-1].val >= num) --mintail;
		minqueue[mintail].val = num;minqueue[mintail++].pos = i;
		
		while (maxhead < maxtail && maxqueue[maxtail-1].val <= num) --maxtail;
		maxqueue[maxtail].val = num;maxqueue[maxtail++].pos = i;
	}
	for (int i=k+1;i<=n;i++){
		mincur[++cur] = minqueue[minhead].val;
		maxcur[cur] = maxqueue[maxhead].val;
		scanf("%d", &num);
		
		while (minhead<mintail && i-minqueue[minhead].pos>=k) ++minhead;
		while (minhead<mintail && minqueue[mintail-1].val>=num) --mintail;
		minqueue[mintail].val = num; minqueue[mintail++].pos = i;
		
		while (maxhead<maxtail && i-maxqueue[maxhead].pos>= k) ++maxhead;
		while (maxhead<maxtail && maxqueue[maxtail-1].val<=num) --maxtail;
		maxqueue[maxtail].val = num; maxqueue[maxtail++].pos = i;
	}
	mincur[++cur] = minqueue[minhead].val;
	maxcur[cur] = maxqueue[maxhead].val;
	
	for (int i = 1; i <= n-k+1; ++i)
		printf("%d ", mincur[i]);
	printf("\n");
	for (int i = 1; i <= n-k+1; ++i)
		printf("%d ", maxcur[i]);
	return 0;
}
