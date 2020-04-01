#include<bits/stdc++.h>
using namespace std;
int i,i0,i1,n,k,ans;
long long dp[2005][5005];
struct node
{
    long long w,h;
}a[5005];
struct line
{
    long long k,b;
};
long long cal(line a,long long pos){return a.k*pos+a.b;}
double cross(line a,line b)
{
    return ((double)a.b-b.b)/(b.k-a.k);
}
bool cmp(node a,node b)
{
    return a.h<b.h;
}
deque<line>q;
map<long long,long long>mp;
int main()
{
    scanf("%d %d",&n,&k);
    long long sum=0;
    for(i=1;i<=n;i++)scanf("%lld %lld",&a[i].w,&a[i].h),mp[a[i].h]+=a[i].w,sum+=a[i].h*a[i].w;
    i=1;
    for(auto it:mp)
    {
        a[i].h=it.first;
        a[i].w=it.second;
        i++;
    }
    n=mp.size();
    sort(a+1,a+1+n,cmp);
    for(i=1;i<=k;i++)
    {
        long long sumw=0;
        while(!q.empty())q.pop_back();
        for(i0=1;i0<=n;i0++)
        {
            sumw+=a[i0].w;
            while(q.size()>1)
            {
                line x=q.back();
                q.pop_back();
                line y=q.back();
                if(cross(x,{a[i0].h,dp[i-1][i0-1]-(sumw-a[i0].w)*a[i0].h})<=cross(y,x))
                {
                    continue;
                }
                else
                {
                    q.push_back(x);
                    break;
                }
            }
            if(!(i==1&&i0!=1))q.push_back({a[i0].h,dp[i-1][i0-1]-(sumw-a[i0].w)*a[i0].h});
            while(q.size()>1)
            {
                line x=q.front();
                q.pop_front();
                line y=q.front();
                if(cal(x,sumw)<=cal(y,sumw))continue;
                else
                {
                    q.push_front(x);
                    break;
                }
            }
            dp[i][i0]=cal(q.front(),sumw);
        }
    }
    printf("%lld\n",sum-dp[k][n]);
    return 0;
}