#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[502][502], b[502], n, t, t1;
int compare(int a, int b){
	return a > b;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	 	for (int j = i+1; j <= n; ++j){
	 		scanf("%d", &a[i][j]); a[j][i] = a[i][j];
	 	}
	for (int i = 1; i <= n; ++i){
		t = t1 = 0;
	  	for (int j = 1; j <= n; ++j){
		  	if (a[i][j] > t1){
			  	t = t1; t1 = a[i][j];
			}
	   		else if (a[i][j] > t) t = a[i][j];
		}
	  	b[i] = t;
    }
    sort(b+1, b+n+1, compare);
    printf("1\n");
    printf("%d", b[1]);
    return 0; 
}
