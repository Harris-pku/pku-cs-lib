#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 6662333;
long long n, ans = 1, a = 2;
int main(){
	cin >> n;
	for (n -= 1; n; n >>= 1, a = (a*a)%maxn)
		if (n & 1)
			ans = (ans * a) % maxn;
	cout << ans;
	return 0;
}
