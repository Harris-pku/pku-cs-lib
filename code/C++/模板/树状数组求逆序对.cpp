#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 500005;
struct Node{
	int val, pos;
}node[N];
int c[N], reflect[N], n; long long ans;
int compare(const Node& a, const Node& b){
	return a.val < b.val;
}
int lowbit(int x){
	return x & (-x);
}
void update(int x){
	while (x <= n){
		c[x]++;
	    x += lowbit(x);
	}
}
int getsum(int x){
	int sum = 0;
	while (x > 0){
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
	 	scanf("%d", &node[i].val);
	 	node[i].pos = i;
	}
	sort(node+1, node+n+1, compare);
	for (int i = 1; i <= n; ++i)
	 	reflect[node[i].pos] = i;
	for (int i = 1; i <= n; ++i){
	 	update(reflect[i]);
	 	ans += i - getsum(reflect[i]);
	}
	cout << ans;
	return 0;
}
