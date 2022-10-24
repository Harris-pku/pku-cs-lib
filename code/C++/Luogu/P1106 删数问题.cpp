#include <iostream>
#include <string>

using namespace std;

string f[251][251], s; int k, i;
const string oo = "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
inline string mns(const string &a, const string &b){
    return a.size() < b.size() || (a.size() == b.size() && a < b) ? a : b;
}
int main(){
    cin >> s >> k;
    s = ' ' + s;
    int n = s.size() - 1;
    for (int i = 1; i <= n - k; i++)
        f[0][i] = oo;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - k; j++)
            f[i][j] = mns(f[i - 1][j], f[i - 1][j - 1] + s[i]);
    for (i = 0; i < f[n][n - k].size() && f[n][n - k][i] == '0'; i++)
        ;
    for (; i < f[n][n - k].size(); i++)
        cout << f[n][n - k][i];
    return 0;
}
