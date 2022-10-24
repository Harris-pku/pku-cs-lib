#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int i, m, n, j, k, z;
int main(){
    cin >> n >> m;
    m = max(n, m);
    n = min(n, m);
    z = m * (m + 1) * (3 * n - m + 1) / 6;
    while (m)
        k += m, m--;
    while (n)
        j += n, n--;
    cout << z << " " << k * j - z;
    return 0;
}
