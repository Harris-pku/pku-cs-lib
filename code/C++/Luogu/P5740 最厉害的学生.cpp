/*  Coder: Harris
    Time: 2020.5.3
    Website: https://www.luogu.com.cn/problem/P5740
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct student{
    char name[10];
    int chi, math, eng, sum;
    void scanf_infor(){
        cin >> name >> chi >> math >> eng;
        sum = chi + math + eng;
    }
    void print_infor(){
        cout << name << " ";
        printf("%d %d %d\n", chi, math, eng);
    }
}a[1005];
int n, maxn, x = 1; // maxn 是当前总分最高值，x 为总分最高的选手的编号
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        a[i].scanf_infor();
        if (a[i].sum > maxn){
            x = i; maxn = a[i].sum;
        }
    }
    a[x].print_infor();
    return 0;
}
/*
input:
3
senpai 114 51 4
lxl 114 10 23
fafa 51 42 60

output:
senpai 114 51 4
*/