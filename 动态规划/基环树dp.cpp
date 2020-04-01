#include<bits/stdc++.h>
using namespace std;
long long i,i0,n,m,v[1000005],pre[1000005],dp[1000005][2][2],ans;
vector<int>mp[1000005];
vector<pair<int,int> >q;
int fin(int x)
{
    int tmp=x,tmp2;
    while(pre[tmp]!=tmp)tmp=pre[tmp];
    while(x!=tmp)tmp2=pre[x],pre[x]=tmp,x=tmp2;
    return tmp;
}
void uni(int x,int y){if(fin(x)!=fin(y))pre[fin(y)]=fin(x);}
void dfs(int now,int ex,int root)
{
    dp[now][0][1]=dp[now][1][1]=v[now];
    for(auto i:mp[now])
    {
        dfs(i,ex,root);
        for(int i0=0;i0<2;i0++)
        {
            dp[now][i0][0]+=max(dp[i][i0][0],dp[i][i0][1]);
            dp[now][i0][1]+=dp[i][i0][0];
        }
    }
    if(ex==now)dp[now][1][0]=dp[now][0][1]=0;
}
int main()
{
    scanf("%lld",&n);
    ans=0;
    for(i=1;i<=n;i++)pre[i]=i;
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&v[i],&m);
        if(fin(m)==fin(i))q.push_back({i,m});
        else uni(m,i),mp[m].push_back(i);
    }
    for(i=0;i<q.size();i++)
    {
        dfs(q[i].first,q[i].second,q[i].first);
        ans+=max(dp[q[i].first][1][0],max(dp[q[i].first][0][0],dp[q[i].first][0][1]));
    }
    printf("%lld\n",ans);
    return 0;
}
