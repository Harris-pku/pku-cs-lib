#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, T;
int check(int x){
	int t = floor(sqrt(x * 2));
	if (t * (t + 1) == x * 2)
		return 1;
	return 0;
}
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		printf("%d\n", check(n - 1));
	}
	return 0;
}
