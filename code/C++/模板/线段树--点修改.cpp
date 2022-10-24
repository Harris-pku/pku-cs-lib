#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1000000;

int minv[maxn*5],n;

void build(int o, int L, int R){
	
}

int ql,qr;//query min:[ql,qr]
int query(int o, int L, int R){
	int M = L + (R-L)/2,ans=0x7ffffff;
	if (ql<=L && qr>=R) return minv[o];
	if (ql<=M) ans=min(ans, query(o*2, L, M));
	if (qr>M) ans=min(ans, query(o*2+1, M+1, R));
	return ans;
}

int p,v;//a[p]=v;
void update(int o, int L, int R){
	int M = L + (R-L)/2;
	if (L==R) minv[o]=v;
	else{
		if (p<=M) update(o*2, L, M);else update(o*2+1, M+1, R);
		minv[o]=min(minv[o*2], minv[o*2+1]);
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&p,&v);update(1,1,n);
	}
}
