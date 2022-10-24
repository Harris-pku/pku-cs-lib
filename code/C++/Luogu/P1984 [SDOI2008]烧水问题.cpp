#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	double ans = 420000.00 / n, tot = ans;
	for (int i = 1; i < n; i++){
		tot *= (double)(2*i - 1) / (double)(2*i);
		ans += tot;
	}
	printf("%.2lf", ans);
	return 0;
}
