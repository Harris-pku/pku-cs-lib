/*  Coder: Harris
    Time: 2020.7.17
    Website: https://www.luogu.com.cn/problem/P5730
    Algorithm: simulation
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string h[10][5] = {
    {"XXX","X.X","X.X","X.X","XXX"}, //0
    {"..X","..X","..X","..X","..X"}, //1
    {"XXX","..X","XXX","X..","XXX"}, //2
    {"XXX","..X","XXX","..X","XXX"}, //3
    {"X.X","X.X","XXX","..X","..X"}, //4
    {"XXX","X..","XXX","..X","XXX"}, //5
    {"XXX","X..","XXX","X.X","XXX"}, //6
    {"XXX","..X","..X","..X","..X"}, //7
    {"XXX","X.X","XXX","X.X","XXX"}, //8
    {"XXX","X.X","XXX","..X","XXX"}, //9
};
string s; int n;
int main(){
    cin >> n >> s;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < n; j++){
            cout << h[s[j]-'0'][i];
            if (j != n-1) cout << ".";
        }
        cout << endl;
    }
    return 0;
}
/*
input:
10
0123456789

output:
XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
X.X...X...X...X.X.X.X...X.....X.X.X.X.X
X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
X.X...X.X.....X...X...X.X.X...X.X.X...X
XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
*/