#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, cur;
double d[10], pi[10], d1, c, d2, p, pmin = 1000, gas, ans, d0;
int main(){
    cin >> d1 >> c >> d2 >> p >> n;
    double x = c*d2; pi[0] = p;
    for (int i = 1; i <= n; ++i){
        cin >> d[i] >> pi[i];
    }
    for (int i = 1; i <= n; ++i){
        if (d[i]-d[i-1] > x){
            cout << "No Solution"; return 0;
        }
    }
    while(d1 - d0){
        for(int i = cur+1; d[i]-d0 <= x && i <= n; ++i){
            if (pi[i] < pmin){
                pmin = pi[i]; cur = i;
            }
        }
        if (pmin <= p){
            ans += ((d[cur]-d0) / d2 - gas) * p;
            gas = (d[cur]-d0) / d2;
        } 
        else if(d1-d0 > x){
            ans += (c-gas) * p;
            gas = c;
        }
        else{
            ans += ((d1-d0)/d2-gas) * p; break; 
        }
        gas = gas - (d[cur]-d0) / d2; 
        d0 = d[cur]; p = pmin; pmin = 1000; 
    }
    printf("%.2lf", ans);
    return 0; 
}
