#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

string s; int tot;
int main(){
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; ++i)
        if (s[i] == '1') tot++;
    printf("%d", tot);
    return 0;
}