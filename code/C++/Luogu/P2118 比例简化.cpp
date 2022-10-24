#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

double a, b, c, d, l, sth, lower = 10000000;
int main(){
    cin >> a >> b >> l;  
    sth = a / b;
    for (double i = 1; i <= l; ++i) 
        for (double j = 1; j <= l; ++j)  
            if (i/j>=sth && i/j<lower-0.000000001){
                c = i; d = j; lower = i / j;
            }    
    cout << c << ' ' << d;
    return 0;  
}  
