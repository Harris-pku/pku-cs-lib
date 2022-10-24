#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

queue<int> q; int n, x, cur;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &x);
        if (x == 1){
            scanf("%d", &cur);
            q.push(cur);
        }
        else{
            cur = q.front();
            printf("%d\n", cur);
            q.pop();
        }
    }
    printf("size = %d\n", q.size());
}
