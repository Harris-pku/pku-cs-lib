#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000005];
int you, wu, tyou, twu, k, n, b, c, maxn, minn=1000000;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d%d", &b, &c);
	 	++a[b]; --a[c];
	 	if (c-1 > maxn) maxn = c-1;
	 	if (b<minn) minn = b;
	}
    for (int i = minn; i <= maxn; ++i){
		k += a[i];
     	if (k){
		 	++tyou; twu = 0;
			 if (tyou > you) you = tyou;
		}
     	else{
			++twu; tyou = 0;
			if (twu > wu) wu = twu;
		}
    }
    printf("%d %d", you, wu);
    return 0;
}
