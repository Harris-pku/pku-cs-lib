#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long di(){
	long long k = 0; char c;
	while ((c = getchar()) != EOF){
		char s[10];	int x;
		switch (c){
			case '[': continue;
			case ']': break;
			case 'R':{
				scanf("%s %d", s, &x);
				long long t = di();
				k += t * x;
				break;
			}
			case 'F':{
				scanf("%s %d", s, &x);
				k += x;
			}
			case 'B':{
				scanf("%s %d", s, &x);
				k -= x;
			}
		}
	}
	return k;
}
int main(){
	long long ans = di();
	printf("%lld\n", ans >= 0 ? ans : -ans);
	return 0;
}
