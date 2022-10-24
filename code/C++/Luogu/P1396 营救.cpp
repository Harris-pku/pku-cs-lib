#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 50005
#define maxm 100005
int v[maxm], nex[maxm], w[maxm], h[maxn], dis[maxn], vis[maxn];
int q[maxm*5], head, tail, n, m, cur, s, t, p, l, r, mid;
inline int can(int x){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
	q[head=0] = s; tail = 1; vis[s] = 1; dis[s] = 1;
	while (head < tail){
		cur = q[head++]; p = h[cur]; vis[cur] = 0;
	    while (p){
			if (w[p] <= x){
                if (v[p] == t) return 1;
				if (dis[v[p]] == 0x3f3f3f3f){
                    dis[v[p]] = 1;
				    if (!vis[v[p]]){
					    vis[v[p]] = 1; q[tail++] = v[p];
				    }
                }
			}
	    	p = nex[p];
		}
	}
    if (dis[t] == 0x3f3f3f3f) return 0;
    else return 1;
}
int main(){
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; ++i){
		scanf("%d%d%d", &cur, &v[i], &w[i]);
	    nex[i] = h[cur]; h[cur] = i;
	    v[m+i] = cur; w[m+i] = w[i];
	    nex[m+i] = h[v[i]]; h[v[i]] = m+i;
        r = max(r, w[i]);
	}
	while (l < r){
        mid = (l+r) >> 1;
        if (can(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d", l);
	return 0;
} 
