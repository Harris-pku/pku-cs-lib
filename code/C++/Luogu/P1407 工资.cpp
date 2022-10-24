#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, sum, h, t;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &m); sum = 0;
		for (int j = 1; j <= m; j++){
			scanf("%d", &h);
			if (!sum)
				t = h;
			if (h == t)
				sum++;
			else
				sum--;
		}
		printf("%d\n", t);
	}
	return 0;
}
