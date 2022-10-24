#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int p = 1e9 + 7;
int bk[5005], n, cur, ans, maxx;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &cur);
        bk[cur]++; maxx = max(maxx, cur);
    }
    for (int i = 1; i <= maxx; ++i){
        for (int j = i; j <= min(maxx, 5000 - i); j++){
            if (i == j){
                if (bk[i] >= 2 && bk[i << 1] >= 2)
                    ans = (ans + (bk[i] * (bk[i]-1) / 2LL % p * (bk[i<<1] * (bk[i<<1]-1) / 2) % p)) % p;
            }
            else{
                if (bk[i] >= 1 && bk[j] >= 1 && bk[i+j] >= 2)
                    ans = (ans + (bk[i] * bk[j] % p * (bk[i+j] * (bk[i+j]-1) / 2) % p)) % p;
            }
        }
    }
    cout << ans;
    return 0;
}