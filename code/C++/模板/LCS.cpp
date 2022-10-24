#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char num[505][505], flag[505][505], a[505], b[505];
int n, m;
void LCS(){
    int i, j;
    for (i = 1; i <= strlen(a); ++i)
        for (j = 1; j <= strlen(b); ++j)
            if (a[i-1] == b[j-1]){
                num[i][j] = num[i-1][j-1] + 1;
                flag[i][j] = 1;
            }
            else if (num[i][j-1] > num[i-1][j]){
                num[i][j] = num[i][j-1]; flag[i][j] = 2;
            }
            else{
                num[i][j] = num[i-1][j]; flag[i][j] = 3;
            }
}
void getLCS(){
	char res[500]; int k = 0;
    int i = strlen(a); int j = strlen(b);
    while (i>0 && j>0)
        if (flag[i][j] == 1){
            res[k++] = a[i-1]; i--; j--;
        }
        else if (flag[i][j] == 2) j--;
        else if (flag[i][j] == 3) i--;
	for (i = k-1; i >= 0; --i)
	    printf("%c", res[i]);
}
int main(){
    ios::sync_with_stdio(false);
    cin >> a; cin >> b;
    LCS();
    printf("%d\n", num[strlen(a)][strlen(b)]);
    getLCS();
    return 0;
}
