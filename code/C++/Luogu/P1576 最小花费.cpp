#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 2005
#define maxm 200005
int v[maxm], nex[maxm], h[maxn], vis[maxn];
int q[maxm*5], head, tail; int n, m, t, s, p, cur;
double dis[maxn], w[maxm];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i){
		scanf("%d%d%lf", &t, &v[i], &w[i]);
	    nex[i] = h[t]; h[t] = i; w[i] = 1 - w[i]/100;
        v[m+i] = t; w[m+i] = w[i];
        nex[m+i] = h[v[i]]; h[v[i]] = m+i;
	}
    scanf("%d%d", &s, &t);
	q[head] = s; tail++; vis[s] = 1; dis[s] = 1;
	while (head < tail){
		cur = q[head++]; p = h[cur]; vis[cur] = 0;
	    while (p){
			if (dis[cur] * w[p] > dis[v[p]]){
				dis[v[p]] = dis[cur] * w[p];
				if (!vis[v[p]]){
					vis[v[p]] = 1; q[tail++] = v[p];
				}
			}
	    	p = nex[p];
		}
	}
	printf("%.8f", 100 / dis[t]);
	return 0;
} 
