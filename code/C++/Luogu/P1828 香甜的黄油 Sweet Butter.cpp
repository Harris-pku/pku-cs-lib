#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int w[805], d[805], f[805], s[805], q[10005];
int n, p, c, x, y, z, head, tail, sum, minn = 0x7ffffff, ans;
struct Node{
	int v, w;
} a[805][805];

int main(){
	scanf("%d%d%d", &n, &p, &c);
	for (int i = 1; i <= n; i++){
		scanf("%d", &x);
		w[x]++;
	}
	for (int i = 1; i <= c; i++){
		scanf("%d%d%d", &x, &y, &z);
		s[x]++;	s[y]++;
		a[x][s[x]].v = y; a[x][s[x]].w = z;
		a[y][s[y]].v = x; a[y][s[y]].w = z;
	}
	for (int j = 1; j <= p; j++){
		x = j;
		memset(d, 10, sizeof(d));
		memset(f, 0, sizeof(f));
		memset(q, 0, sizeof(q));
		d[x] = head = 0;
		q[tail=1] = x; f[x] = 1;
		while (head < tail){
			y = q[++head]; f[y] = 0;
			for (int i = 1; i <= s[y]; i++){
				if (d[y] + a[y][i].w < d[a[y][i].v]){
					d[a[y][i].v] = d[y] + a[y][i].w;
					if (!f[a[y][i].v]){
						q[++tail] = a[y][i].v;
						f[a[y][i].v] = 1;
					}
				}
			}
		}
		sum = 0;
		for (int i = 1; i <= p; i++)
			sum += w[i] * d[i];
		minn = min(minn, sum);
	}
	printf("%d\n", minn);
	return 0;
}
