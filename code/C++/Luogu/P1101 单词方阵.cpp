#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char a[105][105], s[105][105]; char c[8] = "yizhong"; int n;
int h[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
inline void pt(int x, int y, int k){
	for (int i = 0; i < 7; ++i)
	 	s[x + i*h[k][0]][y + i*h[k][1]] = c[i];
	return;
}
inline int sou(int x, int y, int k){
	for (int i = 1; i < 7; ++i){
		int xx = x + i*h[k][0];
		int yy = y + i*h[k][1];
		if (xx<1 || xx>n || yy<1 || yy>n || a[xx][yy]!=c[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	 	scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; ++i)
	 	for (int j = 1; j <= n; ++j)
	  		s[i][j] = '*';
	for (int i = 1; i <= n; ++i)
	 	for (int j = 1; j <= n; ++j){
			if (a[i][j] == 'y')
	  			for (int k = 0; k < 8; ++k)
	    			if (sou(i,j,k)) pt(i,j,k);
	 	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
	  		printf("%c", s[i][j]);
	 	printf("\n");  
	}
	return 0;
}
