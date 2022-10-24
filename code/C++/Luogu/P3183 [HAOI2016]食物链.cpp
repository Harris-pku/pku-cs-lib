#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> to[100005];
int q[1000005], ru[100005], chu[100005], num[100005], head, tail, n, m, x, y, ans;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d%d", &x, &y); to[x].push_back(y); ru[y]++; chu[x]++;
    }
    for (int i = 1; i <= n; ++i)
        if (!ru[i] && chu[i]){
            q[tail++] = i; num[i] = 1;
        }
    while (head < tail){
        x = q[head++];
        for (int i = 0; i < to[x].size(); ++i){
            if (--ru[to[x][i]] == 0)
                q[tail++] = to[x][i];
            num[to[x][i]] += num[x];
        }
        if (!to[x].size()) ans += num[x];
    }
    printf("%d", ans);
    return 0;
}
