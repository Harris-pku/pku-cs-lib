#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

string s; char f[100005];
int sn[100005], sm[100005], b[5] = {1};
int ans, x, k, l1, l2;
int main(){
	cin >> s; f[0] = '+';
	for (int i = 1; i <= 4; ++i)
		b[i] = b[i-1] * 10;
	for (int i = s.size() - 1; i>=0; --i){
		if (s[i]>='0' && s[i]<='9' && x<=3){
			k = s[i]-'0'; sn[l1] += k*b[x++];
		}
	 	if (s[i]=='+' || s[i]=='*'){
			f[++l1] = s[i]; x = 0;
		}
	}
	for (int i = 0; i <= l1; ++i){
		if (f[i] == '*') sm[l2] = sn[i]*sm[l2] % 10000;
	 	else sm[++l2] = sn[i];
	}
	for (int i = 1; i <= l2; ++i){
		ans += sm[i]; ans %= 10000;
	}
	printf("%d", ans);
	return 0;
}

