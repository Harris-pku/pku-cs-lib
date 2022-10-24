/*  Coder: Harris
    Time: 2015.9.6
    Website: https://www.luogu.com.cn/problem/P1308
    Algorithm: simulation
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string a, b; int pos, cur, tot;
int main(){
	getline(cin, a);
	getline(cin, b);
	for (int i = 0; i < a.length(); ++i){
		a[i] = tolower(a[i]);
	}
	for (int i = 0; i < b.length(); ++i){
		b[i] = tolower(b[i]);
	}
	a = ' ' + a + ' '; b = ' ' + b + ' ';
	pos = cur = b.find(a);
	if (pos == string::npos){
		printf("-1\n");
	}
	else{
		while (cur != string::npos){
			tot++;
			cur = b.find(a, cur+1);
		}
		printf("%d %d\n", tot, pos);
	}
	return 0;
}
/*
input:
To
to be or not to be is a question

output:
2 0
*/