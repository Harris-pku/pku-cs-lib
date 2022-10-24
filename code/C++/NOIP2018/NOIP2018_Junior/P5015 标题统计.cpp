#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
char s[20];int ans;
int main(){
	while (cin>>s){
		ans += strlen(s);
	}
	printf("%d",ans);
	return 0;
} 
