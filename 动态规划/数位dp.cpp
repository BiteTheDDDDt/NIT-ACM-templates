#include <bits/stdc++.h>
using namespace std;
long long i,n,m,dp[20][300],a[20],T;
long long dfs(int len,bool maxi,int sum)
{
    if(dp[len][sum]!=-1&&maxi==0)return dp[len][sum];
    long long cnt=0;
    if(!len)return sum%10==0;
    int maxn=maxi?a[len]:9;
    for(int i=0;i<=maxn;i++)cnt+=dfs(len-1,maxi&&i==a[len],sum+i);
    return maxi?cnt:dp[len][sum]=cnt;
}
long long div(long long tmp)
{
    memset(a,0,sizeof(a));
    int p=0;
    while(tmp)a[++p]=tmp%10,tmp/=10;
    return dfs(p,1,0);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld %lld",&n,&m);
        printf("Case #%lld: ",i);
        if(n)printf("%lld\n",div(m)-div(n-1));
        else printf("%lld\n",div(m));
    }
    return 0;
}
