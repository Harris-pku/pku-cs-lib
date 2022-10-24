#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

string s;
int palindrome(int x){
    int flag = 1;
    for (int i = 0; i < x; ++i){
        if (s[i] != s[x-i-1]){
            flag = 0; break;
        }
    }
    return flag;
}
int main(){
    cin >> s;
    for (int i = s.length(); i; i /= 2){
        if (i&1 || !palindrome(i)){
            printf("%d", i); break;
        }
    }
    return 0;
}
