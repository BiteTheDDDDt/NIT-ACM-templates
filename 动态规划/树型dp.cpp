#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,dp[1005][2],ans;
vector<int>mp[1005];
void dfs(int now,int root)
{
    for(int i:mp[now])
    {
        if(i==root)continue;
        dfs(i,now);
        if(dp[i][0]+1>dp[now][0])dp[now][1]=dp[now][0],dp[now][0]=dp[i][0]+1;
        else if(dp[i][0]+1>dp[now][1])dp[now][1]=dp[i][0]+1;
    }
}
void solve(int now,int root);
void change_root(int nowa,int nowb)
{
    int tmpa[2]={dp[nowa][0],dp[nowa][1]},tmpb[2]={dp[nowb][0],dp[nowb][1]};
    int son=dp[nowa][dp[nowb][0]+1==dp[nowa][0]]+1;
    if(son>dp[nowb][0])dp[nowb][1]=dp[nowb][0],dp[nowb][0]=son;
    else if(son>dp[nowb][1])dp[nowb][1]=son;
    solve(nowb,nowa);
    dp[nowb][0]=tmpb[0],dp[nowb][1]=tmpb[1];
}
void solve(int now,int root)
{
    ans=max(ans,dp[now][0]);
    for(auto i:mp[now])
    {
        if(i==root)continue;
        change_root(now,i);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)mp[i].clear();
        ans=0;
        for(i=1;i<n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        dfs(1,-1);
        solve(1,-1);
        printf("%d\n",n*2-ans-2);
    }
    return 0;
}
