#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

const int maxn = 50010;
const int maxm = 500010;
const int inf = 2000000010;
int sumflow, tot, mincost, n, m, s, t;
struct Edge{
	int u, v, cap, cost, next;
} edge[maxm<<1];
int head[maxn], dis[maxn], pp[maxn], vis[maxn];

void addedge(int u, int v, int cap, int cost){
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].cap = cap;
	edge[tot].cost = cost;
	edge[tot].next = head[u];
	head[u] = tot++;
}

bool spfa(){
	queue<int> q;
	int cur, x;
	memset(vis, 0, sizeof(vis));
	memset(pp, -1, sizeof(pp));
	for (int i = 1; i <= n; i++)
		dis[i] = inf;
	vis[s] = 1;
	dis[s] = 0;
	q.push(s);
	while (!q.empty()){
		cur = q.front();
		q.pop();
		vis[cur] = 0;
		for (int i = head[cur]; i != -1; i = edge[i].next){
			x = edge[i].v;
			if (edge[i].cap && dis[x] > dis[cur] + edge[i].cost){
				dis[x] = dis[cur] + edge[i].cost;
				pp[x] = i;
				if (!vis[x]){
					q.push(x);
					vis[x] = 1;
				}
			}
		}
	}
	if (dis[t] == inf)
		return false;
	return true;
}

void MCMF(){
	int minflow, flow = 0;
	while (spfa()){
		minflow = inf + 1;
		for (int i = pp[t]; i != -1; i = pp[edge[i].u])
			minflow = min(minflow, edge[i].cap);
		flow += minflow;
		for (int i = pp[t]; i != -1; i = pp[edge[i].u])		{
			edge[i].cap -= minflow;
			edge[i ^ 1].cap += minflow;
		}
		mincost += dis[t] * minflow;
	}
	sumflow = flow;
}

int main(){
	int u, v, cap, cost;
	memset(head, -1, sizeof(head));
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d%d", &u, &v, &cap, &cost);
		addedge(u, v, cap, cost);
		addedge(v, u, 0, -cost);
	}
	for (int i = 0; i <= 9; i++)
		printf("%d ", edge[i].next);
	MCMF();
	printf("%d %d", sumflow, mincost);
	return 0;
}
