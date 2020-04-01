#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)/2)
const int maxn=300005;
int i,i0,n,m,a[maxn];
struct node
{
    long long sum,lm,rm,mx;
    friend node operator+(node a,node b)
    {
        node c;
        c.sum=a.sum+b.sum;
        c.lm=max(a.lm,a.sum+b.lm),c.rm=max(b.rm,b.sum+a.rm);
        c.mx=max(a.mx,b.mx),c.mx=max(c.mx,a.rm+b.lm);
        return c;
    }
}tree[maxn*4];
void b_tree(int l,int r,int p)
{
    if(l==r)tree[p].lm=tree[p].rm=tree[p].mx=max(0,a[l]),tree[p].sum=a[l];
    else
    {
        b_tree(l,mid,p*2),b_tree(mid+1,r,p*2+1);
        tree[p]=tree[p*2]+tree[p*2+1];
    }
}
void c_tree(int l,int r,int p,int x,int y)
{
    if(l==r)tree[p].lm=tree[p].rm=tree[p].mx=max(0,y),tree[p].sum=y;
    else
    {
        if(x<=mid)c_tree(l,mid,p*2,x,y);
        else c_tree(mid+1,r,p*2+1,x,y);
        tree[p]=tree[p*2]+tree[p*2+1];
    }
}
node q_tree(int l,int r,int p,int a,int b)
{
    if(l==a&&r==b)return tree[p];
    else
    {
        if(b<=mid)return q_tree(l,mid,p*2,a,b);
        else if(a>=mid+1)return q_tree(mid+1,r,p*2+1,a,b);
        else return q_tree(l,mid,p*2,a,mid)+q_tree(mid+1,r,p*2+1,mid+1,b);
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    b_tree(1,n,1);
    while(m--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%lld\n",q_tree(1,n,1,l,r).mx);
    }
    return 0;
}
