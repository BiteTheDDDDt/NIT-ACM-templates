#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,tree[1000005][26],num,sum[1000005],cnt;
char s[11];
void c_tree()
{
    int len=strlen(s),root=0;
    for(int i=0;i<len;i++)
    {
        if(!tree[root][s[i]-'a'])tree[root][s[i]-'a']=++cnt;
        sum[tree[root][s[i]-'a']]++;
        root=tree[root][s[i]-'a'];
    }
}
int q_tree()
{
    int len=strlen(s),root=0;
    for(int i=0;i<len;i++)
    {
        root=tree[root][s[i]-'a'];
        if(!root)return 0;
    }
    return sum[root];
}
int main()
{
    while(gets(s)&&s[0]!='\0')c_tree();
    while(gets(s)!=NULL) printf("%d\n",q_tree());
    return 0;
}
