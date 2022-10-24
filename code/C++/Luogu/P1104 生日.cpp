/*  Coder: Harris
    Time: 2016.8.16
    Website: https://www.luogu.com.cn/problem/P1104
    Algorithm: simulation
*/
#include <iostream>    
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;    

struct ti{
    string name;
    long long sum;
    bool operator < (const ti & x) const{
        return sum < x.sum;
    }
}a[10001];

int n, x, y, z;
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].name >> x >> y >> z;
	    a[i].sum = x*10000000 + y*100000 + z*1000 + 100 - i;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++){
        cout << a[i].name << endl;
    }
    return 0;
}
/*
input:
3
Yangchu 1992 4 23
Qiujingya 1993 10 13
Luowen 1991 8 1

output:
Luowen
Yangchu
Qiujingya
*/