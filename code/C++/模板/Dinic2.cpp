#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=250;
struct node{
    int u,v,next,c;
};
node edge[maxn<<1];
int head[maxn], dis[maxn], n, m, ans, cnt;

void init(){
    memset(head,-1,sizeof(head));
    cnt=0;
    memset(dis,-1,sizeof(dis));
    ans=0;
}

void add(int a,int b,int c){
    edge[cnt].u=a;
    edge[cnt].v=b;
    edge[cnt].c=c;
    edge[cnt].next=head[a];
    head[a]=cnt++;
}

int bfs()// 给各点分层，离源点的远近分
{
	memset(dis, -1, sizeof(dis));
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    int i;
    int cur;
    while (!q.empty()){ 
    	cur = q.front();
        q.pop();
        for(i=head[cur]; i != -1; i = edge[i].next){
        	if(dis[edge[i].v] == -1 && edge[i].c > 0){
        		dis[edge[i].v] = dis[cur] + 1;
				q.push(edge[i].v);
   }
  }
 }
 if(dis[m] < 0)
  return 0;
 return 1;
 
}

int Find(int x,int low){//增广
    int a;
    if(x==m) return low;
    for(int i=head[x];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(dis[v]==dis[x]+1 && edge[i].c>0 &&(a=Find(v,min(low,edge[i].c))))
        {
            edge[i].c -=a;
            edge[i^1].c +=a;
            return a;
        }
    }
    return 0;
}

void dinic(){
    int temp;
    while(bfs()){
        temp=Find(1,0x3f3f3f3f);
        ans+=temp;
    }
    printf("%d\n",ans);
}

int main(){
	while(~scanf("%d%d",&n,&m)){
    int a,b,flow;
    init();
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a,&b,&flow);
        add(a,b,flow);
        add(b,a,0);
    }
    dinic();
}
return 0;
}
