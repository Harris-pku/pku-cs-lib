#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double h, s, v, l, k, g = 10.0, eps = 0.0001; int n, ans;
int main(){
	scanf("%lf%lf%lf%lf%lf%d", &h, &s, &v, &l, &k, &n);
	for (int i = 0; (i < n) && (i <= s); i++)
		if (v > -eps + (s - i) * sqrt(g / (2 * h)) && v < eps + (s - i + l) * sqrt(g / (2 * (h - k))))
			ans++;
	printf("%d", ans);
	return 0;
}
