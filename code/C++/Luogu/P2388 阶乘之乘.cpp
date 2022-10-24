#include <cstdio>
#include <algorithm>

using namespace std;

long long ans;
int n, i;
int main(){
	scanf("%d", &n);
	for (i = 0; i <= n - 5; i = i + 5)
		ans += (i / 5 + i / 25 + i / 125 + i / 625 + i / 3125 + i / 15625 + i / 78125 + i / 390625 + i / 1953125 + i / 9765625 + i / 48828125) * 5;
	for (; i <= n; i++)
		ans += i / 5 + i / 25 + i / 125 + i / 625 + i / 3125 + i / 15625 + i / 78125 + i / 390625 + i / 1953125 + i / 9765625 + i / 48828125;
	printf("%lld", ans);
	return 0;
}
