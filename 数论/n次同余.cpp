#include<bits/stdc++.h>
using namespace std;
long long quick_mod(long long a,long long b,long long mod)
{
    long long ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
//快速幂
long long ex_gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0) 
    {
        x = 1, y = 0;
        return a;
    }
    else 
    {
        long long r = ex_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}
//扩展欧几里得算法
vector<long long>v;
bool g_text(long long g,long long p)
{
    for(long long i=0;i<v.size();i++)if(quick_mod(g,(p-1)/v[i],p)==1)return 0;
    return 1;
}
long long primitive_root(long long p)
{
    long long tmp=p-1;
    for(long long i=2;i<=tmp/i;i++)
    {
        if(tmp%i==0)
        {
            v.push_back(i);
            while(tmp%i==0)tmp/=i;
        }
    }
    if(tmp!=1)v.push_back(tmp);
    long long g=1;
    while(1)
    {
        if(g_text(g,p))return g;
        ++g;
    }
}
//求解原根
struct sa
{
    long long x;
    int id;
    bool operator<(const sa &b)const
    {
        if (x == b.x) return id < b.id;
        return x<b.x;
    }
}rec[100500];
//用rec存离散对数
long long discerte_log(long long x,long long n,long long m)
{
    int s=(int)(sqrt((double)m+0.5));
    while((long long)s*s<=m)s++;
    long long cur=1;
    sa tmp;
    for(int i=0;i<s;i++)
    {
        tmp.x=cur,tmp.id=i;
        rec[i]=tmp;
        cur=cur*x%m;
    }
    sort(rec,rec+s);
    //这里不能用map查找比较慢，采用排序二分就快了
    long long mul= quick_mod(cur, m - 2, m) % m;
    //这里有的方法是在下面的循环里求解快速幂，但本题是不行的  要在循环外面弄，保证时间
    cur=1; 
    for(long long i=0;i<s;i++)
    {
        long long more=n*cur%m;
        tmp.x=more,tmp.id=-1;
        int j=lower_bound(rec,rec+s,tmp)-rec;
        if(rec[j].x==more)return i*s+rec[j].id;
        cur=cur*mul%m;
    }
    return -1;
}
//求解离散对数
vector<long long>residue(long long p,long long n,long long a)
{
    vector<long long>ret;
    if(a==0)
    {
        ret.push_back(0);
        return ret;
    }
    long long g=primitive_root(p),m=discerte_log(g,a,p);
    if(m==-1)return ret;
    long long A=n,B=p-1,C=m,x,y,G=ex_gcd(A,B,x,y);
    if(C%G!=0)return ret;
    x=x*(C/G)%B;
    long long delta=B/G;
    for(int i=0;i<G;i++)
    {
        x=((x+delta)%B+B)%B;
        ret.push_back(quick_mod(g,x,p));
    }
    sort(ret.begin(),ret.end());
    ret.erase(unique(ret.begin(),ret.end()),ret.end());
    return ret;
}
//求解n次剩余 X^A MOD P =B
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long p,A,b;
        v.clear();
        scanf("%I64d%I64d%I64d",&p,&A,&b);
        vector<long long>ans;
        ans=residue(p,A,b);
        if(ans.empty()){
            puts("No Solution");
        }
        else {
            for(unsigned int i=0;i<ans.size();i++){
                printf("%I64d ",ans[i]);
            }
            puts("");
        }
    }
    return 0;
}