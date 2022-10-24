/*  Coder: Harris
    Time: 2020.7.3
    Website: https://www.luogu.com.cn/problem/P2433
    Algorithm: simulation
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

double pi = 3.141593;
int T;
int main(){
    scanf("%d", &T);
    switch (T){
        case  1: printf("I love Luogu!"); break;
        case  2: printf("6 4"); break;
        case  3: printf("3\n12\n2"); break;
        case  4: printf("%.3f", 500.0 / 3); break;
        case  5: printf("%d", 480 / 32); break;
        case  6: cout << sqrt(36 + 81); break;
        case  7: printf("110\n90\n0"); break;
        case  8: cout << 10 * pi << endl << 25 * pi << endl << 500 * pi / 3; break;
        case  9: printf("22"); break;
        case 10: printf("9"); break;
        case 11: cout << 100.0 / 3; break;
        case 12: printf("13\nR"); break;
        case 13: printf("%d", (int)(pow(4*pi*1064/3, 1.0/3))); break;
        case 14: printf("50"); break;
    }
    return 0;
}