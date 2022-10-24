#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[800], ch; int n, a, b, w, ans;
int main(){
    scanf("%d%s", &n, s);
    memcpy(s+n, s, n);
    for (int i = 0; i < (n<<1); ++i){
        if (s[i] == 'w'){
            b++; w++;
        }
        else if (s[i] == ch){
            b++; w = 0;
        }
        else{
            ans = max(ans, a+b); a = b - w;
            b = w + 1; w = 0; ch = s[i];
        }
    }
    ans = max(ans, a+b);
    printf("%d\n", min(ans, n));
    return 0;
}