/*  Coder: Harris
    Time: 2020.5.2
    Website: https://www.luogu.com.cn/problem/P5744
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct student{
    string s;
    int age, grade;
    void scanf_infor(){
        cin >> s >> age >> grade;
    }
    void improve(){
    	age++;
        grade += grade / 5;
        if (grade > 600) grade = 600;
    }
    void print_infor(){
        cout << s << " " << age << " " << grade << endl;
    }
}a[1005];

int n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        a[i].scanf_infor();
        a[i].improve();
        a[i].print_infor();
    }
    return 0;
}
/*
input:
3
kkksc03 24 0
chen_zhe 14 400
nzhtl1477 18 590

output:
kkksc03 25 0
chen_zhe 15 480
nzhtl1477 19 600
*/