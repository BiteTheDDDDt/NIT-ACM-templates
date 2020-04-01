#include<bits/stdc++.h>
using namespace std;
const int bace[5]={2,3,7,61,24251};
long long qmul(long long x,long long y,long long mod){return (x*y-(long long)((long double)x/mod*y)*mod+mod)%mod;}
long long qpow(long long a,long long b,long long mod){long long r=1,t=a; while(b){if(b&1)r=qmul(r,t,mod);b>>=1;t=qmul(t,t,mod);}return r;}
bool millerrabin(long long x)
{
    if(x==46856248255981ll||x<2)return false;
    if(x==2||x==3||x==7||x==61||x==24251)return true;
    long long ba=x-1,r;
    int ti=0,j;
    while(!(ba&1))ba>>=1,++ti;
    for(int i=0;i<=1;i++)
    {
        r=qpow(bace[i],ba,x);
        if(r==1||r==x-1)continue;
        for(j=1;j<=ti;++j)
        {
            r=qmul(r,r,x);
            if(r==x-1)break;
        }
        if(j>ti)return false;
    }
    return true;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long pollardpho(long long n,int c)
{
    long long x,y,d;
    int i=1,k=2;
    y=x=rng()%(n-1)+1;
    while(++i)
    {
        x=(qmul(x,x,n)+c)%n;
        d=__gcd(y-x,n);
        if(d>1&&d<n)return d;
        if(x==y)return n;
        if(i==k)y=x,k<<=1;
    }
}
vector<long long>v0;
void fin(long long x,int cnt)
{
    if(x==1)return;
    if(millerrabin(x))
    {
        v0.push_back(x);
        return;
    }
    long long p=x;
    while(p==x)p=pollardpho(x,cnt--);
    fin(p,cnt),fin(x/p,cnt);
}
int main()
{
    long long n,T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        v0.clear();
        if(n==1)v0.push_back(1);
        fin(n,120);
        sort(v0.begin(),v0.end());
        for(int i=0;i<v0.size();i++)printf("%d%c",v0[i],i==v0.size()-1?'\n':' ');
    }
    return 0;
}