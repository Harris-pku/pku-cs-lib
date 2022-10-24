#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, cord[15], ans[15], f[1005];
int getbig(int deep){
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= 1000; i++){
		f[i] = 1000;
		for (int j = 1; j <= deep; j++)
			if (i >= cord[j])
				f[i] = min(f[i], f[i - cord[j]] + 1);
		if (f[i] > n){
			if (i > ans[0]){
				ans[0] = i;
				for (int j = 1; j <= deep; ++j)
					ans[j] = cord[j];
			}
			return i;
		}
	}
}
void Dp(int deep){
	int x = getbig(deep);
	if (deep == m)
		return;
	for (int i = x; i > cord[deep]; --i){
		cord[deep + 1] = i;
		Dp(deep + 1);
	}
}
int main(){
	cin >> n >> m;
	cord[1] = 1;
	Dp(1);
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << " ";
	cout << endl;
	cout << "MAX=" << ans[0] - 1 << endl;
	return 0;
}
