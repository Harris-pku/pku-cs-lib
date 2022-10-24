#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, sum;
int main(){
	scanf("%d", &n);
	for (int i = 2; i <= 10000000; i += 2){
		for (int j = i - 1; j >= 1; j--){
			if (++sum == n){
				printf("%d/%d", j, i - j);
				return 0;
			}
		}
		for (int j = 1; j <= i; j++){
			if (++sum == n){
				printf("%d/%d", j, i - j + 1);
				return 0;
			}
		}
	}
	return 0;
}
