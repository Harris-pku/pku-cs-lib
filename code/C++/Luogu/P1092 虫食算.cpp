#include <cstdio>
#include <algorithm>

using namespace std;

int match[30], n; bool flag[30];
char fa[30], fb[30], fs[30];
void dfs(int step, bool plus = false){
    if (step == n)
    if (!plus){
        for (int k = 0; k < n; k++)
        printf("%d ", match[k]);
        exit(0);
    }
    else
        return;
    for (int k = n - 2 - step; k >= 0; k--)
        if (match[fa[k]] != -1 && match[fb[k]] != -1 && match[fs[k]] != -1 && (match[fa[k]] + match[fb[k]]) % n != match[fs[k]] && (1 + match[fa[k]] + match[fb[k]]) % n != match[fs[k]])
            return;
    int tmp = n - 1 - step;
    if (match[fa[tmp]] == -1){
        for (int k = n - 1; k >= 0; k--){
            if (!flag[k]){
                match[fa[tmp]] = k;
                flag[k] = true;
                dfs(step, plus);
                match[fa[tmp]] = -1;
                flag[k] = false;
            }
        }
    }
    else if (match[fb[tmp]] == -1){
        for (int k = n - 1; k >= 0; k--)
            if (!flag[k]){
                match[fb[tmp]] = k;
                flag[k] = true;
                dfs(step, plus);
                match[fb[tmp]] = -1;
                flag[k] = false;
            }
        }
    else if (match[fs[tmp]] == -1){
        int res = match[fa[tmp]] + match[fb[tmp]] + plus;
        for (int k = 0; k < n; k++){
            if (match[k] == res % n)
            return;
        }
        match[fs[tmp]] = res % n;
        flag[match[fs[tmp]]] = true;
        dfs(step + 1, res >= n);
        flag[match[fs[tmp]]] = false;
        match[fs[tmp]] = -1;
    }
    else{
        int res = match[fa[tmp]] + match[fb[tmp]] + plus;
        if (match[fs[tmp]] == res % n)
        dfs(step + 1, res >= n);
    }
}
int main(){
    scanf("%d\n%s\n%s\n%s", &n, fa, fb, fs);
    for (int i = 0; i < n; i++){
        match[i] = -1;
        fa[i] -= 'A'; fb[i] -= 'A'; fs[i] -= 'A';
    }
    dfs(0);
    return 0;
}
