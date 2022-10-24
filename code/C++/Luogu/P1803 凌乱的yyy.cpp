#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000005;
int f[maxn], nex[maxn]; int n, maxi, l, r;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d%d", &l, &r);
	 	nex[l] = nex[l] ? min(nex[l], r) : r;
	 	if (r > maxi) maxi = r;
	}
	for (int i = maxi-1; i >= 0; --i){
		f[i] = nex[i] ? max(f[nex[i]] + 1, f[i+1]) : f[i+1];
	}
	printf("%d", f[0]);
	return 0;
}
