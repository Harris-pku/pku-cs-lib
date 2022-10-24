#include <cstdio>

using namespace std;

const int maxn = 10005;
long long catalan[maxn]; int n;
int main(){
	catalan[0] = catalan[1] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		for (int k = 0; k < i; k++){
			catalan[i] = ((catalan[k] * catalan[i - k - 1]) % 100000007 + catalan[i]) % 100000007;
		}
	printf("%lld", catalan[n]);
	return 0;
}
