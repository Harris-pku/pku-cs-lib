#include <cstdio>
#include <algorithm>

using namespace std;

int a[35], n, m;
int main(){
	scanf("%d", &n);
	a[0] = m = 1; n--;
	for (int i = 1; i <= 30; i++){
		a[i] = a[i-1] * 2; m++;
		if (n >= a[i])
			n -= a[i];
		else{
			a[i] = n;
			n -= a[i];
		}
		if (n <= 0)
			break;
	}
	for (int i = 1; i <= m - 2; i++){
		if (a[i] == a[m-1]){
			a[m-1]--; a[i]++;
		}
	}
	sort(a, a+m);
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%d ", a[i]);
	return 0;
}
