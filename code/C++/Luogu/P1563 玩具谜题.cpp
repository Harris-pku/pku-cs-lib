/*  Coder: Harris
    Time: 2016.11.25
    Website: https://www.luogu.com.cn/problem/P1563
    Algorithm: simulation
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

char name[100010][15];
int face[100010], n, m, f, k, t = 1;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d %s", &face[i], name[i]);
	while (m--){
		scanf("%d%d", &f, &k);
		if ((f && !face[t]) || (!f && face[t])){
			t += k;
			if (t > n)
				t -= n;
			continue;
		}
		if ((f && face[t]) || (!f && !face[t])){
			t -= k;
			if (t < 1)
				t += n;
			continue;
		}
	}
	printf("%s\n", name[t]);
	return 0;
}
/*
input:
7 3
0 singer
0 reader
0 mengbier 
1 thinker
1 archer
0 writer
1 mogician 
0 3
1 1
0 2

output:
writer
*/