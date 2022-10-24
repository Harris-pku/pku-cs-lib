#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[100005], n, m, l, r, mid, sum;
bool can(int x){
	int t = 1, sum = 0;
	for (int i = n; i >= 1; --i){
		if (sum+a[i] <= x) sum += a[i];
	 	else{
			sum = 0; t++; i++;
		   	if (t > m) break;
	    }
	}
	return t <= m;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	 	sum += a[i];
	}
	r = sum;
	while (l < r){
		mid = (l + r) >> 1;
	 	if (can(mid)) r = mid;
	 	else l = mid + 1;
	}
	printf("%d", l);
	return 0;
}
