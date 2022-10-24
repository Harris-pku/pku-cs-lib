#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	if (!b) return a;
	else return gcd(b, a%b);
}

int n, a0, a1, b0, b1, x, ans;
int main(){
	scanf("%d", &n);
	while (n--){
	 	scanf("%d%d%d%d", &a0, &a1, &b0, &b1); ans = 0;  
     	if (a0%a1 || b1%b0){
			printf("0\n"); continue;
		}
	 	for (int i = a1; i*i <= b1; i += a1)  
      		if (b1%i == 0){
				x = i;
	  			if (gcd(a0/a1, x/a1) == 1 && gcd(b1/b0, b1/x) == 1) ans++;  
       			x = b1 / i;
       			if (x!=i && x%a1 == 0){
					if (gcd(a0/a1, x/a1) == 1 && gcd(b1/b0, b1/x) == 1) ans++;
				}
	    		
      		}
     printf("%d\n", ans);
	}
	return 0;
}
