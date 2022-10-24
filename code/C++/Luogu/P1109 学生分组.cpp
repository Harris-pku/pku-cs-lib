#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[105], minn, maxn, sum, n, l, r;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	scanf("%d%d", &l, &r);
	if (sum < l * n || sum > r * n){
		printf("-1"); return 0;
	}
	for (int i = 1; i <= n; i++){
		if (a[i] < l)
			minn += l - a[i];
		if (a[i] > r)
			maxn += a[i] - r;
	}
	printf("%d", max(minn, maxn));
	return 0;
}
