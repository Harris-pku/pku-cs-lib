#include <cstdio>
#include <cstring>

using namespace std;

int f[1000010], r[1000010], n, m, num, count, sum, a, b, i;
int main(){
    scanf("%d%d", &n, &m);
    while (m--){
        scanf("%d%d%d", &num, &a, &b);
        if (num){
            for (i = a; i <= b; i++)
                if (f[i]){
                    f[i] = 0; r[i] = 1;
                    count++;
                }
        }
        else
            for (i = a; i <= b; i++){
                if (!f[i]){
                    if (r[i]){
                        sum++; r[i] = 0;
                    }
                    f[i] = 1;
                }
            }
    }
    printf("%d\n", count - sum);
    printf("%d", sum);
    return 0;
}
