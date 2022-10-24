#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int ans[20010], tot, a, b, c, k;
int main(){
	scanf("%d", &k);
	for (int i = 10000; i <= 30000; i++){
		a = i / 100;
		b = (i % 10000 / 10);
		c = i % 1000;
		if (a % k == 0 && b % k == 0 && c % k == 0)
			ans[++tot] = i;
	}
	for (int i = 1; i <= tot; i++)
		printf("%d\n", ans[i]);
	if (!tot)
		printf("No");
	return 0;
}
