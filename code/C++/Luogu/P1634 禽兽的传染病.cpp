#include <iostream>
#include <cstdio>

using namespace std;

long long ans; int x, n;
int main(){
	scanf("%d%d", &x, &n);
	x++; ans = 1;
	for (int i = 1; i <= n; i++)
		ans *= x;
	cout << ans;
	return 0;
}
