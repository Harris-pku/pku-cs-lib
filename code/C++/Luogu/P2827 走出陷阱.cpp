#include <cstdio>
#include <algorithm>

using namespace std;

int l, r, x;
int sum(int n){
	int m, ans = 0;
	while (n){
		m = n % 10; n /= 10;
		ans += m;
	}
	return ans;
}
int main(){
	scanf("%d%d%d", &l, &r, &x);
	for (int i = l; i <= r; i++)
		if (sum(i) == x){
			printf("%d\n", i); break;
		}
	for (int i = r; i >= l; i--)
		if (sum(i) == x){
			printf("%d\n", i);
			break;
		}
	return 0;
}
