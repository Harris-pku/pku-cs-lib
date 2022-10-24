#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

set<string> se, see; string s; char ch;
int n, len, ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        cin >> s; len = s.length();
        for (int i = 0; i < len; ++i)
            if (isalpha(s[i])) s[i] = tolower(s[i]);
        se.insert(s);
    }
    ch = getchar(); s.clear();
    while (scanf("%c", &ch) == 1){
        if (ch == '\n') break;
        if (isalpha(ch)){
            ch = tolower(ch); s += ch;
        }
        else{
            if (!s.empty()){
                if (se.count(s)) see.insert(s); s.clear();
            }
            if (ch == '.'){
                ans += see.size(); see.clear();
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}