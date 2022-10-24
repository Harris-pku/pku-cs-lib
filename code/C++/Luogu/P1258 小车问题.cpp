#include <cstdio>
#include <algorithm>

using namespace std;

double a, b, s, x;
int main(){
	scanf("%lf%lf%lf", &s, &a, &b);
	x = (a + b) * s / (b + 3 * a);
	printf("%.6f", (x / b + (s - x) / a));
	return 0;
}
