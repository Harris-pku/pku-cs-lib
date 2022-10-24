#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 2005
#define maxm 4000005
int a[maxn][maxn], dis[maxn], vis[maxn], n, m, t, p, x, y, z;
int q[maxm*2], head, tail; int num[maxn] = {0, 1};
int main(){
	scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
    memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= m; ++i){
		scanf("%d%d%d", &x, &y, &z);
        a[x][y] = min(a[x][y], z);
	}
	q[head] = 1; tail++; vis[1] = 1; dis[1] = 0;
	while (head < tail){
		t = q[head++]; vis[t] = 0;
        if (t==n) continue;
	    for (int i = 1; i <= n; ++i){
			if (dis[t] + a[t][i] < dis[i]){
				dis[i] = dis[t] + a[t][i];
                num[i] = num[t];
			}
            else if (dis[t] + a[t][i] == dis[i]){
                num[i] += num[t];
            }
            if (num[i] && !vis[i]){
				vis[i] = 1; q[tail++] = i;
			}
		}
        num[t] = 0;
	}
	if (dis[n] != 0x3f3f3f3f)
        printf("%d %d", dis[n], num[n]);
    else printf("No answer");
	return 0;
} 
