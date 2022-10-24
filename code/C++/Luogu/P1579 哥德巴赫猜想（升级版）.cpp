#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
int n;
int prime(int x){
	if (x == 2)
		return 1;
	for (int i = 2; i <= ceil(sqrt(x)); i++){
		if (x % i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d", &n);
	for (int k = 2; k <= 3; k++){
		for (int i = 2; i <= n / 2; i++){
			if (prime(i) && prime(n-k-i)){
				printf("%d %d %d", k, i, n-k-i);
				return 0;
			}
		}
	}
	return 0;
}
