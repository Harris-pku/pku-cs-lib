/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5716
    Algorithm: simulation
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int y, m;
int main(){
	cin >> y >> m;
    switch (m){
        case  1: cout << 31; break;
        case  2: if ((y%4==0 && y%100!=0) || y%400==0) cout << 29;
	             else cout << 28;
                 break;
        case  3: cout << 31; break;
        case  4: cout << 30; break;
        case  5: cout << 31; break;
        case  6: cout << 30; break;
        case  7: cout << 31; break;
        case  8: cout << 31; break;
        case  9: cout << 30; break;
        case 10: cout << 31; break;
        case 11: cout << 30; break;
        case 12: cout << 31; break;
    }
	return 0;
}
/*
input:
2000 2

output:
29
*/