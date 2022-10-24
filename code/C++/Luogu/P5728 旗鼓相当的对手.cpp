/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5728
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct student{
    int chi, math, eng, sum;
} a[1005];

int n, ans;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d%d", &a[i].chi, &a[i].math, &a[i].eng);
        a[i].sum = a[i].chi + a[i].math + a[i].eng;
    }
    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
            int flag = 1;
            if (abs(a[i].chi - a[j].chi) > 5) flag = 0;
            if (abs(a[i].math-a[j].math) > 5) flag = 0;
            if (abs(a[i].eng - a[j].eng) > 5) flag = 0;
            if (abs(a[i].sum - a[j].sum) > 10) flag = 0;
            if (flag) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
/*
input:
3
90 90 90
85 95 90
80 100 91

output:
2
*/