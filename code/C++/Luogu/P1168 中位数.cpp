#include <cstdio>
#include <queue>
#define ins(x) ((x) < mid ? L.push(x) : R.push(x))

using namespace std;

priority_queue<int> L;
priority_queue<int, vector<int>, greater<int>> R;
int n, x, y, mid;
int main(){
	scanf("%d%d", &n, &x);
	printf("%d\n", mid = x);
	R.push(x);
	for (int i = 1; i <= ((n - 1) >> 1); i++){
		scanf("%d%d", &x, &y);
		ins(x); ins(y);
		while (L.size() >= R.size()){
			R.push(L.top());
			L.pop();
		}
		while (R.size() - 1 > L.size()){
			L.push(R.top());
			R.pop();
		}
		printf("%d\n", mid = R.top());
	}
	return 0;
}
