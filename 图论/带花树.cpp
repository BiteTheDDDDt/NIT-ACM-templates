#include<bits/stdc++.h>
#define T 1205
using namespace std;
int head[T],lst[T*T*2],nxt[T*T];
int tot,n,m;
void ins(int x,int y)
{
    lst[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
int ma[T],st[T],pr[T],fa[T],q[T],v[T];
int ans,TI,u,t;
int lca(int x,int y)
{
    for(TI++;;swap(x,y))if(x)
    {
        if(v[x]==TI)return x;
        v[x]=TI;
        x=fa[pr[ma[x]]];
    }
}
void up(int x,int y,int f)
{
    while(fa[x]!=f)
    {
        pr[x]=y;
        if(st[ma[x]]>0)st[q[++t]=ma[x]]=0;
        if(fa[x]==x)fa[x]=f;
        if(fa[ma[x]]==ma[x])fa[ma[x]]=f;
        x=pr[y=ma[x]];
    }
}
int match(int x)
{
    for(int i=1;i<=n;i++)fa[i]=i,st[i]=-1;
    st[q[t=1]=x]=0;
    for(int l=1;l<=t;l++)for(int i=head[q[l]];i;i=nxt[i])if(st[lst[i]]<0)
    {
        st[lst[i]]=1;
        pr[lst[i]]=q[l];
        if(!ma[lst[i]])
        {
            for(int j=q[l],k=lst[i];j;j=pr[k=u])
            {
                u=ma[j];
                ma[j]=k;
                ma[k]=j;
            }
            return 1;
        }
        st[q[++t]=ma[lst[i]]]=0;
    }
    else if(fa[lst[i]]!=fa[q[l]]&&!st[lst[i]])
    {
        int f=lca(lst[i],q[l]);
        up(q[l],lst[i],f);
        up(lst[i],q[l],f);
        for(int j=1;j<=n;j++)fa[j]=fa[fa[j]];
    }
    return 0;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        TI=tot=0;
        memset(head,0,sizeof(head));
        memset(ma,0,sizeof(ma));
        memset(v,0,sizeof(v));
        scanf("%d %d",&n,&m);
        ans=-n;
        for(int i=1;i<=n;i++)
        {
            ins(i,i+n),ins(i+n,i);
            int num,tmp;
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&tmp);
                tmp+=2*n;
                ins(tmp,i),ins(i,tmp);
                ins(tmp,i+n),ins(i+n,tmp);
            }
        }
        n=2*n+m;
        for(int i=1;i<=n;i++)ans+=!ma[i]&&match(i);
        printf("%d\n",ans);
    }
    return 0;
}
