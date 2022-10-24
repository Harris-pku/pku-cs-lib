#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int p[500010][50],deep[500010],n,m,k,A,B;
int next[1000010],h[1000010],v[1000010];
void dfs(int x){
	for (int i=h[x];i>0;i=next[i])
	 if (deep[v[i]]==-1)
	 {deep[v[i]]=deep[x]+1;
	  p[v[i]][0]=x;
	  dfs(v[i]);
	 }
}
int lca(int x,int y){
	int t;
	if (deep[x]<deep[y]) swap(x,y);
	for (t=0;(1<<t)<=deep[x];t++); t--;
	if (deep[x]!=deep[y])
	 for (int i=t;i>=0;i--)
	  if (deep[x]-(1<<i)>=deep[y]) x=p[x][i];
	if (x==y) return x;
	for (int i=t;i>=0;i--)
	 if (p[x][i] && (p[x][i]-p[y][i])) {x=p[x][i];y=p[y][i];}
	return p[x][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<n*2-1;i+=2)
	{scanf("%d%d",&v[i+1],&v[i]);
	 next[i]=h[v[i+1]];h[v[i+1]]=i;
	 next[i+1]=h[v[i]];h[v[i]]=i+1;
	}
	memset(deep,-1,sizeof(deep));
	deep[k]=0;
	dfs(k);
	for (int j=1;(1<<j)<=n;j++)
	 for (int i=1;i<=n;i++)
	  if (p[i][j-1]!=-1) p[i][j]=p[p[i][j-1]][j-1];
	for (int i=1;i<=m;i++)
	{scanf("%d%d",&A,&B);
	 printf("%d\n",lca(A,B));
	}
}
