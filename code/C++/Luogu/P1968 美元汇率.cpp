#include <cstdio>
#include <algorithm>

using namespace std;

double dollar[105] = {100}, mark[105], x[105], y[105];
int a[105], n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	{
		scanf("%d", &a[i]);
		x[i] = (double)a[i] / (double)100;
		y[i] = (double)100 / (double)a[i];
	}
	for (int i = 1; i <= n; i++){
		dollar[i] = max(dollar[i-1], mark[i-1] * y[i]);
		mark[i] = max(mark[i-1], dollar[i-1] * x[i]);
	}
	printf("%.2lf", dollar[n]);
	return 0;
}
