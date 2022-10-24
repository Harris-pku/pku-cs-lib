#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int phi[10000005], n;
long long sum_phi(int x){
	memset(phi, 0, sizeof phi);
	phi[1] = 1;
	for (int i = 1; i <= n; ++i)
	 	if (!phi[i]) 
	 		for (int j = i;j <= n;j += i){
				if (!phi[j]) phi[j] = j;
	         	phi[j] = phi[j] / i * (i-1);
	        }
	long long ans = 0;
	for (int i = 1;i <= n; ++i)
	 	ans += phi[i];
	return ans;
}
int main(){
	scanf("%d", &n);
	cout << sum_phi(n);
}
