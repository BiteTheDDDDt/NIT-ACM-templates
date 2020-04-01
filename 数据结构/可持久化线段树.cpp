#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,cnt,root[100005],head[100005];
struct node
{
    int l,r,sum;
}tree[2100005];
#define mid (l+r)/2
void build_tree(int l,int r,int &p)
{
    p=cnt++;
    if(l!=r)build_tree(l,mid,tree[p].l),build_tree(mid+1,r,tree[p].r);
    tree[p].sum=0;
}
void c_tree(int l,int r,int &p,int old,int a,int v)
{
    p=cnt++,tree[p]=tree[old];
    if(l==r)
    {
        tree[p].sum+=v;
        return;
    }
    if(a<=mid)c_tree(l,mid,tree[p].l,tree[old].l,a,v);
    else c_tree(mid+1,r,tree[p].r,tree[old].r,a,v);
    tree[p].sum=tree[tree[p].l].sum+tree[tree[p].r].sum;
}
int q_tree(int l,int r,int p,int a,int b)
{
    if(l==a&&r==b)return tree[p].sum;
    if(a>=mid+1)return q_tree(mid+1,r,tree[p].r,a,b);
    else if(b<=mid) return q_tree(l,mid,tree[p].l,a,b);
    else return q_tree(mid+1,r,tree[p].r,mid+1,b)+q_tree(l,mid,tree[p].l,a,mid);
}
struct point
{
    int num,i;
}a[100005];
bool cmp(point a,point b){return a.num<b.num;}
vector<int>v;
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        printf("Case %d:\n",cas);
        cnt=0,v.clear();
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)scanf("%d",&a[i].num),a[i].i=i,v.push_back(a[i].num);
        sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
        sort(a+1,a+1+n,cmp);
        build_tree(1,n,root[0]);
        for(i=1;i<=n;i++)
        {
            a[i].num=lower_bound(v.begin(),v.end(),a[i].num)-v.begin()+1;
            c_tree(1,n,root[i],root[i-1],a[i].i,1);
            head[a[i].num]=i;
        }
        while(m--)
        {
            int l,r,num;
            scanf("%d %d %d",&l,&r,&num);
            num=upper_bound(v.begin(),v.end(),num)-v.begin();
            printf("%d\n",q_tree(1,n,root[head[num]],l+1,r+1));
        }
    }
    return 0;
}
