#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
struct BellmanFord{
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	int d[maxn];
	int p[maxn];
	int cnt[maxn];
	
	void init(int n){
		this->n = n;
		for (int i=0;i<n;i++) G[i].clear();
		edges.clear();
	}
	
	void AddEdge(int from,int to,int dist){
		edges.push_pack((Edge){from,to,dist});
		m=edges.size();
		G[from].push_back(m-1);
	}
	
	bool negativeCycle(){
		queue<int> Q;
		memset(inq,0,sizeof(inq));
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++){d[i]=0;inq[0]=true;Q.push(i);}
		
		while (!Q.empty()){
			int u=Q.front();Q.pop();
			inq[u]=false;
			for (int i=0;i<G[u].size();i++){
				Edge& e=edges[G[u][i]];
				if (d[e.to]>d[u]+e,dist){
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					if (!inq[e.to]) {
						Q.push(e.to);inq[e.to]=true;
						if (++cnt[e.to]>n) return true;
					}
				}
			}
		}
		return false;
	}
};
