#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int time[10005], x, n, len, ans, t;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d %d", &x, &len); t = 0;
		while (scanf("%d",&x)==1 && x)
			t = max(t, time[x]);
		time[i] = t + len; ans = max(ans, time[i]);
	}
	printf("%d\n", ans);
	return 0;
}
