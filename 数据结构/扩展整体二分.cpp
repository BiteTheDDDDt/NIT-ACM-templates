#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)/2)
const int maxn=100000;
int ans[3*maxn+5],tree[maxn*4+5];
struct node
{
    int tpe,id;//tpe为1表示插入，2表示查询,3表示删除。id表示编号，来确保输出答案时有序。
    int x,y,num;//num表示权值，x、y表示坐标。
    int lx,rx,ly,ry;//表示查询范围。
};
void c_tree(int l,int r,int p,int x,int num)
{
    if(l==r)
    {
        tree[p]=max(tree[p],num);
        if(!num)tree[p]=0;
    }
    else
    {
        if(x<=mid)c_tree(l,mid,p*2,x,num);
        else c_tree(mid+1,r,p*2+1,x,num);
        tree[p]=max(tree[p*2],tree[p*2+1]);
    }
}
int q_tree(int l,int r,int p,int L,int R)
{
    if(l==L&&r==R)return tree[p];
    else
    {
        if(R<=mid)return q_tree(l,mid,p*2,L,R);
        else if(L>mid)return q_tree(mid+1,r,p*2+1,L,R);
        else return max(q_tree(l,mid,p*2,L,mid),q_tree(mid+1,r,p*2+1,mid+1,R));
    }
}
queue<node>q[25][2];
void all_binary(int l,int r,int dep,bool f)
{
    if(q[dep][f].empty())return;
    while(!q[dep][f].empty())
    {
        node tmp=q[dep][f].front();
        q[dep][f].pop();
        if(tmp.tpe==1)
        {
            c_tree(1,maxn,1,tmp.x,tmp.num);
            if(l!=r)
            {
                if(tmp.y<=mid)q[dep+1][0].push(tmp);
                else q[dep+1][1].push(tmp);
            }
        }
        if(tmp.tpe==2)
        {
            if(tmp.ly==l&&tmp.ry==r)ans[tmp.id]=max(ans[tmp.id],q_tree(1,maxn,1,tmp.lx,tmp.rx));
            else
            {
                if(l!=r)
                {
                    if(tmp.ly<=mid)
                    {
                        node tmp0=tmp;
                        tmp0.ry=min(tmp0.ry,mid);
                        q[dep+1][0].push(tmp0);
                    }
                    if(tmp.ry>mid)
                    {
                        node tmp0=tmp;
                        tmp0.ly=max(tmp0.ly,mid+1);
                        q[dep+1][1].push(tmp0);
                    }
                }
            }
        }
        if(tmp.tpe==3)
        {
            c_tree(1,maxn,1,tmp.x,0);
            if(l!=r)
            {
                if(tmp.y<=mid)q[dep+1][0].push(tmp);
                else q[dep+1][1].push(tmp);
            }
        }
    }
    all_binary(l,mid,dep+1,0),all_binary(mid+1,r,dep+1,1);
}
vector<node>v;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        node tmp;
        ans[i]=-1;
        tmp.id=i;
        scanf("%d",&tmp.tpe);
        if(tmp.tpe==1)scanf("%d %d %d",&tmp.x,&tmp.y,&tmp.num),v.push_back(tmp);
        if(tmp.tpe==2)scanf("%d %d %d %d",&tmp.lx,&tmp.rx,&tmp.ly,&tmp.ry);
        q[0][0].push(tmp);
    }
    for(node tmp:v)
    {
        tmp.tpe=3;
        q[0][0].push(tmp);
    }
    all_binary(1,maxn,0,0);
    for(int i=1;i<=n;i++)if(ans[i]!=-1)printf("%d\n",ans[i]);
    return 0;
}
