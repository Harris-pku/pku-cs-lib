#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100005;
struct Node{
	int val, pos;
} a[N], b[N];
int c[N], ra[N], rb[N], n;
long long ans;
int compare(const Node &a, const Node &b){
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
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i].val);
		a[i].pos = i;
	}
	sort(a+1, a+n+1, compare);
	for (int i = 1; i <= n; i++)
		ra[a[i].pos] = i;
	for (int i = 1; i <= n; i++){
		scanf("%d", &b[i].val);
		b[i].pos = i;
	}
	sort(b+1, b+n+1, compare);
	for (int i = 1; i <= n; i++)
		rb[b[i].pos] = i;
	for (int i = 1; i <= n; i++)
		c[rb[i]] = i;
	for (int i = 1; i <= n; i++)
		ra[i] = c[ra[i]];
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++){
		update(ra[i]);
		ans += i - getsum(ra[i]);
		ans %= 99999997;
	}
	cout << ans;
	return 0;
}
