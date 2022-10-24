#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, cur, sum;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &cur);
        sum += cur;
    }
    if (sum & 1) printf("Alice");
    else printf("Bob");
    return 0;
}