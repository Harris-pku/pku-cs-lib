#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char a[210], b[210], s;
int k, lena, lenb, len, c[210];
int main(){
	scanf("%d", &k);
	scanf("%s%s", a, b);
	lena = strlen(a);
	lenb = strlen(b);
	len = max(lena, lenb);
	for (int i = lena - 1; i >= 0; i--)
		c[lena-i] += a[i]>='a' ? a[i]-'a'+10 : a[i]-'0';
	for (int i = lenb - 1; i >= 0; i--)
		c[lenb-i] += b[i]>='a' ? b[i]-'a'+10 : b[i]-'0';
	for (int i = 1; i <= len; i++){
		c[i+1] += c[i] / k;
		c[i] %= k;
	}
	if (c[len + 1])
		len++;
	for (int i = len; i > 0; i--){
		s = c[i] > 9 ? c[i] - 10 + 'a' : c[i] + '0';
		printf("%c", s);
	}
	return 0;
}
