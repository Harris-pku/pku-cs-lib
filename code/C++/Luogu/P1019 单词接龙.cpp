#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char s[25][25];
int n, maxl, visit[25];
bool check(int i, int j, int k){
	for (int m = 0; m < strlen(s[i]) - j; m++)
		if (s[k][m] != s[i][j + m] || m >= strlen(s[k]) - 1)
			return 0;
	return 1;
}
void dfs(int i, int j, int l){
	maxl = max(maxl, l);
	for (int k = 1; k <= n; k++){
		if (visit[k] < 2 && check(i, j, k)){
			visit[k]++;
			for (int m = 1; m < strlen(s[k]); m++)
				dfs(k, m, l + strlen(s[k]) - strlen(s[i]) + j);
			visit[k]--;
		}
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	cin >> s[0][0];
	dfs(0, 0, 1);
	cout << maxl;
	return 0;
}
