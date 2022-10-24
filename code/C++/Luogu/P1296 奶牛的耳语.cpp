#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000005], n, d, ans;
int main(){
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (abs(a[j] - a[i]) <= d)
				ans++;
			else
				break;
	printf("%d", ans);
	return 0;
}
