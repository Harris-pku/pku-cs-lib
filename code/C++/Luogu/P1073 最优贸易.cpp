#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
	int u, v, nex;
}a[500005], b[500005];
int ha[100005], hb[100005], maxn[100005], minn[100005];
int w[100005], vis[100005], n, m, x, y, z, numa, numb, ans;
int q[2000005], head, tail;
void add(Node a[], int h[], int u, int v, int & num){
	a[num].u = u; a[num].v = v;
	a[num].nex = h[u]; h[u] = num++;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	 	scanf("%d", &w[i]);
	for (int i = 1; i <= m; ++i){
		scanf("%d%d%d", &x, &y, &z);
	 	if (z == 1){
			add(a, ha, x, y, numa); add(b, hb, y, x, numb);
		}
	 	else {
			add(a, ha, x, y, numa); add(a, ha, y, x, numa);
		   	add(b, hb, x, y, numb); add(b, hb, y, x, numb);
	    }
	}
	memset(minn, 6, sizeof(minn));
	memset(maxn, -1, sizeof(maxn));

	tail = q[0] = vis[1] = 1; minn[1] = w[1];
	while (head < tail){
		x = q[head++]; vis[x] = 0;
	 	for (int i = ha[x]; i ; i = a[i].nex)
	  		if (minn[x]<minn[a[i].v] || w[a[i].v]<minn[a[i].v]){
				minn[a[i].v] = min(w[a[i].v], minn[x]);
	   			if (!vis[a[i].v]){
					q[++tail] = a[i].v; vis[a[i].v] = 1;
				}
	  		}
	}

	head = 0; tail = 1; q[0] = n; vis[n] = 1; maxn[n] = w[n];
	while (head < tail){
		x = q[head++]; vis[x] = 0;
	 	for (int i = hb[x]; i ; i = b[i].nex)
	  		if (maxn[x]>maxn[b[i].v] || w[b[i].v]>maxn[b[i].v]){
				maxn[b[i].v] = max(w[b[i].v], maxn[x]);
	   			if (!vis[b[i].v]){
					q[++tail] = b[i].v; vis[b[i].v] = 1;
				}
	  		}
	}
	for (int i = 1; i <= n; ++i)
	 	ans = max(ans, maxn[i]-minn[i]);
	printf("%d\n", ans);
	return 0;
}
