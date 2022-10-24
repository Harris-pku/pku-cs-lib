#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

string s1, s2; char c;
int a[2005][2], k, len1, len2;
int main(){
	cin >> k >> s1 >> s2;
	len1 = s1.size();
	len2 = s2.size();
	for (int i = len1 - 1; i >= 0; i--)
		a[len1-i][0] = s1[i] >= '0' && s1[i] <= '9' ? s1[i] - '0' : s1[i] - 'A' + 10;
	for (int i = len2 - 1; i >= 0; i--)
		a[len2-i][1] = s2[i] >= '0' && s2[i] <= '9' ? s2[i] - '0' : s2[i] - 'A' + 10;
	len1 = max(len1, len2);
	for (int i = 1; i <= len1; i++){
		a[i][0] += a[i][1];
		a[i+1][0] += a[i][0] / k;
		a[i][0] %= k;
	}
	if (a[len1+1][0])
		len1++;
	for (int i = len1; i >= 1; i--){
		if (a[i][0] <= 9)
			cout << a[i][0];
		else{
			c = a[i][0] - 10 + 'A';
			printf("%c", c);
		}
	}
	return 0;
}
