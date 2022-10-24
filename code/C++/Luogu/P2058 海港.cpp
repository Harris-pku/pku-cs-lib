/*  Coder: Harris
	Time: 2017.2.10
	Website: https://www.luogu.com.cn/problem/P2058
	Algorithm: enumeration
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int f[100010], da[300010], time[300010];
int sum[100010], n, m, t, k, h, ans;
int main(){
	scanf("%d", &n);
	while (n--){
		scanf("%d%d", &t, &k);
	 	while (k--){
			time[++m] = t;
			scanf("%d", &da[m]);
	  		if (!f[da[m]]) ans++;
	  		f[da[m]]++;
	 	}
	 	while (t-time[h] >= 86400)
			if (--f[da[h++]] == 0) ans--;
	 	printf("%d\n",ans);
	}
	return 0;
}

