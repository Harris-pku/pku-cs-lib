#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

string solve(){
    string s = "", s1; char c; int n;
    while (cin >> c){
        if (c == '['){
            cin >> n;
            s1 = solve();
            while (n--) s += s1;
        }
        else{
            if (c == ']') return s;
            else s += c;
        }
    }
}
int main(){
    cout << solve();
    return 0;
}
