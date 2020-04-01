#include<bits/stdc++.h>
using namespace std;
const int maxn=300005,ALP=26;
string t;
struct PalindromeAutomaton
{
    int next[maxn][ALP],fail[maxn],s[maxn],n,p;
    int cnt[maxn];//表示节点i表示的本质不同的串的个数（建树时求出的不是完全的，最后count()函数跑一遍以后才是正确的）
    int num[maxn];//表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数
    int len[maxn];//len[i]表示节点i表示的回文串的长度（一个节点表示一个回文串），当前有p个节点
    int last;//指向新添加一个字母后所形成的最长回文串表示的节点
    //num[last]为最后添加的一个字母所增加的回文子串个数。
    int newnode(int l)
    {
        for(int i=0;i<ALP;i++)next[p][i]=0;
        cnt[p]=num[p]=0,len[p]=l;
        return p++;
    }
    void init()
    {
        p=last=n=0,s[n]=-1,fail[0]=1;
        newnode(0),newnode(-1);
    }
    int get_fail(int x)
    {
        while(s[n-len[x]-1]!=s[n])x=fail[x];
        return x;
    }
    void add(int c)
    {
        s[++n]=c;
        int cur=get_fail(last);
        if(!next[cur][c])
        {
            int now=newnode(len[cur]+2);
            fail[now]=next[get_fail(fail[cur])][c];
            next[cur][c]=now,num[now]=num[fail[now]] + 1;
        }
        last=next[cur][c];
        cnt[last]++;
    }
    void count()
    {
        for(int i=p-1;i>=0;i--)cnt[fail[i]]+=cnt[i];
    }
    void dfs(int now)
    {
        for(int i=0;i<ALP;i++)
        {
            if(next[now][i])
            {
                t+='a'+i;
                cout<<t<<endl;
                dfs(next[now][i]);
                t=t.substr(0,t.size()-1);
            }
        }
    }
}pam;
char s[300005];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        pam.init();
        int len=strlen(s);
        for(int i=0;i<len;i++)pam.add(s[i]-'a');
        pam.dfs(0);
    }
    return 0;
}