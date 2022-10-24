#include <cstdio>
#include <algorithm>

using namespace std;

struct shu{
	int fen, hao, force;
} a[200005], b[200005], c[200005];
int n, r, q;
bool compare(const shu &x, const shu &y){
	if (x.fen != y.fen)
		return x.fen > y.fen;
	else
		return x.hao < y.hao;
}
int main(){
	scanf("%d%d%d", &n, &r, &q);
	for (int i = 0; i < n * 2; i++){
		scanf("%d", &a[i].fen);
		a[i].hao = i;
	}
	for (int i = 0; i < n * 2; i++)
		scanf("%d", &a[i].force);
	sort(a, a + n*2, compare);
	while (r--){
		for (int i = 0, m = 0; i < n * 2; i += 2, m++)
			if (a[i].force > a[i + 1].force){
				a[i].fen++; b[m] = a[i];
				c[m] = a[i + 1];
			}
			else{
				a[i + 1].fen++;
				b[m] = a[i + 1];
				c[m] = a[i];
			}
		merge(b, b+n, c, c+n, a, compare);
	}
	printf("%d", a[q-1].hao + 1);
	return 0;
}
