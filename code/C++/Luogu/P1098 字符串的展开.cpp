/*  Coder: Harris
    Time: 2016.8.22
    Website: https://www.luogu.com.cn/problem/P1098
    Algorithm: simulation
*/
#include <iostream>     
#include <string>    
#include <algorithm>
#include <cstdio>

using namespace std;    

string a; int x, y, z;
int main(){
    cin >> x >> y >> z >> a;    
    for (int i = 1; i < a.length()-1; ++i) 
	 	if ((a[i]=='-') && (a[i-1]<a[i+1]) && (a[i+1]-a[i-1]<=26) && (a[i+1]!='-') && (a[i-1]!='-')){
	 	string tf = "";
      	int start = z==1 ? a[i-1]+1 : a[i+1]-1, end = z==1 ? a[i+1]-1 : a[i-1]+1;    
      	for (int j = start; z==1 ? j<=end : j>=end; z==1 ? j++ : j--){
	   		for (int k = 1; k <= y; k++){
			   tf += x==1 ? tolower(j) : x==2 ? toupper(j) : '*';
			}
		}
        a.replace(i, 1, tf);
    }
    cout << a;
    return 0;
}
/*
input:
1 2 1
abcs-w1234-9s-4zz

output:
abcsttuuvvw1234556677889s-4zz
*/