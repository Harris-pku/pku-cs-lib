#include<cstdio>
#include<algorithm>
using namespace std;
const int maxans=1000000000;
const int maxn=100005;
const int maxlog_2_n=25;
int f[maxn][maxlog_2_n];int b[maxlog_2_n];int n,m,l,r,ans,t;
int main()
{
	scanf("%d%d",&m,&n);b[0]=1;
	for (int i=1;i<=m;i++) scanf("%d",&f[i][0]);
	for (int j=1;j<=20;j++)
	{b[j]=b[j-1]*2;
	 if (b[j]>m) {t=j;break;}
	 for (int i=1;i<=m;i++)
	 {if (i+b[j]-1>m) break;
	  f[i][j]=min(f[i][j-1],f[i+b[j-1]][j-1]);
	 }
	}
	for (int i=1;i<=n;i++)
	{scanf("%d%d",&l,&r);
	 ans=maxans;
	 for (int j=t;j>=0;j--)
	 {if (b[j]>r-l+1) continue;
	  ans=min(ans,f[l][j]);
	  l+=b[j];}
	 printf("%d ",ans);
	}
} 
