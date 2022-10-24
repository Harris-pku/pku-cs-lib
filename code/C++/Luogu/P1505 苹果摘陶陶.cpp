#include <cstdio>
#include <algorithm>

using namespace std;

int app[2005], tao[2005], n, m, ans;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &app[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &tao[i]);
	sort(app + 1, app + n + 1);
	sort(tao + 1, tao + m + 1);
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			if (app[i] > tao[j] && tao[j]){
				ans++; tao[j] = 305; break;
			}
	printf("%d", m-ans);
	return 0;
}
