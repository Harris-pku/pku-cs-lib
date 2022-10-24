#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 10000005;
int n, m, x, tot; bool flag[maxn];

void Eratosthenes(int n){
	memset(flag, 1, sizeof(flag));
	flag[0] = flag[1] = 0;
	for (int i = 2; i <= n; ++i){
		if (flag[i]){
            for (int j = 2*i; j <= n; j += i)
                flag[j] = 0;
        }
	}
}

int main(){
	scanf("%d%d", &n, &m);
	Eratosthenes(n);
	for (int i = 1; i <= m; ++i){
		scanf("%d", &x);
	 	printf(flag[x] ? "Yes\n" : "No\n");
	}
	return 0;
}
