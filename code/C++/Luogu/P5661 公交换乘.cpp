#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct tic{
    int p, t;
}q[100005];
int n, x, y, z, head, tail, ans, flag;
int main(){
    scanf("%d", &n);
    for (int k = 0; k < n; ++k){
        scanf("%d%d%d", &z, &x, &y);
        if (!z){
            q[tail].p = x; q[tail++].t = y; ans += x;
        }
        else{
            int flag = 0;
            for (int i = head; i < tail; ++i){
                if (y-q[i].t<=45 && x<=q[i].p){
                    q[i].p = -1; flag = 1; break;
                }
                else if (y-q[i].t>45){
                    head = i+1;
                }
            }
            if (!flag) ans += x;
        }
    }
    printf("%d", ans);
    return 0;
}