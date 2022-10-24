#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int h[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, m, cur, ans;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 12; ++i)
        for (int j = 1; j <= h[i]; ++j){
            cur = (j%10)*1000 + (j/10)*100 + (i%10)*10 + (i/10);
            cur = cur*10000 + i*100 + j;
            if (cur>=n && cur<=m) ans++;
        }
    printf("%d", ans);
    return 0;
}
