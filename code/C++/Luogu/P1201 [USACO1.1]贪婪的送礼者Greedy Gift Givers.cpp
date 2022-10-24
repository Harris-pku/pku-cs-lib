#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

string name[15], s; int n, money, m, num;
map<string, int> cnt;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        cin >> name[i];
    for (int i = 1; i <= n; ++i){
        cin >> s >> money >> m;
        if (m) num = money / m;
        else num = 0;
        cnt[s] -= num * m;
        for (int j = 1; j <= m; ++j){
            cin >> s; cnt[s] += num;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << name[i] << " " << cnt[name[i]] << endl;
    return 0;
}