#include <cstdio>
#include <algorithm>

using namespace std;

int v[50005], nex[50005], w[50005], h[1505], dis[1505];
int q[500005], head, tail, n, m, t, p;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
		dis[i] = -1;
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &t, &v[i], &w[i]);
		nex[i] = h[t]; h[t] = i;
	}
	q[head] = 1; tail++;
	while (tail > head){
		t = q[head++]; p = h[t];
		while (p){
			if ((dis[t] + w[p]) > dis[v[p]]){
				dis[v[p]] = dis[t] + w[p];
				q[tail++] = v[p];
			}
			p = nex[p];
		}
	}
	printf("%d", dis[n]);
	return 0;
}
