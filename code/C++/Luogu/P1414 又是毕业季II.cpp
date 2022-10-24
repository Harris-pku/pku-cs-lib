#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int d[1000005], a[10005], n, p, x;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		p = max(p, a[i]);
		x = (int)sqrt(a[i] + 1);
		for (int j = 1; j <= x; j++)
			if (!a[i] % j){
				d[j]++;
				if (j * j != a[i]){
					d[a[i] / j]++;
				}
			}
	}
	for (int i = 1; i <= n; i++){
		while (d[p] < i){
			p--;
		}
		printf("%d", p);
	}
	return 0;
}
