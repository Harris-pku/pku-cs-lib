#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 200005;
int maxv[5 * maxn], n, m;
int ql, qr; //query min:[ql,qr]
int query(int o, int L, int R){
	int M = L + (R - L) / 2, ans = 0;
	if (ql <= L && qr >= R)
		return maxv[o];
	if (ql <= M)
		ans = max(ans, query(o * 2, L, M));
	if (qr > M)
		ans = max(ans, query(o * 2 + 1, M + 1, R));
	return ans;
}

int p, v; //a[p]=v;
void update(int o, int L, int R){
	int M = L + (R - L) / 2;
	if (L == R)
		maxv[o] = max(maxv[o], v);
	else{
		if (p <= M)
			update(o * 2, L, M);
		else
			update(o * 2 + 1, M + 1, R);
		maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
	}
}

int main(){
	scanf("%d%d\n", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d\n", &v);
		p = i; update(1, 1, n);
	}
	int a, b; char c;
	for (int i = 1; i <= m; i++){
		scanf("%c %d %d\n", &c, &a, &b);
		if (c == 'Q'){
			ql = a; qr = b;
			printf("%d\n", query(1, 1, n));
		}
		else{
			p = a; v = b;
			update(1, 1, n);
		}
	}
	return 0;
}
