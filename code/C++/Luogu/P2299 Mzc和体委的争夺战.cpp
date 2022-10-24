#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 2505
#define maxm 1000005
int v[maxm], nex[maxm], w[maxm], h[maxn], dis[maxn];
int q[maxm*2], head, tail;
int n, m, t, p;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
		dis[i] = maxm;
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &t, &v[i], &w[i]);
		nex[i] = h[t]; h[t] = i;
		v[m+i] = t; w[m+i] = w[i];
		nex[m + i] = h[v[i]];
		h[v[i]] = m + i;
	}
	q[head] = 1; tail++;
	while (tail > head){
		t = q[head++]; p = h[t];
		while (p){
			if ((dis[t] + w[p]) < dis[v[p]]){
				dis[v[p]] = dis[t] + w[p];
				q[tail++] = v[p];
			}
			p = nex[p];
		}
	}
	printf("%d", dis[n]);
	return 0;
}
