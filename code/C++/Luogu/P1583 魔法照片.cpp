#include <cstdio>
#include <algorithm>

using namespace std;

struct pe{
	int worth, hao;
} w[20005];
int n, k, c[15];
int compare(const pe &x, const pe &y){
	if (x.worth != y.worth)
		return x.worth > y.worth;
	else
		return x.hao < y.hao;
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= 10; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++){
		scanf("%d", &w[i].worth);
		w[i].hao = i;
	}
	sort(w+1, w+n+1, compare);
	for (int i = 1; i <= n; i++)
		w[i].worth += c[(i-1) % 10 + 1];
	sort(w+1, w+n+1, compare);
	for (int i = 1; i <= k; i++)
		printf("%d ", w[i].hao);
	return 0;
}
