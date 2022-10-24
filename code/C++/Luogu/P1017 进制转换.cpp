#include <iostream>
#include <cstdio>

using namespace std;

int h[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int s[1000005], n, r, k;
int main(){
	cin >> n >> r;
	k = 1;
	cout << n << "=";
	while (n != 0){
		s[k] = n % r;
		n /= r;
		if (s[k] < 0){
			s[k] = s[k] - r; n++;
		}
		k++;
	}
	for (int i = k - 1; i >= 1; i--){
		if (s[i] >= 10)
			putchar(h[s[i] - 10]);
		else
			cout << s[i];
	}
	cout << "(base" << r << ")";
	return 0;
}
