#include <cstdio>
#include <algorithm>

using namespace std;

int a, ans, sum, maxn;
bool f[100005];
int main(){
	scanf("%d", &ans);
	for (int i = 0; i < ans; i++){
		scanf("%d", &a);
		maxn = max(maxn, a);
		if (!f[a]){
			f[a] = true; sum++;
		}
	}
	ans += 10 * maxn + sum * 5;
	printf("%d", ans);
	return 0;
}
