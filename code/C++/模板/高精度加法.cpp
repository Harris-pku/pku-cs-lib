#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

char s1[505], s2[505];
int a[505], b[505];
int main(){
    scanf("%s", s1);
    scanf("%s", s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    int len = max(len1, len2);
    for (int i = 1; i <= len1; i++){
        a[i] = s1[len1 - i] - '0';
    }
    for (int i = 1; i <= len2; i++){
        b[i] = s2[len2 - i] - '0';
    }
    for (int i = 1; i <= len; i++){
        a[i] += b[i];
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }
    if (a[len+1] > 0) len++;
    for (int i = len; i >= 1; i--){
        printf("%d", a[i]);
    }
    return 0;
}