#include<bits/stdc++.h>
using namespace std;
int i,n,m,T,a[50005],ans0[200005],bsize,cnt[1000005],p,p0,pl,pr,tim,ans,timp;
#define bel(x) ((x - 1) / bsize + 1)
struct node{int num,pos,i;}timer[50005];
struct query
{
    int l,r,i,p;
    bool operator < (const query &b) const
    {
        if(bel(l) != bel(b.l)) return l < b.l;
        if(bel(r) != bel(b.r)) return r < b.r;
        return i<b.i;
    }
}q[200005];
void change_time(int ntim)
{
    if(tim>ntim)
    {
        timp--;
        while(timp>=0&&timer[timp].i>ntim)
        {
            if(timer[timp].pos<=pr&&timer[timp].pos>=pl)
            {
                cnt[a[timer[timp].pos]]--;
                if(!cnt[a[timer[timp].pos]])ans--;
                swap(a[timer[timp].pos],timer[timp].num);
                if(!cnt[a[timer[timp].pos]])ans++;
                cnt[a[timer[timp].pos]]++;
            }
            else swap(a[timer[timp].pos],timer[timp].num);
            timp--;
        }
        timp++;
    }
    if(tim<ntim)
    {
        while(timp<p0&&timer[timp].i<ntim)
        {
            if(timer[timp].pos<=pr&&timer[timp].pos>=pl)
            {
                cnt[a[timer[timp].pos]]--;
                if(!cnt[a[timer[timp].pos]])ans--;
                swap(a[timer[timp].pos],timer[timp].num);
                if(!cnt[a[timer[timp].pos]])ans++;
                cnt[a[timer[timp].pos]]++;
            }
            else swap(a[timer[timp].pos],timer[timp].num);
            timp++;
        }
    }
    tim=ntim;
}
int main()
{

    while(scanf("%d",&n)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        bsize=max(1,(int)pow(n,2.0/3));
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=1,p0=p=0;i<=m;i++)
        {
            int op;
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d %d",&q[p].l,&q[p].r);
                q[p].i=i;
                q[p].p=p;
                p++;
            }
            if(op==2)
            {
                scanf("%d %d",&timer[p0].pos,&timer[p0].num);
                timer[p0].i=i;
                p0++;
            }
        }
        sort(q,q+p);
        pl=1,pr=1,ans=1,tim=1,timp=0;
        cnt[a[1]]++;
        for(i=0;i<p;i++)
        {
            change_time(q[i].i);
            while(pl<q[i].l)
            {
                cnt[a[pl]]--;
                if(!cnt[a[pl]])ans--;
                pl++;
            }
            while(pl>q[i].l)
            {
                pl--;
                if(!cnt[a[pl]])ans++;
                cnt[a[pl]]++;
            }
            while(pr<q[i].r)
            {
                pr++;
                if(!cnt[a[pr]])ans++;
                cnt[a[pr]]++;
            }
            while(pr>q[i].r)
            {
                cnt[a[pr]]--;
                if(!cnt[a[pr]])ans--;
                pr--;
            }
            ans0[q[i].p]=ans;
        }
        for(i=0;i<p;i++)printf("%d\n",ans0[i]);
    }
    return 0;
}
