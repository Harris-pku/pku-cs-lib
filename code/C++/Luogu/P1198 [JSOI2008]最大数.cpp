#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 200000;
int maxv[5 * maxn], n = maxn, m, len, d;
void build(int o, int L, int R){

}

int ql, qr;
int query(int o, int L, int R){
	int M = L + (R - L) / 2, ans = 0x3ffffff;
	ans = -ans;
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
		maxv[o] = v;
	else{
		if (p <= M)
			update(o * 2, L, M);
		else
			update(o * 2 + 1, M + 1, R);
		maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
	}
}

int main(){
	scanf("%d%d\n", &m, &d);
	int a, b, t = 0; char c;
	for (int i = 1; i <= m; i++){
		scanf("%c %d\n", &c, &a);
		if (c == 'Q'){
			ql = len - a + 1;
			qr = len;
			printf("%d\n", t = query(1, 1, n));
		}
		else{
			p = ++len;
			v = (a + t) % d;
			update(1, 1, n);
		}
	}
	return 0;
}
