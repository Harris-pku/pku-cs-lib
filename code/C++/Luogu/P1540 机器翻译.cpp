/*  Coder: Harris
    Time: 2016.7.21
    Website: https://www.luogu.com.cn/problem/P1540
    Algorithm: queue
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int visit[1005], q[1005];
int ans, n, m, cur, head = 1, tail = 1;
int main(){
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &cur);
		if (!visit[cur]){
			q[++tail] = cur; // 加入元素
			visit[cur] = 1;
			ans++;
			if (tail-head+1 > m){
				cur = q[head++];
				visit[cur] = 0; // 删除元素
			}
		}
	}
	printf("%d", ans);
	return 0;
}
/*
input:
3 7
1 2 1 5 4 4 1

output:
5
*/