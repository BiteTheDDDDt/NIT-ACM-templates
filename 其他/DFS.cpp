#include<cstdio>
#include<cstring>
int i,i0,n,m,T,a[60][60],vis[60][60],x1,y1,x2,y2,flag,dir[4][2]={1,0,-1,0,0,1,0,-1};
bool chk(int x,int y)
{
    if(x<1||x>n)return 0;
    if(y<1||y>m)return 0;
    if(a[x][y]=='*')return 0;
    if(vis[x][y])return 0;
    return 1;
}
void dfs(int x,int y)
{
    if(x==x2&&y==y2)flag=1;
    if(flag)return;
    vis[x][y]=1;
    for(int i=0;i<4;i++)if(chk(x+dir[i][0],y+dir[i][1]))dfs(x+dir[i][0],y+dir[i][1]);
}
int main()
{
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            memset(vis,0,sizeof(vis));
            scanf("%d %d",&n,&m);
            flag=0;
            for(i=1;i<=n;i++)
            {
                for(i0=1;i0<=m;i0++)
                {
                    scanf(" %c",&a[i][i0]);
                    if(a[i][i0]=='S')x1=i,y1=i0;
                    if(a[i][i0]=='E')x2=i,y2=i0;
                }
            }
            dfs(x1,y1);
            if(flag)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
