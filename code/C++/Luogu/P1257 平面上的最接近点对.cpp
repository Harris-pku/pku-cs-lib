#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n; double x[10005], y[10005], x1, ans = 10000000.0;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &x[i], &y[i]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			x1 = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			ans = min(x1, ans);
		}
	printf("%0.4lf", ans);
	return 0;
}
