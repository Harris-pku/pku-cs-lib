#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=105; 
const int maxv=1005;
int f[maxv];int v[maxn],w[maxn];int n,t;
int main()
{
	scanf("%d%d",&t,&n);
	for (int i=1;i<=n;i++)
	{scanf("%d%d",&v[i],&w[i]);
	 for(int j=t;j>=v[i];j--)
	  f[j]=max(f[j],f[j-v[i]]+w[i]);
	}
	printf("%d",f[t]);
} 
