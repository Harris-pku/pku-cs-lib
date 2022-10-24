#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

int n, cur, k, tot;
set<int> s;
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &cur);
        s.insert(cur);
    }
    if (s.size() < k){
        printf("NO RESULT"); return 0;
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it){
        if (++tot == k){
            printf("%d", *it); break;
        }
    }
    return 0;
}