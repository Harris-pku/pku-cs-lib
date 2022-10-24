#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
bool prime(int x){
	if (x == 1) return 0;
	for (int i = 2; i*i <= x; ++i)
        if(x%i == 0) return 0;
    return 1;
}
void dfs(int x, int cur){
    if (x == n+1) printf("%d\n", cur);
	for (int i = 1; i <= 9; ++i)
        if(prime(cur*10 + i))
            dfs(x+1, cur*10 + i);
}
int main(){
	scanf("%d", &n);
    dfs(1, 0);
    return 0;
}
