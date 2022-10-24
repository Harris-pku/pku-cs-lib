#include <cstdio>

using namespace std;

int n, t, ans;
int main(){
	scanf("%d%d", &n, &ans);
	for (int i = 2; i <= n; i++){
		scanf("%d", &t); ans ^= t;
	}
	printf("%d", ans);
	return 0;
}
