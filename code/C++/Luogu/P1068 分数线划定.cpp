/*  Coder: Harris
    Time: 2015.9.5
    Website: https://www.luogu.com.cn/problem/P1068
    Algorithm: simulation
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

struct student{
    int num, score;
    void scanf_info(){
        scanf("%d%d", &num, &score);
    }
    bool operator < (const student & x) const {
        if (score == x.score){
            return num < x.num;
        }
        return score > x.score;
    }
} a[5005];

int n, m;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        a[i].scanf_info();
    }
    sort(a+1, a+n+1);
    m = floor(1.5 * m);
    while (m < n){
        if (a[m].score == a[m+1].score) m++;
        else break;
    }
    printf("%d %d\n", a[m].score, m);
    for (int i = 1; i <= m; i++){
        printf("%d %d\n", a[i].num, a[i].score);
    }
    return 0;
}
/*
input:
6 3 
1000 90 
3239 88 
2390 95 
7231 84 
1005 95 
1001 88

output:
88 5 
1005 95 
2390 95 
1000 90 
1001 88 
3239 88 
*/