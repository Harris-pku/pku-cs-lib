#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int visit[26], fu[26]; char f[26];
char a[105], b[105], c[105]; int t, l, l1;
void dui(){
	for (int i = 0; i < l; ++i){
		if (visit[b[i]-'A'] && visit[b[i]-'A']!=a[i]){
			t = 1; break;
		}
		if (fu[a[i]-'A'] && fu[a[i]-'A']!=b[i]){
			t = 1; break;
		}
		visit[b[i]-'A'] = a[i]; fu[a[i]-'A'] = b[i];
		f[a[i]-'A'] = b[i];
	}
}
void ying(){
	for (int i = 0; i < l1; ++i){
		c[i] = f[c[i]-'A'];
	}
	printf("%s", c);
}
void falsee(){
	printf("Failed");
}
int main(){
	scanf("%s", a);	scanf("%s", b);	scanf("%s", c);
	l = strlen(a); l1 = strlen(c);
	if (l < 26) t = 1;
	if (!t) dui();
	if (t) falsee();
	else ying();
	return 0;
}
