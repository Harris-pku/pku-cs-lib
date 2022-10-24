#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char s1[2005], s2[2005];
int a[2005], b[2005], c[5005];
int main(){
    scanf("%s", s1);
    scanf("%s", s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    int len = len1 + len2 - 1;
    for (int i = 1; i <= len1; i++){
        a[i] = s1[len1 - i] - '0';
    }
    for (int i = 1; i <= len2; i++){
        b[i] = s2[len2 - i] - '0';
    }
    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            c[i+j-1] += a[i] * b[j];
        }
    }
    for (int i = 1; i <= len; i++){
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
    if (c[len+1] > 0) len++;
    while (c[len] == 0 && len > 1) len--; 
    for (int i = len; i >= 1; i--){
        printf("%d", c[i]);
    }
    return 0;
}