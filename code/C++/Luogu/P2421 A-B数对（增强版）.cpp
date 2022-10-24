#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> f;
long long ans;
int a[200005], n, c;
int main(){
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		f[a[i]]++;
	}
	sort(a+1, a+n+1);
	for (int i = n; i; i--){
		if (f[a[i]] && f[a[i]-c]){
			ans += f[a[i]] * f[a[i]-c];
			f[a[i]] = 0;
		}
	}
	cout << ans;
	return 0;
}
