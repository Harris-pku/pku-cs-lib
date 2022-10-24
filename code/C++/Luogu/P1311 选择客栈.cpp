#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, k, p, color, cost, ans;
int before[55], after[55];
int main(){
	scanf("%d%d%d", &n, &k, &p);
	while (n--){
		scanf("%d%d", &color, &cost);
		if (cost <= p){
			for (int i = 0; i < k; i++){
				before[i] += after[i];
				after[i] = 0;
			}
		}
		ans += before[color];
		if (cost <= p)
			before[color]++;
		else
			after[color]++;
	}
	printf("%d", ans);
	return 0;
}
