#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node{
	int sum, num;
}x[1005], y[1005];
int maxn, n, m, k, l, d, xx1, xx2, yy1, yy2;
int cmp1(Node a, Node b){
	return a.sum > b.sum;
}
int cmp2(Node a, Node b){
	return a.num < b.num;
}
int main(){
	scanf("%d%d%d%d%d", &n, &m, &k, &l, &d);
	for (int i = 1; i < n; ++i){
		x[i].num = i; x[i].sum = 0;
	}
	for (int i = 1; i < m; ++i){
		y[i].num = i; y[i].sum = 0;
	}
	for (int i = 1; i <= d; ++i){
		scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
		if (xx1 == xx2) y[min(yy1, yy2)].sum++;
		if (yy1 == yy2) x[min(xx1, xx2)].sum++;
	}
	sort(x+1, x+n, cmp1);
	sort(y+1, y+m, cmp1);
	sort(x+1, x+k+1, cmp2);
	sort(y+1, y+l+1, cmp2);
	for (int i = 1; i <= k; ++i)
		printf("%d ", x[i].num);
	printf("\n");
	for (int i = 1; i <= l; ++i)
		printf("%d ", y[i].num);
	printf("\n");
	return 0; 
}
