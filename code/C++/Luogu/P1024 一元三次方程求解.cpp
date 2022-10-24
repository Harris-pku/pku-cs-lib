#include <algorithm>
#include <cstring>
#include <cmath> 
#include <cstdio>
#include <iostream>

using namespace std;

const double eps = 1e-6;
double a, b, c, d, x1, x2, xx, l, r, mid; int ans;
double f(double x){
    return a*x*x*x + b*x*x + c*x + d;
}
int main(){
    cin >> a >> b >> c >> d;
    for (int i = -100; i < 100; ++i){
    	l = i; r = i + 1 - 1e-8;
        x1 = f(l); x2 = f(r);
        if (fabs(x1) < eps){
            printf("%.2f ", l); ans++; continue;
        }
        if (x1 * x2 < 0){
            while ((r - l) > eps){
                mid = (l + r) / 2; xx = f(mid);
                if (fabs(xx) < eps){
                    break;
                }
                if (f(l) * f(mid) < 0) r = mid;
                else l = mid;
            }
            printf("%.2f ", mid); ans++;
        }
        if (ans == 3) break;
    }
    return 0;
}
