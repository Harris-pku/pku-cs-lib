/*  Coder: Harris
    Time: 2020.6.28
    Website: https://www.luogu.com.cn/problem/P5741
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct student{
    string name;
    int chi, math, eng, sum;
} a[1005];

int n;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        cin >> a[i].name;
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
            if (flag){
                cout << a[i].name << " " << a[j].name << endl;
            }
        }
    }
    return 0;
}
/*
input:
3
fafa 90 90 90
lxl 95 85 90
senpai 100 80 91

output:
fafa lxl
lxl senpai
*/