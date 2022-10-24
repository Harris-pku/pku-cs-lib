#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 1000005
#define maxm 2000005
int v[maxm], nex[maxm], h[maxn], dis[maxn], vis[maxn];
int q[maxm*2], head, tail; int num[maxn] = {0, 1}, n, m, t, p;
int main(){
	scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; ++i){
		scanf("%d%d", &t, &v[i]);
	    nex[i] = h[t]; h[t] = i;
	    v[m+i] = t; nex[m+i] = h[v[i]]; h[v[i]] = m+i;
	}
	q[head] = 1; tail++; vis[1] = 1; dis[1] = 0;
	while (head < tail){
		t = q[head++]; p = h[t]; vis[t] = 0;
	    while (p){
			if (dis[t] + 1 < dis[v[p]]){
				dis[v[p]] = dis[t] + 1;
                num[v[p]] = num[t];
				if (!vis[v[p]]){
					vis[v[p]] = 1; q[tail++] = v[p];
				}
			}
            else if (dis[t] + 1 == dis[v[p]]){
                num[v[p]] = (num[v[p]] + num[t]) % 100003;
            }
	    	p = nex[p];
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d\n", num[i]);
	return 0;
} 
