#include <cstdio>
#include <algorithm>

using namespace std;

struct shu{
	int jia, num;
} a[505];
int k, m, n, t, c, ans;
int compare(shu x, shu y){
	return x.jia < y.jia;
}
int main(){
	scanf("%d%d%d", &k, &m, &n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d%d", &t, &a[i].num, &c);
		a[i].jia = (m-t) + c;
	}
	sort(a + 1, a + n + 1, compare);
	for (int i = 1; i <= n; i++){
		ans += min(k, a[i].num) * a[i].jia;
		k -= a[i].num;
		if (k <= 0){
			break;
		}
	}
	printf("%d", ans);
	return 0;
}
