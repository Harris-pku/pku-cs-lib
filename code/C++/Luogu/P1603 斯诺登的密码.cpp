/*  Coder: Harris
    Time: 2016.8.19
    Website: https://www.luogu.com.cn/problem/P1603
    Algorithm: simulation
*/
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

string a; long long num[6], ans; int j;
int main(){
    map<string, int> b;
    b["one"] = 1; b["two"] = 2;
    b["three"] = 3; b["four"] = 4;
    b["five"] = 5; b["six"] = 6;
    b["seven"] = 7; b["eight"] = 8;
    b["nine"] = 9; b["ten"] = 10;
    b["eleven"] = 11; b["twelve"] = 12;
    b["thirteen"] = 13; b["fourteen"] = 14;
    b["fifteen"] = 15; b["sixteen"] = 16;
    b["seventeen"] = 17; b["eighteen"] = 18;
    b["nineteen"] = 19; b["twenty"] = 20;
    b["a"] = 1; b["both"] = 2;
    b["another"] = 1; b["first"] = 1;
    b["second"] = 2; b["third"] = 3;
    map<string, int>::iterator it;
    for (int i = 1; i <= 6; i++){
        cin >> a;
        it = b.find(a);
        if (it != b.end()){
            num[j++] = b[a] * b[a] % 100;
        }
    }
    sort(num, num+6);
    for (int i = 0; i < 6; i++){
        ans *= 100; ans += num[i];
    }
    cout << ans;
    return 0;
}
/*
input:
Black Obama is two five zero .

output:
425
*/