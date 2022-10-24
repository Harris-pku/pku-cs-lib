#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int t, n, k;
int main(){
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		scanf("%d%d", &n, &k);
		if ((n & k) == k)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
