#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

map<string, string> fa;
inline string found(string s){
    if (fa[s] == s) return s;
    return fa[s] = found(fa[s]);
}
string s, s1, s2; int n, m, k;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        cin >> s; fa[s] = s;
    }
    for (int i = 1; i <= m; ++i){
        cin >> s1 >> s2;
        string fx = found(s1), fy = found(s2);
        fa[fx] = fy;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i){
        cin >> s1 >> s2;
        string fx = found(s1), fy = found(s2);
        if (fx == fy) printf("Yes.\n");
        else printf("No.\n");
    }
    return 0;
}