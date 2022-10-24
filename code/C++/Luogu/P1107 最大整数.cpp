#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

string a[30]; int n;
int compare(string x, string y){
	return (x + y > y + x);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1, compare);
	for (int i = 1; i <= n; i++)
		cout << a[i];
	return 0;
}
