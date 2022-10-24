#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i * i <= n; i++)
		printf("%d ", i * i);
	return 0;
}
