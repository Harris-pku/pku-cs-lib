#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[25][25][25] = {1};
int dfs(int x, int y, int z){
	if (x <= 0 || y <= 0 || z <= 0)
		return 1;
	if (x > 20 || y > 20 || z > 20)
		return dfs(20, 20, 20);
	if (a[x][y][z])
		return a[x][y][z];
	if (x < y && y < z)
		return a[x][y][z] = dfs(x, y, z-1) + dfs(x, y-1, z-1) - dfs(x, y-1, z);
	return a[x][y][z] = dfs(x-1, y, z) + dfs(x-1, y-1, z) + dfs(x-1, y, z-1) - dfs(x-1, y-1, z-1);
}
int x, y, z;
int main(){
	while (scanf("%d%d%d", &x, &y, &z)){
		if (x == -1 && y == -1 && z == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", x, y, z, dfs(x, y, z));
	}
	return 0;
}
