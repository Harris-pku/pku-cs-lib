#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int n, c, a[200010]; long long ans;
map<int, int> p;
int main(){
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        p[a[i]]++;
    }
    for (int i = 1; i <= n; i++){
        ans += p[a[i] + c];
    }
    cout << ans;
    return 0;
}
