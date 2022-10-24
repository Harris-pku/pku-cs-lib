/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P1205
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
struct Matrix{
    char a[15][15];
    void in(){
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
    }
    Matrix rotate(){
        Matrix ans;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                ans.a[i][j] = a[n-j-1][i];
            }
        }
        return ans;
    }
    Matrix reflex(){
        Matrix ans;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                ans.a[i][j] = a[i][n-j-1];
            }
        }
        return ans;
    }
    bool operator == (const Matrix & b) const {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (a[i][j] != b.a[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
} from, to, mid;

int main(){
    scanf("%d", &n);
    from.in(); to.in(); mid = from;
    for (int i = 1; i <= 3; i++){
        mid = mid.rotate();
        if (mid == to){
            printf("%d\n", i); return 0;
        }
    }
    mid = from.reflex();
    if (mid == to){
        printf("4\n"); return 0;
    }
    for (int i = 1; i <= 3; i++){
        mid = mid.rotate();
        if (mid == to){
            printf("5\n"); return 0;
        }
    }
    if (from == to){
        printf("6\n"); return 0;
    }
    printf("7\n");
    return 0;
}
/*
input:
3
@-@
---
@@-
@-@
@--
--@

output:
1
*/