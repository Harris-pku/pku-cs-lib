#include <iostream>
#include <algorithm>

using namespace std;

int a[15], visit[15], pt[15], n, sum;
void dfs(int x, int tot){
	if (x == n && tot == sum){
		for (int i = 0; i < n; i++)
			cout << pt[i] << " ";
		exit(0);
	}
	if (tot >= sum)
		return;
	for (int i = 1; i <= n; i++){
		if (visit[i]){
			visit[i] = 0;
			pt[x] = i;
			dfs(x + 1, tot + i * a[x]);
			visit[i] = 1;
		}
	}
}
int main(){
	cin >> n >> sum;
	for (int i = 0; i < n; i++){
		a[i] = visit[i + 1] = 1;
		for (int j = i / 2; j > 0; j--)
			a[j] = a[i - j] = a[j] + a[j - 1];
	}
	dfs(0, 0);
	return 0;
}
