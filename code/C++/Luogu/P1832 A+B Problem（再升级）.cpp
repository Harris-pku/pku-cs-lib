#include <cstdio>
#include <cmath>

using namespace std;

long long f[1001] = {1}; int n;
bool prime(int m){
	if (m > 3)
		for (int i = sqrt(m); i >= 2; i--)
			if (!(m % i))
				return 0;
	return 1;
}
int main(){
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		if (prime(i))
			for (int j = i; j <= n; j++)
				f[j] += f[j - i];
	printf("%lld", f[n]);
	return 0;
}
