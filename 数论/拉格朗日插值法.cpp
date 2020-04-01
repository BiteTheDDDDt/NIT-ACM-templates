#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long qpow(long long a,long long b){long long r=1,t=a; while(b){if(b&1)r=(r*t)%mod;b>>=1;t=(t*t)%mod;}return r;}
namespace polysum
{
    //先init前M项,然后计算
    const int D=1000005;
    long long a[D],f[D],g[D],p[D],p1[D],p2[D],b[D],h[D][2],C[D];
    long long calcn(int d,long long *a,long long n)
    {
        if (n<=d) return a[n];
        p1[0]=p2[0]=1;
        long long ans=0;
        for(int i=0;i<=d;i++)p1[i+1]=p1[i]*(n-i+mod)%mod,p2[i+1]=p2[i]*(n-d+i+mod)%mod;
        for(int i=0;i<=d;i++)
        {
            long long t=g[i]*g[d-i]%mod*p1[i]%mod*p2[d-i]%mod*a[i]%mod;
            if ((d-i)&1)ans=(ans-t+mod)%mod;
            else ans=(ans+t)%mod;
        }
        return ans;
    }
    void init(int M)
    {
        f[0]=f[1]=g[0]=g[1]=1;
        for(int i=2;i<=M+4;i++)f[i]=f[i-1]*i%mod;
        g[M+4]=qpow(f[M+4],mod-2);
        for(int i=M+3;i>=2;i--)g[i]=g[i+1]*(i+1)%mod;
    }
    long long polysum(long long n,long long *a,long long m)
    { // a[0].. a[m] \sum_{i=0}^{n-1} a[i]
        a[m+1]=calcn(m,a,m+1);
        for(int i=1;i<=m+1;i++)a[i]=(a[i-1]+a[i])%mod;
        return calcn(m+1,a,n-1);
    }
    long long qpolysum(long long R,long long n,long long *a,long long m)
    { // a[0].. a[m] \sum_{i=0}^{n-1} a[i]*R^i
        if(R==1)return polysum(n,a,m);
        a[m+1]=calcn(m,a,m+1);
        long long r=qpow(R,mod-2),p3=0,p4=0,c,ans;
        h[0][0]=0,h[0][1]=1;
        for(int i=1;i<=m+1;i++)h[i][0]=(h[i-1][0]+a[i-1])*r%mod,h[i][1]=h[i-1][1]*r%mod;
        for(int i=0;i<=m+1;i++)
        {
            long long t=g[i]*g[m+1-i]%mod;
            if (i&1) p3=((p3-h[i][0]*t)%mod+mod)%mod,p4=((p4-h[i][1]*t)%mod+mod)%mod;
            else p3=(p3+h[i][0]*t)%mod,p4=(p4+h[i][1]*t)%mod;
        }
        c=qpow(p4,mod-2)*(mod-p3)%mod;
        for(int i=0;i<=m+1;i++)h[i][0]=(h[i][0]+h[i][1]*c)%mod,C[i]=h[i][0];
        ans=(calcn(m,C,n)*qpow(R,n)-c)%mod;
        if(ans<0)ans+=mod;
        return ans;
    }
}
long long a[1000005];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<=k;i++)a[i]=qpow(i,k);
    polysum::init(k);
    if(k==0)printf("%d\n",n);
    else printf("%lld\n",polysum::polysum(n+1,a,k));
    return 0;
}