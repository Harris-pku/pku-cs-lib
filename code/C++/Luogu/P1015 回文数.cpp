#include <iostream>
#include <cstring>

using namespace std;

string x; int a[10005], n, len;
int hui(int t){
    for (int i = 1; i <= t / 2; i++)
        if (a[i] != a[t - i + 1])
            return 0;
    return 1;
}
int jia(int t){
    int c[10001] = {0}, s = 1;
    for (int i = 1; i <= t; i++){
        c[i] += a[i] + a[t - i + 1];
        c[i + 1] += c[i] / n;
        c[i] %= n;
    }
    if (c[t + 1] != 0)
        t++;
    for (int i = t; i >= 1; i--){
        a[s] = c[i]; s++;
    }
    return t;
}
int main(){
    cin >> n >> x;
    len = x.size();
    for (int i = 1; i <= len; i++){
        if (x[i - 1] < 65)
            a[i] = x[i - 1] - '0';
        else
            a[i] = x[i - 1] - 55;
    }
    for (int i = 1; i <= 30; i++){
        len = jia(len);
        if (hui(len)){
            cout << "STEP=" << i;
            return 0;
        }
    }
    cout << "Impossible!";
    return 0;
}
