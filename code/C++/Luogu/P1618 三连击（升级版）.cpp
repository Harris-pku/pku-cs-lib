#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int f[15], tot, x, y, z, flag;
void solve(int x){
	f[x/100] = f[x/10%10] = f[x%10] = 1;
}
int main(){
	scanf("%d%d%d", &x, &y, &z);
	for (int i = 1; i <= 999 / z; i++){
		memset(f, 0, sizeof(f));
		tot = 0;
		solve(i*x); solve(i*y);	solve(i*z);
		for (int j = 1; j <= 9; j++){
			if (f[j]){
				tot++;
			}
		}
		if (tot == 9){
			printf("%d %d %d\n", i * x, i * y, i * z);
			flag = 1;
		}
	}
	if (!flag)
		printf("No!!!");
	return 0;
}
