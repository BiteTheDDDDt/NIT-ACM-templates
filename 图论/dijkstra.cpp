#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int i,i0,n,m,r;
long long d[maxn];
bool vis[maxn];
struct edge
{
    int to;
    long long v;
    bool operator<(edge a)const{return a.v<v;}
};
vector<edge>mp[maxn];
priority_queue<edge>q;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(i==n)r=a;
        mp[i].push_back({d,a});
        for(int i0=1;i0*i0<=c;i0++)
        {
            if(c%i0==0)
            {
                if(i+i0<=n)mp[i].push_back({i+i0,a+b});
                if(i+c/i0<=n)mp[i].push_back({i+c/i0,a+b});
            }
        }
    }
    int s=1,t=n;
    for(i=1;i<=n;i++)d[i]=(long long)INT_MAX*(n+5);
    d[s]=0;
    q.push({s,d[s]});
    while(!q.empty())
    {
        int to=q.top().to;
        long long v=q.top().v;
        q.pop();
        if(!vis[to])
        {
            vis[to]=1;
            for(auto i:mp[to])
            {
                if(d[i.to]>v+i.v)
                {
                    d[i.to]=v+i.v;
                    q.push({i.to,d[i.to]});
                }
            }
        }
    }
    d[t]+=r;
    if(d[t]>=(long long)INT_MAX*(n+5))d[t]=-1;
    printf("%lld\n",d[t]);
    return 0;
}