#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long ans; int n, m, k, x, y;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%d%d", &x, &y);
	 	if (i==1) k = x;
	 	else k = min(k+m, x);
	 	ans += k * y;
	}
	cout << ans;
	return 0;
}
