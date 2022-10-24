#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, cur, sum, ans;
int main(){
	scanf("%d%d", &n, &sum); ans = sum;
	for (int i = 2; i <= n; i++){
		cin >> cur;
	 	if (sum > 0) cur += sum;
	 	ans = max(ans, cur);
	 	sum = cur;
	}
	printf("%d", ans);
	return 0;
}
