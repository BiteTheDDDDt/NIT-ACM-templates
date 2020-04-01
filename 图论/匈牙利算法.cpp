#include<bits/stdc++.h>
int i,i0,m,n,T,mp[505][505],a,b,girls[505],ans,vis[505];
bool findway(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(mp[i][x]&&(!vis[i]))
        {
            vis[i]=1;
            if((!girls[i])||findway(girls[i]))
            {
                girls[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d",&T)&&T)
    {
        scanf("%d %d",&n,&m);
        ans=0;
        memset(mp,0,sizeof(mp));
        memset(girls,0,sizeof(girls));
        while(T--)
        {
            scanf("%d %d",&a,&b);
            mp[a][b]=1;
        }
        for(i=1;i<=m;i++)
        {
            memset(vis,0,sizeof(vis));
            ans+=findway(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}