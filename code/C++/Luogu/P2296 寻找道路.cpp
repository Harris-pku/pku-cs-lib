#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int v[200005], next[200005], h[10005], visit[10005];
int v1[200005], next1[200005], h1[10005], f[10005];
int q[200005], tail, head, d[10005];
int n, m, x, y, ans, start, end;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i){
		scanf("%d%d", &x, &y);
	  	v[i] = y; next[i] = h[x]; h[x] = i;
	 	v1[i] = x; next1[i] = h1[y]; h1[y] = i;
	}
	scanf("%d%d", &start, &end);
	q[tail++] = end;
	while (head < tail){
		x = q[head++]; f[x] = 1;
	 	x = h1[x];
	 	while (x){
			if (!f[v1[x]]){
				f[v1[x]] = 1; q[tail++] = v1[x];
			}
	  	x=next1[x];
	 	}
	}
	for (int i = 1; i <= n; ++i){
		if (!f[i]) continue;
	 	x = h[i]; y = 1;
	 	while (x){
			if (!f[v[x]]){
				y = 0; break;
			}
	  		x = next[x];
	 	} 
	 	if (y) visit[i] = 1;
	}
	if (!visit[start]) {printf("-1");return 0;}
	memset(q,0,sizeof q);
	memset(d,9,sizeof d);
	d[start]=0;head=tail=0;
	q[tail++]=start;
	while (head<tail)
	{y=q[head++];x=h[y];
	 while (x)
	 {if (visit[v[x]] && d[v[x]]>d[y]+1)
	   d[v[x]]=d[y]+1;q[tail++]=v[x];
	  x=next[x];
	 }
	}
	if (d[end]==151587081) printf("-1");
	else printf("%d",d[end]);
}

