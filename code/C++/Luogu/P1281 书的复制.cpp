#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int a[505], n, m, l, r, mid, sum;
bool can(int x){
	int t = 1, he = 0;
	for (int i = m; i >= 1; i--){
		if (he + a[i] <= x)
			he += a[i];
		else{
			he = 0;
			t++; i++;
			if (t > n)
				break;
		}
	}
	return t <= n;
}

int out[505][2];
void check(int x){
	int cnt = m, he = x;
	for (int i = n; i >= 1; i--){
		out[i][1] = cnt; he = x;
		while (cnt > 0 && he - a[cnt] >= 0)
			he -= a[cnt--];
		out[i][0] = cnt + 1;
	}
	for (int i = 1; i <= n; i++){
		printf("%d %d\n", out[i][0], out[i][1]);
	}
}

int main(){
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	r = sum;
	while (l < r){
		mid = (l + r) >> 1;
		if (can(mid))
			r = mid;
		else
			l = mid + 1;
	}
	check(r);
	return 0;
}
