#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[3005][3005], fa[3005], n, m;
inline int found(int x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
int main(){
    scanf("%d%d", &n, &m);
    
}