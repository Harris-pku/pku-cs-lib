#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int sum[1000005], vis[1000005];
void shai(int n){
    sum[1] = 0; vis[1] = 1;
    for (int i = 2; i <= n; ++i){
        if (!vis[i]){
            sum[i] = sum[i-1] + 1;
            for (int j = 2*i; j <= n; j +=i)
                vis[j] = 1;
        }
        else sum[i] = sum[i-1];
    }
}
int n, m, x, y;
int main(){
    scanf("%d%d", &n, &m);
    shai(m);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d", &x, &y);
        if (x<1 || y>m) cout << "Crossing the line" << endl;
        else{
            cout << sum[y] - sum[x-1] << endl;
        }
    }
    return 0;
}
