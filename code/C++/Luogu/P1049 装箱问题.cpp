#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int f[20005] = {1}, n, m, cur;
int main(){
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &cur);
		for (int j = m; j >= cur; j--){
			f[j] |= f[j - cur];
		}
	}
	for (int i = m; i >= 0; i--){
		if (f[i]){
			printf("%d\n", m - i); break;
		}
	}
	return 0;
}
