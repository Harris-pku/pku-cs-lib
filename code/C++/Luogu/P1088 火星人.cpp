#include <cstdio>
#include <algorithm>

using namespace std;

int a[10005], n, m;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while (m--)
		next_permutation(a, a + n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
