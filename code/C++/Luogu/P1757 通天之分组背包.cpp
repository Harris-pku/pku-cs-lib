#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int f[1010], v[105][10010], w[105][10010], a[105];
int m, n, t, x, y, z;
int main(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d%d", &x, &y, &z);
        t = max(t, z); a[z]++;
        v[z][a[z]] = x; w[z][a[z]] = y;
    }
    for(int k = 1; k <= t; k++)
        for(int j = m; j >= 0; j--)
	        for(int i = 1; i <= a[k]; i++)
                if(j >= v[k][i]) 
                    f[j] = max(f[j], f[j-v[k][i]] + w[k][i]);
    printf("%d\n", f[m]);
    return 0;
}
