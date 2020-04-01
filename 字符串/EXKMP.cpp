#include<bits/stdc++.h>
using namespace std;
int n,T,nex[200005],ex[200005];
char s[200005];
void cal_nex(char *str,int len)
{
    nex[0]=len,nex[1]=0;
    while(nex[1]+1<len&&str[nex[1]]==str[nex[1]+1])nex[1]++;
    for(int i=2,i0=1;i<len;i++)
    {
        if(i+nex[i-i0]<nex[i0]+i0)nex[i]=nex[i-i0];
        else
        {
            nex[i]=max(0,nex[i0]+i0-i);
            while(i+nex[i]<len&&str[nex[i]]==str[i+nex[i]])nex[i]++;
            i0=i;
        }
    }
}
void EX_KMP(char *str,int slen,char *ptr,int plen)
{
    cal_nex(ptr,plen);
    ex[0]=0;
    while(ex[0]<slen&&ex[0]<plen&&str[ex[0]]==ptr[ex[0]])ex[0]++;
    for(int i=1,i0=0;i<slen;i++)
    {
        if(i+nex[i-i0]<ex[i0]+i0)ex[i]=nex[i-i0];
        else
        {
            ex[i]=max(0,ex[i0]+i0-i);
            while(i+ex[i]<slen&&ex[i]<plen&&str[i+ex[i]]==ptr[ex[i]])ex[i]++;
            i0=i;
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %s",&n,s);
        EX_KMP(s,n,s,n);
        int ans=0;
        for(int i=0;i<n;i++)ans+=ex[i],ans%=10007;
        printf("%d\n",ans);
    }
    return 0;
}
