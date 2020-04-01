#include<bits/stdc++.h>
using namespace std;
const int MAXNODE=500005,MAXCHAR=26,MAXN=1000005,MAXM=10005;
int ans,T,n,success[MAXM];
char s[MAXN],t[MAXN];
struct AC_automaton
{
    int ch[MAXNODE][MAXCHAR];
    int sz;
    int val[MAXNODE];
    int fail[MAXNODE];
    int last[MAXNODE];
    int q[MAXNODE];
    int head,tail;
    void clear()
    {
        for(int i=0;i<MAXCHAR;++i)
        {
            ch[0][i]=0;
        }
        sz=head=tail=0;
    }
    int new_node()
    {
        sz++;
        for(int i=0;i<MAXCHAR;++i)
        {
            ch[sz][i]=0;
        }
        fail[sz]=last[sz]=val[sz]=0;
        return sz;
    }
    void insert(char t[])
    {
        int root=0;
        for(int i=0; t[i]!='\0'; ++i)
        {
            if(!ch[root][t[i]-'a'])
            {
                ch[root][t[i]-'a']=new_node();
            }
            root=ch[root][t[i]-'a'];
        }
        ++val[root];
    }
    void getfail()
    {
        for(int i=0; i<MAXCHAR; i++)
        {
            if(ch[0][i])
            {
                q[++tail]=ch[0][i];
            }
        }
        while(head!=tail)
        {
            int root=q[++head];
            for(int i=0; i<MAXCHAR; i++)
            {
                if(!ch[root][i])
                {
                    ch[root][i]=ch[fail[root]][i];
                    continue;
                }
                int child=ch[root][i];
                fail[child]=ch[fail[root]][i];
                last[child]=val[fail[child]]?fail[child]:last[fail[child]];
                q[++tail]=child;
            }
        }
    }
    void addnum(int root)
    {
        if(root)
        {
            ans+=val[root];
            addnum(last[root]);
        }
    }
    void find(char s[])
    {
        int root=0;
        for(int i=0; s[i]!='\0'; i++)
        {
            root=ch[root][s[i]-'a'];
            if(val[root]) addnum(root);
            else if(val[last[root]]) addnum(last[root]);
        }
    }
}AC;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        AC.clear();
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%s",&t);
            AC.insert(t);
            success[i]=0;
        }
        AC.getfail();
        scanf("%s",&s);
        AC.find(s);
        printf("%d\n",ans);
    }
    return 0;
}
