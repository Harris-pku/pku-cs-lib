#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n; unsigned long long k;
int main(){
    cin >> n >> k;
    k ^= k>>1;
    while(~--n){
        cout << (k>>n & 1);
    }
    return 0;
}