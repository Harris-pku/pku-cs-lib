/*  Coder: Harris
    Time: 2016.8.11
    Website: https://www.luogu.com.cn/problem/P1765
    Algorithm: simulation
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string s; int ans, len;
int h[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
int main(){
	getline(cin, s);
	len = s.length();
	for (int i = 0; i < len; i++){
		if (s[i] >= 'a' && s[i] <= 'z'){
			ans += h[s[i] - 'a'];
		}
		else if (s[i] == ' '){
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
/*
input:
i have a dream

output:
23
*/