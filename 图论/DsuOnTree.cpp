#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,col[MAXN],a[MAXN],sz[MAXN],son[MAXN],cnt[MAXN],bigson,max1;
long long ans[MAXN],sum;
vector<int>G[MAXN];
void init() {
    for(int i=1; i<=n; i++)G[i].clear(),cnt[i]=0,max1=0;
}
void initdfs(int now,int fa) {
    sz[now]=1;
    for(auto to:G[now]) {
        if(to==fa)continue;
        initdfs(to,now);
        sz[now]+=sz[to];
        if(sz[to]>sz[son[now]])son[now]=to;//big son or not
    }
}
void add(int now,int fa,int val) {
    //operation
    cnt[col[now]]+=val;
    if(cnt[col[now]]>max1)max1=cnt[col[now]],sum=col[now];
    else if(cnt[col[now]]==max1)sum+=col[now];


    for(auto &to:G[now]) {
        if(to==fa||to==bigson)continue;
        add(to,now,val);
    }
}
void dfs(int now,int fa,int op) {
    for(auto &to:G[now]) {
        if(to==fa)continue;
        if(to!=son[now])dfs(to,now,0);//if(not big son) clear the influence
    }
    if(son[now]) { //as to big son
        dfs(son[now],now,1);//t clear influence
        bigson=son[now];//get big son position
    }
    add(now,fa,1),bigson=0;//count all small son ans
    ans[now]=sum;//update
    if(op==0) { //delete influence from small son
        add(now,fa,-1);
        sum=0;
        max1=0;
    }
}
int main() {
    cin>>n;
    for(int i=1; i<=n; i++)cin>>col[i];
    for(int i=1; i<n; i++) {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    initdfs(1,-1);
    dfs(1,-1,0);
    for(int i=1; i<=n; i++)printf("%lld%c",ans[i],i==n?'\n':' ');
    return 0;
}
