#include <iostream>
#include <set>
#include <string>

using namespace std;

int n, ans;
string s;
int main(){
	ios::sync_with_stdio(false);
	set<string> ss;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s;
		ss.insert(s);
	}
	cout << ss.size();
	return 0;
}
