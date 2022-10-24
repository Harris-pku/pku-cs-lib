#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
int main(){
	scanf("%d", &n);
	printf("%d\n", n);
	for (int i = 1; i <= n; i++){
		k = 1 - i & 1;
		for (int j = 1; j <= i; j++)
			printf("%d", k);
		for (int j = i + 1; j <= n; j++)
			printf("%d", 1 - k);
		printf("\n");
	}
	return 0;
}
