#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int a[100005], f[100005], n, ans = 1;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	 	if (a[i]>a[i-1]) f[i] = 1;
	 	else if (a[i]<a[i-1]) f[i] = 2;
	}
	f[1] = -1;
	for (int i = 2; i <= n; ++i){
	 	if (f[i]!=0 && f[i]!=f[i-1]) ans++;
	    else if (!f[i]) f[i]=f[i-1];
	}
	printf("%d", ans);
	return 0;
}
