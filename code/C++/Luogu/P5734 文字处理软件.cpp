/*  Coder: Harris
    Time: 2020.7.19
    Website: https://www.luogu.com.cn/problem/P5734
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char s[10000], tmp[10000], tmp1[10000];
int n, k, x, y;
int main(){
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        cin >> k;
        switch (k){
            case 1: cin >> tmp; strcat(s, tmp); break;
            case 2: cin >> x >> y; strncpy(tmp, s+x, y);
                    tmp[y] = '\0';
                    strcpy(s, tmp); break;
            case 3: cin >> x >> tmp; strncpy(tmp1, s, x);
                    tmp1[x] = '\0'; strcat(tmp1, tmp);
                    strncpy(tmp, s+x, strlen(s)-x); tmp[strlen(s)-x] = '\0';
                    strcat(tmp1, tmp); strcpy(s, tmp1); break;
            case 4: cin >> tmp;
                    if (strstr(s, tmp) != NULL){
                        x = strstr(s, tmp) - s;
                    }
                    else x = -1;
                    break;
        }
        if (k < 4){
            cout << s << endl;
        }
        else cout << x << endl;
    }
    return 0;
}
/*
input:
4
ILove
1 Luogu
2 5 5
3 3 guGugu
4 gu

output:
ILoveLuogu
Luogu
LuoguGugugu
3
*/