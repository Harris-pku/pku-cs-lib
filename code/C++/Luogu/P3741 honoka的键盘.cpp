/*  Coder: Harris
    Time: 2020.7.19
    Website: https://www.luogu.com.cn/problem/P3741
    Algorithm: simulation
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[105], vk[5] = "VK"; int n, ans;
int cal(){
    int x = 0, tot = 0;
    while (strstr(s+x, vk) != NULL){
        x = strstr(s+x, vk) - s + 1; tot++;
    }
    return tot;
}
int main(){
    scanf("%d%s", &n, s);
    ans = cal();
    for (int i = 0; i < n; i++){
    	char c = s[i];
        s[i] = 'V'; ans = max(ans, cal());
        s[i] = 'K'; ans = max(ans, cal());
        s[i] = c;
    }
    printf("%d", ans);
    return 0;
}
/*
input:
20
VKKKKKKKKKVVVVVVVVVK

output:
3
*/