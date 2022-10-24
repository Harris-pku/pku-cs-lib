#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int mu[50010], d[50010], cnt[50010], prime[50010], tot;
bool not_prime[50010];
int n, m, T;
void Linear_Shaker(){
    mu[1] = d[1] = 1;
    for (int i = 2; i <= 50000; i++){
        if (!not_prime[i]){
            prime[++tot] = i; mu[i] = -1;
            d[i] = 2; cnt[i] = 1;
        }
        for (int j = 1; prime[j] * i <= 50000; j++){
            not_prime[prime[j] * i] = true;
            if (i%prime[j] == 0){
                mu[prime[j] * i] = 0;
                d[prime[j] * i] = d[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[prime[j] * i] = cnt[i] + 1;
                break;
            }
            mu[prime[j] * i] = -mu[i];
            d[prime[j] * i] = d[i] << 1;
            cnt[prime[j] * i] = 1;
        }
    }
    for (int i = 1; i <= 50000; i++){
        mu[i] += mu[i - 1];
        d[i] += d[i - 1];
    }
}

long long Solve(){
    long long re = 0;
    int last;
    if (n > m)
        swap(n, m);
    for (int i = 1; i <= n; i = last+1){
        last = min(n/(n/i), m/(m/i));
        re += (long long)(mu[last] - mu[i-1]) * d[n/i] * d[m/i];
    }
    return re;
}

int main(){
    Linear_Shaker();
    for (cin >> T; T; T--){
        scanf("%d%d", &n, &m);
        printf("%lld\n", Solve());
    }
    return 0;
}
