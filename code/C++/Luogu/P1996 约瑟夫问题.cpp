#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int visit[10005], n, m, t, h, l, h1;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		h = 0;
	 	while (h < m){
		 	t++;
	  		while (t > n) t -= n; 
	  		if (!visit[t]) h++;
	  		if (m == h){
				break;
			}
	 	}
	 	printf("%d ", t); visit[t] = 1;
	}
	return 0; 
} 
