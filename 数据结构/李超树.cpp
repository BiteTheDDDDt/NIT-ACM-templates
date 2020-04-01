#define mid (l+r)/2
struct line
{
    long long k,b;
    bool flag;
}tree[400005];
long long cal(line a,long long pos){return a.k*pos+a.b;}
long long cross(line a,line b){return (a.b-b.b)/(b.k-a.k);}
//max
void c_tree(long long l,long long r,long long p,line k)
{
    if(!tree[p].flag)
    {
        tree[p]=k;
        if(l!=r)tree[p*2].flag=tree[p*2+1].flag=0;
    }
    else if(cal(k,l)>cal(tree[p],l)&&cal(k,r)>cal(tree[p],r))tree[p]=k;
    else if(cal(k,l)>cal(tree[p],l)||cal(k,r)>cal(tree[p],r))
    {
        if((cross(k,tree[p])<=mid)==(k.k>=tree[p].k))swap(k,tree[p]);
        if(cross(k,tree[p])<=mid)c_tree(l,mid,p*2,k);
        else c_tree(mid+1,r,p*2+1,k);
    }
}
long long q_tree(long long l,long long r,long long p,long long x)
{
    if(!tree[p].flag)return INT64_MIN;
    if(l==r)return cal(tree[p],x);
    else
    {
        long long ans=cal(tree[p],x);
        if(x<=mid)return max(ans,q_tree(l,mid,p*2,x));
        else return max(ans,q_tree(mid+1,r,p*2+1,x));
    }
}
//min and segment
void c_tree(int l,int r,int p,line k)
{
    if(k.l<=l&&r<=k.r)
    {
        if(!tree[p].flag)
        {
            tree[p]=k;
            if(l!=r)tree[p*2].flag=tree[p*2+1].flag=0;
        }
        else if(cal(k,l)<=cal(tree[p],l)&&cal(k,r)<=cal(tree[p],r))tree[p]=k;
        else if((cal(k,l)<=cal(tree[p],l))!=(cal(k,r)<=cal(tree[p],r)))
        {
            if((cross(k,tree[p])<=mid)!=(k.k>=tree[p].k))swap(k,tree[p]);
            if(cross(k,tree[p])<=mid)c_tree(l,mid,p*2,k);
            else c_tree(mid+1,r,p*2+1,k);
        }
    }
    else
    {
        int mid=(l+r)/2;
        if(k.l<=mid)c_tree(l,mid,p*2,k);
        if(mid<k.r)c_tree(mid+1,r,p*2+1,k);
    }
}
int q_tree(int l,int r,int p,int x)
{
    if(!tree[p].flag)return INT_MAX/2;
    if(l==r)return cal(tree[p],x);
    else
    {
        int ans=cal(tree[p],x);
        if(x<=mid)return min(ans,q_tree(l,mid,p*2,x));
        else return min(ans,q_tree(mid+1,r,p*2+1,x));
    }
}