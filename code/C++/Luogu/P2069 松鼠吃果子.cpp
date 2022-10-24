#include <iostream>

using namespace std;

int a[10001], n, m, num, k, h = 1;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= m; i++){
        k = i * i * i % 5 + 1;
        if (h + k <= n - i + 1)
            h += k;
        else
            h = k + 1;
        num = a[h];
        for (int j = h; j <= n - i; j++)
            a[j] = a[j + 1];
    }
    cout << num;
    return 0;
}
