//仅可用区间修改区间查询
int sum1[n],sum2[n],n;
void add(int p,int x){for(int i=p;i<=n;i+=i&-i)sum1[i]+=x,sum2[i]+=x*p;}
int ask(int p)
{
    int res=0;
    for(int i=p;i;i-=i&-i)res+=(p+1)*sum1[i]-sum2[i];
    return res;
}
void range_add(int l,int r,int x){add(l,x),add(r+1,-x);}
int range_ask(int l,int r){return ask(r)-ask(l-1);}

//单点修改 区间查询
int sum[n],n;
void add(int p, int x){while(p<=n)sum[p]+=x,p+=p&-p;}
int ask(int p)
{
    int res=0;
    while(p)res+=sum[p],p-=p&-p;
    return res;
}
int range_ask(int l, int r){return ask(r)-ask(l-1);}

void add(int x, int y, int z){ 
    int memo_y = y;
    while(x <= n){
        y = memo_y;
        while(y <= m)
            tree[x][y] += z,tree[x][y]%=mod, y += y & -y;
        x += x & -x;
    }
}
//区间修改 单点查询
void range_add(int xa, int ya, int xb, int yb, int z){//左上点和右下点
    add(xa, ya, z);
    add(xa, yb + 1, -z);
    add(xb + 1, ya, -z);
    add(xb + 1, yb + 1, z);
}
long long ask(int x, int y){
    int res = 0, memo_y = y;
    while(x){
        y = memo_y;
        while(y)
            res += tree[x][y],res%=mod, y -= y & -y;
        x -= x & -x;
    }
    res+=mod,res%=mod;
    return res;
}
