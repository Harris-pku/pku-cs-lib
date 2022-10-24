#include <cstdio>
#include <algorithm>

using namespace std;

int n, sum;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n / 2; i++)
		for (int j = i + 1; j <= n / 2 + 1; j++){
			sum = (i + j) * (j - i + 1) / 2;
			if (sum == n)
				printf("%d %d\n", i, j);
			if (sum > n)
				break;
		}
	return 0;
}
