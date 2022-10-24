#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 30005;
int p[maxn], value[maxn], num[maxn];
int findset(int x, int &pson){
    if (p[x] == x){
        pson = x;
        return 0;
    }
    else{
        value[x] += findset(p[x], p[x]);
        pson = p[x];
        return value[x];
    }
}
void change(int x, int y){
    int fx, fy;
    findset(x, fx);
    findset(y, fy);
    p[fx] = fy;
    value[fx] = num[fy];
    num[fy] += num[fx];
    num[fx] = 0;
    return;
}
void ask(int x, int y){
    int fx, fy;
    findset(x, fx);
    findset(y, fy);
    if (fx != fy)
        printf("-1\n");
    else
        printf("%d\n", abs(value[x] - value[y]) - 1);
    return;
}

int main(){
    int T, x, y;
    char ins[10];
    scanf("%d", &T);
    for (int i = 1; i <= maxn - 10; i++)
        p[i] = i, num[i] = 1;
    while (T--){
        scanf("%s%d%d", ins, &x, &y);
        if (ins[0] == 'M')
            change(x, y);
        else
            ask(x, y);
    }
    return 0;
}
