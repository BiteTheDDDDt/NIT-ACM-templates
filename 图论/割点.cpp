#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
using namespace std;
int n,m,len=0,id=0,ans=0;
int last[maxn],low[maxn],dfn[maxn];
bool bz[maxn];
vector<int>mp[maxn];
void dfs(int x,int root)
{
	int tot=0;
	low[x]=dfn[x]=++id;
    for(int y:mp[x])
	{
		if(!dfn[y])
		{
			dfs(y,root);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]&&x!=root) bz[x]=true;
			if(x==root) tot++;
		}
		low[x]=min(low[x],dfn[y]);
	}
	if(x==root&&tot>=2) bz[root]=true;
}
int main()
{
	int x,y,t;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		mp[x].push_back(y);
        mp[y].push_back(x);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,i);
    for(int i=1;i<=n;i++)if(bz[i])printf("%d\n",i);
}