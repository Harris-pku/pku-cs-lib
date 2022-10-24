#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int exgcd(int a, int b, int &x, int &y){
	if (b == 0){
		x = 1; y = 0; return a;
	}
	int d = exgcd(b, a%b, x, y);
	int t = x;
	x = y; y = t - y*(a/b);
	return d;
}

int a, b, x, y;
int main(){
	scanf("%d%d", &a, &b);
	printf("%d ", exgcd(a, b, x, y));
	printf("%d %d", x, y);
}

