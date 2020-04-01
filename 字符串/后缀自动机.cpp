#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005,ALP=26;
struct SuffixAutomaton
{
    int next[maxn*2][ALP],p,cnt[maxn*2];
    int fail[maxn*2];//表示节点i的后缀链接
    int len[maxn*2];//表示节点i表示的等价集合的最长子串长度
    int last;//指向新添加一个字母后所形成的最长子串所指向的节点
    void init()
    {
        last=p=0,fail[0]=-1;
        newnode(0);
    }
    int newnode(int l)
    {
        for(int i=0;i<ALP;i++)next[p][i]=-1;
        len[p]=l,cnt[p]=0;
        return p++;
    }
    void add(int c)
    {
        int cur=newnode(len[last]+1),t=last;
        cnt[cur]++;
        for(;t!=-1&&next[t][c]==-1;t=fail[t])next[t][c]=cur;
        if(t==-1)fail[cur]=0;
        else
        {
            int q=next[t][c];
            if(len[t]+1==len[q])fail[cur]=q;
            else
            {
                int clone=newnode(len[t]+1);
                fail[clone]=fail[q];
                for(int i=0;i<26;i++)next[clone][i]=next[q][i];
                for(;t!=-1&&next[t][c]==q;t=fail[t])next[t][c]=clone;
                fail[q]=fail[cur]=clone;
            }
            
        }
        last=cur;
    }
    int lcs(char* str,int slen)
    {
        int now=0,l=0,ans=0,sum=0;
        for(int i=0;i<slen;i++)
        {
            int c=str[i]-'a';
            while(now&&next[now][c]==-1)now=fail[now],l=len[now];
            if(next[now][c]!=-1)now=next[now][c],l++;
            ans=max(ans,l);
            sum+=ans;
        }
        return sum;
    }
    int rk[maxn*2];
    void sort()
    {
        for(int i=0;i<p;i++)rk[i]=i;
        std::sort(rk,rk+p,[&](int x,int y){return len[x]>len[y];});
        for(int i=0;i<p;i++)if(fail[rk[i]]!=-1)cnt[fail[rk[i]]]+=cnt[rk[i]];
    }
}sam;
char s[maxn];
int main()
{
    scanf("%s",s);
    sam.init();
    for(int i=0;s[i]!='\0';i++)sam.add(s[i]-'a');
    int ans=0;
    for(int i=0;i<sam.p;i++)if(sam.cnt[i]>1)ans=max(ans,sam.cnt[i]*sam.len[i]);
    printf("%d\n",ans);
    return 0;
}