#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node
{int v,l,next;}e[500010];
int vis[10010],dis[10010],st[10010];
int en,t,c,s,end,start,x,y,z;
int add(int x,int y,int z)
{
    en++;
    int i=en;e[i].l=y;e[i].v=z;
    e[i].next=st[x];st[x]=i;
}
int main()
{
	memset(dis,127,sizeof dis);
    scanf("%d%d%d",&t,&c,&s);
    for (int i=1;i<=c;i++)
    {scanf("%d%d%d",&x,&y,&z);
     add(x,y,z);
     //add(y,x,z);
    }
    start=s;vis[start]=1;dis[start]=0;
    queue<int>que;
    que.push(start);
    while (!que.empty())
    {
        int now=que.front();
        que.pop();
        int t=st[now];
        vis[now]=0;
        while (t!=0)
        {
            if (dis[e[t].l]>dis[now]+e[t].v)
            {
                dis[e[t].l]=dis[now]+e[t].v;
                if (vis[e[t].l]==0)
                {
                    vis[e[t].l]=1;
                    que.push(e[t].l);
                }
            }
            t=e[t].next;
        }
    }
    for (int i=1;i<=t;i++)
    {
        if (dis[i]==2139062143)
            dis[i]=2147483647;
        printf("%d ",dis[i]);
    }
} 
