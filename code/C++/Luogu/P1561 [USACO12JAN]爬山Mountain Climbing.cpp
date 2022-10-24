#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int inf = 0x3f3f3f3f;
int n, x, y, sumx, sumy, minx = inf, miny = inf;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d", &x, &y);
        sumx += x; sumy += y;
        minx = min(minx, x); miny = min(miny, y);
    }
    printf("%d\n", max(sumx+miny, minx+sumy));
    return 0;
}
