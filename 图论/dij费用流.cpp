#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int MAX_V=5005;
const int INF=0x3f3f3f3f;
struct edge {
    int to,cap,cost,rev;
};
int V;
vector<edge>G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
void add_edge(int from,int to,int cap,int cost) {
    G[from].push_back((edge) {
        to,cap,cost,(int)G[to].size()
    });
    G[to].push_back((edge) {
        from,0,-cost,(int)G[from].size()-1
    });
}
int min_cost_flow(int s,int t,int f) {
    int res=0;
    fill(h,h+V+1,0);
    while(f>0) {
        priority_queue<P,vector<P>,greater<P>>que;
        fill(dist,dist+V+1,INF);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty()) {
            P p=que.top();
            que.pop();
            int v=p.second;
            if(dist[v]<p.first)continue;
            for(int i=0; i < G[v].size(); i++) {
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]) {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==INF) {
            return -1;
        }
        for(int v=1; v<=V; v++)h[v]+=dist[v];
        int d=f;
        for(int v=t; v!=s; v=prevv[v]) {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t; v!=s; v=prevv[v]) {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
int a[2005];
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        V=n*2+3;
        for(int i=1;i<=V;i++)G[i].clear();
        int s=2*n+1,s0=s+1,t=s0+1;
        int x,y,z,zz;
        x=s,y=s0,z=k,zz=0;
        add_edge(x,y,z,zz);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            x=s0,y=i,z=1,zz=-a[i];
            add_edge(x,y,z,zz);
            x=i,y=i+n,z=1,zz=0;
            add_edge(x,y,z,zz);
            x=n+i,y=t,z=1,zz=0;
            add_edge(x,y,z,zz);
            for(int i0=1;i0<i;i0++)
            {
                if(a[i0]>a[i])continue;
                x=i0+n,y=i,z=1,zz=-a[i];
                add_edge(x,y,z,zz);
            }
        }
        printf("%d\n",-min_cost_flow(s,t,k));
    }
    return 0;
}