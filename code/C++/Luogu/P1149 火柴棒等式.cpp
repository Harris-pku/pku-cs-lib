#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int h[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, ans;
int num(int x){
	int sum = 0, cur = x;
	if (!cur)
		return h[0];
	while (cur){
		sum += h[cur % 10];
		cur /= 10;
	}
	return sum;
}
int main(){
	scanf("%d", &n);
	n -= 4;
	for (int i = 0; i <= 711; i++){
		for (int j = 0; j <= 711; j++){
			if (num(i) + num(j) + num(i + j) == n){
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
