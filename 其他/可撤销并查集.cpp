struct DisjointSetUnion
{
    int fa[maxn*2],rank[maxn*2];
    stack<pair<int*,int>>stk;
    void init(){for(int i=1;i<=maxn;i++)fa[i]=i,rank[i]=0;}
    int find(int x){return (x^fa[x])?find(fa[x]):x;}
    void join(int x,int y)
    {
        x=find(x),y=find(y);
        if(rank[x]<=rank[y])
        {
            stk.push({fa+x,fa[x]}),fa[x]=y;
            if(rank[x]==rank[y])stk.push({rank+y,rank[y]}),rank[y]++;
        }
        else stk.push({fa+y,fa[y]}),fa[y]=x;
    }
    void undo(){*stk.top().first=stk.top().second,stk.pop();}
}DSU;