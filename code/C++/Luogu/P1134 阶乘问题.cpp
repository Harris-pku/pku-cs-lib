#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int h[4] = {6, 8, 4, 2};
int n, w = 1;
int main(){
	scanf("%d", &n);
	while (n){
		for (int i = 1; i <= n % 10; i++)
			if (i != 5)
				w = w * i % 10;
		n /= 5;
		w = w * h[n % 4] % 10;
	}
	printf("%d", w);
	return 0;
}
