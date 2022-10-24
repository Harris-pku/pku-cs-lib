#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int num[45], cur, ans;
int main(){
	for (int i = 1; i <= 10; i++){
		scanf("%d", &cur);
		if (!num[cur%42]){
			num[cur%42] = 1; ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
