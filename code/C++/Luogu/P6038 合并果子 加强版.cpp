/*  Coder: Harris
    Time: 2020.2.3
    Website: https://www.luogu.com.cn/problem/P6038
    Algorithm: Mergesort
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

queue<long long> q1, q2;
int a[100005], n; long long ans, x, y;
int read(){
    int f = 1, x = 0; char s = getchar();
    while (s<'0' || s>'9'){
        if (s == '-') f = -1;
        s = getchar();
    }
    while (s>='0' && s<='9'){
        x = x*10 + s - '0';
        s = getchar();
    }
    return f * x;
}
int main(){
    n = read();
    for (int i = 1; i <= n; i++){
        x = read(); a[x]++;
    }
    for (int i = 1; i <= 100000; i++){
        while (a[i]){
            a[i]--;
            q1.push(i);
        }
    }
    for (int i = 1; i < n; i++){
        if ((q1.front()<q2.front() && (!q1.empty())) || q2.empty()){
            x = q1.front(); q1.pop();
        }
        else{
            x = q2.front(); q2.pop();
        }
        if ((q1.front()<q2.front() && (!q1.empty())) || q2.empty()){
            y = q1.front(); q1.pop();
        }
        else{
            y = q2.front(); q2.pop();
        }
        ans += x + y;
        q2.push(x + y);
    }
    printf("%lld", ans);
    return 0;
}
/*
input:
3 
1 2 9 

output:
15
*/