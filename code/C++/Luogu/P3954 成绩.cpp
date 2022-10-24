#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int ans, a, b, c;
int main(){
	scanf("%d%d%d", &a, &b, &c);
	ans = a / 10 * 2 + b / 10 * 3 + c / 10 * 5;
	printf("%d", ans);
	return 0;
}
