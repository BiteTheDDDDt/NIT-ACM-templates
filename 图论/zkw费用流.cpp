#include<bits/stdc++.h>
using namespace std;
bool vis[200001];
int n,m,s,t,ans,ans0;
int nedge=-1,p[200001],c[200001],cc[200001],nex[200001],head[200001],dist[200001];
void addedge(int x,int y,int z,int zz){p[++nedge]=y;c[nedge]=z;cc[nedge]=zz;nex[nedge]=head[x];head[x]=nedge;}
bool spfa(int s,int t)
{
    memset(vis,0,sizeof vis);
    for(int i=0;i<=n;i++)dist[i]=1e9;
    dist[t]=0,vis[t]=1;
    deque<int>q;
    q.push_back(t);
    while(!q.empty())
    {
        int now=q.front();
        q.pop_front();
        for(int k=head[now];k>-1;k=nex[k])if(c[k^1]&&dist[p[k]]>dist[now]-cc[k])
        {
            dist[p[k]]=dist[now]-cc[k];
            if(!vis[p[k]])
            {
                vis[p[k]]=1;
                if(!q.empty()&&dist[p[k]]<dist[q.front()])q.push_front(p[k]);
                else q.push_back(p[k]);
            }
        }
        vis[now]=0;
    }
    return dist[s]<1e9;//不要求流量最大则设置为<0
}
int dfs(int x,int low)
{
    if(x==t)
    {
        vis[t]=1;
        return low;
    }
    int used=0,a;
    vis[x]=1;
    for(int k=head[x];k>-1;k=nex[k])
    {
        if(!vis[p[k]]&&c[k]&&dist[x]-cc[k]==dist[p[k]])
        {
            a=dfs(p[k],min(c[k],low-used));
            if(a)ans+=a*cc[k],c[k]-=a,c[k^1]+=a,used+=a;
            if(used==low)break;
        }
    }
    return used;
}
int costflow()
{
    int flow=0;
    while(spfa(s,t))
    {
        vis[t]=1;
        while(vis[t])
        {
            memset(vis,0,sizeof vis);
            flow+=dfs(s,1e9);
        }
    }
    return flow;
}
int main()
{
    memset(nex,-1,sizeof nex),memset(head,-1,sizeof head);
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y,z,zz;
        scanf("%d%d%d%d",&x,&y,&z,&zz);
        addedge(x,y,z,zz),addedge(y,x,0,-zz);
    }
    ans=0;
    ans0=costflow();
    printf("%d %d\n",ans0,ans);
    return 0;
}
