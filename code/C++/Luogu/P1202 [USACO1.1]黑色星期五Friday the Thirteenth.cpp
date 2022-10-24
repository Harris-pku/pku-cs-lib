#include <cstdio>
#include <algorithm>

using namespace std;

int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day[8], n, r = 1;
int main(){
	scanf("%d", &n);
	for (int i = 1900; i < 1900 + n; i++){
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			mon[2] = 29;
		else
			mon[2] = 28;
		for (int j = 1; j <= 12; j++)
			for (int k = 1; k <= mon[j]; k++){
				if (k == 13)
					day[r]++;
				r = (r + 1) > 7 ? r - 6 : r + 1;
			}
	}
	printf("%d %d ", day[6], day[7]);
	for (int i = 1; i <= 5; i++)
		printf("%d ", day[i]);
	return 0;
}
