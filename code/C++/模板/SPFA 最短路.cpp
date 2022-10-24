#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 2505
#define maxm 1000005
int v[maxm], nex[maxm], w[maxm], h[maxn], dis[maxn], vis[maxn];
int q[maxm*2], head, tail; int n, m, cur, s, p;
int main(){
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= m; ++i){
		scanf("%d%d%d", &cur, &v[i], &w[i]);
	    nex[i] = h[cur]; h[cur] = i;
	    v[m+i] = cur; w[m+i] = w[i];
	    nex[m+i] = h[v[i]]; h[v[i]] = m+i;
	}
	memset(dis, 0x3f, sizeof(dis));
	q[head] = s; tail++; vis[s] = 1; dis[s] = 0;
	while (head < tail){
		cur = q[head++]; p = h[cur]; vis[cur] = 0;
	    while (p){
			if (dis[cur] + w[p] < dis[v[p]]){
				dis[v[p]] = dis[cur] + w[p];
				if (!vis[v[p]]){
					vis[v[p]] = 1; q[tail++] = v[p];
				}
			}
	    	p = nex[p];
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", dis[i]);
	return 0;
} 
