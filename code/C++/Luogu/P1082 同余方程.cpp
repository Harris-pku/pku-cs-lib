#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int a, b, x, y;
void exgcd(int a, int b, int & x, int & y){
	if (!b){
		x = 1; y = 0; return;
	}
	exgcd(b, a%b, y, x);
	y -= x*(a/b); 
}
int main(){
	scanf("%d%d", &a, &b);
	exgcd(a, b, x, y);
	printf("%d", (x+b) % b);
	return 0;
}
