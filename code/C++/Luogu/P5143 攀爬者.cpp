/*  Coder: Harris
    Time: 2020.7.3
    Website: https://www.luogu.com.cn/problem/P5143
    Algorithm: simulation
*/
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

struct point{
    int x, y, z;
    bool operator < (const point & t) const{
        return z < t.z;
    }
} a[50005];

inline double dis(int i, int j){
    double ans = 0;
    ans = sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)
             + (a[i].y-a[j].y)*(a[i].y-a[j].y)
             + (a[i].z-a[j].z)*(a[i].z-a[j].z));
    return ans;
}

int n; double ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    }
    sort(a+1, a+n+1);
    for (int i = 2; i <= n; i++){
        ans += dis(i-1, i);
    }
    printf("%.3f", ans);
    return 0;
}
/*
input:
5
2 2 2
1 1 1
4 4 4
3 3 3
5 5 5

output:
6.928
*/