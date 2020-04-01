#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,v[100005],dp[100005],ans[100005];
struct node
{
    int to,v;
};
vector<node>mp[100005];
int dfs(int now,int root)
{
    if(dp[now])return dp[now];
    int cnt=v[now];
    for(int i=0;i<mp[now].size();i++)
    {
        if(mp[now][i].to==root)continue;
        cnt=max(cnt,dfs(mp[now][i].to,now)+v[now]-mp[now][i].v);
    }
    return dp[now]=cnt;
}
void dfs0(int now,int root,int maxn1,int maxn2,int maxi1,int maxi2)
{
    if(maxn1<0)maxn1=0;
    if(maxn2<0)maxn2=0;
    maxn1+=v[now],maxn2+=v[now];
    if(maxi1==now)maxi1=maxi2,maxn1=maxn2;
    ans[now]=max(dp[now],maxn1);
    for(int i=0;i<mp[now].size();i++)
    {
        if(mp[now][i].to==root)continue;
        if(dp[mp[now][i].to]+v[now]-mp[now][i].v>maxn1)maxn2=maxn1,maxn1=dp[mp[now][i].to]+v[now]-mp[now][i].v,maxi1=mp[now][i].to;
        else if(dp[mp[now][i].to]+v[now]-mp[now][i].v>maxn2)maxn2=dp[mp[now][i].to]+v[now]-mp[now][i].v,maxi2=mp[now][i].to;
    }
    for(int i=0;i<mp[now].size();i++)
    {
        if(mp[now][i].to==root)continue;
        dfs0(mp[now][i].to,now,maxn1-mp[now][i].v,maxn2-mp[now][i].v,maxi1,maxi2);
    }
    return;
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
        dfs0(1,-1,0,0,0,0);
        for(i=1;i<=n;i++)
        {
            printf("%d",ans[i]);
            if(i==n)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
