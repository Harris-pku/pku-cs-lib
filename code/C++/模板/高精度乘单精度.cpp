#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char s1[2005];
int a[2005], k;
int main(){
    scanf("%s", s1);
    scanf("%d", &k);
    int len = strlen(s1);
    for (int i = 1; i <= len; i++){
        a[i] = s1[len - i] - '0';
    }
    for (int i = 1; i <= len; i++){
        a[i] *= k;
    }
    for (int i = 1; i <= len; i++){
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }
    while (a[len+1] > 0){
        len++;
        a[len+1] = a[len] / 10;
        a[len] %= 10;
    }
    while (a[len] == 0 && len > 1) len--; 
    for (int i = len; i >= 1; i--){
        printf("%d", a[i]);
    }
    return 0;
}
