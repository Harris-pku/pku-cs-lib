#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, t, m, h, g;
int gcd(int a, int b){
	if (!b) return a;
	return gcd(b, a%b);
}
int main(){
	cin >> h;
	for (int k = 1; k <= h; k++){
		cin >> n >> t >> m;
		m /= gcd(t, m);
		for (int i = 3; i <= n; i++){
			cin >> t;
			if (m != 1)
				m /= gcd(t, m);
			else
				break;
		}
		if (m == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
