#include <iostream>
#include <algorithm>

using namespace std;

int a[15] = {1}, ans, n, t, t1, t2;
int h[6] = {1, 3, 7, 30, 120, 365};
int main(){
	cin >> n;
	for (int i = 1; i <= 11; i++)
		a[i] = a[i-1] * 2;
	for (int i = 1; i <= n; i++){
		cin >> t;
		if (t){
			if (t2){
				if (t2 > 10) t2 = 10;
				t1 -= a[t2 - 1];
			}
			if (t1 < 0) t1 = 0;
			t1++; t2 = 0;
		}
		else{
			t2++; continue;
		}
		for (int j = 0; j <= 5; j++)
			if (t1 >= h[j])
				ans++;
	}
	cout << ans;
	return 0;
}
