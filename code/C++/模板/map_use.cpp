#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

map<string, int> ma; string s;
int main(){
    ma["July"] = 7;
    ma["May"] = 5;
    ma["June"] = 6;
    printf("size = %d\n", ma.size());
    cin >> s;
    if (ma.count(s)){
        cout << ma[s] << endl;
    }
    if (ma.empty()){
        printf("ma is empty\n");
    }
    else printf("ma is not empty\n");
    ma.clear();
    if (ma.empty()){
        printf("ma is empty\n");
    }
    else printf("ma is not empty\n");
    return 0;
}
