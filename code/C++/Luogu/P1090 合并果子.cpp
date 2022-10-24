#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > q;
long long ans; int n, t, x, y;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
        scanf("%d", &t); q.push(t);
    }
	for (int i = 1; i < n; i++){
        x = q.top(); q.pop();
	    y = q.top(); q.pop();
	    ans += x + y; q.push(x + y);
	}
	cout << ans;
    return 0;
}