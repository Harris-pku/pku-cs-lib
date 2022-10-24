#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int T, n;
int f[25005], a[105], ans;
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		sort(a+1, a+n+1);
		memset(f, 0, sizeof(f));
		ans = n;
		for (int i = 1; i <= n; i++){
			if (f[a[i]]){
				ans--; continue;
			}
			f[a[i]] = 1;
			for (int j = a[i] + 1; j <= a[n]; j++){
				f[j] |= f[j-a[i]];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
