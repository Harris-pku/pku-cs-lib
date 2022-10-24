#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

const int maxn = 10010;
const int maxm = 200010;
using namespace std;

int v[maxm], nex[maxm], w[maxm], h[maxn], dis[maxn];
int q[maxm*5], head, tail;
int n, m, t, p, x, y, e;
map<string, int> ma;
string s;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		dis[i] = 200000000;
	for (int i = 1; i <= n; i++){
		cin >> s; ma[s] = i;
	}
	for (int i = 1; i <= m; i++){
		cin >> s; x = ma[s];
		cin >> s; y = ma[s];
		scanf("%d", &t);
		v[2*i] = y; w[2*i] = t;
		nex[i*2] = h[x]; h[x] = i*2;
		v[2*i-1] = x; w[2*i-1] = t;
		nex[i*2-1] = h[y];
		h[y] = i*2-1;
	}
	cin >> s; x = ma[s];
	cin >> s; y = ma[s];
	cin >> s; t = ma[s];
	dis[t] = 0;	q[head] = t; tail++;
	while (head < tail){
		e = q[head++]; p = h[e];
		while (p){
			if (dis[v[p]] > dis[e] + w[p]){
				dis[v[p]] = dis[e] + w[p]; q[tail++] = v[p];
			}
			p = nex[p];
		}
	}
	int ans1 = dis[x] > dis[y];
	ans1++;
	int ans2 = dis[x] - dis[y];
	ans2 = ans2 > 0 ? ans2 : -ans2;
	printf("%d %d", ans1, ans2);
	return 0;
}
