#include <iostream>
#include <algorithm>

using namespace std;

int a[1005]; int a1, a2, a3, a4, a5, a6, ans;
int main(){
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	for (int i1 = 0; i1 <= a1; i1++)
		for (int i2 = 0; i2 <= a2; i2++)
			for (int i3 = 0; i3 <= a3; i3++)
				for (int i4 = 0; i4 <= a4; i4++)
					for (int i5 = 0; i5 <= a5; i5++)
						for (int i6 = 0; i6 <= a6; i6++)
							a[i1 * 1 + i2 * 2 + i3 * 3 + i4 * 5 + i5 * 10 + i6 * 20]++;
	for (int i = 1; i <= 1000; i++)
		if (a[i]){
			ans++;
		}
	cout << "Total=" << ans;
	return 0;
}
