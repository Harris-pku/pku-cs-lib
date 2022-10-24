#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define s1(i) s1[i-1]
#define s2(i) s2[i-1]

using namespace std;

char s1[1000010], s2[1010];
int p[1010], n, m;
void match(){
	int j = 0;
	for (int i = 2; i <= m; i++){
		while (j && s2(j + 1) != s2(i))
			j = p[j];
		if (s2(j + 1) == s2(i))
			j++;
		p[i] = j;
	}
}

void kmp(){
	int j = 0;
	for (int i = 1; i <= n; i++){
		while (j && s1(i) != s2(j + 1))
			j = p[j];
		if (s1(i) == s2(j + 1))
			j++;
		if (j == m){
			printf("%d\n", i - m + 1);
			j = p[j];
		}
	}
}

int main(){
	scanf("%s", s1);
	scanf("%s", s2);
	n = strlen(s1);
	m = strlen(s2);
	match();
	kmp();
	for (int i = 1; i <= m; i++)
		printf("%d ", p[i]);
	return 0;
}
