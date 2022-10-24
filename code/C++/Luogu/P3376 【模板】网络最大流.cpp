#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100010;
struct node{
	int u, v, next, cap;
} edge[maxn<<1];

int h[maxn], dis[maxn], n, m, cnt, ans, S, T;
int a, b, c;

void add(int a, int b, int c){
	edge[cnt].u = a;
	edge[cnt].v = b;
	edge[cnt].cap = c;
	edge[cnt].next = h[a];
	h[a] = cnt++;
}

int bfs(){
	memset(dis, -1, sizeof(dis));
	queue<int> q;
	dis[S] = 0;
	q.push(S);
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int i = h[cur]; i != -1; i = edge[i].next){
			if (dis[edge[i].v] == -1 && edge[i].cap > 0){
				dis[edge[i].v] = dis[cur] + 1;
				q.push(edge[i].v);
			}
		}
	}
	if (dis[T] < 0)
		return 0;
	return 1;
}

int find(int x, int flow)
{ //����
	if (x == T)
		return flow;
	int a;
	for (int i = h[x]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if (dis[v] == dis[x] + 1 && edge[i].cap > 0 && (a = find(v, min(flow, edge[i].cap)))){
			edge[i].cap -= a; edge[i ^ 1].cap += a;
			return a;
		}
	}
	return 0;
}

void Dinic(){
	int tmp;
	while (bfs()){
		tmp = find(S, 0x7fffff);
		ans += tmp;
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d%d%d%d", &n, &m, &S, &T);
	memset(h, -1, sizeof(h));
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c); add(b, a, 0);
	}
	Dinic();
	return 0;
}
