#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

int fa[105], le[105], ri[105], n, cur, x, y;
void xianxu(int x){
    printf("%d ", x);
    if (le[x]) xianxu(le[x]);
    if (ri[x]) xianxu(ri[x]);
}
void zhongxu(int x){
    if (le[x]) zhongxu(le[x]);
    printf("%d ", x);
    if (ri[x]) zhongxu(ri[x]);
}
void houxu(int x){
    if (le[x]) houxu(le[x]);
    if (ri[x]) houxu(ri[x]);
    printf("%d ", x);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d%d", &cur, &x, &y);
        le[cur] = x; ri[cur] = y;
    }
    xianxu(1); printf("\n");
    zhongxu(1); printf("\n");
    houxu(1); printf("\n");
    return 0;
}