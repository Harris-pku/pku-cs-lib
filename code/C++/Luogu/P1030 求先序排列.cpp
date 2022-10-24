#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

string zhongxu, houxu;
void xianxu(string zhong, string hou){
    if (zhong.size() > 0){
        char ch = hou[hou.size() - 1];
        cout << ch;
        int k = zhong.find(ch);
        xianxu(zhong.substr(0, k), hou.substr(0, k));
        xianxu(zhong.substr(k+1), hou.substr(k, zhong.size()-k-1));
    }
}
int main(){
    cin >> zhongxu; cin >> houxu;
    xianxu(zhongxu, houxu); cout << endl;
    return 0;
}