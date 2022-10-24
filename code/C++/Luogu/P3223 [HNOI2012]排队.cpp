#include <cstdio>
#include <algorithm>

using namespace std;

long long buf[1010], f[20];
int n, m, len(1);
const long long p = 1e15;
void multiply(long long x){
	long long t(0), rec;
	for (int i = 1; i <= len; i++){
		rec = buf[i] * x;
		buf[i] = rec % p + t;
		t = rec / p;
	}
	if (t){
		buf[++len] = t;
	}
}
int main(){
	buf[1] = 1;
	scanf("%d%d", &n, &m);
	multiply(n*n + 3*n + 2*m);
	for (int i = 2; i <= n+1; i++)
		multiply(i);
	for (int i = n-m+4; i <= n+2; i++)
		multiply(i);
	printf("%lld", buf[len]);
	while (--len){
		printf("%015lld", buf[len]);
	}
	return 0;
}
