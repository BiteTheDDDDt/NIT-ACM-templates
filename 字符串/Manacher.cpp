#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
char ma[maxn*2],s[maxn];
int mp[maxn*2];
void Manacher(char *s,int len)
{
    int l=0;
    ma[l++]='$',ma[l++]='#';
    for(int i=0;i<len;i++)ma[l++]=s[i],ma[l++]='#';
    ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;i++)
    {
        mp[i]=mx>i?min(mp[id*2-i],mx-i):1;
        while(ma[i+mp[i]]==ma[i-mp[i]])mp[i]++;
        if(i+mp[i]>mx)mx=i+mp[i],id=i;
    }
}
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        Manacher(s,len);
        int ans=0;
        for(int i=0;i<2*len+2;i++)ans=max(ans,mp[i]-1);
        printf("%d\n",ans);
    }
}