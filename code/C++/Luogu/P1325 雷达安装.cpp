#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

struct node{
    double x, y, a, b;
    bool operator < (const node & t) const{
        if (b == t.b) return a < t.a;
        return b < t.b;
    }
    void cal(double r){
        a = x - sqrt(r*r - y*y);
        b = x + sqrt(r*r - y*y);
    }
} h[1005];

double xx, yy;
int n, r, tot, sum = 1, cur = 1, flag;

int main(){
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++){
        cin >> h[i].x >> h[i].y;
        if (h[i].y > r){
            printf("-1\n");
            return 0;
        }
        h[i].cal(r);
    }
    sort(h+1, h+n+1);
    for (int i = 2; i <= n; i++){
        if (h[i].a <= h[cur].b) continue;
            sum++;
            cur = i;
    }
    printf("%d\n", sum);
    return 0;
}