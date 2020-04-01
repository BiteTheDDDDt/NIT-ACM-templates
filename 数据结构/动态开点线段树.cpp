#include<bits/stdc++.h>
using namespace std;
const int maxn=5000000;
#define mid (l+r)/2
long long cnt=0;
struct node
{
    long long lson,rson,v,sum;
}tree[maxn+5];
long long new_node()
{
    long long p=++cnt;
    tree[p].lson=tree[p].rson=0;
    tree[p].v=0,tree[p].sum=0;
    return p;
}
void p_tree(long long p)
{
    if(tree[tree[p].lson].v==tree[tree[p].rson].v)tree[p].v=tree[tree[p].lson].v;
    else tree[p].v=-1;
    tree[p].sum=tree[tree[p].lson].sum+tree[tree[p].rson].sum;
}
void new_son(int l,int r,int p){tree[p].lson=new_node(),tree[p].rson=new_node();}
void c_tree(long long l,long long r,long long p,long long L,long long R,long long x)
{
    if(l==L&&r==R)tree[p].v=x,tree[p].sum=(R-L+1)*x;
    else
    {
        if(!tree[p].lson)new_son(l,r,p);
        if(L<=mid)c_tree(l,mid,tree[p].lson,L,min(R,mid),x);
        if(R>=mid+1)c_tree(mid+1,r,tree[p].rson,max(mid+1,L),R,x);
        p_tree(p);
    }
}
void c0_tree(long long l,long long r,long long p,long long L,long long R,long long x)
{
    if(tree[p].sum==0)return;
    if(l==L&&r==R)
    {
        if(tree[p].v!=-1)
        {
            tree[p].v/=x,tree[p].sum=(R-L+1)*tree[p].v;
        }
        else
        {
            c0_tree(l,mid,tree[p].lson,l,mid,x),c0_tree(mid+1,r,tree[p].rson,mid+1,r,x);
            p_tree(p);
        }
    }
    else
    {
        if(!tree[p].lson)new_son(l,r,p);
        if(tree[p].v!=-1)
        {
            tree[tree[p].lson].v=tree[p].v,tree[tree[p].rson].v=tree[p].v;
            tree[tree[p].lson].sum=(mid-l+1)*tree[p].v,tree[tree[p].rson].sum=(r-mid)*tree[p].v;
        }
        if(L<=mid)c0_tree(l,mid,tree[p].lson,L,min(R,mid),x);
        if(R>=mid+1)c0_tree(mid+1,r,tree[p].rson,max(mid+1,L),R,x);
        p_tree(p);
    }
}
long long q_tree(long long l,long long r,long long p,long long L,long long R)
{
    if(tree[p].sum==0)return 0;
    if(tree[p].v!=-1)return (R-L+1)*tree[p].v;
    if(l==L&&r==R)return tree[p].sum;
    else
    {
        long long res=0;
        if(L<=mid&&tree[p].lson)res+=q_tree(l,mid,tree[p].lson,L,min(R,mid));
        if(R>=mid+1&&tree[p].rson)res+=q_tree(mid+1,r,tree[p].rson,max(mid+1,L),R);
        return res;
    }
}
int main()
{
    long long root=new_node(),n,m;
    scanf("%lld %lld",&n,&m);
    for(long long l=1,r=1;l<=n;l=r+1,r=(l<=n)?n/(n/l):0)c_tree(1,n,root,l,r,n/l);
    while(m--)
    {
        long long op,l,r,x;
        scanf("%lld %lld %lld",&op,&l,&r);
        if(op==1)
        {
            scanf("%lld",&x);
            if(x!=1)c0_tree(1,n,root,l,r,x);
        }
        else printf("%lld\n",q_tree(1,n,root,l,r));    
    }
    return 0;
}