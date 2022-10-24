#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int a[1005][1005], hang[1005], lie[1005], n, ans, flag = 1;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            scanf("%d", &a[i][j]);
            hang[i] += a[i][j]; lie[j] += a[i][j];
            if (!a[i][j]) flag = 0;
        }
    for (int i = 1; i <= n; ++i){
    	for (int j = 1; j <= n; ++j){
    		if (!a[i][j]){
    			ans = max(ans, hang[i] + lie[j]);
    		}
    	}
    }
    if (!flag){
    	printf("%d", ans);
    }
    else printf("Bad Game!");
    return 0;
}
