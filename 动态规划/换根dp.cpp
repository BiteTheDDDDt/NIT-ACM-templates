#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,v[100005],dp[100005],ans[100005];
struct node{int to,d;};
vector<node>mp[100005];
void dfs(int now,int root)
{
    dp[now]=v[now];
    for(auto it:mp[now])
    {
        if(it.to==root)continue;
        dfs(it.to,now);
        dp[now]=max(dp[now],dp[it.to]+v[now]-it.d);
    }
}
void solve(int now,int root);
void change_root(int nowa,int nowb,int d)
{
    int tmpa=dp[nowa],tmpb=dp[nowb];
    dp[nowa]=v[nowa];
    for(auto it:mp[nowa])
    {
        if(it.to==nowb)continue;
        dp[nowa]=max(dp[nowa],dp[it.to]+v[nowa]-it.d);
    }
    dp[nowb]=max(dp[nowb],dp[nowa]+v[nowb]-d);
    solve(nowb,nowa);
    dp[nowa]=tmpa,dp[nowb]=tmpb;
}
void solve(int now,int root)
{
    ans[now]=dp[now];
    for(int i=0;i<mp[now].size();i++)
    {
        if(mp[now][i].to==root)continue;
        change_root(now,mp[now][i].to,mp[now][i].d);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)mp[i].clear(),dp[i]=0;
        for(i=1;i<=n;i++)scanf("%d",&v[i]);
        for(i=1;i<n;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            mp[a].push_back({b,c});
            mp[b].push_back({a,c});
        }
        dfs(1,-1);
        solve(1,-1);
        for(i=1;i<=n;i++)
        {
            printf("%d",ans[i]);
            if(i==n)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
