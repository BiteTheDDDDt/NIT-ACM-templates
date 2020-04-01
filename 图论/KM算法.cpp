#include<bits/stdc++.h>
using namespace std;

const int maxn=305;
const int inf=1e9;

int n,minz;
int wx[maxn],wy[maxn],match[maxn];
int mp[maxn][maxn],slack[maxn],pre[maxn];
bool viy[maxn];

void Bfs(int k)
{
	int py=0,px,yy=0,delta;
	match[py]=k;
	for(int i=0;i<=n;i++)pre[i]=0,slack[i]=inf;
	do
    {
		px=match[py],delta=inf,viy[py]=1;
		for(int i=1; i<=n; ++i)
        {
            if(!viy[i])
            {
                if(wx[px]+wy[i]-mp[px][i]<slack[i])slack[i]=wx[px]+wy[i]-mp[px][i],pre[i]=py;
                if(slack[i]<delta)delta=slack[i],yy=i;
            }
        }
		for(int i=0; i<=n; ++i)
        {
            if(viy[i])wx[match[i]]-=delta,wy[i]+=delta;
			else slack[i]-=delta;
        }
		py=yy;
	}while(match[py]!=0);
	while(py)match[py]=match[pre[py]],py=pre[py];
}

int Km()
{
	for(int i=1; i<=n; ++i)
    {
		wx[i]=0,wy[i]=0,match[i]=0;
		for(int j=1; j<=n; ++j)wx[i]=max(wx[i],mp[i][j]);
	}
	for(int i=1;i<=n;++i)memset(viy,0,sizeof(viy)),Bfs(i);
	int Ans=0;
	for(int i=1;i<=n;++i)Ans+=wx[match[i]]+wy[i];
	return Ans;
}

int main()
{
	while(~scanf("%d",&n))
    {
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)scanf("%d",&mp[i][j]);
		printf("%d\n",Km());
	}
	return 0;
}
