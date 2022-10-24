#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

stack<int> s; int n, x, cur;
int main(){
    scanf("%d", &n);
    for (int i  = 1; i <= n; ++i){
        scanf("%d", &x);
        if (x == 1){
            scanf("%d", &cur);
            s.push(cur);
        }
        else{
            cur = s.top();
            printf("%d ", cur);
            s.pop();
        }
    }
    printf("size = %d\n", s.size());
}
