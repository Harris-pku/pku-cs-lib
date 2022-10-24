#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

string a, b, ab[7], ba[7];
int n = 1, k;
queue<string> qa, qb;
map<string, int> visa, visb;
int main(){
    cin >> a >> b;
    while (cin >> ab[n] >> ba[n])
        n++;
    n--;
    visa[a] = 1;
    visb[b] = 1;
    qa.push(a);
    qb.push(b);
    while (1){
        if (qa.empty() || qb.empty()){
            cout << "NO ANSWER!" << endl;
            return 0;
        }
        string ta, tb;
        ta = qa.front();
        tb = qb.front();
        for (int i = 1; i <= n; i++){
            k = 0;
            while (ta.find(ab[i], k) != -1){
                k = ta.find(ab[i], k);
                int l = ab[i].size();
                ta.replace(k, l, ba[i]);
                if (visa[ta] == 0){
                    visa[ta] = visa[qa.front()] + 1;
                    qa.push(ta);
                }
                if (visb[ta] != 0){
                    cout << visa[ta] + visb[ta] - 2 << endl;
                    return 0;
                }
                k++; ta = qa.front();
            }
            k = 0;
            while (tb.find(ba[i], k) != -1){
                k = tb.find(ba[i], k);
                int l = ba[i].size();
                tb.replace(k, l, ab[i]);
                if (visb[tb] == 0){
                    visb[tb] = visb[qb.front()] + 1;
                    qb.push(tb);
                }
                if (visa[tb] != 0){
                    cout << visa[tb] + visb[tb] - 2 << endl;
                    return 0;
                }
                k++; tb = qb.front();
            }
        }
        qa.pop(); qb.pop();
    }
    return 0;
}
