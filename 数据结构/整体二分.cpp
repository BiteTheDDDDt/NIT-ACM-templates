#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,ans[100005],bit[100005],f,bac[100005];
struct node
{
    int num,i,l,r,tpe;
}tmp,tmp0;
int lowbit(int t){return t&(-t);}
int sum(int i)
{
    int s=0;
    while(i>0)s+=bit[i],i-=lowbit(i);
    return s;
}
void add(int i,int x){while(i<=n+1)bit[i]+=x,i+=lowbit(i);}
queue<node>q[35][2];
void all_binary(int l,int r,int dep,bool f)
{
    if(q[dep][f].empty())return;
    if(l==r)
    {
        while(!q[dep][f].empty())
        {
            tmp=q[dep][f].front(),q[dep][f].pop();
            if(tmp.tpe==1)ans[tmp.i]=max(ans[tmp.i],min(tmp.r-tmp.l+1-tmp.num,l));
        }
        return;
    }
    int mid=(l+r+1)/2,tcnt;
    while(!q[dep][f].empty())
    {
        tmp=q[dep][f].front(),q[dep][f].pop();
        if(tmp.tpe==1)
        {
            tcnt=sum(tmp.r)-sum(tmp.l-1);
            if(tmp.r-tmp.l+1-tcnt-tmp.num<mid)q[dep+1][0].push(tmp);
            else tmp.num+=tcnt,q[dep+1][1].push(tmp);
        }
        if(tmp.tpe==2)
        {
            if(tmp.num<mid)
            {
                add(tmp.i,1);
                q[dep+1][0].push(tmp);
            }
            else
            {
                q[dep+1][1].push(tmp);
            }
        }
        if(tmp.tpe==3)
        {
            if(tmp.num<mid)
            {
                add(tmp.i,-1);
                q[dep+1][0].push(tmp);
            }
            else
            {
                q[dep+1][1].push(tmp);
            }
        }
    }
    all_binary(l,mid-1,dep+1,0);
    all_binary(mid,r,dep+1,1);
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(ans,-1,sizeof(ans));
        tmp.tpe=2;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&bac[i]);
            tmp.num=bac[i],tmp.i=i;
            q[0][0].push(tmp);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&tmp.tpe);
            if(tmp.tpe==1)scanf("%d %d",&tmp.l,&tmp.r),tmp.num=0,tmp.i=i,q[0][0].push(tmp);
            if(tmp.tpe==2)
            {
                scanf("%d %d",&tmp.i,&tmp.num);
                tmp0.tpe=3,tmp0.i=tmp.i,tmp0.num=bac[tmp.i];
                q[0][0].push(tmp0);
                q[0][0].push(tmp);
                bac[tmp.i]=tmp.num;
            }
        }
        tmp.tpe=3;
        for(i=1;i<=n;i++)
        {
            tmp.num=bac[i],tmp.i=i;
            q[0][0].push(tmp);
        }
        all_binary(1,n,0,0);
        for(i=0;i<m;i++)if(ans[i]!=-1)printf("%d\n",ans[i]);
    }
    return 0;
}
