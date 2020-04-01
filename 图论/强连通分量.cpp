#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int i,i0,n,m,T,dfn[maxn],low[maxn],deep,col[maxn],sum,cnt[maxn],out[maxn];
bool vis[maxn];
vector<int>mp[maxn];
stack<int>stk;
void dfs(int now)
{
    dfn[now]=low[now]=++deep;
    stk.push(now);
    vis[now]=1;
    for(auto i:mp[now])
    {
        if(!dfn[i])
        {
            dfs(i);
            low[now]=min(low[now],low[i]);
        }
        else if(vis[i])low[now]=min(low[now],low[i]);
    }
    if(dfn[now]==low[now])
    {
        sum++;
        while(vis[now])
        {
            col[stk.top()]=sum;
            vis[stk.top()]=0;
            cnt[sum]++;
            stk.pop();
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        sum=deep=0;
        for(i=1;i<=n;i++)mp[i].clear(),dfn[i]=0,cnt[i]=0,out[i]=0;
        while(m--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            mp[a].push_back(b);
        }
        for(i=1;i<=n;i++)if(!dfn[i])dfs(i);
        int ans=0;
        for(i=1;i<=n;i++)for(auto i0:mp[i])out[col[i]]+=(col[i]!=col[i0]);
        for(i=1;i<=sum;i++)if(!out[i]&&cnt[i]>1)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
