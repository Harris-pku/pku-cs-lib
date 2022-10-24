#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long a[100005], t, cnt, n, m, ans, cur, s;
int main(){
	cin >> n;
	for (long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> m >> t >> s >> cur;
	a[t] += s;
	for (long long i = 1; i <= n; i++){
		cnt += (i-m) * a[i];
	}
	t = abs(cnt) + 1;
	for (long long i = 1; i <= n; i++){
		if (abs(cnt+(i-m)*cur) < t){
			t = abs(cnt+(i-m)*cur);
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
