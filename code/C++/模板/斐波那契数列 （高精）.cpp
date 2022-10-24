#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5005; 
int a[3][maxn];int n;
int main()
{
	scanf("%d",&n);
	if (!n) {printf("0");return 0;}
	a[1][1]=a[1][0]=a[2][0]=1;a[2][1]=2;
	for (int i=3;i<=n;i++)
	{a[i%3][0]=a[(i-1)%3][0];
	 for (int j=1;j<=a[i%3][0];j++)
	 {a[i%3][j]=j==1 ? a[(i-1)%3][j]+a[(i-2)%3][j] : a[(i-1)%3][j]+a[(i-2)%3][j]+a[i%3][j];
	  a[i%3][j+1]=a[i%3][j] / 10;
	  a[i%3][j]%=10;
	 }
	 if (a[i%3][a[i%3][0]+1]) a[i%3][0]++;
	}
	for (int i=a[n%3][0];i>=1;i--)
	 printf("%d",a[n%3][i]);
}
