#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

char s[105], s1[105];
int len, f = 1;
int main(){
	scanf("%d", &len);
	cin >> s1;
	cin >> s;
	for (int i = 0; i < len; i++){
		if (s[i] > s1[i]){
			f = 0; break;
		}
	}
	if (f)
		cout << s;
	else
		printf("-1");
	return 0;
}
