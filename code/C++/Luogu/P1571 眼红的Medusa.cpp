#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int a[200005], c[100005], v[100005], n, m;
int main(){
	map<int, int> f;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		c[i] = a[i]; f[a[i]] = i;
	}
	for (int i = n + 1; i <= n + m; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+m+1);
	for (int i = 1; i <= n + m; i++)
		if (a[i] == a[i + 1]){
			v[f[a[i]]] = 1; i++;
		}
	for (int i = 1; i <= n; i++)
		if (v[i])
			printf("%d ", c[i]);
	return 0;
}
