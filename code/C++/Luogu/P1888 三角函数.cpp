#include <cstdio>
#include <algorithm>

using namespace std;

int t, h, f, x, y, z;
int gcd(int a, int b){
	if (!b) return a;
	return gcd(b, a%b);
}
int main(){
	scanf("%d%d%d", &x, &y, &z);
	t = max(x, y); h = min(x, y);
	t = max(t, z); h = min(h, z);
	f = gcd(t, h);
	printf("%d/%d", h/f, t/f);
	return 0;
}
