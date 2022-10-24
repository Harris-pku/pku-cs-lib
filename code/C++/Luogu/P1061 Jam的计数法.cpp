#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int s, t, w; char s1[30];
int main(){
    scanf("%d%d%d", &s, &t, &w);
    scanf("%s", s1+1);
    for (int i = 1; i <= 5; ++i){
        for (int j = w; j >= 1; --j){
            if (s1[j]-'a'+1 < t+j-w){
                s1[j]++;
                for (int k = j+1; k <= w; ++k)
                    s1[k] = s1[k-1] + 1;
                printf("%s\n", s1+1);
                break;
            }
        }
    }
    return 0;
}