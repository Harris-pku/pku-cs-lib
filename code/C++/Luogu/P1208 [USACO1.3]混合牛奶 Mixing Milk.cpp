/*  Coder: Harris
    Time: 2015.10.31
    Website: https://www.luogu.com.cn/problem/P1478
    Algorithm: greedy algorithm
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Cow{
    int price, num;
    bool operator < (const Cow & x) const{
        return price < x.price;
    }
}cow[2000005];
int n, m, ans;
int main(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &cow[i].price, &cow[i].num);
    sort(cow+1, cow+n+1);
    for (int i = 1; i <= n; ++i){
        if (cow[i].num <= m){
            m -= cow[i].num; ans += cow[i].price * cow[i].num;
        }
        else{
            ans += m * cow[i].price; break;
        }
    }
    printf("%d", ans);
    return 0;
}
/*
input:
100 5
5 20
9 40
3 10
8 80
6 30

output:
630
*/