#include <iostream>
#include <algorithm>

using namespace std;

int a[10005], n, m, k, t, w, r, b = 1, ans;
int main(){
	cin >> n >> m >> k >> w >> r;
	t = m / k * w;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= r; i++){
		a[b] -= t;
		if (a[b] < 0) b++;
	}
	for (int i = 1; i <= n; i++)
		if (a[i] > 0) ans++;
	cout << ans;
	return 0;
}
