#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const double eps = 1e-6;
double l, r = 2.0, mid;
double f(double x){
    return x * x - 2;
}
int main(){
    while ((r - l) > eps){
        mid = (l + r) / 2;
        if (fabs(f(mid)) < eps)
            break;
        if (f(l) * f(mid) < 0) r = mid;
        else l = mid;
        cout << l << " " << r << " " << mid << endl;
    }
    cout << mid;
    return 0;
}
