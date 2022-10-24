#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int n, m, bef, cur, cnt;
map<int, int> ma;
int main(){
    scanf("%d%d%d", &n, &m, &bef);
    ma[bef] = ++cnt;
    for (int i = 2; i <= n; i++){
        scanf("%d", &cur);
        if (bef == cur) continue;
        ma[cur] = ++cnt;
        bef = cur;
    }
    for (int i = 1; i <= m; i++){
        scanf("%d", &cur);
        map<int, int>::iterator it = ma.find(cur);
        if (it != ma.end()){
            printf("%d ", ma[cur]);
        }
        else printf("-1 ");
    }
    return 0;
}