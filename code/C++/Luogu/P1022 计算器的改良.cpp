#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int zhi, tot, xi, deng = 1, fu = 1;
char S[100], q, w;
int main(){
	scanf("%s", S);
	q = strlen(S);
	for (int i = 0; i < q; i++){
		if (S[i] == '+'){
			zhi -= tot * deng * fu;
			tot = 0; fu = 1;
		}
		else if (S[i] == '-'){
			zhi -= tot * deng * fu;
			tot = 0; fu = -1;
		}
		else if (S[i] == '='){
			zhi -= tot * deng * fu;
			deng = -1; tot = 0; fu = 1;
		}
		else if (S[i] >= 'a' && S[i] <= 'z'){
			xi += tot * deng * fu;
			if (!xi)
				xi = 1;
			w = S[i]; tot = 0;
		}
		else
			tot = tot * 10 + (int)(S[i] - '0');
	}
	zhi += tot * fu;
	printf("%c=%.3f", w, (zhi * 1.0) / (xi * 1.0));
	return 0;
}
