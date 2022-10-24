/*  Coder: Harris
    Time: 2020.5.3
    Website: https://www.luogu.com.cn/problem/P5742
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct student{
    int num, score1, score2;
    double score;
    void scanf_infor(){
        cin >> num >> score1 >> score2;
        score = 0.7*score1 + 0.3*score2;
    }
    bool is_excellent(){
        if ((score1+score2)>140 && score>=80) return true;
        return false;
    }
}a[1005];

int n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        a[i].scanf_infor();
    }
    for (int i = 1; i <= n; i++){
        if (a[i].is_excellent())
            printf("Excellent\n");
        else printf("Not excellent\n");
    }
    return 0;
}
/*
input:
4
1223 95 59
1224 50 7
1473 32 45
1556 86 99

output:
Excellent
Not excellent
Not excellent
Excellent
*/