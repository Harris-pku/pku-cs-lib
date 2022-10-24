#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int L = 1005;
string s[102][102];
int in[10][2], cur[1005];
string pluses(string x, string y){
    string ans;
    int a[L] = {0}, b[L] = {0}, lena = x.size(), lenb = y.size();
    for (int i = 0; i < lena; i++)
        a[lena-1-i] = x[i] - '0';
    for (int i = 0; i < lenb; i++)
        b[lenb-1-i] = y[i] - '0';
    int len = max(lena, lenb);
    for (int i = 0; i < len; i++){
        a[i] += b[i];
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    if (a[len])
        len++;
    for (int i = len - 1; i >= 0; i--)
        ans += a[i] + '0';
    return ans;
}
string times(string x, int y){
    string ans;
    int lena = x.size();
    memset(cur, 0, sizeof(cur));
    for (int i = lena - 1; i >= 0; i--)
        cur[lena - i - 1] = x[i] - '0';
    int w = 0;
    for (int i = 0; i < lena; i++){
        cur[i] = cur[i] * y + w;
        w = cur[i] / 10;
        cur[i] = cur[i] % 10;
    }
    while (w){
        cur[lena++] = w % 10;
        w /= 10;
    }
    lena--;
    while (lena >= 0)
        ans += cur[lena--] + '0';
    return ans;
}
int main(){
    s[0][0] = s[1][1] = "1";
    s[1][0] = "0";
    for (int i = 2; i <= 100; i++)
        for (int j = 1; j <= i; j++)
            s[i][j] = pluses(s[i-1][j-1], times(s[i-1][j], j));
    for (int i = 0; (cin >> in[i][0] >> in[i][1]) && i < 10; ++i){
        if (in[i][0] < in[i][1])
            printf("0\n");
        else
            cout << s[in[i][0]][in[i][1]] << "\n";
    }
    return 0;
}