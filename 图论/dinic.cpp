#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int VM=2520;
const int EM=500010;
const int INF=0x3f3f3f3f;

struct Edge{
    int u,v,nxt;
    int flow;
}edge[EM<<1];

int n,m,cnt,head[VM];
int src,des,dep[VM];

void addedge(int cu,int cv,int cf){
    edge[cnt].u=cu;  edge[cnt].v=cv;  edge[cnt].flow=cf;
    edge[cnt].nxt=head[cu];  head[cu]=cnt++;

    edge[cnt].u=cv;  edge[cnt].v=cu;  edge[cnt].flow=0;
    edge[cnt].nxt=head[cv];  head[cv]=cnt++;
}

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int legal(int i,int j,int k){
    int x=i+dir[k][0];
    int y=j+dir[k][1];
    return x>=1 && x<=n && y>=1 && y<=m;
}

int BFS(){
    queue<int> q;
    while(!q.empty())
        q.pop();
    memset(dep,-1,sizeof(dep));
    dep[src]=0;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].v;
            if(edge[i].flow>0 && dep[v]==-1){
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[des]!=-1;
}
int DFS(int u,int minx){
    int ans=0;
    if(u==des)
        return minx;
    for(int i=head[u];i!=-1 && ans<minx;i=edge[i].nxt){
        int v=edge[i].v;
        if(edge[i].flow>0 && dep[v]==dep[u]+1){
            int tmp=min(edge[i].flow,minx-ans);
            tmp=DFS(v,tmp);
            ans+=tmp;
            edge[i].flow-=tmp;
            edge[i^1].flow+=tmp;
        }
    }
    if(!ans)
        dep[u]=-2;
    return ans;
}

int Dinic(){
    int ans=0,tmp;
    while(BFS()){
        while(1){
            tmp=DFS(src,INF);
            if(tmp==0)
                break;
            ans+=tmp;
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        cnt=0;
        memset(head,-1,sizeof(head));
        int x,sum=0;
        src=0;  des=n*m+1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                scanf("%d",&x);
                sum+=x;
                if((i+j)%2==0){
                    addedge(src,(i-1)*m+j,x);
                    for(int k=0;k<4;k++){
                        if(legal(i,j,k))
                            addedge((i-1)*m+j,(i+dir[k][0]-1)*m+(j+dir[k][1]),INF);
                    }
                }else{
                    addedge((i-1)*m+j,des,x);
                    for(int k=0;k<4;k++){
                        if(legal(i,j,k))
                            addedge((i+dir[k][0]-1)*m+(j+dir[k][1]),(i-1)*m+j,INF);
                    }
                }
            }
        int maxflow=Dinic();
        printf("%d\n",sum-maxflow);
    }
    return 0;
}
