#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map<string, string> fa;
string found(string x){
    if (fa[x] == x) return x;
    return fa[x] = found(fa[x]);
}
string s, fs; char ch;
int main(){
    while (cin>>ch && ch!='$'){
        cin >> s;
        if (ch == '#'){
            fs = s; if (fa[s] == "") fa[s] = s;
        }
        else if (ch == '+') fa[s] = fs;
        else cout << s << ' ' << found(s) << endl;
    }
    return 0;
}