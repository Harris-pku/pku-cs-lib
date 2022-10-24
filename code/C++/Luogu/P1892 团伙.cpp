#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <iostream>

using namespace std;

int t[1005], fa[1005];
int n, m, x, y, h; char c;
int find(int x){
	if (fa[x] == x)	return x;
	return fa[x] = find(fa[x]);
}
void hebing(int x, int y){
	int x1 = find(x), y1 = find(y);
	if (x1 != y1){
		fa[x1] = y1;
		h--;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	h = n;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++){
		cin >> c;
		scanf("%d%d", &x, &y);
		if (c == 'F')
			hebing(x, y);
		else{
			if (t[y])
				hebing(x, t[y]);
			if (t[x])
				hebing(t[x], y);
			t[x] = y; t[y] = x;
		}
	}
	printf("%d", h);
	return 0;
}
