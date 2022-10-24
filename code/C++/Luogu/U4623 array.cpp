#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> f;
int a[100005], n, ans;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if (!f[a[i]]){
			ans++;
		}
		f[a[i]] = 1;
	}
	printf("%d", ans);
	return 0;
}
