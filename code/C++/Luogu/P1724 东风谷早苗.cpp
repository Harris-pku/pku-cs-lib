#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct Point{
	int x, y;
} point[5010];
char s[5010]; int len, T, X, Y, t;
int main(){
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i < len; i++){
		if (s[i] == 'E') X++;
		if (s[i] == 'S') Y--;
		if (s[i] == 'W') X--;
		if (s[i] == 'N') Y++;
		point[i+1] = (Point){X, Y};
	}
	scanf("%d", &T);
	t = T % len;
	printf("%d %d\n", point[t].x + T / len * X, point[t].y + T / len * Y);
	return 0;
}
