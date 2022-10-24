#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int vis[1010],link[1010],a[1010][1010],n,m,k,x,y,sum;
bool dfs(int x){
     for (int i=1;i<=m;i++)
      if (a[x][i] && !vis[i]){
	   vis[i]=1;
       if (!link[i] || dfs(link[i])) {link[i]=x;return 1;}
      }
     return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++){
	 scanf("%d%d",&x,&y);
	 a[x][y]=1;
	}
	for (int i=1;i<=n;i++){
	 memset(vis,0,sizeof(vis));
     if (dfs(i)) sum++;
    }
    printf("%d\n",sum);
    return 0;
}
