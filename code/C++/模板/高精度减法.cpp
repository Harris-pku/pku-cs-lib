#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

string s1, s2;
int a[10105], b[10105];
int main(){
    cin >> s1; cin >> s2;
    if (s1.length() < s2.length() || (s1.length() == s2.length() && s1 < s2)){
        swap(s1, s2); printf("-");
    }
    int len1 = s1.length(), len2 = s2.length();
    for (int i = 1; i <= len1; i++){
        a[i] = s1[len1-i] - '0';
    }
    for (int i = 1; i <= len2; i++){
        b[i] = s2[len2-i] - '0';
    }
    for (int i = 1; i <= len1; i++){
        if (a[i] < b[i]){
            a[i+1]--; a[i] += 10;
        }
        a[i] -= b[i];
    }
    while (a[len1]==0 && len1>1){
        len1--;
    }
    for (int i = len1; i >= 1; i--){
        printf("%d", a[i]);
    }
    return 0;
}
