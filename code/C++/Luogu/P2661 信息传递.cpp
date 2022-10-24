#include <cstdio> 
#include <algorithm>   

using namespace std;

int t[200005], r[200005], n, i, j, sum, ans = 200000;
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; ++i){
        scanf("%d", &t[i]); r[t[i]]++;
    }
    for (i = 1; i <= n; ++i) 
	    if (!r[i]){
            r[i] = -1;  
            for (j = t[i]; --r[j] == 0; j = t[j])
                r[j] = -1;   
        }
    for (i = 1; i <= n; ++i) 
	    if (r[i] != -1){
            sum = 0; r[i] = -1;
            for (j = t[i]; j != i; j = t[j]){
                r[j] = -1; sum++;
            }
            ans = min(ans, sum);  
        }
    printf("%d", ans);
    return 0;
}     