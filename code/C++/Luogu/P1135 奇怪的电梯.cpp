#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int k[210], d[210], f[210]; int n, a, b, x, y;
int q[100010], head, tail;
int main(){
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
		scanf("%d", &k[i]);
	memset(d, 1, sizeof(d));
	d[a] = 0; q[head] = a; f[a] = 1; tail++;
	while (head < tail){
		x = q[head++]; y = x + k[x]; f[x] = 0;
		if (y>0 && y<=n && d[y]>d[x]+1) {
			d[y] = d[x] + 1;
			if (!f[y]){
				q[tail++] = y; f[y] = 1;
			}
		}
		y = x - k[x];
		if (y>0 && y<=n && d[y]>d[x]+1) {
			d[y] = d[x] + 1;
			if (!f[y]){
				q[tail++] = y; f[y] = 1;
			}
		}
	}
	if (d[b] <= 10000) printf("%d", d[b]);
	else printf("-1");
	return 0;
}

