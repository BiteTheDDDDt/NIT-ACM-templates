#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int i,i0,n,m,dp[1005];
void add_dp(int x,int cnt,int n)
{
    for(int i=n;i>=(cnt+1)*x;i--)dp[i]-=dp[i-(cnt+1)*x],dp[i]+=mod,dp[i]%=mod;
    for(int i=x;i<=n;i++)dp[i]+=dp[i-x],dp[i]%=mod;
}
void del_dp(int x,int cnt,int n)
{
    for(int i=n;i>=x;i--)dp[i]-=dp[i-x],dp[i]+=mod,dp[i]%=mod;
    for(int i=(cnt+1)*x;i<=n;i++)dp[i]+=dp[i-(cnt+1)*x],dp[i]%=mod;
}
int main()
{
    scanf("%d",&n);
    dp[0]=1,m=0;
    while(n--)
    {
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);//添加价值为x的y个物品 在1000范围内
        if(op==1)add_dp(x,y,1000);
        if(op==2)del_dp(x,y,1000);
        for(i=0;i<=1000;i++)m^=dp[i];
    }
    printf("%d\n",m);
    return 0;
}
