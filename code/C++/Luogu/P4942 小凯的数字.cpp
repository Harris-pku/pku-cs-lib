#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long l, r, n, ans; int T;
int main(){
	scanf("%d", &T);
	while(T--){
		cin >> l >> r;
		n = (r - l + 1) % 9;
		ans = 5*((l+r)%9)*n % 9;
		cout << ans % 9 << endl;
	}
	return 0;
}
