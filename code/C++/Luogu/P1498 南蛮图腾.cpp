#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int a[1005] = {1}, n;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < (1<<n); i++){
        for (int j = 1; j < (1<<n)-i; j++){
            printf(" ");
        }
        for (int j = i; j >= 0; j--){
            a[j] ^= a[j-1];
        }
        if ((i&1) == 0){
			for (int j = 0; j <= i; j++){
			    printf(a[j] ? "/\\" : "  ");
            }
        }
        else{
		    for (int j = 0; j <= i; j += 2){
		        printf(a[j] ? "/__\\" : "    ");
            }
            printf("\n");
        }
    }
    return 0;
}
