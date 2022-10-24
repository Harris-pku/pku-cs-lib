#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int v[10010],w[10010],f[10010],n,m;
int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++)
	 scanf("%d%d",&v[i],&w[i]);
	for (int i=1;i<=n;i++)
	 for (int j=v[i];j<=m;j++)
	  f[j]=max(f[j],f[j-v[i]]+w[i]);
	printf("%d",f[m]);
}
