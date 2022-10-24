#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1005];
int k, len, f;
int main(){
	scanf("%d %s", &k, s);
	len = strlen(s);
	for (int i = 0; i < len; i++){
		if (s[i] - '0' == 0)
			continue;
		if (f)
			printf("+");
		printf("%d*%d^%d", s[i] - '0', k, len - i - 1);
		f = 1;
	}
	return 0;
}
