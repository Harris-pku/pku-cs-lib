#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 500005;
int bef[maxn], q[maxn], n, x, t, ans;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &x);
		while (t && x > q[t]){
			t--; ans++;
		}
		if (t){
			if (q[t] == x){
				ans += bef[t];
				if (bef[t] < t)
					ans++;
			}
			else
				ans++;
		}
		q[++t] = x;
		if (q[t - 1] == x)
			bef[t] = bef[t - 1] + 1;
		else
			bef[t] = 1;
	}
	printf("%d", ans);
	return 0;
}