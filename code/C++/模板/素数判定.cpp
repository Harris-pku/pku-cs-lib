#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int is_prime(int n){
	if (n <= 1) return 0;
	int m = floor(sqrt(n));
	for (int i = 2; i <= m; ++i)
	 	if (n%i == 0) return 0;
	return 1;
}

int n;
int main(){
	scanf("%d", &n);
	if (is_prime(n)) printf("%d is a prime", n);
	else printf("%d is not a prime", n);
	return 0;
}
