#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n,bef,cur,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&cur);
		if (cur > bef) ans += cur-bef;
		bef = cur;
	}
	printf("%d",ans);
	return 0;
}
