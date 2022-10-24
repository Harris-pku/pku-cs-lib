#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long ans, n;
int gcd(int a, int b){
	if (!b) return a;
	else return gcd(b, a%b);
}

int xx(int x, int y){
	return x xor y;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	 	for (int j = i; j <= n; j++){
			printf("%d %d\n", gcd(i,j), xx(i,j));
	  		if (gcd(i,j) == xx(i,j)) ans++;
	 	}
	cout << ans;
	return 0;
}

