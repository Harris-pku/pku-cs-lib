#include <iostream>
#include <algorithm>

using namespace std;
int a, b, n, t;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> t;
		if (t)
			a++;
		else
			b++;
	}
	if (!b){
		cout << "-1";
		return 0;
	}
	if (a < 9){
		cout << "0";
		return 0;
	}
	for (int i = 1; i <= a / 9; i++)
		cout << "555555555";
	for (int i = 1; i <= b; i++)
		cout << "0";
	return 0;
}
