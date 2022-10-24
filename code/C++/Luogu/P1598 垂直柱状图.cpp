/*  Coder: Harris
    Time: 2015.9.25
    Website: https://www.luogu.com.cn/problem/P1598
    Algorithm: simulation
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string s; int len, tot, ans[30];
int main(){
	for (int i = 1; i <= 4; i++){
		getline(cin, s);
		len = s.length();
		for (int i = 0; i < len; i++){
			if (s[i] >= 'A' && s[i] <= 'Z'){
				ans[s[i] - 'A' + 1]++;
				tot = max(tot, ans[s[i] - 'A' + 1]);
			}
		}
	}
	for (int i = tot; i >= 1; i--){
		for (int j = 1; j <= 26; j++){
			if (ans[j] >= i)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	for (int i = 'A'; i <= 'Z'; i++){
		printf("%c ", i);
	}
	return 0;
}
/*
input:
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!

output:
                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/